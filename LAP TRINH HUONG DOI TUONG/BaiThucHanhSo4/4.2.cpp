#include<iostream>

using namespace std;

class printer
{
	protected:
		float trongluong;
		char hangsx[20];
		int namsx;
		int tocdo;
	friend void sua_NSX(printer &a);
};
class dotprinter:public printer
{
	private:
		int matdokim;
	public:
		void nhap();
		void xuat();
};
class laserprinter:public printer
{
	private:
		int dophangiai;
	public:
		void nhap();
		void xuat();
};

void dotprinter::nhap()
{
	cout<<"Trong Luong: ";							cin>>trongluong;
	cout<<"Hang SX: ";				fflush(stdin);	gets(hangsx);
	cout<<"Nam SX: ";								cin>>namsx;
	cout<<"Toc do: ";								cin>>tocdo;
	cout<<"Mat do kim: ";							cin>>matdokim;
}
void dotprinter::xuat()
{
	cout<<"--------DOTPRINTER-------"<<endl;
	cout<<"Trong luong: "<<trongluong<<endl;
	cout<<"Hang SX: "<<hangsx<<endl;
	cout<<"Nam SX: "<<namsx<<endl;
	cout<<"Toc do: "<<tocdo<<endl;
	cout<<"Mat do kim"<<matdokim<<endl;
}
void laserprinter::nhap()
{
	cout<<"Trong Luong: ";							cin>>(trongluong);
	cout<<"Hang SX: ";				fflush(stdin);	gets(hangsx);
	cout<<"Nam SX: ";								cin>>namsx;
	cout<<"Toc do: ";								cin>>tocdo;
	cout<<"Do phan giai: ";							cin>>dophangiai;
}
void laserprinter::xuat()
{
	cout<<"--------LASERPRINTER-------"<<endl;
	cout<<"Trong luong: "<<trongluong<<endl;
	cout<<"Hang SX: "<<hangsx<<endl;
	cout<<"Nam SX: "<<namsx<<endl;
	cout<<"Toc do: "<<tocdo<<endl;
	cout<<"Do phan giai: "<<dophangiai<<endl;
}
void sua_NSX(printer &a)
{
	a.namsx=2020;
}
int main()
{
	dotprinter a;
	laserprinter b;
	cout<<"Nhap thong tin dotprinter"<<endl;
	a.nhap();
	cout<<"Nhap thong tin laserprinter"<<endl;
	b.nhap();
	a.xuat();
	b.xuat();
	cout<<"*******THONG TIN SAU KHI SUA********"<<endl;
	sua_NSX(a);
	a.xuat();
	sua_NSX(b);
	b.xuat();
}


