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
    // ��ȡͼƬ�Ŀ�Ⱥ͸߶�
    cols = p->get_width();  // ��
    rows = p->get_height();     // ��

    // std::cout <<cols;

    int hexHeight = 13; // �����εĸ߶�
    int hexWidth = 9;   // �����εĿ��
    int hexVerticalSpacing = 8; // ��ֱ����ļ�ࣨ3/4 �߶ȣ�

    // �������������������������
    int hexCols = (cols - 1) / 8;
    int hexRows = (rows - 5) / 8;

    // std::cout << hexCols << " " << hexRows << std::endl;


    // ��ʼ����ҵ����̶ȵ�����
    grid.resize(hexRows, std::vector<int>(hexCols, -1)); // Ĭ�ϱ��Ϊ���ɴ-1��

    // ��������������
    for (int hy = 0; hy < hexRows; ++hy) {
        for (int hx = 0; hx < hexCols; ++hx) {
            // ���������ε����ĵ�
            int centerX = hx * (hexWidth - 1) + (hy % 2 == 1 ? 0 : hexWidth / 2) + 1; // ż���к������е�ˮƽƫ��
            int centerY = hy * hexVerticalSpacing + hexHeight / 2 + 1;


            // ������ĵ��Ƿ���ͼƬ��Χ��
            if (centerX >= 0 && centerX < cols && centerY >= 0 && centerY < rows) {
                pxl* pixel = p->get_pxl(centerX, centerY);
                if (pixel != nullptr) {
                    int r = pixel->red;
                    int g = pixel->green;
                    int b = pixel->blue;

                    if (isValidHexagonColor(r, g, b)) {
                        // ������ɫ�����ҵ����̶�
                        grid[hy][hx] = 255 * 255 * 3 - (r * r + g * g + b * b);
                    }
                }
            }

            // ���û��������Чֵ������Ϊ -1���հ�����
    // ��ӡ������Ϣ
    // if (hy < 3){
    //         std::cout << "Hexagon (" << hy << ", " << hx << "): center (" 
    //           << centerX << ", " << centerY << "), grid value = " 
    //           << grid[hy][hx] << std::endl;
    // }
        }
    }

    // ���¿��
    cols = hexCols;  // ��
    rows = hexRows;     // ��

}

// �����������ж���ɫ�Ƿ�������Ч��������
bool State::isValidHexagonColor(int r, int g, int b) {
    if (r == 255 && g == 255 && b == 255) return false;
    if (r == 0 && g == 0 && b == 0) return false;
    return true;
}

int State::solve() {

    // ���ȶ��У��洢 {��ǰ·��Ȩ�غ�, ��ǰ�ݵ����� (x, y)}
    typedef std::pair<int, std::pair<int, int>> Node; // {��ǰ·��Ȩ�غ�, {x, y}}

    // С���ѣ�����·��Ȩ����������
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    // ���·���������飬��¼����㵽ÿ���ڵ�����·��Ȩ��
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, INT_MAX));  // ��ʼ��Ϊ�����

    std::vector<std::vector<bool>> vis(rows, std::vector<bool>(cols, false));

    // ���
    pq.push({ grid[0][0], {0, 0} });
    dist[0][0] = grid[0][0];

    int count = 0;

    // Dijkstra �㷨
    while (!pq.empty()) {
        Node curr = pq.top();   // ȡ����ǰ������Ȩ����С�Ľڵ�
        pq.pop();

        int currCost = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        // ����ڵ��Ѿ����ʹ�������
        if (vis[x][y]) continue;
        vis[x][y] = true;


        // ��������յ㣬���ؽ��
        if (x == rows - 1 && y == cols - 1) {
            return currCost - grid[0][0];
        }

        // ���ݵ�ǰ�е���ż��ѡ��ƫ����
        const int* dx = (x % 2 == 0) ? dx_odd : dx_even; // �� 0 ����������
        const int* dy = (x % 2 == 0) ? dy_odd : dy_even;

        // �����������ڽڵ�
        for (int i = 0; i < 6; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                int newCost = currCost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({ newCost, {nx, ny} });   // ���뵱ǰȨ�غ�������Ľڵ�
                }
            }
        }
    }
}
