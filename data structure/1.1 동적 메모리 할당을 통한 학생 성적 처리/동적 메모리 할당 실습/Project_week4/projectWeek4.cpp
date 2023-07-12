#include<iostream>
using namespace std;

void main() {

	int num;

	cout << "학생수는 ";
	cin >> num;

	int* score = new int[num];							//동적 메모리 할당을 위한 new연산자 사용

	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		cout << i << "번째 학생의 성적은 ";
		cin >> score[i];
		sum += score[i];
	}

	cout << "평균은 " << (double)sum / num << " 입니다." << endl;
}