#include<iostream>
using namespace std;

class DNode {
public:
	int data;
	DNode* llink;
	DNode* rlink;
};

DNode* Head = NULL;						// # 헤드포인터





//제일 뒤에 추가
void insert_node(DNode* new_node) {			// # 값을 받아서 그 값을 갖는 노드를 만들어내야함
	//// 새노드 할당 및 사전 작업
	new_node->rlink = Head;
	new_node -> llink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;
	/*
	//new_node를 제일 뒤쪽에 추가
	new_node->rlink = Head;
	new_node->rlink = Head->llink;
	Head->llink->rlink = new_node;
	Head->llink = new_node;*/
}



// 값을 가진 노드를 삭제
void delete_node(int value) {
	for (DNode* list = Head->rlink; list != Head; list = list->rlink)
		if (list->data == value) {//list에 해당하는 노드를 삭제
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
	// 헤드 노드를 생성
	Head = new DNode;
	Head->llink = Head;
	Head->rlink = Head;

	int num, data;

	cout << "입력할 노드의 개수는 ?";
	cin >> num;

	// 8개의 노드를 삽입하여 연결리스트 구성

	for (int i = 0; i < num; i++)
	{
		//노드값 입력
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
	delete_node(45); print_list();				// # 존재하지 않는 거 걍 지워봄 (테스트)
	delete_node(80); print_list();				// # 마지막 노드도 한 번 지워봄 (테스트)
	delete_node(10); print_list();				// # 가장 앞 노드도 지워봄 (테스트)
	
}