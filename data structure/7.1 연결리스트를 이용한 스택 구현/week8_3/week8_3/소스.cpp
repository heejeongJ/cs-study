#include <iostream>
using namespace std;

//연결리스트를 이용한 스택 구현

class Node {
public:
	int data;
	Node* link;
};

Node *SP = NULL;

bool is_stack_empty() {

		return(SP == NULL);
	}

void push(int value) {
	Node *new_node = new Node;
	new_node->data = value;
	//new_node->link = NULL;

	new_node->link = SP;
	SP = new_node;
}

int pop() {
		if (is_stack_empty()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		else {
			int x = SP->data;
			SP = SP->link;
			return x;
		}
	}

void print_stack() {
		cout << "STACK 상태 출력" << endl;
		for (Node* ptr = SP; ptr != NULL; ptr = ptr->link)
			cout << ptr->data << endl;
	}



void main() {

	push(10);
	push(20);
	pop();
	push(30);
	push(40);
	pop();
	push(50);
	push(60);
	print_stack();
	pop();
	pop();
	pop();
	print_stack();
}