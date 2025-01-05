#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include "stack.h"

template <class T>
class Queue {
private:
    // 两个栈实现一个队列
    Stack<T> *in;
    Stack<T> *out;
    int size;
public:
    Queue();
    Queue(Queue &other);
    ~Queue();
    Queue &operator=(Queue &other);
    int get_size() const;
    void push(T *t);
    void push(Node<T> *n);
    Node<T> *pop();
    void print();
};

#include "queue.cpp"
#endif
