#include<bits/stdc++.h>

using namespace std;

class SANPHAM
{
	protected:
		char masp[10];
		char tensp[20];
		char ngayn[20];
	public:
		void nhap();
		void xuat();
};
class DIEUHOA:public SANPHAM
{
	private:
		float congsuat;
		char tenhsx[20];
		int giaban;
	public:
		void nhap();
		void xuat();
		friend void search(DIEUHOA a[100], int n);
};

void SANPHAM::nhap()
{
	cout<<"MaSP: ";				fflush(stdin);	gets(masp);
	cout<<"Ten SP:";			fflush(stdin);	gets(tensp);
	cout<<"Ngay nhap: ";		fflush(stdin);	gets(ngayn);
}
void SANPHAM::xuat()
{
	cout<<setw(15)<<masp<<setw(15)<<tensp<<setw(15)<<ngayn;
}
void DIEUHOA::nhap()
{
	SANPHAM::nhap();
	cout<<"Cong Suat: ";						cin>>congsuat;
	cout<<"Ten Hang SX: ";		fflush(stdin);	gets(tenhsx);
	cout<<"Gia Ban: ";							cin>>giaban;
}
void DIEUHOA::xuat()
{
	SANPHAM::xuat();
	cout<<setw(15)<<congsuat<<setw(15)<<tenhsx<<setw(15)<<giaban<<endl;
}

void search(DIEUHOA a[100], int n)
{
	int min=a[0].giaban;
	for(int i=0; i<n; i++){
		if(a[i].giaban<min){
			min=a[i].giaban;
		}
	}
	for(int i=0; i<n; i++){
		if(strcmp(a[i].tenhsx,"Electrilux")==0 && a[i].giaban==min){
			a[i].xuat();
		}
	}
	
}
int main()
{
	DIEUHOA a[100];
	int n;
	cout<<"So dieu hoa: ";						cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<setw(15)<<"MASP"<<setw(15)<<"TenSP"<<setw(15)<<"Ngay Nhap"<<setw(15)<<"CongSuat"<<setw(15)<<"Ten HSX"<<setw(15)<<"GiaBan"<<endl;
	search(a,n);
}
/*
2
SP01
quat
28/9/2003
8
Electrilux
10
SP02
Tivi
29/6/2006
9
Samsung
9
*/

