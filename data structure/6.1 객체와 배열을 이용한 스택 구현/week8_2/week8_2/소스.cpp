//c++ó�� Ŭ���� �̿��ؼ� �����غ�(��ü���� ���α׷���), �̰� ��õ�ϼ̾� c ��Ÿ�Ϻ��� c++��Ÿ���� ����ϰ� ����
//week8_1�� �ۼ��� �ڵ�� C��Ÿ���̾�
#include <iostream>
//#include <stack> ����ϸ� stack�� �� �����ϰ� �������� �ʾƵ� stack ����� �� �ְ� ��. ���� �ؿ� stack<int> s;�� �����ؾߵ�
using namespace std;

//��ü + �迭�� �̿��� ���� ����
const int MAX_STACK_SIZE = 100;

class Stack {

	//��� ����
public:
	int MyStack[MAX_STACK_SIZE];
	int Top;		

	//������ �Լ�
	Stack() {
		Top = -1;
	}

	//��� �Լ�

	bool is_stack_full() {
		return(Top == MAX_STACK_SIZE - 1);
	}

	bool is_stack_empty() {
		return(Top == -1);
	}

	void push(int value) {
		if (is_stack_full()) {
			cout << "ERROR : Stack Overflow" << endl;
			exit(1);
		}
		else {
			MyStack[++Top] = value;			//Top�� ���� ������Ű�� ������ Top�� ���� �ε����� ����϶� ��(�̷� ������� ���ֽ� ���迡 ���� �� ���� ������)
		}
	}

	int pop() {
		if (is_stack_empty()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		
		return MyStack[Top--];				// MyStack[Top]�� �����ϰ� ������ ���� ���Ŀ� Top�� �ϳ� �ڷ� �ٿ���� ��(������, ���� ���̴ϱ�)
	}

	int peek() {
		if (is_stack_empty()) {
			cout << "ERROR : empty Stack" << endl;
		}
		else return(MyStack[Top]);
	}

	void print_stack() {
		cout << "STACK ���� ���" << endl;
		for (int i = Top; i >= 0; i--)
			cout << MyStack[i] << endl;
	}
};


void main() {
	Stack s;				// s ��ü ����, ���� ���� #include<stack> ����ϸ� �̰� stack<int>s;�� �����ؾߵ�.

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