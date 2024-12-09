#include <iostream>
#include <string>
using namespace std;

/*
	�˳����ʺϼ����λ�������
*/

// �ڵ㹹����
typedef struct Node {
	char data;	// �ڵ�����
	Node* next;	// ָ���һ�ڵ�
}sNode, * sLink;	// ջ�ڵ� ջ�ڵ�ָ��

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
		return ' ';
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
		return ' ';
	}
	return top->data;
}

// ����Ȩ���жϺ���
bool precedence(char op1, char op2) {
	int weight1 = 0, weight2 = 0;	// Ȩ��ֵ
	switch (op1)
	{
		case '(': 
			weight1 = 0; break;
		case '+':
		case '-': 
			weight1 = 1; break;
		case '*':
		case '/': 
			weight1 = 2; break;
	}
	switch (op2)
	{
		case '+':
		case '-': 
			weight2 = 1; break;
		case '*':
		case '/': 
			weight2 = 2; break;
		case '(':
			weight2 = 3; break;
	}
	// �ж�Ȩ�����ȼ�
	if (weight1 >= weight2)
	{
		return true;	// ��Ҫ��ջ������������
	}

	return false;
}

// ��׺���ʽת��׺���ʽ����
string infixToPostfix(string expr) {
	sLink opStack = NULL;	// ��������ջ
	string postfix;		// ת����ĺ�׺���ʽ

	for (auto& token : expr) {
		switch (token)
		{
			case ' ':
				break;	// �����ո�
			case '+':
			case '-':
			case '*':
			case '/':
			case '(': {
				// �ж����ȼ�
				while (!isEmpLinkStack(opStack) && precedence(getLinkStackTop(opStack), token)) {
					// ��ջ�����׺���ʽ
					postfix += linkPop(opStack);
				}
				linkPush(opStack, token);
				break;
			}
			case ')': {
				// ��ջֱ��'('
				while (getLinkStackTop(opStack) != '(') {
					// ��ջ�����׺���ʽ
					postfix += linkPop(opStack);
				}
				linkPop(opStack);	// �˵�'('
				break;
			}
			default: {
				// �������
				postfix += token;
				break;
			}
		}
	}

	// ���ջ
	while (!isEmpLinkStack(opStack))
	{
		postfix += linkPop(opStack);
	}
	return postfix;
}

// ��׺���ʽ���㺯��
int calcuPostfix(string postfix) {
	sLink numStack = NULL;		// �������ջ
	int result;		// ������
	int left, right;
	for (const auto& token : postfix) {
		switch (token)
		{
			case '+': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left + right); break;
			case '-': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left - right); break;
			case '*': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left * right); break;
			case '/': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left / right); break;
			default : // �������
				linkPush(numStack, (token - '0'));
		}
	}

	return getLinkStackTop(numStack);	// ���������Զ��� 1λ
}

int main() {
	// ��ȡ���ʽ
	string expr;
	getline(cin, expr);

	string postfix = infixToPostfix(expr);
	int result = calcuPostfix(postfix);

	cout << result << endl;
}