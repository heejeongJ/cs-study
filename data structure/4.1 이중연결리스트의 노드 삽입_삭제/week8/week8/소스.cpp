#include<iostream>
using namespace std;

class DNode {
public:
	int data;
	DNode* llink;
	DNode* rlink;
};

DNode* Head = NULL;						// # ���������





//���� �ڿ� �߰�
void insert_node(DNode* new_node) {			// # ���� �޾Ƽ� �� ���� ���� ��带 ��������
	//// ����� �Ҵ� �� ���� �۾�
	new_node->rlink = Head;
	new_node -> llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
	/*
	//new_node�� ���� ���ʿ� �߰�
	new_node->rlink = Head;
	new_node->rlink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;*/
}



// ���� ���� ��带 ����
void delete_node(int value) {
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
		if (list->data == value) {//list�� �ش��ϴ� ��带 ����
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			return;
		}
}


void print_list() {
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
		if (list == Head->rlink) cout << "-->" << list->data;
		else cout << "-->" << list->data;
	cout << endl;
}



void main()
{
	// ��� ��带 ����
	Head = new DNode;
	Head->llink = Head;
	Head->rlink = Head;

	int num, data;

	cout << "�Է��� ����� ������ ?";
	cin >> num;

	// 8���� ��带 �����Ͽ� ���Ḯ��Ʈ ����

	for (int i = 0; i < num; i++)
	{
		//��尪 �Է�
		cin >> data;

		DNode* new_node = new DNode;
		new_node->data = data;
		new_node->llink = NULL;
		new_node->rlink = NULL;

		insert_node(new_node);
	}
	
	print_list();


	
	delete_node(40); print_list();
	delete_node(47); print_list();
	delete_node(45); print_list();				// # �������� �ʴ� �� �� ������ (�׽�Ʈ)
	delete_node(80); print_list();				// # ������ ��嵵 �� �� ������ (�׽�Ʈ)
	delete_node(10); print_list();				// # ���� �� ��嵵 ������ (�׽�Ʈ)
	
}