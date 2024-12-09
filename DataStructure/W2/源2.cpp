#include <iostream>
using namespace std;

// �ڵ�ṹ��
struct Node
{
	Node* prior;
	int data;
	Node* next;
};

int main() {

	// ��������ѭ������
	int n = 0, m = 0;	// �ڵ���  ˫�����������ʼλ��

	cin >> n;

	// ͷָ�롢βָ��
	Node* head = NULL;
	Node* tail = NULL;

	int data = 0;
	for (int i = 0; i < n; i++) {
		cin >> data;

		Node* pNode = new Node;
		pNode->data = data;

		// ��ʼ����ͷָ��
		if (head == NULL) {
			head = pNode;
			tail = pNode;
			head->next = head;
		}
		else {
			// ���ӽڵ�
			tail->next = pNode;
			tail = pNode;
			tail->next = head;	// ѭ������
		}
	}

	// ������ѭ����Ϊ˫��ѭ��
	Node* current = head;	// ��¼��ǰλ��
	Node* pre = tail;	// ��¼��ǰָ���ǰһλ


	// ��������ÿ���ڵ��ǰλ�ڵ�
	do {
		current->prior = pre;
		pre = current;
		current = current->next;
	} while (current != head);


	// ȷ��˫�����������ʼλ��
	cin >> m;

	// ��������
	Node* start = head;

	while (start->data != m) {
		start = start->next;
	}

	// �������
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