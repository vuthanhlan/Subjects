#include<iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;

class NSX
{
	private:
		char mansx[20];
		char tennsx[30];
		char dcnsx[30];
	public:
		void nhap();
		void xuat();
};
void NSX::nhap()
{
	cout<<"ma nha san xuat: ";               fflush(stdin);   gets(mansx);
	cout<<"ten nha san xuat: ";              fflush(stdin);   gets(tennsx);
	cout<<"dia chi nha san xuat: ";          fflush(stdin);   gets(dcnsx);
}
void NSX::xuat()
{
	cout<<setw(10)<<mansx<<setw(10)<<tennsx<<setw(10)<<dcnsx;
}
class HANG
{
	private:
		char mahang[20];
		char tenhang[20];
		NSX x;
	public:
		void nhap();
		void xuat();
};
void HANG::nhap()
{
	cout<<"ma hang: ";                 fflush(stdin);   gets(mahang);
	cout<<"ten hang: ";                fflush(stdin);   gets(tenhang);
	x.nhap();
}
void HANG::xuat()
{
	cout<<setw(10)<<mahang<<setw(10)<<tenhang<<setw(10);
	x.xuat();
}
int main()
{
	HANG a;
	a.nhap();
	a.xuat();
}



