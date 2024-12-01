#include<iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;

class HANG
{
	private:
		char mahang[10];
		char tenhang[20];
		int dongia;
	public:
		void nhap();
		void xuat();
};
void HANG::nhap()
{
	cout<<"ma hang: ";                 fflush(stdin);  gets(mahang);
	cout<<"ten hang: ";                fflush(stdin);  gets(tenhang);
	cout<<"don gia: ";                                 cin>>dongia;
}
void HANG::xuat()
{
	cout<<setw(15)<<mahang<<setw(15)<<tenhang<<setw(15)<<dongia<<endl;
}
class PHIEU
{
	private:
		char maphieu[10];
		HANG *x;
		int n;
	public:
		void nhap();
		void xuat();
};
void PHIEU::nhap()
{
	cout<<"Ma phieu: ";              fflush(stdin);  gets(maphieu);
	cout<<"so mat hang: ";                        	 cin>>n;
	x=new HANG[n];
	for(int i=0; i<n; i++)
		x[i].nhap();
}
void PHIEU::xuat()
{
	cout<<setw(10)<<"Ma Phieu: "<<maphieu<<endl;
	cout<<setw(15)<<"ma hang"<<setw(15)<<"ten hang"<<setw(15)<<"don gia"<<endl;
	for(int i=0; i<n; i++)
		x[i].xuat();
}
int main(){
	PHIEU a;
	a.nhap();
	a.xuat();
}




