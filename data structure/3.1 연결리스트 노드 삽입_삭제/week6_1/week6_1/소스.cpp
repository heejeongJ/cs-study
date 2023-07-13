#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head = NULL;						// # NULL�� �ʱ�ȭ �� �� �ص� ��, �̰� �������� ����� �� �ֵ��� ���������� ����ϱ� ���� �Լ� �ۿ� ���� ������ ��������


// # ���� �����
void reverse() {
	Node* ptr;
	Node* p, * q, * r;

	p = Head;
	q = NULL;	// r = NULL;�� �ᵵ �׸� �� �ᵵ �׸�
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;	//q�� ��ũ�� �������� ����
	}
	Head = q;

}



//���� �ڿ� �߰�
void insert_node(int value) {			// # ���� �޾Ƽ� �� ���� ���� ��带 ��������

	Node* new_node;

	new_node = new Node;				// # ���� �ϳ� �Ҵ� �޴°ž�., ���ο� ��带 �Ҵ����
	new_node->data = value;
	new_node->link = NULL;

	if (Head == NULL) {
		Head = new_node;
	}
	else {
		//������ ��带 ã�´�
		Node* list = Head;

		while (list->link != NULL)
			list = list->link;
		//�� ���, list�� ������ ��带 ����Ŵ
		list->link = new_node;
	}
}


void print_list() {
	for (Node* list = Head; list != NULL; list = list->link)
		if (list->link != NULL) cout << list->data << "->";
		else cout << list->data << endl;
}



void main()
{


	// 8���� ��带 �����Ͽ� ���Ḯ��Ʈ ����


	insert_node(10);							
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);
	insert_node(70);
	insert_node(80);

	print_list();

	reverse();									// # ���� Ȯ��
	print_list();
}