#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
class LOPHOC;
class NGUOI
{
	protected:
		char hoten[20];
		char ngaysinh[20];
		char que[50];
	public:
		void nhap();
		void xuat();	
};

void NGUOI::nhap()
{
	cout<<"Ho ten: ";			fflush(stdin);	gets(hoten);
	cout<<"Ngay sinh: ";		fflush(stdin);	gets(ngaysinh);
	cout<<"que: ";				fflush(stdin);	gets(que);
}

void NGUOI::xuat()
{
	cout<<setw(15)<<hoten<<setw(15)<<ngaysinh<<setw(15)<<que;
}
class SINHVIEN: public NGUOI
{
	private:
		char masv[10];
		char nganh[20];
		int khoahoc;
	public:
		void nhap();
		void xuat();
		friend void dem(LOPHOC a);
		friend void sx(LOPHOC &a);
};
void SINHVIEN::nhap()
{
	NGUOI::nhap();
	cout<<"Ma sinh vien: ";				fflush(stdin);	gets(masv);
	cout<<"Nganh: ";					fflush(stdin);	gets(nganh);
	cout<<"Khoa hoc: ";									cin>>khoahoc;
}
void SINHVIEN::xuat()
{
	NGUOI::xuat();
	cout<<setw(15)<<masv<<setw(15)<<nganh<<setw(15)<<khoahoc<<endl;
}

class LOPHOC
{
	private:
		char malh[10];
		char tenlh[20];
		char ngaymo[20];
		SINHVIEN *x;
		int n;
		char gv[20];
	public:
		void nhap();
		void xuat();
		friend void dem(LOPHOC a);
		friend void sx(LOPHOC &a);
};

void LOPHOC::nhap()
{
	cout<<"ma lop hoc: ";			fflush(stdin);	gets(malh);
	cout<<"ten lop hoc: ";			fflush(stdin);	gets(tenlh);
	cout<<"ngay mo: ";				fflush(stdin);	gets(ngaymo);
	cout<<"so sinh vien: ";							cin>>n;
	x=new SINHVIEN[n];
	for(int i=0; i<n; i++){
		x[i].nhap();
	}
	cout<<"giang vien: ";			fflush(stdin);	gets(gv);
}
void LOPHOC::xuat()
{
	cout<<setw(15)<<"Ma lop hoc: "<<setw(15)<<malh;
	cout<<setw(15)<<"Ten lop hoc: "<<setw(15)<<tenlh<<endl;
	cout<<setw(15)<<"Ngay mo: "<<setw(15)<<ngaymo;
	cout<<setw(15)<<"Giang Vien: "<<setw(15)<<gv<<endl;
	cout<<setw(15)<<"Ho ten"<<setw(15)<<"ngay sinh"<<setw(15)<<"que"<<setw(15)<<"Ma SV"<<setw(15)<<"Nganh"<<setw(15)<<"khoa hoc"<<endl;
	for(int i=0; i<n; i++){
		x[i].xuat();
	}
}

void dem(LOPHOC a)
{
	int dem=0;
	for(int i=0; i<a.n; i++){
		if(a.x[i].khoahoc==11)
			dem++;
	}
	cout<<"So sinh vien khoa 11 la: "<<dem<<endl;
}

void sx(LOPHOC &a)
{
	for(int i=0; i<a.n-1;i++){
		for(int j=i+1;j<a.n; j++){
			if(a.x[i].khoahoc>a.x[j].khoahoc){
				SINHVIEN tmp=a.x[i];
				a.x[i]=a.x[j];
				a.x[j]=tmp;
			}
		}
	}
}
int main()
{
	LOPHOC lh1;
	lh1.nhap();
	lh1.xuat();
	dem(lh1);
	sx(lh1);
	cout<<"--------------------------------------------------------------------------"<<endl;
	lh1.xuat();
}


