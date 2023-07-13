#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// 연결리스트의 노드 구조
typedef struct Node {
public:
	struct Node* link;
	int coef;	// 계수
	int expon;	// 지수
}Node;

// 연결리스트 헤더
typedef struct ListHeader {
	int length;
	Node* head;
	Node* tail;
}ListHeader;

// 초기화 함수
void init(ListHeader* plist)
{
	plist->length = 0;
	plist->head = plist->tail = NULL;
}


// 노드 마지막에 삽입
void insert_node(ListHeader* plist, int coef, int expon)			// 여기서 plist는 연결리스트의 헤더를 가리키는 포인터
{
	Node* temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
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
		if (a->expon == b->expon) {					// (a의 차수 > b의 차수)라면,
			sum = a->coef + b->coef;
			if (sum != 0) insert_node(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {				// (a의 차수 == b의 차수)라면
			insert_node(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {										// (b의 차수 > a의 차수)라면,
			insert_node(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a와 b 중에 하나가 먼저 끝나면 남아있는 항들은 c 다항식으로 전부 가져옴
	if (a != NULL)
		for (; a != NULL; a = a->link)
			insert_node(plist3, a->coef, a->expon);
	if (b != NULL)
		for (; b != NULL; b = b->link)
			insert_node(plist3, b->coef, b->expon);
}

// 다항식 출력하는 함수
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


// 연결리스트를 통한 다항식 계산
int main() 
{
	ListHeader a, b, c;
	init(&a);					// 연결리스트 초기화
	init(&b);
	init(&c);

	// 다항식 a 생성
	insert_node(&a, 3, 12);
	insert_node(&a, 2, 8);
	insert_node(&a, 1, 0);

	// 다항식 b 생성
	insert_node(&b, 8, 12);
	insert_node(&b, -3, 10);
	insert_node(&b, 10, 6);

	// 다항식 c 생성
	addPoly(&a, &b, &c);
	poly_print(&c);
	
}