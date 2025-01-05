#include "stack.h"
#include "queue.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

Stack<std::string> *history;

Stack<std::string> *tmp;

int resume();
int undo();


int resume() {
    // 如果 history 是空指针  执行初始化
    if (history == NULL) {
        history = new Stack<std::string>();
    }

    // 如果 tmp 是空指针  执行初始化
    if (tmp == NULL) {
        tmp = new Stack<std::string>();
    }

    // 撤销"撤销"操作
    if (tmp->get_size() == 0) {
        return 0;
    }

    Node<std::string> *n = tmp->pop();
    history->push(n);

    return 0;
}

int undo() {
    // 如果 history 是空指针  执行初始化
    if (history == NULL) {
        history = new Stack<std::string>();
    }

    // 如果 tmp 是空指针  执行初始化
    if (tmp == NULL) {
        tmp = new Stack<std::string>();
    }

    // 撤销操作
    if (history->get_size() == 0) {
        return 0;
    }

    Node<std::string> *n = history->pop();
    tmp->push(n);

    return 0;
}
