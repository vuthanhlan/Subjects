#include<bits/stdc++.h>

using namespace std;

class Nguoi
{
	protected:
		char HoTen[20];
		int tuoi;
		char gioitinh[10];
	public:
		void nhap();
		void xuat();
};

class NhanVien:public Nguoi
{
	private:
		char manv[10];
		char chucvu[20];
		int luong;
	public:
		void nhap();
		void xuat();	
};

class CongTy
{
	private:
		char MaCT[10];
		char diachi[30];
		NhanVien *x;
		int n;
	public:
		void nhap();
		void xuat();
};		

void Nguoi::nhap()
{
	cout<<"Nhap Ten: ";				fflush(stdin);	gets(HoTen);
	cout<<"Nhap tuoi: ";							cin>>tuoi;
	cout<<"Nhap gioi tinh: ";		fflush(stdin);	gets(gioitinh);
}
void Nguoi::xuat()
{
	cout<<setw(15)<<HoTen<<setw(15)<<tuoi<<setw(15)<<gioitinh;
}
void NhanVien::nhap()
{
	Nguoi::nhap();
	cout<<"Nhap Ma NV: ";			fflush(stdin);	gets(manv);
	cout<<"Nhap Chuc vu: ";			fflush(stdin);	gets(chucvu);
	cout<<"Nhap Luong: ";							cin>>luong;
}
void NhanVien::xuat()
{
	Nguoi::xuat();
	cout<<setw(15)<<manv<<setw(15)<<chucvu<<setw(15)<<luong<<endl;
}
void CongTy::nhap()
{
	cout<<"Nhap MaCT: ";		fflush(stdin);	gets(MaCT);
	cout<<"Nhap Dia chi: ";		fflush(stdin);	gets(diachi);
	cout<<"Nhap so nhan vien: ";				cin>>n;
	x=new NhanVien[n];
	for(int i=0; i<n; i++){
		cout<<"nhap Nhan Vien thu "<<i+1<<endl;
		x[i].nhap();
	}
}
void CongTy::xuat()
{
	cout<<"\n-------THONG TIN CONG TY----------\n";
	cout<<setw(15)<<"MaCT: "<<MaCT;
	cout<<setw(15)<<"Dia Chi: "<<diachi<<endl<<endl;
	cout<<setw(15)<<"HoTen"<<setw(15)<<"Tuoi"<<setw(15)<<"Gioi Tinh"<<setw(15)<<"MaNV"<<setw(15)<<"ChucVu"<<setw(15)<<"Luong"<<endl;
	for(int i=0; i<n; i++){
		x[i].xuat();
	}
}
int main()
{
	CongTy a;
	a.nhap();
	a.xuat();
}
/*
HUJK
sfd
2
1
dfgsfh
20
nu
NV01
fdgfd
5000
2
fdg
16
nu
NV02
dfgdsf
6000
*/

