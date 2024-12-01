#include<iostream>
#include<iomanip>
using namespace std;

class nhanvien
{
	private:
		char hoten[30];
		char chucvu[50];
	public:
		void nhap();
		void xuat();
};
void nhanvien::nhap()
{
	cout<<" nhap ho ten: ";       fflush(stdin);       gets(hoten);
	cout<<" nhap chuc vu: ";      fflush(stdin);       gets(chucvu);
}
void nhanvien::xuat()
{
	cout<<setw(15)<<"NHAN VIEN KIEM KE: "<<hoten;
	cout<<setw(15)<<" CHUC VU: "<<chucvu<<endl;
}

class phong
{
	private:
		char maph[10];
		char tenph[20];
		char tentp[20];
	public:
		void nhap();
		void xuat();
};
void phong::nhap()
{
	cout<<"nhap ma phong: ";      			fflush(stdin);     gets(maph);
	cout<<"nhap ten phong: ";     			fflush(stdin);     gets(tenph);
	cout<<"nhap ten truong phong: ";     	fflush(stdin);     gets(tentp);
}
void phong::xuat()
{
	cout<<setw(15)<<"MA PHONG: "<<maph;
	cout<<setw(15)<<"TEN PHONG: "<<tenph<<endl;
	cout<<setw(15)<<"TRUONG PHONG: "<<tentp<<endl;
}

class taisan
{
	private:
		char tents[30];
		int SL;
		char trinhtrang[50];
	public:
		void nhap();
		void xuat();
		friend class phieu;
};
void taisan::nhap()
{
	cout<<"nhap ten san pham: ";                    fflush(stdin);  gets(tents);
	cout<<"nhap so luong: ";                        cin>>SL;
	cout<<"nhap tinh trang: ";                      fflush(stdin);  gets(trinhtrang);
}
void taisan::xuat()
{
	cout<<setw(15)<<tents<<setw(15)<<SL<<setw(15)<<trinhtrang<<endl;
}

class phieu
{
	private:
		char maph[20];
		char ngay[12];
		nhanvien X;
		phong Y;
		taisan *Z;
		int n;
	public:
		void nhap();
		void xuat();
};
void phieu::nhap()
{
	cout<<"nhap ma phieu: ";         fflush(stdin); gets(maph);
	cout<<"nhap ngay: ";             fflush(stdin); gets(ngay);
	X.nhap();
	Y.nhap();
	cout<<"nhap so tai san: ";       cin>>n;
	Z= new taisan[n];
	for(int i=0; i<n; i++){
		Z[i].nhap();
	}
	
}
void phieu::xuat()
{
	cout<<setw(40)<<"PHIEU KIEM KE TAI SAN"<<endl;
	cout<<setw(15)<<"MA PHIEU: "<<maph;
	cout<<setw(15)<<"NGAY KIEM KE: "<<endl;
	X.xuat();
	Y.xuat();
	cout<<setw(15)<<"TEN TAI SAN"<<setw(15)<<"SO LUONG"<<setw(15)<<"TINH TRANG"<<endl;
	for(int i=0; i<n; i++){
		Z[i].xuat();
	}
	cout<<"so tai san da kiem ke: "<<n;
	int T=0;
	for(int i=0; i<n; i++){
		T=+Z[i].SL;
	}
	cout<<setw(15)<<"Tong so luong: "<<T;
}
int main()
{
	phieu k;
	k.nhap();
	k.xuat();

    
}



