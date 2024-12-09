#include <iostream>
using namespace std;

// 节点结构体
struct Node
{
	Node* prior;
	int data;
	Node* next;
};

int main() {

	// 创建单向循环链表
	int n = 0, m = 0;	// 节点数  双向链表输出开始位置

	cin >> n;

	// 头指针、尾指针
	Node* head = NULL;
	Node* tail = NULL;

	int data = 0;
	for (int i = 0; i < n; i++) {
		cin >> data;

		Node* pNode = new Node;
		pNode->data = data;

		// 初始连接头指针
		if (head == NULL) {
			head = pNode;
			tail = pNode;
			head->next = head;
		}
		else {
			// 连接节点
			tail->next = pNode;
			tail = pNode;
			tail->next = head;	// 循环连接
		}
	}

	// 将单项循环改为双向循环
	Node* current = head;	// 记录当前位置
	Node* pre = tail;	// 记录当前指针的前一位


	// 遍历连接每个节点的前位节点
	do {
		current->prior = pre;
		pre = current;
		current = current->next;
	} while (current != head);


	// 确定双向链表输出开始位置
	cin >> m;

	// 遍历链表
	Node* start = head;

	while (start->data != m) {
		start = start->next;
	}

	// 逆向输出
	current = start;
	do {
		cout << current->data;
		current = current->prior;

		if (current != start) {
			cout << ' ';
		}
	} while (current != start);

	return 0;
}