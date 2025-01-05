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
    std::vector<std::vector<int>> grid; // �洢ÿ���ݵĲ�ҵ����̶�
    int rows; // ����
    int cols; // ����

    // ����ƫ�������ֱ���������к�ż����
    const int dx_odd[6] = { -1, 0, 1, 1, 0, -1 };  // �����е� x ƫ����
    const int dy_odd[6] = { 0, 1, 0, 1, -1, 1 };  // �����е� y ƫ����

    const int dx_even[6] = { -1, -1, 0, 0, 1, 1 }; // ż���е� x ƫ����
    const int dy_even[6] = { -1, 0, -1, 1, -1, 0 }; // ż���е� y ƫ����


    // �ж�һ�������Ƿ��ڵ�ͼ��Χ��
    bool isValid(int x, int y);

    bool isValidHexagonColor(int r, int g, int b);

public:
    State();
    State(State& other);
    State(State&& other);
    ~State();
    State& operator=(State&& other);
    State& operator=(State& other);

    void parse(PNG* p);     // ����ÿ��ͼƬÿ�����ؽڵ�Ĳ�ҵ����̶�
    int solve();
};

#endif
