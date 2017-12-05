#include "BankAccount.h"
#include"console.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
void esc();

void BankAccount::ChangePin(string id)
{
	char c = 0,pin[7],npin[7],cpin[7];
	int i = 0,n = 0,t,m;
	string arr[20];
	system("cls");
	TextColor(14);
	cout<<"\t************************\n";
	cout<<"\t*  ";TextColor(10);
	cout<<"    Doi Ma Pin    ";TextColor(14);
	cout<<"  *";
	cout<<"\n\t************************\n";
	ifstream file("The.dat");
	while(!file.eof())
	{
		file>>arr[i];
		i++;
		n++;
	}
	file.close();
	for(i = 0;i < n;i++)
	{
		if(arr[i] == id)
		{
			t = i+2;
		}
	}
	s1:TextColor(7);i = 0;
	cout<<"\nNhap Pin Hien Tai: ";TextColor(15);
	while(1) {
        c = getch();
        if (c == 13) {
            break;
        } else {
            pin[i++] = c;
            cout << "*" ;
        }
    }
    pin[i] = '\0';
	if(pin == arr[t])
	{
		s2:TextColor(7);c = 0;i = 0;cout<<"\nNhap Pin Moi: ";TextColor(15);
		while(1) {
        c = getch();
        if (c == 13) {
            break;
        } else {
            npin[i++] = c;
            cout << "*" ;
        }
		}
		npin[i] = '\0';string pin1 = npin;
		c = 0;i = 0;TextColor(7);
		cout<<"\nXac Nhan Pin: ";TextColor(15);
		while(1) {
        c = getch();
        if (c == 13) {
            break;
        } else {
            cpin[i++] = c;
            cout << "*" ;
        }
		}
		cpin[i] = '\0';
		if(pin1 == cpin)
		{
			arr[t] = npin;
			ofstream file("The.dat");
			for(i = 0;i < n;i++)
			{
				file<<arr[i]<<endl;
			}
			file.close();TextColor(11);
			cout<<"\n\tDoi Pin Thanh Cong!";
			TextColor(10);
			cout<<"\nNhan    <Enter> de quay lai Menu\n\t<Esc>   de thoat chuong trinh!";
			m = getch();
			if(m == 27)
			{
				TextColor(12);
				cout<<"\n\tThoat chuong trinh!";
				getch();
				exit(0);
			}
			system("cls");
		}
		else
		{
			TextColor(12);
			cout<<"\nPin Moi Va Pin xac nhan khong trung khop.<Enter> de nhap lai - <Esc> de thoat!";
			esc();
			goto s2;
		}
	}
	else
	{
		TextColor(12);
		cout<<"\nMa Pin khong dung.<Enter> de nhap lai - <Esc> de thoat!";
		esc();
		goto s1;
	}


}


void esc()
{
	int c;
	c = getch();
	if(c == 27)
	{
		cout<<"\n\tThoat chuong trinh!";
		getch();
		exit(0);
	}
}

BankAccount::BankAccount(void)
{
}


BankAccount::~BankAccount(void)
{
}
