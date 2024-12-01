#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class QUANLY
{
	private:
		char maql[10];
		char hoten[20];
	public:
		void nhap();
		void xuat();
};
void QUANLY::nhap()
{
	cout<<"ma quan ly: ";				fflush(stdin);	gets(maql);
	cout<<"ho ten: ";					fflush(stdin);	gets(hoten);
}
void QUANLY::xuat()
{
	cout<<setw(15)<<"Ma quan ly: "<<setw(15)<<maql;
	cout<<setw(15)<<"Ho ten: "<<setw(15)<<hoten<<endl;
}
class MAY
{
	private:
		char mamay[10];
		char kieumay[10];
		char tinhtrang[50];
	public:
		void nhap();
		void xuat();
};
void MAY::nhap()
{
	cout<<"ma may:";					fflush(stdin);	gets(mamay);
	cout<<"kieu may: ";				fflush(stdin);	gets(kieumay);
	cout<<"Tinh trang: ";			fflush(stdin);	gets(tinhtrang);
}
void MAY::xuat()
{
	cout<<setw(15)<<mamay<<setw(15)<<kieumay<<setw(15)<<tinhtrang<<endl;
}
class PHONGMAY
{
	private:
		char maphong[10];
		char tenphong[20];
		float dientich;
		QUANLY x;
		MAY *y;
		int n;
	public:
		void nhap();
		void xuat();
};
void PHONGMAY::nhap()
{
	cout<<"Ma phong: ";					fflush(stdin);	gets(maphong);
	cout<<"ten phong: ";					fflush(stdin);	gets(tenphong);
	cout<<"dien tich: ";								cin>>dientich;
	x.nhap();
	cout<<"so may: ";									cin>>n;
	y=new MAY[n];
	for(int i=0; i<n; i++)
		y[i].nhap();
	
}
void PHONGMAY::xuat()
{
	cout<<setw(15)<<"Ma phong: "<<setw(15)<<maphong<<setw(15)<<"Ten phong: "<<setw(15)<<tenphong<<endl;
	cout<<setw(15)<<"Dien Tich: "<<setw(15)<<dientich<<endl;
	x.xuat();
	cout<<setw(15)<<"ma may"<<setw(15)<<"kieu may"<<setw(15)<<"tinh trang"<<endl;
	for(int i=0; i<n; i++)
		y[i].xuat();
}
int main()
{
	PHONGMAY a;
	a.nhap();
	a.xuat();
}



