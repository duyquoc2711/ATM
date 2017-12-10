#include "UserTransaction.h"
#include "console.h"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<cstring>
#include<conio.h>
#include<stdio.h>
#include<ctime>
using namespace std;
string InttoString(int n);
void Esc();
string getdate();

void UserTransaction::History(string id)
{
	system("cls");
	string str;
	TextColor(14);
	cout<<"\t************************\n";
	cout<<"\t*  ";TextColor(10);
	cout<<"NOI DUNG GIAO DICH";TextColor(14);
	cout<<"  *";
	cout<<"\n\t************************\n\n";
	ifstream file("GiaoDich/"+id+".dat");
	while(!file.eof())
	{
		char c[255];
		file.getline(c,255);
		if(c[18] == 'R'||c[19] == 'R'||c[17] == 'R'||c[16] == 'R')
		{
			TextColor(12);
			cout<<c<<endl;
		}
		else if(c[18] == 'C'||c[19] == 'C'||c[17] == 'C'||c[16] == 'C')
		{
			TextColor(11);
			cout<<c<<endl;
		}
		else if(c[18] == 'N'||c[19] == 'N'||c[17] == 'N'||c[16] == 'N')
		{
			TextColor(13);
			cout<<c<<endl;
		}
	}
	file.close();
	TextColor(10);
	cout<<"\nNhan    <Enter> de quay lai Menu\n\t<Esc>   de thoat chuong trinh!";
	Esc();
	system("cls");
}

void UserTransaction::Transfer(string id)
{
	fflush(stdin);
	bool test = false;
	system("cls");
	string arr[20],arrt[20],arrr[20],rid,arrh1[50],arrh2[50];
	int i = 0,n = 0,tranf,m;
	TextColor(14);
	cout<<"\t************************\n";
	cout<<"\t*  ";TextColor(10);
	cout<<"   CHUYEN TIEN    ";TextColor(14);
	cout<<"  *";
	cout<<"\n\t************************\n";
	ifstream file("The.dat");
	if(file.fail())
	{
		cout<<"failed to open file!";
	}
	while(!file.eof())
	{
		getline(file,arr[i]);
		i++;
		n++;
	}
	file.close();
	s1:TextColor(2);cout<<"\nNhap so tai khoan muon chuyen: ";
	TextColor(15);getline(cin,rid);
	for(i = 0;i < n;i++)
	{
		if(rid == arr[i])
		{
			test = true;
		}
	}
	if(test == false)
	{
		TextColor(12);
		cout<<"Tai khoan chuyen den khong ton tai.<Enter> de nhap lai - <Esc> de thoat!";
		Esc();
		goto s1;
	}
	else
	{
		i = 0;
		ifstream filet("TaiKhoan/"+id+".dat");
		if(filet.fail())
		{
			cout<<"failed to open file!";
		}
		while(!filet.eof())
		{
			char temp[255];
			filet.getline(temp,255);
			arrt[i] = temp;
			i++;
		}
		filet.close();
		i = 0;
		ifstream filer("TaiKhoan/"+rid+".dat");
		if(filer.fail())
		{
			cout<<"failed to open file!";
		}
		while(!filer.eof())
		{
			char temp[255];
			filer.getline(temp,255);
			arrr[i] = temp;
			i++;
		}
		filer.close();
		s2:TextColor(2);
		cout<<"\nNhap so tien can chuyen: ";TextColor(15);cin>>tranf;
		if(tranf > (stoi(arrt[1]) + 50000))
		{
			TextColor(12);
			cout<<"So tien vuot qua so du.<Enter> de nhap lai - <Esc> de thoat!";
			Esc();
			goto s2;
		}
		else
		{
			arrt[1] = InttoString(stoi(arrt[1]) - tranf);
			ofstream filet("TaiKhoan/"+id+".dat");
			for(i = 0;i <= 2;i++)
			{
				filet<<arrt[i]<<endl;
			}
			filet.close();
			arrr[1] = InttoString(stoi(arrr[1]) + tranf);
			ofstream filer("TaiKhoan/"+rid+".dat");
			for(i = 0;i <= 2;i++)
			{
				filer<<arrr[i]<<endl;
			}
			filer.close();
			i = 0; n = 0;
			ifstream file3("GiaoDich/"+id+".dat");
			if(file3.fail())
			{
				cout<<"!!!";
			}
			while(!file3.eof())
			{
				char temp[255];
				file3.getline(temp,255);
				arrh1[i] = temp;
				i++;
				n++;
			}
			file3.close();
			arrh1[i] = getdate() + "-Chuyen " + InttoString(tranf) + "VND"+" Den TK " + rid+".";
			ofstream file4("GiaoDich/"+id+".dat");
			for(i = 0;i <= n;i++)
			{
				file4<<arrh1[i]<<endl;
			}
			file4.close();
			i = 0; n = 0;
			ifstream file5("GiaoDich/"+rid+".dat");
			if(file5.fail())
			{
				cout<<"!!!";
			}
			while(!file5.eof())
			{
				char temp[255];
				file5.getline(temp,255);
				arrh2[i] = temp;
				i++;
				n++;
			}
			file5.close();
			arrh2[i] = getdate() + "-Nhan   " + InttoString(tranf) + "VND tu TK " + id+".";
			ofstream file6("GiaoDich/"+rid+".dat");
			for(i = 0;i <= n;i++)
			{
				file6<<arrh2[i]<<endl;
			}
			file6.close();
			TextColor(11);
			cout<<"\n\tGiao Dich Thanh Cong!\n";
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
	}
}

void UserTransaction::Withdraw(string id)
{
	system("cls");
	fflush(stdin);
	int width,balance,m,i = 0,n = 0;
	string arr[20],arrh[50];
	TextColor(14);
	cout<<"\t************************\n";
	cout<<"\t*  ";TextColor(10);
	cout<<"     RUT TIEN     ";TextColor(14);
	cout<<"  *";
	cout<<"\n\t************************\n";
	ifstream file("TaiKhoan/"+id+".dat");
	if(file.fail())
	{
		cout<<"!!!";
	}
	for(i = 0;i <= 2;i++)
	{
		char temp[255];
		file.getline(temp,255);
		arr[i] = temp;
	}
	file.close();
	balance = stoi(arr[1]);
	s1:TextColor(2);cout<<"\nNhap so tien can rut(VND): ";TextColor(15);cin>>width;
	if(width > (balance - 50000))
	{
		TextColor(12);
		cout<<"So tien vuot qua so du.<Enter> de nhap lai - <Esc> de thoat!";
		Esc();
		goto s1;
	}
	else if(width < 50000)
	{
		TextColor(12);
		cout<<"So tien rut phai tren 50000.<Enter> de nhap lai - <Esc> de thoat!";
		Esc();
		goto s1;
	}
	else
	{
		arr[1] = InttoString(balance - width);
		ofstream file("TaiKhoan/"+id+".dat");
		for(int i = 0;i <= 2;i++)
		{
		file<<arr[i]<<endl;
		}
		file.close();
		i = 0; n = 0;
		ifstream file1("GiaoDich/"+id+".dat");
		if(file1.fail())
		{
			cout<<"!!!";
		}
		while(!file1.eof())
		{
			char temp[255];
			file1.getline(temp,255);
			arrh[i] = temp;
			i++;
			n++;
		}
		file1.close();
		arrh[i] = getdate() + "-Rut    " + InttoString(width) + "VND.";
		ofstream file2("GiaoDich/"+id+".dat");i = 0; 
		while(i<=n) {
			file2<<arrh[i++]<<endl;
		}
		file2.close();
		TextColor(11);
		cout<<"\n\tGiao dich thanh cong!\n";
		TextColor(10);
		cout<<"\nNhan    <Enter> de quay lai Menu\n\t<Esc> de thoat chuong trinh!";
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
}

string InttoString(int n)
{
	stringstream convert;
	convert << n;
	return convert.str();
}

void Esc()
{
	int c;
	c = getch();
	if(c == 27)
	{
		TextColor(12);
		cout<<"\n\tThoat chuong trinh!";
		getch();
		exit(0);
	}
}

string getdate()
{
	string date;
    time_t now;
    struct tm nowlocal;
    now = time(NULL);
    nowlocal = *localtime(&now);
    date = InttoString(nowlocal.tm_mday) + "/" + InttoString(1 + nowlocal.tm_mon) + "/";
    date += InttoString(1900 + nowlocal.tm_year) + " " + InttoString(nowlocal.tm_hour);
    date += ":" + InttoString(nowlocal.tm_min) + ":" + InttoString(nowlocal.tm_sec);
    return date;
}

UserTransaction::UserTransaction(void)
{
}


UserTransaction::~UserTransaction(void)
{
}
