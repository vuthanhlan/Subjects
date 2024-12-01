#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class DATE
{
	private:
		int dd, mm, yy;
	public:
		void nhap();
		void xuat();
};
void DATE::nhap()
{
	cout<<"Nhap ngay: "<<dd;              cin>>dd;
	cout<<"Nhap thang: "<<mm;             cin>>mm;
	cout<<"Nhap nam: "<<yy;               cin>>yy;
}
void DATE::xuat()
{
	cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
}
class NHANSU
{
	private:
		char mans[20];
		char hoten[30];
		DATE ns;
	public:
		void nhap();
		void xuat();
};
void NHANSU::nhap()
{
	cout<<"ma nhan su: ";          fflush(stdin);     gets(mans);
	cout<<"ho ten: ";              fflush(stdin);     gets(hoten);
	ns.nhap();
}
void NHANSU::xuat()
{
	cout<<"ma nhan su: "<<mans<<endl;
	cout<<"ho ten: "<<hoten<<endl;
	ns.xuat();
}
int main()
{
	NHANSU x;
	x.nhap();
	x.xuat();
}



