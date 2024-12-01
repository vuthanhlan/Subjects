#include<iostream>
#include<iomanip>
#include<stdio.h>

using namespace std;

class SinhVien
{
	private:
		char Masv[10];
		char Hoten[30];
		float DiemToan;
		float DiemLy;
		float DiemHoa;
	public:
		void nhap();
		void xuat();
		friend float sum(SinhVien x);
};
void SinhVien::nhap()
{
	cout<<"Nhap ma Sinh Vien: ";			fflush(stdin);	gets(Masv);
	cout<<"Nhap ho ten Sinh Vien: ";		fflush(stdin);	gets(Hoten);
	cout<<"Nhap Diem Toan: ";								cin>>DiemToan;
	cout<<"Nhap Diem Ly: ";									cin>>DiemLy;
	cout<<"Nhap Diem Hoa: ";								cin>>DiemHoa;
}
void SinhVien::xuat()
{
	cout<<Masv<<setw(20)<<Hoten<<setw(15)<<DiemToan<<setw(15)<<DiemLy<<setw(15)<<DiemHoa;
}
float sum(SinhVien x)
{
	float sum=x.DiemToan+x.DiemLy+x.DiemHoa;
	return sum;
}
int main()
{
	SinhVien a[100];
	int n;
	cout<<"Nhap so Sinh Vien: ";		cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<"MaSV"<<setw(20)<<"Ho Ten"<<setw(15)<<"Diem Toan"<<setw(15)<<"Diem Ly"<<setw(15)<<"Diem Hoa"<<setw(15)<<"Tong diem"<<endl;
	for(int i=0; i<n; i++){
		a[i].xuat();
		cout<<setw(15)<<sum(a[i])<<endl;
	}
	
}




