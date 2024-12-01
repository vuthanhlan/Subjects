#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class PHIEU;
class NHANVIEN
{
	private:
		char hoten[30];
		char chucvu[50];
	public:
		void nhap();
		void xuat();
};
void NHANVIEN::nhap()
{
	cout<<"Ho ten: ";               fflush(stdin);     gets(hoten);
	cout<<"Chuc vu: ";              fflush(stdin);     gets(chucvu);
}
void NHANVIEN::xuat()
{
	cout<<setw(15)<<"Nhan Vien Kiem Ke: "<<setw(15)<<hoten;
	cout<<setw(15)<<"Chuc vu: "<<setw(15)<<chucvu<<endl;
}
class PHONG
{
	private:
		char tenP[30];
		char maP[10];
		char tenTP[30];
	public:
		void nhap();
		void xuat();
};
void PHONG::nhap()
{
	cout<<"ten phong: ";                fflush(stdin);   gets(tenP);
	cout<<"ma phong: ";                 fflush(stdin);   gets(maP);
	cout<<"Ten truong phong: ";         fflush(stdin);   gets(tenTP);
}
void PHONG::xuat()
{
	cout<<setw(15)<<"Ten phong: "<<setw(15)<<tenP;
	cout<<setw(15)<<"Ma phong: "<<setw(15)<<maP<<endl;
	cout<<setw(15)<<"Truong phong: "<<setw(15)<<tenTP<<endl;
}
class TAISAN
{
	private:
		char tenTS[30];
		int SL;
		char tinhtrang[50];
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
		friend void sapxep(PHIEU &t);
		friend void sua(PHIEU &t);
		char* gettenTS() 
		{ 
			return tenTS;
		}
		void setSL(int newSL)
		{
			SL = newSL;
		}
		
};
void TAISAN::nhap()
{
	cout<<"ten tai san: ";                fflush(stdin);      gets(tenTS);
	cout<<"so luong: ";                                       cin>>SL;
	cout<<"Tinh trang: ";                 fflush(stdin);      gets(tinhtrang);

}
void TAISAN::xuat()
{
	cout<<setw(15)<<tenTS<<setw(15)<<SL<<setw(15)<<tinhtrang<<endl;
}
class PHIEU
{
	private:
		char maphieu[10];
		char ngay[12];
		NHANVIEN x;
		PHONG y;
		TAISAN *z;
		int n;
	public:
		void nhap();
		void xuat();
		friend void sua(PHIEU &t);
		friend void sapxep(PHIEU &t);
};
void PHIEU::nhap()
{
	cout<<"ma phieu: ";           fflush(stdin);     gets(maphieu);
	cout<<"Ngay lap: ";           fflush(stdin);     gets(ngay);
	x.nhap();
	y.nhap();
	cout<<"So tai san: ";                            cin>>n;
	z=new TAISAN[n];
	for(int i=0; i<n; i++)
		z[i].nhap();
}
void PHIEU::xuat()
{
	cout<<setw(40)<<"-----------PHIEU KIEM KE TAI SAN------------"<<endl;
	cout<<setw(15)<<"Ma phieu: "<<setw(15)<<maphieu;
	cout<<setw(15)<<"Ngay lap: "<<setw(15)<<ngay<<endl;
	x.xuat();
	y.xuat();
	cout<<setw(15)<<"Ten tai san"<<setw(15)<<"So Luong"<<setw(15)<<"Tinh Trang"<<endl;
	for(int i=0; i<n; i++)
		z[i].xuat();
	cout<<setw(15)<<"Tong so tai san: "<<n;
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=z[i].SL;
	cout<<setw(20)<<"Tong so luong: "<<sum;
}
void sua(PHIEU &t)
{
	for(int i=0; i<t.n;i++){
		if(strcmp(t.z[i].tenTS,"May vi tinh")==0)
			t.z[i].SL=20;
	}
}
void sapxep(PHIEU &t)
{
	for(int i=0; i<t.n-1; i++){
		for(int j=i+1; j<t.n;j++){
			if(t.z[i].SL<t.z[j].SL){
				TAISAN temp = t.z[i];
				t.z[i]=t.z[j];
				t.z[j]=temp;
			}
		}
	}
}
int main()
{
	PHIEU k;
	k.nhap();
	k.xuat();
	sua(k);
	cout<<"\n\nDANH SACH SAU KHI SUA"<<endl;
	k.xuat();
	sapxep(k);
	cout<<"\n\nDANH SACH SAU KHI SAP XEP"<<endl;
	k.xuat();
}






