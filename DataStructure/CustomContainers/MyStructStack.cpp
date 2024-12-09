#include <iostream>
using namespace std;

// 节点构造体
typedef struct Node {
	char data;	// 节点数据
	Node* next;	// 指向后一节点
}sNode, *sLink;	// 栈节点 栈节点指针

// 链式栈的相关函数
void clearLinkStack(sLink& top);
bool isEmpLinkStack(sLink& top);
void linkPush(sLink& top, char a);
char linkPop(sLink& top);
char getLinkStackTop(sLink& top);

// 置空栈
void clearLinkStack(sLink& top) {
	// 循环出栈，最后指针指向空
	while (top) {
		linkPop(top);
	}
	top = NULL;
}

// 判断栈空
bool isEmpLinkStack(sLink& top) {
	return top == NULL;
}

// 入栈
void linkPush(sLink& top, char a) {
	sLink node = new sNode;
	node->data = a;
	node->next = top;
	top = node;
}

// 出栈，且删除出栈节点
char linkPop(sLink& top) {
	// 判断栈空
	if (isEmpLinkStack(top)) {
		return '\0';
	}

	char a;	// 存储返回值
	sLink node;	// 待删除的节点
	a = top->data;
	node = top;
	top = top->next;
	delete node;
	return a;
}

// 返回栈顶元素
char getLinkStackTop(sLink& top) {
	if (isEmpLinkStack(top)) {
		return '\0';
	}
	return top->data;
}
