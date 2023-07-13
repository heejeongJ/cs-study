#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// ���Ḯ��Ʈ�� ��� ����
typedef struct Node {
public:
	struct Node* link;
	int coef;	// ���
	int expon;	// ����
}Node;

// ���Ḯ��Ʈ ���
typedef struct ListHeader {
	int length;
	Node* head;
	Node* tail;
}ListHeader;

// �ʱ�ȭ �Լ�
void init(ListHeader* plist)
{
	plist->length = 0;
	plist->head = plist->tail = NULL;
}


// ��� �������� ����
void insert_node(ListHeader* plist, int coef, int expon)			// ���⼭ plist�� ���Ḯ��Ʈ�� ����� ����Ű�� ������
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
}


// c = a + b
void addPoly(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3) {
	Node* a = plist1->head;
	Node* b = plist2->head;
	int sum;
	while (a != NULL && b != NULL) {
		if (a->expon == b->expon) {					// (a�� ���� > b�� ����)���,
			sum = a->coef + b->coef;
			if (sum != 0) insert_node(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {				// (a�� ���� == b�� ����)���
			insert_node(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {										// (b�� ���� > a�� ����)���,
			insert_node(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a�� b �߿� �ϳ��� ���� ������ �����ִ� �׵��� c ���׽����� ���� ������
	if (a != NULL)
		for (; a != NULL; a = a->link)
			insert_node(plist3, a->coef, a->expon);
	if (b != NULL)
		for (; b != NULL; b = b->link)
			insert_node(plist3, b->coef, b->expon);
}

// ���׽� ����ϴ� �Լ�
void poly_print(ListHeader* plist)
{
	Node* p = plist->head;
	for (; p; p = p->link) {
		printf("%3.0dx^%d", p->coef, p->expon);
		if (p != plist->tail) {
			cout << " +";
		}
	}
}


// ���Ḯ��Ʈ�� ���� ���׽� ���
int main() 
{
	ListHeader a, b, c;
	init(&a);					// ���Ḯ��Ʈ �ʱ�ȭ
	init(&b);
	init(&c);

	// ���׽� a ����
	insert_node(&a, 3, 12);
	insert_node(&a, 2, 8);
	insert_node(&a, 1, 0);

	// ���׽� b ����
	insert_node(&b, 8, 12);
	insert_node(&b, -3, 10);
	insert_node(&b, 10, 6);

	// ���׽� c ����
	addPoly(&a, &b, &c);
	poly_print(&c);
	
}