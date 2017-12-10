#include "FileUtility.h"
#include"console.h"
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

void FileUtility::dangNhap(string &id)
{
	char c,pin[7];
	bool test = false;
	int i = 0,n = 0,t1,d = 1;
	string arr[20],user;
	TextColor(14);
	cout<<"\t************************\n";
	cout<<"\t*  ";TextColor(10);
	cout<<"Dang Nhap He Thong";TextColor(14);
	cout<<"  *";
	cout<<"\n\t************************\n";
	ifstream fileinput("The.dat");
	if(fileinput.fail())
	{
		cout<<"failed to open file!";
	}
	while(!fileinput.eof())
	{
		char temp[255];
		fileinput>>temp;
		arr[i] = temp;
		i++;
		n++;
	}
	fileinput.close();
	s1:TextColor(2);
	cout<<"user:";TextColor(15);
	getline(cin,user);
	for(int i = 1;i < n;i+=3)
	{
		if (arr[i] == user)
		{
			t1 = i;
			test = true;
			break;
		}

	}
	if(test == false)
	{
		TextColor(12);
		cout<<"Tai Khoan Khong Ton Tai.<Enter> de nhap lai - <Esc> de thoat!\n";
		int x;
		x = getch();
		if(x == 27)
		{
			cout<<"\n\tThoat chuong trinh!";
			getch();
			exit(0);
		}
		goto s1;
	}
	s2:i = 0;TextColor(2);
	cout<<"PIN:";TextColor(15);
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
	if(arr[t1+1] == pin)
	{
		id = arr[t1-1];
		system("cls");
		TextColor(14);
		cout<<"\t************************\n";
		cout<<"\t* ";TextColor(10);
		cout<<"DANG NHAP THANH CONG";TextColor(14);
		cout<<" *";
		cout<<"\n\t************************\n";
	}
	else
	{
		if(d<3)
		{
			TextColor(12);
			cout<<"\nPIN khong chinh xac.<Enter> de nhap lai - <Esc> de thoat!!\n";
			int y;
			y = getch();
			if(y == 27)
			{
				cout<<"\n\tThoat chuong trinh!";
				getch();
				exit(0);
			}
			d++;
			goto s2;
		}
		else
		{
			TextColor(12);
			cout<<"\nNhap sai 3 lan.Thoat chuong trinh!\n";
			TextColor(15);
			system("pause");
			exit(0);
		}
	}
}

FileUtility::FileUtility(void)
{
}


FileUtility::~FileUtility(void)
{
}
