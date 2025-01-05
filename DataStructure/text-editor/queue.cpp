#include "queue.h"
#include <iostream>
template <class T>
Queue<T>::Queue() {
    in = new Stack<T>();
    out = new Stack<T>();
    size = 0;
}

template <class T>
Queue<T>::Queue(Queue &other) {
    // 深拷贝
    in = new Stack<T>(*(other.in));
    out = new Stack<T>(*(other.out));
    size = other.size;
}

template <class T>
Queue<T>::~Queue() {
    if (in) {
        delete in;
        in = NULL;
    }
    if (out) {
        delete out;
        out = NULL;
    }
}

template <class T>
Queue<T> &Queue<T>::operator=(Queue &other) {
    if (in) delete in;
    if (out) delete out;
    in = new Stack<T>(*(other.in));
    out = new Stack<T>(*(other.out));
    size = other.size;
    return *this;
}

template <class T>
int Queue<T>::get_size() const {
    return size;
}

template <class T>
void Queue<T>::push(T *t) {
    if (t == NULL) {
        return;
    }

    Node<T> *n = new Node<T>(t);
    in->push(n);
    size++;

    return;
}

template <class T>
void Queue<T>::push(Node<T> *n) {
    if (n == NULL) {
        return;
    }

    in->push(n);
    size++;

    return;
}

template <class T>
Node<T> *Queue<T>::pop() {
    if (out->get_size() == 0) {
        while (in->get_size() > 0) {
            Node<T> *n = in->pop();
            out->push(n);
        }
    }

    Node<T> *n = out->pop();
    size--;

    return n;
}

template <class T>
void Queue<T>::print() {
    // 按照从后部到前部的顺序打印
    // 先打印in栈，再打印out栈
    if (in) {
        in->print();
    }

    // out栈需要逆序打印  但是out栈不清空
    if (out) {
        Stack<T> *tmp = new Stack<T>(*out);
        Stack<T> *reserve = new Stack<T>();
        while (tmp->get_size() > 0) {
            Node<T> *n = tmp->pop();
            reserve->push(n);
        }
        reserve->print();
    }
    // 打印结束
    std::cout << "END" << std::endl;

    return;
}
