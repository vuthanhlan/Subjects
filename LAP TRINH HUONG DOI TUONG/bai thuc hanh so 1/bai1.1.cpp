#include<iostream>
#include<iomanip>

using namespace std;

class sinhvien
{
	private:
		int  masv;
		char hoten[20];
		int tuoi;
		float diem;
	public:
		void nhap();
		void xuat();
};
void sinhvien::nhap()
{
	cout<<"Nhap ma sinh vien: ";            cin>>masv;
	cout<<"Nhap ho ten sinh vien: ";        fflush(stdin);  gets(hoten);
	cout<<"Nhap tuoi cua sinh vien: ";      cin>>tuoi;
	cout<<"Nhap diem cua sinh vien: ";      cin>>diem;
}
void sinhvien::xuat()
{
	cout<<"MASV: "<<masv<<endl;
	cout<<"HoTen: "<<hoten<<endl;
	cout<<"Tuoi: "<<tuoi<<endl;
	cout<<"Diem: "<<diem<<endl;
	
}
int main()
{
	sinhvien a,b;
	a.nhap();
	b.nhap();
	cout<<"\nthong tin cua sinh vien a la:\n";
	a.xuat();
	cout<<"thong tin cua sinh vien b la:\n";
	b.xuat();
}











