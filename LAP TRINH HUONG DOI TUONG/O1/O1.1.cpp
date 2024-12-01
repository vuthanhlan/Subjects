#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
class NCC
{
	private:
		char MaNCC[10];
		char TenNCC[20];
		char Diachi[30];
	public:
		void nhap();
		void xuat();
};
class Hang
{
	private:
		char Tenhang[20];
		float Dongia;
		int SL;
	public:
		void nhap();
		void xuat();
		friend class Phieu;
};
class Phieu
{
	private:
		char Maphieu[10];
		char ngay[12];
		NCC x;
		Hang ds[20];
		int n;
	public:
		void nhap();
		void xuat();
};
void NCC::nhap()
{
	cout<<"Ma nha cung cap: ";				fflush(stdin);		gets(MaNCC);
	cout<<"Ten nha cung cap: ";				fflush(stdin);		gets(TenNCC);
	cout<<"dia chi nha cung cap: ";			fflush(stdin);		gets(Diachi);
}
void NCC::xuat()
{
	cout<<setw(15)<<"Ma NCC: "<<setw(15)<<MaNCC;
	cout<<setw(15)<<"Ten NCC: "<<setw(15)<<TenNCC<<endl;
	cout<<setw(15)<<"Dia Chi: "<<setw(15)<<Diachi<<endl;
}
void Hang::nhap()
{
	cout<<"Ten Hang: ";				fflush(stdin);	gets(Tenhang);
	cout<<"Don Gia: ";								cin>>Dongia;
	cout<<"So Luong: ";								cin>> SL;
	
}
void Hang::xuat()
{
	cout<<setw(15)<<Tenhang<<setw(15)<<Dongia<<setw(15)<<SL<<setw(15)<<Dongia*SL<<endl;
}
void Phieu::nhap()
{
	cout<<"Ma Phieu: ";					fflush(stdin);	gets(Maphieu);
	cout<<"Ngay lap: ";					fflush(stdin);	gets(ngay);
	x.nhap();
	cout<<"Nhap so don hang: ";							cin>>n;
	for(int i=0; i<n; i++){
		ds[i].nhap();
	}
}
void Phieu::xuat()
{
	cout<<setw(40)<<"--------PHIEU NHAP HANG--------"<<endl;
	cout<<setw(15)<<"Ma Phieu: "<<setw(15)<<Maphieu;
	cout<<setw(15)<<"Ngay Lap: "<<setw(15)<<ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"Ten Hang"<<setw(15)<<"Don Gia"<<setw(15)<<"So Luong"<<setw(15)<<"Thanh Tien"<<endl;
	for(int i=0; i<n; i++){
		ds[i].xuat();
	}
	float sum=0;
	for(int i=0; i<n; i++)
		sum+=ds[i].Dongia*ds[i].SL;
	
	cout<<setw(45)<<"Cong Thanh Tien "<<setw(15)<<sum;
}

int main()
{
	Phieu a;
	a.nhap();
	a.xuat();
}




