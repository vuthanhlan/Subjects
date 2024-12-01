#include<bits/stdc++.h>
using namespace std;
class CAUTHU;
class PERSON
{
	protected:
		char Hoten[50];
		char Ngays[20];
		char Quequan[100];
};
class VANDONGVIEN: public PERSON
{
	protected:
		char BoMon[30];
		int Thunhap;
	public:
		friend void max(CAUTHU a[100], int n);	
};
class CAUTHU: public VANDONGVIEN
{
	private:
		char CLB[100];
		char Vitri[100];
	public:
		void nhap();
		void xuat();
		friend void search(CAUTHU a[100], int n);
		friend void max(CAUTHU a[100], int n);	
};

void CAUTHU::nhap()
{
	cout<<"Ho ten: ";		fflush(stdin);	gets(Hoten);
	cout<<"Ngay Sinh: ";	fflush(stdin);	gets(Ngays);
	cout<<"Que quan: ";		fflush(stdin);	gets(Quequan);
	cout<<"Bo Mon: ";		fflush(stdin);	gets(BoMon);
	cout<<"Thu Nhap: ";						cin>>Thunhap;
	cout<<"CLB: ";			fflush(stdin);	gets(CLB);
	cout<<"Vi tri: ";		fflush(stdin);	gets(Vitri);
					
}
void CAUTHU::xuat()
{
	cout<<setw(15)<<Hoten<<setw(15)<<Ngays<<setw(15)<<Quequan<<setw(15)<<BoMon<<setw(15)<<Thunhap<<setw(15)<<CLB<<setw(15)<<Vitri<<endl;
}

void search(CAUTHU a[100], int n)
{
	for(int i=0; i<n; i++){
		if(strcmp(a[i].CLB,"T&T")==0){
			a[i].xuat();
		}
	}
}
void max(CAUTHU a[100], int n)
{
	int max=a[0].Thunhap;
	for(int i=1; i<n; i++){
		if(a[i].Thunhap>max){
			max=a[i].Thunhap;
		}
	}
	for(int i=0; i<n; i++){
		if(a[i].Thunhap==max){
			a[i].xuat();
		}
	}
}
int main()
{
	CAUTHU a[100];
	int n;
	do{
		cout<<"Nhap so Cau Thu: ";
		cin>>n;
	}while(n<=0||n>=50);
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<"======Danh sach cau thu o CLB T&T=========\n";
	cout<<setw(15)<<"Ho Ten"<<setw(15)<<"Ngay Sinh"<<setw(15)<<"Que Quan"<<setw(15)<<"Bo Mon"<<setw(15)<<"Thu Nhap"<<setw(15)<<"CLB"<<setw(15)<<"Vi Tri"<<endl;
	search(a,n);
	
	cout<<"\n======Cau thu co thu nhap cao nhat =========\n";
	cout<<setw(15)<<"Ho Ten"<<setw(15)<<"Ngay Sinh"<<setw(15)<<"Que Quan"<<setw(15)<<"Bo Mon"<<setw(15)<<"Thu Nhap"<<setw(15)<<"CLB"<<setw(15)<<"Vi Tri"<<endl;
	max(a,n);
}

/*
3
vu van A
18/6/2009
Thai Binh
bong ro
1300000
T&T
Center
Hoang Viet B
9/5/20005
Ha Noi
dien kinh
1500000
HHT
O
Nguyen Minh C
19/5/2003
Thanh Hoa
Bong Chuyen
1000000
JHK
Cong
*/
