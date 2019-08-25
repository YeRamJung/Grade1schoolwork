#include <iostream>
using namespace std;

class Node {
public:
	int coef;  //���
	int expon;  //�¼�
	Node *link;
};

//���ο� ��带 �Ҵ�޾Ƽ� �ʱ�ȭ��Ű�� ���� �޴� ��
Node *MakeANode(int coef, int expon) {
	Node *ptr;
	ptr = new Node;
	ptr->coef = coef;
	ptr->expon = expon;
	ptr->link = NULL;
	return ptr;
}

//��带 ���ʿ� ���ִ� �� 
Node * insertNodeAtRear(Node *new_node, Node *head) {
	if (head == NULL)   return new_node;  //���鸮��Ʈ�� ���
	else {
		//������ ��带 ã�Ƽ� �ڿ� new_node�� �����϶�
		Node*list = head;
		while (list->link != NULL)
			list = list->link;
		list->link = new_node;
		return new_node;
	}
}

//���׽� ����
Node *AddPoly(Node *p, Node *q, Node *r) {

	Node *C = NULL;
	int sum = 0; //���尪 ����
	Node *head_C = NULL;

	while (p&&q) {
		//���׽� A���� = ���׽� B������ ���
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
		//���׽� B������ ���׽�A�������� ū ���
		else if (p->expon < q->expon) {
			C = MakeANode(q->coef, q->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			q = q->link;
		}
		//���׽� A������ ���׽�B�������� ū ���
		else if (p->expon > q->expon) {
			C = MakeANode(p->coef, p->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			p = p->link;
		}
	}
	//B�� ������ ������ ������ ��, ���� �׵��� ���� C�� �־��ش�
	if (q == NULL) {
		while (p) {
			C = MakeANode(p->coef, p->expon);
			r = insertNodeAtRear(C, r);
			if (head_C == NULL) head_C = r;
			p = p->link;
		}
	}
	//A�� ������ ������ ������ ��, ���� �׵��� ���� C�� �־��ش�
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

//������ִ� �Լ�
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