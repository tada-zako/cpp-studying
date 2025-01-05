#include "state.h"
#include <iostream>
#include <queue>
#include <cmath>
#include <climits>

State::State() : rows(0), cols(0) {}

State::State(State& other) : grid(other.grid), rows(other.rows), cols(other.cols) {}

State::State(State&& other) : grid(std::move(other.grid)), rows(other.rows), cols(other.cols) {}

State::~State() {}

State& State::operator=(State& other) {
    if (this == &other) return *this;
    grid = other.grid;
    rows = other.rows;
    cols = other.cols;
    return *this;
}

State& State::operator=(State&& other) {
    if (this == &other) return *this;
    grid = std::move(other.grid);
    rows = other.rows;
    cols = other.cols;
    return *this;
}

bool State::isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != -1;
}

void State::parse(PNG* p) {
    // 获取图片的宽度和高度
    cols = p->get_width();  // 列
    rows = p->get_height();     // 行

    // std::cout <<cols;

    int hexHeight = 13; // 六边形的高度
    int hexWidth = 9;   // 六边形的宽度
    int hexVerticalSpacing = 8; // 垂直方向的间距（3/4 高度）

    // 计算六边形网格的行数和列数
    int hexCols = (cols - 1) / 8;
    int hexRows = (rows - 5) / 8;

    // std::cout << hexCols << " " << hexRows << std::endl;


    // 初始化产业发达程度的网格
    grid.resize(hexRows, std::vector<int>(hexCols, -1)); // 默认标记为不可达（-1）

    // 遍历六边形网格
    for (int hy = 0; hy < hexRows; ++hy) {
        for (int hx = 0; hx < hexCols; ++hx) {
            // 计算六边形的中心点
            int centerX = hx * (hexWidth - 1) + (hy % 2 == 1 ? 0 : hexWidth / 2) + 1; // 偶数行和奇数行的水平偏移
            int centerY = hy * hexVerticalSpacing + hexHeight / 2 + 1;


            // 检查中心点是否在图片范围内
            if (centerX >= 0 && centerX < cols && centerY >= 0 && centerY < rows) {
                pxl* pixel = p->get_pxl(centerX, centerY);
                if (pixel != nullptr) {
                    int r = pixel->red;
                    int g = pixel->green;
                    int b = pixel->blue;

                    if (isValidHexagonColor(r, g, b)) {
                        // 根据颜色计算产业发达程度
                        grid[hy][hx] = 255 * 255 * 3 - (r * r + g * g + b * b);
                    }
                }
            }

            // 如果没有设置有效值，保持为 -1（空白区域）
    // 打印调试信息
    // if (hy < 3){
    //         std::cout << "Hexagon (" << hy << ", " << hx << "): center (" 
    //           << centerX << ", " << centerY << "), grid value = " 
    //           << grid[hy][hx] << std::endl;
    // }
        }
    }

    // 更新宽高
    cols = hexCols;  // 列
    rows = hexRows;     // 行

}

// 辅助函数：判断颜色是否属于有效的六边形
bool State::isValidHexagonColor(int r, int g, int b) {
    if (r == 255 && g == 255 && b == 255) return false;
    if (r == 0 && g == 0 && b == 0) return false;
    return true;
}

int State::solve() {

    // 优先队列，存储 {当前路径权重和, 当前州的坐标 (x, y)}
    typedef std::pair<int, std::pair<int, int>> Node; // {当前路径权重和, {x, y}}

    // 小顶堆，按照路径权重升序排序
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    // 最短路径距离数组，记录从起点到每个节点的最短路径权重
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, INT_MAX));  // 初始化为无穷大

    std::vector<std::vector<bool>> vis(rows, std::vector<bool>(cols, false));

    // 起点
    pq.push({ grid[0][0], {0, 0} });
    dist[0][0] = grid[0][0];

    int count = 0;

    // Dijkstra 算法
    while (!pq.empty()) {
        Node curr = pq.top();   // 取出当前队列中权重最小的节点
        pq.pop();

        int currCost = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        // 如果节点已经访问过，跳过
        if (vis[x][y]) continue;
        vis[x][y] = true;


        // 如果到达终点，返回结果
        if (x == rows - 1 && y == cols - 1) {
            return currCost - grid[0][0];
        }

        // 根据当前行的奇偶性选择偏移量
        const int* dx = (x % 2 == 0) ? dx_odd : dx_even; // 第 0 行是奇数行
        const int* dy = (x % 2 == 0) ? dy_odd : dy_even;

        // 遍历六个相邻节点
        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                int newCost = currCost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({ newCost, {nx, ny} });   // 存入当前权重和所到达的节点
                }
            }
        }
    }
}
