#include<bits/stdc++.h>

using namespace std;

class DIEM
{
	private:
		int x,y,z;
	public:
		DIEM();
		DIEM(int a, int b, int c);
		DIEM operator+(DIEM a);
		friend istream& operator>>(istream &in, DIEM & a);
		friend ostream& operator<<(ostream &out, DIEM a);
		
};
DIEM::DIEM()
{
	x=y=z=0;
}
DIEM::DIEM(int a, int b, int c)
{
	x=a;
	y=b;
	z=c;
}
istream& operator>>(istream &in, DIEM & a)
{
	cout<<"x= ";			in>>a.x;
	cout<<"y= ";			in>>a.y;
	cout<<"z= ";			in>>a.z;
return in;
}
ostream& operator<<(ostream &out, DIEM a)
{
	out<<"("<<a.x<<","<<a.y<<","<<a.z<<")"<<endl;
}

DIEM DIEM::operator+(DIEM a)
{
	DIEM kq;
	kq.x=x+a.x;
	kq.y=y+a.y;
	kq.z=z+a.z;
return kq;
}
int main()
{
	DIEM M,N;
	cout<<"Nhap diem M\n";			cin>>M;
	cout<<"Nhap diem N\n";			cin>>N;
	cout<<"Tong Hai diem la: K"<<M+N;
}

