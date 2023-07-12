#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head = NULL;						// # NULL로 초기화 꼭 안 해도 돼, 이곳 저곳에서 사용할 수 있도록 전역변수로 사용하기 위해 함수 밖에 따로 별도로 선언해줌



/*경우c
void insert_node(int value) {			// # 값을 받아서 그 값을 갖는 노드를 만들어내야함

	Node* new_node;

	new_node = new Node;				// # 방을 하나 할당 받는거야., 새로운 노드를 할당받음
	new_node->data = value;
	new_node->link = NULL;

	new_node->link = Head;				// # 새 노드를 첫번째 노드로 띄어줌
	Head = new_node;
}

void print_list() {
	for (Node* list = Head; list != NULL; list = list->link)
		cout << list->data << "->";
}
*/


// 값을 가진 노드를 삭제
void delete_node(int value) {
	if (Head == NULL) {
		cout << "빈 리스트입니다.";
		return;
	}
	else if (Head->data == value) {
		Head = Head->link;
		return;
	}
	else {
		Node* list = Head;
		while (list->link != NULL) {
			if (list->link->data == value) {
				list->link = list->link->link;			// # 다음방엔 다음다음방의 주소를 넣어라
				return;
			}
			list = list->link;
		}
	}

}



//제일 뒤에 추가
void insert_node(int value) {			// # 값을 받아서 그 값을 갖는 노드를 만들어내야함

	Node* new_node;

	new_node = new Node;				// # 방을 하나 할당 받는거야., 새로운 노드를 할당받음
	new_node->data = value;
	new_node->link = NULL;

	if (Head == NULL) {
		Head = new_node;
	}
	else {
		//마지막 노드를 찾는다
		Node* list = Head;

		while (list->link != NULL) 
			list = list->link;
		//이 경우, list는 마지막 노드를 가리킴
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


	// 8개의 노드를 삽입하여 연결리스트 구성

	delete_node(10);							// # 시험 삼아 지워봄

	insert_node(10);							
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);
	insert_node(70);
	insert_node(80);

	print_list();

	

	delete_node(40); print_list();
	delete_node(70); print_list();
	delete_node(45); print_list();				// # 존재하지 않는 거 걍 지워봄 (테스트)
	delete_node(80); print_list();				// # 마지막 노드도 한 번 지워봄 (테스트)
	delete_node(10); print_list();				// # 가장 앞 노드도 지워봄 (테스트)

}