#include <iostream>
using namespace std;

//�迭�� �̿��� ���� ����
const int MAX_STACK_SIZE = 100;

int MyStack[MAX_STACK_SIZE];
int Top = -1;					//�ʱⰪ -1��,����������� �� ǥ���ϱ� ���� �빮�ڷ� ���� �ž�(��Ģ�� �ƴѵ� ���� �빮�ڸ� ���� �ҹ��ڸ� �����̶�� ������)


bool is_stack_full() {
	/*�Ʒ� ������ ���ٷ� ����,(�ʺ�����)
	if (Top == MAX_STACK_SIZE - 1)return true;
	else return false;
	*/
	return(Top == MAX_STACK_SIZE - 1);
}

bool is_stack_empty() {
	/*�Ʒ� ������ ���ٷ� ����,(�ʺ�����)
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
		/*�Ʒ� ������ ���ٷ� ����,(�ʺ�����)
		Top++;
		MyStack[Top] = value;
		*/
		MyStack[++Top] = value;			//Top�� ���� ������Ű�� ������ Top�� ���� �ε����� ����϶� ��(�̷� ������� ���ֽ� ���迡 ���� �� ���� ������)
	}
}

int pop() {
	if (is_stack_empty()) {
		cout << "ERROR : Stack Underflow" << endl;
		exit(1);
	}
	/*�Ʒ� ������ �� �ٷ� ����,(�ʺ�����)
	int x = MyStack[Top];				// ���� ���� �ִ� ���� x�� �����ϰ�
	Top--;								// Top�� �ϳ� ���ҽ�����
	return x;
	*/
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