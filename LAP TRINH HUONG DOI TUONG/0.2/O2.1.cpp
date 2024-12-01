#include<iostream>
#include<string.h>

using namespace std;
class Tivi;
class Hang;
class Date{
	private:
		int D;
		int M;
		int Y;
	public:
		void nhap();
		void xuat();
	friend class Tivi;
};
class NSX{
	private:
		char Tennsx[20];
		char Diachi[20];
	public:
		void nhap();
		void xuat();
	friend class Hang;
};
class Hang{
	protected:
		char Tenhang[15];
		NSX x;
		float Dongia;
	public:
		void nhap();
		void xuat();
		Hang();
};
class Tivi:public Hang{
		float Kichthuoc;
		Date Ngaynhap;
	public:
		void nhap();
		void xuat();
		Tivi();
};
Hang::Hang(){
	strcpy(Tenhang,"");
	strcpy(x.Tennsx,"");
	strcpy(x.Diachi,"");
	Dongia = 0;
}
Tivi::Tivi():Hang(){
	Kichthuoc = 0;
	Ngaynhap.D = Ngaynhap.M = Ngaynhap.Y = 0;
}
void Date::nhap(){
	cout << "Ngay: ";		cin >> D;
	cout << "Thang: ";		cin >> M;
	cout << "Nam: ";		cin >> Y;
}
void Date::xuat(){
	cout << "Ngay: " << D << endl;
	cout << "Thang: " << M << endl;
	cout << "Nam: " << Y << endl;	
}
void NSX::nhap(){
	cout << "Ten NSX: ";			fflush(stdin);		gets(Tennsx);
	cout << "Dia chi NSX: ";		fflush(stdin);		gets(Diachi);
}
void NSX::xuat(){
	cout << "Ten NSX: " << Tennsx << endl;
	cout << "Dia chi NSX: " << Diachi << endl;
}
void Hang::nhap(){
	cout << "Ten hang: ";		fflush(stdin);		gets(Tenhang);
	x.nhap();
	cout << "Don gia: ";							cin >> Dongia;
}
void Hang::xuat(){
	cout << "Ten hang: " << Tenhang << endl;
	x.xuat();
	cout << "Don gia: " << Dongia << endl;
}
void Tivi::nhap(){
	Ngaynhap.nhap();
	Hang::nhap();
	cout << "Kich thuoc: ";			cin >> Kichthuoc;
}
void Tivi::xuat(){
	Ngaynhap.xuat();
	Hang::xuat();
	cout << "Kich thuoc: " << Kichthuoc << endl;
}
int main(){
	Tivi a;
	a.nhap();
	cout << "Thong tin TIVI vua nhap: " << endl;
	a.xuat();
}
