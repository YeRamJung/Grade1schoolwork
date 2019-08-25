#include <iostream>
#include "class2.h"

using namespace std;


void CoffeeVendingMachine::fill()
{
	for (int i = 0; i < 3; i++)
		tong[i].fill();
}

void CoffeeVendingMachine::selectEspresso()
{
	tong[0].consume();
	tong[1].consume();
}

void CoffeeVendingMachine::selectAmericano()
{
	tong[0].consume();
	for (int i = 0; i < 2; i++)
		tong[1].consume();
}

void CoffeeVendingMachine::selectSugarCoffee()
{
	tong[0].consume();
	for (int i = 0; i < 2; i++)
		tong[1].consume();
	tong[2].consume();
}

void CoffeeVendingMachine::show()
{
	cout << "커피 : " << tong[0].getSize() << " 물 : " << tong[1].getSize() << " 설탕 : " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	cout << "**** 커피 자판기를 작동합니다. *****" << endl;
	while (1)
	{
		int selectNum = 0;
		cout << "메뉴를 눌러주세요 (1 : 에스프레스, 2 : 아메리카노, 3 : 설탕커피, 4 : 잔량보기, 5 : 채우기, 6 : 끝내기) ";
		cin >> selectNum;

		if (selectNum == 1)
			selectEspresso();

		else if (selectNum == 2)
			selectAmericano();

		else if (selectNum == 3)
			selectSugarCoffee();

		else if (selectNum == 4)
			show();

		else if (selectNum == 5)
			fill();

		else if (selectNum == 6)
			break;

		else
			cout << "숫자를 잘 못 입력하셨습니다. 다시 골라주세요.";
	}
}