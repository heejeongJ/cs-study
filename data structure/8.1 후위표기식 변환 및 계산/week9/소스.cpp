//c++ó�� Ŭ���� �̿��ؼ� �����غ�(��ü���� ���α׷���)
//week8_1�� �ۼ��� �ڵ�� C��Ÿ���̾�
#include <iostream>
using namespace std;
#include<stack>
/*
//�迭�� �̿��� ���� ����
const int MAX_STACK_SIZE = 100;
class Node {
public:
	int data;
	Node* link;
};

class Stack {

	//��� ����
public:
	int *SP;

	//������ �Լ�
	Stack() {
		SP = NULL;
	}

	//��� �Լ�


	bool is_stack_empty() {
		
		return(SP == NULL);
	}

	void push(int value) {
		Node* new_node = new Node;
		new_node->data = value;
		
		new_Node->link = SP;
		SP = new_node;
		}
	}

	int pop() {
		if (is_stack_empty()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		int x = SP->data;
		SP = SP->link;
		return x;
	}

	int peek() {
		if (is_stack_empty()) {
			cout << "ERROR : empty Stack" << endl;
		}
		else return(SP->data);
	}

	void print_stack() {
		cout << "STACK ���� ���" << endl;
		for (Node* list=SP; list !=NULL;list=list->link)
			cout << MyStack[i] << endl;
	}
};


void main() {
	Stack s;				// s ��ü ����
	stack <int>s2;
	s.push(10);				// s��� ������ push~
	s.push(20);
	s.pop();
	s.push(30);
	s.push(40);
	s.pop();
	s.push(50);
	s.push(60);
	s.print_stack();
	s.pop();
	s.pop();
	s.pop();
	s.print_stack();
}
*/