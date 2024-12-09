#include <iostream>
using namespace std;

// �ڵ㹹����
typedef struct Node {
	char data;	// �ڵ�����
	Node* next;	// ָ���һ�ڵ�
}sNode, *sLink;	// ջ�ڵ� ջ�ڵ�ָ��

// ��ʽջ����غ���
void clearLinkStack(sLink& top);
bool isEmpLinkStack(sLink& top);
void linkPush(sLink& top, char a);
char linkPop(sLink& top);
char getLinkStackTop(sLink& top);

// �ÿ�ջ
void clearLinkStack(sLink& top) {
	// ѭ����ջ�����ָ��ָ���
	while (top) {
		linkPop(top);
	}
	top = NULL;
}

// �ж�ջ��
bool isEmpLinkStack(sLink& top) {
	return top == NULL;
}

// ��ջ
void linkPush(sLink& top, char a) {
	sLink node = new sNode;
	node->data = a;
	node->next = top;
	top = node;
}

// ��ջ����ɾ����ջ�ڵ�
char linkPop(sLink& top) {
	// �ж�ջ��
	if (isEmpLinkStack(top)) {
		return '\0';
	}

	char a;	// �洢����ֵ
	sLink node;	// ��ɾ���Ľڵ�
	a = top->data;
	node = top;
	top = top->next;
	delete node;
	return a;
}

// ����ջ��Ԫ��
char getLinkStackTop(sLink& top) {
	if (isEmpLinkStack(top)) {
		return '\0';
	}
	return top->data;
}
