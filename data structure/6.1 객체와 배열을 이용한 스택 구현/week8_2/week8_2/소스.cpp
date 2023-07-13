//c++처럼 클래스 이용해서 구현해봄(객체지향 프로그래밍), 이걸 추천하셨어 c 스타일보다 c++스타일이 깔끔하고 좋아
//week8_1에 작성한 코드는 C스타일이야
#include <iostream>
//#include <stack> 사용하면 stack을 막 선언하고 설정하지 않아도 stack 사용할 수 있게 돼. 쓰면 밑에 stack<int> s;로 변경해야돼
using namespace std;

//객체 + 배열을 이용한 스택 구현
const int MAX_STACK_SIZE = 100;

class Stack {

	//멤버 변수
public:
	int MyStack[MAX_STACK_SIZE];
	int Top;		

	//생성자 함수
	Stack() {
		Top = -1;
	}

	//멤버 함수

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
			MyStack[++Top] = value;			//Top을 먼저 증가시키고 증가된 Top의 값을 인덱스로 사용하란 뜻(이런 방식으로 자주써 시험에 나올 거 같음 숙지해)
		}
	}

	int pop() {
		if (is_stack_empty()) {
			cout << "ERROR : Stack Underflow" << endl;
			exit(1);
		}
		
		return MyStack[Top--];				// MyStack[Top]을 리턴하고 리턴이 끝난 직후에 Top을 하나 뒤로 줄여라란 뜻(숙지해, 많이 쓰이니까)
	}

	int peek() {
		if (is_stack_empty()) {
			cout << "ERROR : empty Stack" << endl;
		}
		else return(MyStack[Top]);
	}

	void print_stack() {
		cout << "STACK 상태 출력" << endl;
		for (int i = Top; i >= 0; i--)
			cout << MyStack[i] << endl;
	}
};


void main() {
	Stack s;				// s 객체 선언, 만약 위에 #include<stack> 사용하면 이건 stack<int>s;로 변경해야돼.

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