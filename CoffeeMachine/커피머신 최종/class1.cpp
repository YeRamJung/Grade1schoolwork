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
		cout << "���ᰡ �����մϴ�." << endl;
	else
		size -= 1;
}

int Container::getSize()
{
	return size;
}