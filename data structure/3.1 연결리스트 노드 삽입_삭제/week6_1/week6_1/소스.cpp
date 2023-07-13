#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* link;
};

Node* Head = NULL;						// # NULL로 초기화 꼭 안 해도 돼, 이곳 저곳에서 사용할 수 있도록 전역변수로 사용하기 위해 함수 밖에 따로 별도로 선언해줌


// # 역순 만들기
void reverse() {
	Node* ptr;
	Node* p, * q, * r;

	p = Head;
	q = NULL;	// r = NULL;은 써도 그만 안 써도 그만
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;	//q의 링크를 역순으로 변경
	}
	Head = q;

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


	insert_node(10);							
	insert_node(20);
	insert_node(30);
	insert_node(40);
	insert_node(50);
	insert_node(60);
	insert_node(70);
	insert_node(80);

	print_list();

	reverse();									// # 역순 확인
	print_list();
}