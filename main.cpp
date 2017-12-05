#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include "console.h"
#include "FileUtility.h"
#include "BankAccount.h"
#include "UserTransaction.h"
using namespace std;



int main()
{
	UserTransaction usertransaction;
	BankAccount bankaccount;
	FileUtility fileutility;
	string id;
	int chon;
	fileutility.dangNhap(id);
	s1:
	TextColor(10);
	cout<<"Chon thao tac muon thuc hien\n";
	TextColor(7);
	cout<<"1.Rut Tien\n2.Chuyen Tien\n3.Doi Ma Pin\n4.Xem noi dung giao dich";
	cout<<"\nChon: ";cin>>chon;
	switch(chon)
	{
		case 1:
		{
			usertransaction.Withdraw(id);
			goto s1;
			break;			
		}
		case 2:
		{
			usertransaction.Transfer(id);
			goto s1;
			break;
		}
		case 3:
		{
			bankaccount.ChangePin(id);
			goto s1;
			break;
		}
		case 4:
		{
			usertransaction.History(id);
			goto s1;
			break;
		}
		default:
		{
			return 0;
		}
	}
	cout<<endl<<endl;
	TextColor(15);
	system("pause");
	return 0;
}