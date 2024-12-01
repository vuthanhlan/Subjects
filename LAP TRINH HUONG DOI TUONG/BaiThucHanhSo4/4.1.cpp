#include<iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;

class person
{
	protected:
		char hoten[30];
		int ngaysinh;
		char que[50];
};
class kysu:public person
{
	private:
		char nganh[20];
		int ntn;
	public:
		void nhap();
		void xuat();
		friend void tim(kysu a[100], int n)
};
void kysu::nhap()
{
	cout<<"ho ten: ";				fflush(stdin);	gets(hoten);
	cout<<"ngay sinh:";								cin>>ngaysinh;
	cout<<"que: ";					fflush(stdin);	gets(que);
	cout<<"nganh: ";				fflush(stdin);	gets(nganh);
	cout<<"nam tot nghiep: ";		fflush(stdin);	cin>>ntn;
}
void kysu::xuat()
{
	cout<<hoten<<setw(25)<<ngaysinh<<setw(15)<<que<<setw(15)<<nganh<<setw(15)<<ntn<<endl;
}
void tim(kysu a[100], int n)
{
	max=a[0].ntn;
	for(int i=1; i<n; i++){
		if(a[i].ntn>max ){
			max=a[i].ntn;
		}
	}
	cout<<"Ho Ten"<<setw(25)<<"Ngay Sinh"<<setw(15)<<"que"<<setw(15)<<"nganh"<<setw(15)<<"Nam TN"<<endl;
	for(int i=0; i<n; i++){
		if(a[i].ntn==max){
			a[i].xuat();
		}
	}
}

int main()
{
	kysu a[100];
	int n;
	cout<<"Nhap so ky su: ";			cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<"Ho Ten"<<setw(25)<<"Ngay Sinh"<<setw(15)<<"que"<<setw(15)<<"nganh"<<setw(15)<<"Nam TN"<<endl;
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
}






