#include<iostream>
using namespace std;

void main() {

	int num;

	cout << "�л����� ";
	cin >> num;

	int* score = new int[num];							//���� �޸� �Ҵ��� ���� new������ ���

	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		cout << i << "��° �л��� ������ ";
		cin >> score[i];
		sum += score[i];
	}

	cout << "����� " << (double)sum / num << " �Դϴ�." << endl;
}