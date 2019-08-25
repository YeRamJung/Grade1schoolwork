//미로 찾기 문제
#include <iostream>
using namespace std;

#define MAZE_SIZE 10
#define STACK_SIZE 100

//구조체로 (행, 열) 표현
typedef struct {
	int x, y;
}element;

class Stack {
public:
	element data[STACK_SIZE];
	int top;  //stack pointer

			  // 생성자 함수
	Stack() {
		top = -1;
	}

	//스택이 현재 비었는지 아닌지
	bool is_empty() {
		return(top == -1);
	}

	//스택이 현재 꽉 찼는지 아닌지 (top이 마지막 원소를 가리키는지 아닌지 판단하자)
	bool is_full() {
		return(top == STACK_SIZE - 1);
	}

	void push(element value) {
		//스택이 꽉 찬 경우
		if (is_full()) {
			cout << "Stack Overflow!!! 스택이 이미 꽉 찼습니다" << endl;
			return;
		}
		else {
			data[++top] = value;
		}
	}

	element pop() {
		//스택이 비어있는 경우
		if (is_empty()) {
			cout << "Stack Underflow!!! 스택이 현재 비었습니다." << endl;
			exit(-1);
		}
		else {
			return(data[top--]);
		}
	}

	element peek() {
		if (is_empty()) {
			cout << "Stack Underflow!!! 스택이 현재 비었습니다." << endl;
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

//위치를 스택에 삽입
void push_loc(int x, int y) {
	if (x < 0 || y < 0)  return;
	if (maze[x][y] != '1' && maze[x][y] != '.') {
		element tmp;
		tmp.x = x;
		tmp.y = y;
		stack.push(tmp);
	}
}


//화면에 미로 출력
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
		maze[x][y] = '.'; //지나간 자리에는 .표시

		maze_print(maze);

		push_loc(x - 1, y);
		push_loc(x + 1, y);
		push_loc(x, y - 1);
		push_loc(x, y + 1);

		if (stack.is_empty()) {
			cout << "실패" << endl;
			return 0;
		}
		else
			here = stack.pop();
	}

	cout << "성공" << endl;
	return 0;
}
