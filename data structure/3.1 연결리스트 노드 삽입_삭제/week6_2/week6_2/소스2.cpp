#include <iostream>
using namespace std;

// 가장 높은 항이 맨 앞에 나오게, 같은 지수가 아닌건 그대로 나열, 새로운 항을 만들어서 c에 추가해주셈(항의 지수를 비교해가면서 크면 앞으로 작으면 뒤로 보내는 과정 넣어줘)
//연결리스트가 두개니까 두개를 동시에 비교시켜주고, 첫번째 노드 비교, 두번째 노드 비교 이런식으로 해주면돼, 항을 하나씩 비교한다고 생각해
//연결리스트 3개야(a,b,c). 헤드라는 표현보단? 전역변수 a,b,c 사용하면 돼 팁임
class Node {
public:
	int data;
	Node* link;
};

Node* Head = NULL;

void main()