#include <iostream>
#include "class1.h"

using namespace std;

Container::Container() { size = 10; }
void Container::fill()
{
	size = 10;
}

void Container::consume()
{
	if (size < 1)
		cout << "원료가 부족합니다." << endl;
	else
		size -= 1;
}

int Container::getSize()
{
	return size;
}