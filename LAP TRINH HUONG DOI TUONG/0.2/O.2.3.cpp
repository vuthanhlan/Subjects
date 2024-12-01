#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>>
using namespace std;
class TRUONGDH;
class KHOA
{
	private:
		char makhoa[10];
		char tenkhoa[20];
		char truongkhoa[20];
	friend class TRUONGDH;
	friend void xoa(TRUONGDH &t);
};
class BAN
{
	private:
		char maban[10];
		char tenban[20];
		char ngaylap[20];
	friend class TRUONGDH;
};
class TRUONG
{
	protected:
		char matruong[10];
		char tentruong[20];
		char diachi[30];
	public:
		void nhap();
		void xuat();
};

class TRUONGDH:public TRUONG
{
	private:
		KHOA x[100];
		int n;
		BAN y[100];
		int m;
	public:
		void nhap();
		void xuat();
		friend void xoa(TRUONGDH &t);
};
void TRUONG::nhap()
{
	cout<<"Ma truong: ";				fflush(stdin);	gets(matruong);
	cout<<"Ten truong: ";				fflush(stdin);	gets(tentruong);
	cout<<"Dia chi: ";					fflush(stdin);	gets(diachi);
}

void TRUONG::xuat()
{
	cout<<setw(15)<<"Ma truong: "<<matruong;
	cout<<setw(15)<<"Ten truong: "<<tentruong;
	cout<<setw(15)<<"Dia chi: "<<diachi<<endl;
}

void TRUONGDH::nhap()
{
	TRUONG::nhap();
	cout<<"so khoa: ";									cin>>n;
	for(int i=0; i<n; i++){
		cout<<"ma khoa: ";				fflush(stdin);	gets(x[i].makhoa);
		cout<<"ten khoa: ";				fflush(stdin);	gets(x[i].tenkhoa);
		cout<<"truong khoa: ";			fflush(stdin);	gets(x[i].truongkhoa);
	}
	cout<<"so ban: ";									cin>>m;	
	for(int i=0; i<m; i++){
		cout<<"ma ban: ";				fflush(stdin);	gets(y[i].maban);
		cout<<"ten ban: ";				fflush(stdin);	gets(y[i].tenban);
		cout<<"Ngay thanh lap: ";		fflush(stdin);	gets(y[i].ngaylap);
	}		
}

void TRUONGDH::xuat()
{
	TRUONG::xuat();
	cout<<setw(15)<<"Ma Khoa"<<setw(15)<<"Ten Khoa"<<setw(15)<<"Truong Khoa"<<endl;
	for(int i=0; i<n; i++){
		cout<<setw(15)<<x[i].makhoa<<setw(15)<<x[i].tenkhoa<<setw(15)<<x[i].truongkhoa<<endl;
	}
	cout<<setw(15)<<"Ma Ban"<<setw(15)<<"Ten Ban"<<setw(15)<<"Ngay Thanh Lap"<<endl;
	for(int i=0; i<m; i++){
		cout<<setw(15)<<y[i].maban<<setw(15)<<y[i].tenban<<setw(15)<<y[i].ngaylap<<endl;
	}
}

void xoa(TRUONGDH &t)
{
	int d=0;
	for(int i=0; i<t.n; i++){
		if(strcmp(t.x[i].makhoa,"KH01")==0){
			d++;
		}
		
	}
	if(d==0) cout<<"Khong co ma khoa KH01"<<endl;
	else{
		cout<<"-----------------THONG TIN SAU KHI XOA---------------"<<endl;
		for(int i=0; i<t.n; i++){
				if(strcmp(t.x[i].makhoa,"KH01")==0 ){
					for(int j=i; j<t.n-1; j++){
						t.x[j]=t.x[j+1];
					}
					t.n--;
				}	
		}		
	}
}
int main()
{
	TRUONGDH dh;
	dh.nhap();
	dh.xuat();
	xoa(dh);
	dh.xuat();
}

