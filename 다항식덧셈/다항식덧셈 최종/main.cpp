#include <iostream>
using namespace std;

class Node {
public:
	int coef;  //계수
	int expon;  //승수
	Node *link;
};

//새로운 노드를 할당받아서 초기화시키고 값을 받는 것
Node *MakeANode(int coef, int expon) {
	Node *ptr;
	ptr = new Node;
	ptr->coef = coef;
	ptr->expon = expon;
	ptr->link = NULL;
	return ptr;
}

//노드를 뒤쪽에 껴넣는 것 
Node * insertNodeAtRear(Node *new_node, Node *head) {
	if (head == NULL)   return new_node;  //공백리스트인 경우
	else {
		//마지막 노드를 찾아서 뒤에 new_node를 연결하라
		Node*list = head;
		while (list->link != NULL)
			list = list->link;
		list->link = new_node;
		return new_node;
	}
}

//다항식 덧셈
Node *AddPoly(Node *p, Node *q, Node *r) {

	Node *C = NULL;
	int sum = 0; //저장값 변수
	Node *head_C = NULL;

	while (p&&q) {
		//다항식 A지수 = 다항식 B지수인 경우
		if (p->expon == q->expon) {
			if (p->expon + q->expon != 0) {
				sum = p->coef + q->coef;
				C = MakeANode(sum, p->expon);
				r = insertNodeAtRear(C, r);
				if (head_C == NULL) head_C = r;
				p = p->link;
				q = q->link;
			}
		}
		//다항식 B지수가 다항식A지수보다 큰 경우
		else if (p->expon < q->expon) {
			C = MakeANode(q->coef, q->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			q = q->link;
		}
		//다항식 A지수가 다항식B지수보다 큰 경우
		else if (p->expon > q->expon) {
			C = MakeANode(p->coef, p->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			p = p->link;
		}
	}
	//B가 마지막 노드까지 돌았을 때, 남은 항들을 전부 C에 넣어준다
	if (q == NULL) {
		while (p) {
			C = MakeANode(p->coef, p->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			p = p->link;
		}
	}
	//A가 마지막 노드까지 돌았을 때, 남은 항들을 전부 C에 넣어준다
	if (p == NULL) {
		while (q) {
			C = MakeANode(q->coef, q->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			q = q->link;
		}
	}
	return head_C;
}

//출력해주는 함수
void printPoly(Node *node) {
	for (; node != NULL; node = node->link) {
		if(node->link==NULL)
			cout << node->coef << "x^" << node->expon;
		else{ 
			cout << node->coef << "x^" << node->expon;
			if (node->link->coef > 0)
				cout << "+";
		}
		/*
		cout << node->coef << "x^" << node->expon;
		if (node->link->coef > 0 && node->link != NULL)
			cout << "+";
	    */
	}
	cout << endl;
}


void main() {
	Node *p = NULL, *q = NULL, *r = NULL;
	Node *A = NULL, *B = NULL, *C = NULL;

	A = MakeANode(3, 12);
	insertNodeAtRear(A, p);
	p = A;
	A = MakeANode(2, 8);
	insertNodeAtRear(A, p);
	A = MakeANode(1, 0);
	insertNodeAtRear(A, p);
	cout << "A: ";
	printPoly(p);


	B = MakeANode(8, 12);
	insertNodeAtRear(B, q);
	q = B;
	B = MakeANode(-3, 10);
	insertNodeAtRear(B, q);
	B = MakeANode(10, 6);
	insertNodeAtRear(B, q);
	cout << "B: ";
	printPoly(q);

	Node *getR = NULL;
	cout << "C: ";
	getR = AddPoly(p, q, r);
	printPoly(getR);
}