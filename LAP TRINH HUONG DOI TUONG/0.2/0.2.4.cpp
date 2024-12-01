#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;
class BENHNHAN;
class NGUOI
{
	protected:
		char hoten[20];
		int tuoi;
	public:
		void nhap();
		void xuat();
		friend class BENHNHAN;
		friend void dem(BENHNHAN a[],int n);
		friend void sua(BENHNHAN a[], int n);
};
void NGUOI::nhap()
{
	cout<<"Ho ten: ";			fflush(stdin);	gets(hoten);
	cout<<"Tuoi: ";								cin>>tuoi;
}
void NGUOI::xuat()
{
	cout<<setw(15)<<hoten<<setw(15)<<tuoi;
}

class BENHVIEN
{
	private:
		char tenbv[20];
		char diachi[30];
		NGUOI gd;
	friend class BENHNHAN;
};

class BENHNHAN:public NGUOI
{
	private:
		char ma[10];
		char tieusu[50];
		char chuandoan[50];
		BENHVIEN x;
		int n;
	public:
		void nhap();
		void xuat();
		friend void dem(BENHNHAN a[],int n);
		friend void sua(BENHNHAN a[], int n);
	
};

void BENHNHAN::nhap()
{
		NGUOI::nhap();
		cout<<"Ma: ";					fflush(stdin);	gets(ma);
		cout<<"Tieu su: ";				fflush(stdin);	gets(tieusu);
		cout<<"Chuan doan: ";			fflush(stdin);	gets(chuandoan);
		cout<<"Ten benh vien: ";		fflush(stdin);	gets(x.tenbv);
		cout<<"Dia chi: ";				fflush(stdin);	gets(x.diachi);
		x.gd.nhap();
}
void BENHNHAN::xuat()
{	NGUOI::xuat();
	cout<<setw(15)<<ma<<setw(15)<<tieusu<<setw(15)<<chuandoan<<setw(15)<<x.tenbv<<setw(15)<<x.diachi<<setw(15);
	x.gd.xuat();
	cout<<endl;
}

void dem(BENHNHAN a[],int n)
{
	int dem=0;
	for(int i=0; i<n; i++){
		if(a[i].NGUOI::tuoi>30)
			dem++;
	}
	cout<<"so benh nhan lon hon 30 tuoi: "<<dem<<endl;
}

void sua(BENHNHAN a[], int n)
{
	int d=0;
	for(int i=0; i<n;i++){
		if(strcmp(a[i].ma,"BN01")==0)
			d++;
	}
	if(d==0) cout<<"Khong co benh nhan ma BN01"<<endl;
	else{
		for(int i=0; i<n; i++){
			if(strcmp(a[i].ma,"BN01")==0)
				a[i].NGUOI::tuoi=20;
		}
	}
}
int main(){
	BENHNHAN a[200];
	int n ;cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<setw(15)<<"Ten BN"<<setw(15)<<"Tuoi"<<setw(15)<<"Ma"<<setw(15)<<"Tieu Su"<<setw(15)<<"Chuan Doan"<<setw(15)<<"Ten BV"<<setw(15)<<"Dia Chi"<<setw(15)<<"Ten Giam doc"<<setw(15)<<"Tuoi"<<endl;
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
	dem(a,n);
	sua(a,n);
	cout<<"---THONG TIN SAU KHI SUA------"<<endl;
	cout<<setw(15)<<"Ten BN"<<setw(15)<<"Tuoi"<<setw(15)<<"Ma"<<setw(15)<<"Tieu Su"<<setw(15)<<"Chuan Doan"<<setw(15)<<"Ten BV"<<setw(15)<<"Dia Chi"<<setw(15)<<"Ten Giam doc"<<setw(15)<<"Tuoi"<<endl;
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
}



