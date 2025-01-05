#ifndef STATE_H_
#define STATE_H_

#include "suan_png.h"
#include "pxl.h"
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

class State {
private:
    std::vector<std::vector<int>> grid; // 存储每个州的产业发达程度
    int rows; // 行数
    int cols; // 列数

    // 坐标偏移量，分别针对奇数行和偶数行
    const int dx_odd[6] = { -1, 0, 1, 1, 0, -1 };  // 奇数行的 x 偏移量
    const int dy_odd[6] = { 0, 1, 0, 1, -1, 1 };  // 奇数行的 y 偏移量

    const int dx_even[6] = { -1, -1, 0, 0, 1, 1 }; // 偶数行的 x 偏移量
    const int dy_even[6] = { -1, 0, -1, 1, -1, 0 }; // 偶数行的 y 偏移量


    // 判断一个坐标是否在地图范围内
    bool isValid(int x, int y);

    bool isValidHexagonColor(int r, int g, int b);

public:
    State();
    State(State& other);
    State(State&& other);
    ~State();
    State& operator=(State&& other);
    State& operator=(State& other);

    void parse(PNG* p);     // 解析每张图片每个像素节点的产业发达程度
    int solve();
};

#endif
