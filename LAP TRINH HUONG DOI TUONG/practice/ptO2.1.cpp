#include<bits/stdc++.h>

using namespace std;
class TIVI;
class NSX
{
	private:
		char tennsx[20];
		char diachi[30];
	public:
		void nhap();
		void xuat();
		friend class HANG;
};
class DATE
{
	private:
		int D,M,Y;
	public:
		void nhap();
		void xuat();
		friend class TIVI;
};
class HANG
{
	protected:
		char tenhang[20];
		NSX x;
		int dongia;
	public:
		void nhap();
		void xuat();
		HANG();
	
};
class TIVI:public HANG
{
	private:
		int kichthuoc;
		DATE ngaynhap;
	public:
		void nhap();
		void xuat();
		TIVI();
};
void NSX::nhap()
{
	cout<<"Ten NSX: ";				fflush(stdin);	gets(tennsx);
	cout<<"Dia chi: ";				fflush(stdin);	gets(diachi);
}
void NSX::xuat()
{
	cout<<"Ten NSX: "<<tennsx<<endl;
	cout<<"Dia: "<<diachi<<endl;
}

void DATE::nhap()
{
	cout<<"Nhap ngay: ";				cin>>D;
	cout<<"Nhap thang: ";				cin>>M;
	cout<<"Nhap nam: ";					cin>>Y;
}
void DATE::xuat()
{
	cout<<"thoi Gian: "<<D<<"/"<<M<<"/"<<Y<<endl;
}
void HANG::nhap()
{
	cout<<"Nhap ten hang: ";		fflush(stdin);	gets(tenhang);
	x.nhap();
	cout<<"Nhap Don Gia: ";							cin>>dongia;
}
void HANG::xuat()
{
	cout<<"Ten Hang: "<<tenhang<<endl;
	x.xuat();
	cout<<"Don gia: "<<dongia<<endl;
}
HANG::HANG()
{
	strcpy(tenhang," ");
	strcpy(x.tennsx," ");
	strcpy(x.diachi," ");
	dongia=0;
}
TIVI::TIVI():HANG()
{
	kichthuoc = 0;
	ngaynhap.D = ngaynhap.M = ngaynhap.Y = 0;
}
void TIVI::nhap()
{
	HANG::nhap();
	cout<<"Kich Thuoc: ";				cin>>kichthuoc;
	ngaynhap.nhap();
	
}
void TIVI::xuat()
{
	cout<<"THONG TIN CUA TIVI"<<endl;
	HANG::xuat();
	cout<<"Kich thuoc: "<<kichthuoc<<endl;
	ngaynhap.xuat();
}
int main()
{
	TIVI t;
	t.nhap();
	t.xuat();
}






