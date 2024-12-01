#include<bits/stdc++.h>
using namespace std;
class Phieu;
class DonVi{
	private:
		char madv[10];
		char tendv[20];
		char dcdv[30];
		char tdv[20];
	public:
		void nhap();
		void xuat();
};
class TaiSan{
	private:
		char mats[10];
		char tents[20];
		char dvt[20];
		int gt;
	public:
		void nhap();
		void xuat();	
		friend class Phieu;
};

class Phieu{
	private:
		char ngayl[20];
		char nguoil[20];
		DonVi x;
		TaiSan y[100];
		int n;
	public:
		void nhap();
		void xuat();
};
void DonVi::nhap()
{
	cout<<"Nhap Ma DV: ";		fflush(stdin);	gets(madv);
	cout<<"Nhap Ten DV: ";		fflush(stdin);	gets(tendv);
	cout<<"Nhap Dia Chi DV: ";	fflush(stdin);	gets(dcdv);
	cout<<"Nhap Truong DV: ";	fflush(stdin);	gets(tdv);
}
void DonVi::xuat()
{
	cout<<setw(15)<<"Ma don vi: "<<setw(15)<<madv;
	cout<<setw(15)<<"Ten don vi: "<<setw(15)<<tendv<<endl;
	cout<<setw(15)<<"dia chi don vi: "<<setw(15)<<dcdv;
	cout<<setw(15)<<"Truong don vi: "<<setw(15)<<tdv<<endl;
}
void TaiSan::nhap()
{
	cout<<"nhap MaTS: ";		fflush(stdin);	gets(mats);
	cout<<"Nhap TenTS: ";		fflush(stdin);	gets(tents);
	cout<<"nhap Don vi tinh: ";	fflush(stdin);	gets(dvt);
	cout<<"Nhap Gia Tri: ";						cin>>gt;
}
void TaiSan::xuat()
{
	cout<<setw(15)<<mats<<setw(15)<<tents<<setw(15)<<dvt<<setw(15)<<gt<<endl;
}
void Phieu::nhap()
{
	cout<<"Nhap Ngay lap: ";		fflush(stdin);	gets(ngayl);
	cout<<"Nhap Nguoi Lap: ";		fflush(stdin);	gets(nguoil);
	x.nhap();
	cout<<"Nhap so tai san: ";						cin>>n;
	for(int i=0; i<n; i++)
	{
		y[i].nhap();
	}
}
void Phieu::xuat()
{
	cout<<setw(15)<<"Ngay Lap: "<<setw(15)<<ngayl;
	cout<<setw(15)<<"Nguoi lap: "<<setw(15)<<nguoil<<endl;
	x.xuat();
	cout<<"Chi Tiet: "<<endl;
	cout<<setw(15)<<"MaTS"<<setw(15)<<"TenTS"<<setw(15)<<"DonViTinh"<<setw(15)<<"Gia Tri"<<endl;
	for(int i=0; i<n; i++){
		y[i].xuat();
	}
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=y[i].gt;
	}
	cout<<setw(15)<<"Tong so luong thiet bi: "<<setw(35)<<sum<<endl;
	cout<<setw(20)<<"Giam doc"<<setw(20)<<"Phong Quan Ly"<<setw(20)<<"Nguoi Lap"<<endl;
}
int main()
{
	Phieu a;
	a.nhap();
	a.xuat();
}
/*
17/06/2017
Tran Duy Thanh
DV001
CongTyADZ
Cau Giay
Ha Van Huy
3
TS001
Nha Xuong
Met vuong
5000
TS002
May CNC
Chiec
5
TS003
Oto
Chiec
10
*/
