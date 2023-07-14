//c++처럼 클래스 이용해서 구현해봄(객체지향 프로그래밍)
//week8_1에 작성한 코드는 C스타일이야
#include <iostream>
using namespace std;
#include<stack>
/*
//배열을 이용한 스택 구현
const int MAX_STACK_SIZE = 100;
class Node {
public:
	int data;
	Node* link;
};

class Stack {

	//멤버 변수
public:
	int *SP;

	//생성자 함수
	Stack() {
		SP = NULL;
	}

	//멤버 함수


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
		cout << "STACK 상태 출력" << endl;
		for (Node* list=SP; list !=NULL;list=list->link)
			cout << MyStack[i] << endl;
	}
};


void main() {
	Stack s;				// s 객체 선언
	stack <int>s2;
	s.push(10);				// s라는 스택의 push~
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