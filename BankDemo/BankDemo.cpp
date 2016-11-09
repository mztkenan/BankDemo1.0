// BankDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Date date(2008, 11, 1);
	SavingAccount accounts[] = { SavingAccount(date,"03755117",0.015),SavingAccount(date,"02342342",0.015) };
	CreditAccount ca(date, "c5392394", 10000, 0.0005, 50);

	const int n = sizeof(accounts) / sizeof(SavingAccount);

	accounts[0].deposit(Date(2008, 11, 5), 5000, "salary");
	ca.withdraw(Date(2008, 11, 15), 2000, "buy a cell");
	accounts[1].deposit(Date(2008, 11, 25), 10000, "sell stock 0323");

	ca.settle(Date(2008,12,1));

	ca.deposit(Date(2008, 12, 1),2016,"repay the credit");
	accounts[0].deposit(Date(2008, 12, 5), 5500, "salary");
	
	accounts[0].settle(Date(2009, 1, 1));
	accounts[1].settle(Date(2009, 1, 1));
	ca.settle(Date(2009, 1, 1));

	cout << endl;
	accounts[0].show();
	accounts[1].show();
	ca.show();

	cout << "Total:" << Account::getTotal() << endl;
	return 0;
}

