#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class NCC
{
	private:
		char MaNCC[10];
		char TenNCC[30];
		char Address[50];
		int phone;
	public:
		void nhap();
		void xuat();
};
class Product
{
	private:
		char MaSP[10];
		char TenSP[30];
		int SL;
		int Dongia;
	public:
		void nhap();
		void xuat();
		friend class Phieu;
		char *getTenSP()
		{
			return TenSP;
		}
		int getSL()
		{
			return SL;
		}
		int getDongia()
		{
			return Dongia;
		}
		
};
class Phieu
{
	private:
		char MaPhieu[10];
		char Ngay[20];
		NCC x;
		Product y[100];
		int n;
	public:
		void nhap();
		void xuat();
		friend void kt(Phieu t);
		friend void sx(Phieu &t);
};
void NCC::nhap()
{
	cout<<"Ma nha cung cap: ";					fflush(stdin);	gets(MaNCC);
	cout<<"Ten nha cung cap: ";					fflush(stdin);	gets(TenNCC);
	cout<<"Dia Chi Nha Cung Cap: ";				fflush(stdin);	gets(Address);
	cout<<"So dien thoai: ";									cin>>phone;

}
void NCC::xuat()
{
	cout<<setw(15)<<"Ma NCC: "<<setw(15)<<MaNCC;
	cout<<setw(15)<<"Ten NCC: "<<setw(15)<<TenNCC<<endl;
	cout<<setw(15)<<"Dia Chi: "<<setw(15)<<Address;
	cout<<setw(15)<<"SDT: "<<setw(15)<<phone<<endl;
}
void Product::nhap()
{
	cout<<"Ma SP: ";			fflush(stdin);	gets(MaSP);
	cout<<"Ten SP:";			fflush(stdin);	gets(TenSP);
	cout<<"So Luong: ";							cin>>SL;
	cout<<"Don gia: ";							cin>>Dongia;
}
void Product::xuat()
{
	cout<<setw(15)<<MaSP<<setw(15)<<TenSP<<setw(15)<<SL<<setw(15)<<Dongia<<setw(15)<<SL*Dongia<<endl;
}
void Phieu::nhap()
{
	cout<<"Ma Phieu: ";				fflush(stdin);	gets(MaPhieu);
	cout<<"Ngay Lap: ";				fflush(stdin);	gets(Ngay);
	x.nhap();
	cout<<"nhap so san pham: "; 					cin>>n;
	for(int i=0; i<n; i++){
		y[i].nhap();
	}
}
void Phieu::xuat()
{
	cout<<"-------PHIEU NHAP VAN PHONG PHAM--------"<<endl;
	cout<<setw(15)<<"Ma Phieu: "<<setw(15)<<MaPhieu;
	cout<<setw(15)<<"Ngay lap: "<<setw(15)<<Ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"Ma SP"<<setw(15)<<"Ten san pham"<<setw(15)<<"So Luong"<<setw(15)<<"Don Gia"<<setw(15)<<"Thanh tien"<<endl;
	for(int i=0; i<n; i++){
		y[i].xuat();
	}
	int Sum=0;
	for(int i=0; i<n; i++){
		Sum+=y[i].SL*y[i].Dongia;
	}
	cout<<setw(70)<<"TONG  "<<Sum<<endl;
	
	cout<<setw(15)<<"Hieu truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap"<<endl;
}
void kt(Phieu t)
{
	for(int i=0; i<t.n; i++){
		if(t.y[i].getSL()<80)
		cout<<t.y[i].getTenSP()<<", ";
	}
}
void sx(Phieu &t)
{
	for(int i=0; i<t.n-1;i++){
		for(int j=i+1; j<t.n;j++){
			if(t.y[i].getDongia()>t.y[j].getDongia()){
					Product tmp=t.y[i];
					t.y[i]=t.y[j];
					t.y[j]=tmp;
			}	
		}
	}
}
int main(){
	Phieu a;
	a.nhap();
	a.xuat();
	cout<<"San pham co so luong nho hon 80 la: ";
	kt(a);
	sx(a);
	a.xuat();
}

