#include <stack>
#include <queue>

// 在不使用 loop 前提下  判断队列和栈是否包含相同的元素

int Compare_stack_queue(std::stack<int> *s, std::queue<int> *q);
int Compare_stack_queue(std::stack<int> *s, std::queue<int> *q) {
    // 如果栈和队列都为空  返回 1   没有 empty() 方法
    if (s->size() == 0 && q->size() == 0) {
        return 1;
    }

    // 如果栈和队列的大小不相等  返回 0
    if (s->size() != q->size()) {
        return 0;
    }

    // 基于递归的思想  逐个比较栈和队列的元素
    int sTop = s->top();
    int qFront = q->front();

    q->pop();
    s->pop();

    // 如果栈和队列的元素不相等  返回 0
    if (sTop != qFront) {
        return 0;
    }

    // 递归调用
    int result = Compare_stack_queue(s, q);

    // 恢复栈和队列的状态
    s->push(sTop);
    // 恢复队列的状态
    std::queue<int> tmp;
    while (!q->size() == 0)
    {
        tmp.push(q->front());
        q->pop();
    }
    q->push(qFront);
    while (!tmp.size() == 0)
    {
        q->push(tmp.front());
        tmp.pop();
    }

    return result;
}
