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
	cout << "Ŀ�� : " << tong[0].getSize() << " �� : " << tong[1].getSize() << " ���� : " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	cout << "**** Ŀ�� ���Ǳ⸦ �۵��մϴ�. *****" << endl;
	while (1)
	{
		int selectNum = 0;
		cout << "�޴��� �����ּ��� (1 : ����������, 2 : �Ƹ޸�ī��, 3 : ����Ŀ��, 4 : �ܷ�����, 5 : ä���, 6 : ������) ";
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
			cout << "���ڸ� �� �� �Է��ϼ̽��ϴ�. �ٽ� ����ּ���.";
	}
}