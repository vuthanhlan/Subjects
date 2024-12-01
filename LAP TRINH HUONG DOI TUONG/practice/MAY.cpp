#include<bits/stdc++.h>
using namespace std;
class MAYTINH;
class NSX
{
	private:
		char TenNSX[20];
		char Diachi[30];
		friend class MAY;
	friend void xoa(MAYTINH a[100],int &n);
};

class MAY
{
	protected:
		char nhanhieu[20];
		NSX x;
		float Giathanh;
	public:
		void nhap();
		void xuat();
		friend void sx(MAYTINH a[100],int n);
};
class MAYTINH:public MAY,NSX
{
	private:
		float tocdo;
		float RAM;
		float HDD;
	public:
		void nhap();
		void xuat();
		friend void sx(MAYTINH a[100],int n);
		friend void xoa(MAYTINH a[100],int &n);
		
};
void MAY::nhap()
{
	cout<<"Nhap Nhan Hieu: ";	fflush(stdin);	gets(nhanhieu);
	cout<<"Nhap Ten NSX: ";		fflush(stdin);	gets(x.TenNSX);
	cout<<"Nhap Dia chi NSX:";	fflush(stdin);	gets(x.Diachi);
	cout<<"Gia Thanh: ";						cin>>Giathanh;
}
void MAY::xuat()
{
	cout<<setw(15)<<nhanhieu<<setw(15)<<x.TenNSX<<setw(15)<<x.Diachi<<setw(15)<<Giathanh;
}
void MAYTINH::nhap()
{
	MAY::nhap();
	cout<<"Nhap toc do: ";				cin>>tocdo;
	cout<<"Dung luong RAM: ";			cin>>RAM;
	cout<<"Dung Luong HDD: ";			cin>>HDD;
}
void MAYTINH::xuat()
{
	MAY::xuat();
	cout<<setw(15)<<tocdo<<setw(15)<<RAM<<setw(15)<<HDD<<endl;
}
void sx(MAYTINH a[100],int n)
{
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n;j++){
			if(a[i].Giathanh<a[j].Giathanh){
				MAYTINH temp= a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void xoa(MAYTINH a[100],int &n)
{
	int d=0;
	for(int i=0; i<n; i++){
		if(strcmp(a[i].x.TenNSX,"Intel")==0){
			d++;
		}
	}
		if(d==0) cout<<"Khong co may tinh hang Intel"<<endl;
		else{
			for(int i=0; i<n; i++)
			{
				if(strcmp(a[i].x.TenNSX,"Intel")==0){
					for(int j=i; j<n-1;j++){
						a[j]=a[j+1];
					}
					n--;
				}
			}
		}
	
}
int main()
{
	MAYTINH a[100];
	int n;
	cout<<"Nhap so may tinh: ";					cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<setw(15)<<"Nhan hieu"<<setw(15)<<"Ten NSX"<<setw(15)<<"Dia Chi NSX"<<setw(15)<<"Gia Thanh"<<setw(15)<<"Toc do"<<setw(15)<<"DLuong RAM"<<setw(15)<<"DLuong HDD<<"<<endl;
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
	cout<<"\n\n--THONG TIN SAU KHI SAP XEP---\n"<<endl;
	sx(a,n);
	cout<<setw(15)<<"Nhan hieu"<<setw(15)<<"Ten NSX"<<setw(15)<<"Dia Chi NSX"<<setw(15)<<"Gia Thanh"<<setw(15)<<"Toc do"<<setw(15)<<"DLuong RAM"<<setw(15)<<"DLuong HDD<<"<<endl;
	for(int i=0; i<n; i++)
	{
		a[i].xuat();
	}
	xoa(a,n);
	cout<<"\n\n--THONG TIN SAU KHI SAP XOA---\n"<<endl;
	cout<<setw(15)<<"Nhan hieu"<<setw(15)<<"Ten NSX"<<setw(15)<<"Dia Chi NSX"<<setw(15)<<"Gia Thanh"<<setw(15)<<"Toc do"<<setw(15)<<"DLuong RAM"<<setw(15)<<"DLuong HDD<<"<<endl;
	for(int i=0; i<n; i++)
	{
		a[i].xuat();
	}
	
}

/*
2
xxfhg
Intel
gh
5
8
9
6
2
zfgh
bkjg
8
9
6
2
*/

