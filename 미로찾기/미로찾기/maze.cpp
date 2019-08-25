//�̷� ã�� ����
#include <iostream>
using namespace std;

#define MAZE_SIZE 10
#define STACK_SIZE 100

//����ü�� (��, ��) ǥ��
typedef struct {
	int x, y;
}element;

class Stack {
public:
	element data[STACK_SIZE];
	int top;  //stack pointer

			  // ������ �Լ�
	Stack() {
		top = -1;
	}

	//������ ���� ������� �ƴ���
	bool is_empty() {
		return(top == -1);
	}

	//������ ���� �� á���� �ƴ��� (top�� ������ ���Ҹ� ����Ű���� �ƴ��� �Ǵ�����)
	bool is_full() {
		return(top == STACK_SIZE - 1);
	}

	void push(element value) {
		//������ �� �� ���
		if (is_full()) {
			cout << "Stack Overflow!!! ������ �̹� �� á���ϴ�" << endl;
			return;
		}
		else {
			data[++top] = value;
		}
	}

	element pop() {
		//������ ����ִ� ���
		if (is_empty()) {
			cout << "Stack Underflow!!! ������ ���� ������ϴ�." << endl;
			exit(-1);
		}
		else {
			return(data[top--]);
		}
	}

	element peek() {
		if (is_empty()) {
			cout << "Stack Underflow!!! ������ ���� ������ϴ�." << endl;
			exit(-1);
		}
		else {
			return(data[top]);
		}
	}
};

Stack stack;
element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '0', '0', '1', '0', '0', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '0', '0', '0', '0', '1' },
	{ '1', '0', '1', '1', '1', '0', '0', '1', '0', '1' },
	{ '1', '0', '0', '0', '1', '0', '0', '1', '0', '1' },
	{ '1', '0', '1', '0', '1', '0', '0', '1', '0', '1' },
	{ '1', '0', '1', '0', '1', '0', '0', '1', '0', '1' },
	{ '1', '0', '1', '0', '1', '0', '0', '1', '0', '1' },
	{ '1', '0', '1', '0', '0', '0', '0', '1', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' }
};

//��ġ�� ���ÿ� ����
void push_loc(int x, int y) {
	if (x < 0 || y < 0)  return;
	if (maze[x][y] != '1' && maze[x][y] != '.') {
		element tmp;
		tmp.x = x;
		tmp.y = y;
		stack.push(tmp);
	}
}


//ȭ�鿡 �̷� ���
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	cout << endl;
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int r = 0; r < MAZE_SIZE; r++) {
			cout << maze[i][r];
		}
		cout << endl;
	}
}

int main(void) {
	int x, y;
	here = entry;
	while (maze[here.x][here.y] != 'x') {
		x = here.x;
		y = here.y;
		maze[x][y] = '.'; //������ �ڸ����� .ǥ��

		maze_print(maze);

		push_loc(x - 1, y);
		push_loc(x + 1, y);
		push_loc(x, y - 1);
		push_loc(x, y + 1);

		if (stack.is_empty()) {
			cout << "����" << endl;
			return 0;
		}
		else
			here = stack.pop();
	}

	cout << "����" << endl;
	return 0;
}
