#include <iostream>
#include <string>
using namespace std;

/*
	此程序不适合计算多位数字情况
*/

// 节点构造体
typedef struct Node {
	char data;	// 节点数据
	Node* next;	// 指向后一节点
}sNode, * sLink;	// 栈节点 栈节点指针

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
		return ' ';
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
		return ' ';
	}
	return top->data;
}

// 符号权重判断函数
bool precedence(char op1, char op2) {
	int weight1 = 0, weight2 = 0;	// 权重值
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
	// 判断权重优先级
	if (weight1 >= weight2)
	{
		return true;	// 需要出栈操作，返回真
	}

	return false;
}

// 中缀表达式转后缀表达式函数
string infixToPostfix(string expr) {
	sLink opStack = NULL;	// 符号排序栈
	string postfix;		// 转换后的后缀表达式

	for (auto& token : expr) {
		switch (token)
		{
			case ' ':
				break;	// 跳过空格
			case '+':
			case '-':
			case '*':
			case '/':
			case '(': {
				// 判断优先级
				while (!isEmpLinkStack(opStack) && precedence(getLinkStackTop(opStack), token)) {
					// 出栈存入后缀表达式
					postfix += linkPop(opStack);
				}
				linkPush(opStack, token);
				break;
			}
			case ')': {
				// 出栈直到'('
				while (getLinkStackTop(opStack) != '(') {
					// 出栈存入后缀表达式
					postfix += linkPop(opStack);
				}
				linkPop(opStack);	// 退掉'('
				break;
			}
			default: {
				// 数字情况
				postfix += token;
				break;
			}
		}
	}

	// 清空栈
	while (!isEmpLinkStack(opStack))
	{
		postfix += linkPop(opStack);
	}
	return postfix;
}

// 后缀表达式计算函数
int calcuPostfix(string postfix) {
	sLink numStack = NULL;		// 存放数字栈
	int result;		// 计算结果
	int left, right;
	for (const auto& token : postfix) {
		switch (token)
		{
			case '+': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left + right); break;
			case '-': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left - right); break;
			case '*': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left * right); break;
			case '/': right = linkPop(numStack); left = linkPop(numStack); linkPush(numStack, left / right); break;
			default : // 数字情况
				linkPush(numStack, (token - '0'));
		}
	}

	return getLinkStackTop(numStack);	// 计算结果可以多余 1位
}

int main() {
	// 获取表达式
	string expr;
	getline(cin, expr);

	string postfix = infixToPostfix(expr);
	int result = calcuPostfix(postfix);

	cout << result << endl;
}