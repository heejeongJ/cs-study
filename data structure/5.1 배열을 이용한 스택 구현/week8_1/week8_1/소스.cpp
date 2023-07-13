#include <iostream>
using namespace std;

//배열을 이용한 스택 구현
const int MAX_STACK_SIZE = 100;

int MyStack[MAX_STACK_SIZE];
int Top = -1;					//초기값 -1줌,전역변수라는 걸 표기하기 위해 대문자로 쓰는 거야(원칙은 아닌데 보통 대문자면 전역 소문자면 지역이라고 생각함)


bool is_stack_full() {
	/*아래 한줄을 두줄로 쓰면,(초보수준)
	if (Top == MAX_STACK_SIZE - 1)return true;
	else return false;
	*/
	return(Top == MAX_STACK_SIZE - 1);
}

bool is_stack_empty() {
	/*아래 한줄을 두줄로 쓰면,(초보수준)
	if (Top == -1)return true;
	else return false;
	*/
	return(Top == -1);
}

void push(int value) {
	if (is_stack_full()) {
		cout << "ERROR : Stack Overflow" << endl;
		exit(1);
	}
	else {
		/*아래 한줄을 두줄로 쓰면,(초보수준)
		Top++;
		MyStack[Top] = value;
		*/
		MyStack[++Top] = value;			//Top을 먼저 증가시키고 증가된 Top의 값을 인덱스로 사용하란 뜻(이런 방식으로 자주써 시험에 나올 거 같음 숙지해)
	}
}

int pop() {
	if (is_stack_empty()) {
		cout << "ERROR : Stack Underflow" << endl;
		exit(1);
	}
	/*아래 한줄을 세 줄로 쓰면,(초보수준)
	int x = MyStack[Top];				// 가장 위에 있는 값을 x로 지정하고
	Top--;								// Top을 하나 감소시켜줘
	return x;
	*/
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