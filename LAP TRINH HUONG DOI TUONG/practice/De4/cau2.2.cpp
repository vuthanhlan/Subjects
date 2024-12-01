#include<bits/stdc++.h>
using namespace std;
class CHUSOHUU;
class XE{
	protected:
		char mauson[20];
		char bienso[20];
		char noidk[20];
		int namdk;
	public:
		XE();
		XE(char *a, char *b, char *c, int d);
		void nhap();
		void xuat();
};
class CHUSOHUU:public XE
{
	private: 
		char tencsh[20];
		char cmt[20];
	public:
		CHUSOHUU();
		CHUSOHUU(char * a, char *b);
		void nhap();
		void xuat();
	friend void search(CHUSOHUU a[100],int n);
};
XE::XE()
{
	strcpy(mauson,"");
	strcpy(bienso,"");
	strcpy(noidk,"");
	namdk=0;
}
XE::XE(char *a, char *b, char *c, int d)
{
	strcpy(mauson,a);
	strcpy(bienso,b);
	strcpy(noidk,c);
	namdk=d;
}
void XE::nhap()
{
	cout<<"mau son: ";			fflush(stdin);	gets(mauson);
	cout<<"bien so: ";			fflush(stdin);	gets(bienso);
	cout<<"noi DK: ";			fflush(stdin);	gets(noidk);
	cout<<"Nam DK: ";							cin>>namdk;
}
void XE::xuat()
{
	cout<<setw(15)<<mauson<<setw(15)<<bienso<<setw(15)<<noidk<<setw(15)<<namdk;
}
CHUSOHUU::CHUSOHUU():XE()
{
	strcpy(tencsh,"");
	strcpy(cmt,"");
}
CHUSOHUU::CHUSOHUU(char * a, char *b)
{
	strcpy(tencsh,a);
	strcpy(cmt,b);
}
void CHUSOHUU::nhap()
{
	XE::nhap();
	cout<<"Ten CSH: ";			fflush(stdin);	gets(tencsh);
	cout<<"CMT: ";				fflush(stdin);	gets(cmt);
}
void CHUSOHUU::xuat()
{
	XE::xuat();
	cout<<setw(15)<<tencsh<<setw(15)<<cmt<<endl;
}

void search(CHUSOHUU a[100], int n)
{
	int d=0;
	for(int i=0; i<n; i++){
		if(strcmp(a[i].noidk,"Ha Noi")==0){
			d++;
		}
	}
	if(d==0) cout<<"Khong co CSH dang ki o Ha Noi!";
	else
	{
		cout<<setw(15)<<"Mau Son"<<setw(15)<<"Bien So"<<setw(15)<<"Noi DK"<<setw(15)<<"Nam DK"<<setw(15)<<"Ten CSH"<<setw(15)<<"CMT"<<endl;
		for(int i=0; i<n; i++){
			if(strcmp(a[i].noidk,"Ha Noi")==0){
				a[i].xuat();
			}
		}
	}
}
int main()
{
	CHUSOHUU a[100];
	int n;
	cout<<"Nhap so CSH: ";			cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	search(a,n);
}
/*
2
den
2599
ha noi
2008
Vu Van A
2889956
bac
8623
Thai Binh
2006
Hoang mai
549895
*/



