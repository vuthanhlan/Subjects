#include<bits/stdc++.h>

using namespace std;

class HHCN
{
	private:
		int CD,CR,CC;
	public:
		HHCN();
		HHCN(int a, int b, int c);
		friend istream& operator>>(istream &in, HHCN &x);
		friend ostream& operator<<(ostream &out, HHCN x);
		int operator++();
		HHCN operator+(HHCN a);
};

//Phuong thuc khoi tao
HHCN::HHCN()
{
	CD=CR=CC=0;
}
HHCN::HHCN(int a, int b, int c)
{
	CD=a;
	CR=b;
	CC=c;
}

//ham toan tu nhap
istream& operator>>(istream &in, HHCN &x)
{
	cout<<"Nhap Chieu dai: ";			in>>x.CD;
	cout<<"Nhap Chieu rong: ";			in>>x.CR;
	cout<<"Nhap Chieu cao: ";			in>>x.CC;
return in;
}
//ham toán tu xuat
ostream& operator<<(ostream &out, HHCN x)
{
	out<<"HHCN("<<x.CD<<";"<<x.CR<<";"<<x.CC<<") "<<endl;
return out;
}
// Phuong thuc tra ve dien tich toan phan
//Stp=(d+r)*2*h+2*d*r
int HHCN::operator++()
{
	int kq;
	kq=(CD+CR)*2*CC+2*CD*CR;
return kq;
}
HHCN HHCN::operator+(HHCN a)
{
	HHCN kq;
	if(CC==a.CC && CR==a.CR){
		kq.CD=CD+a.CD;
		kq.CR=CR+a.CR;
		kq.CC=CC+a.CC;
	}
	else{
		cout<<"Khong thoa man dieu kien!"<<endl;
	}
return kq;
}
int main()
{
	HHCN a,b;
	ofstream ghi("HHCN.txt");
	cout<<"nhap HHCN a\n";				cin>>a;
	cout<<"HHCN a: "<<a;
	ghi<<"HHCN a: "<<a;
	cout<<"nhap HHCN b\n";				cin>>b;
	cout<<"HHCN b: "<<b;
	ghi<<"HHCN b: "<<b;
	cout<<"Dien tich toan phan cua HHCN a la: "<<++a<<endl;
	ghi<<"Dien tich toan phan cua HHCN a la: "<<++a<<endl;
	cout<<"Dien tich toan phan cua HHCN b la: "<<++b<<endl;
	ghi<<"Dien tich toan phan cua HHCN b la: "<<++b<<endl;
	cout<<"ghep 2 HHCN: "<<a+b<<endl;
	ghi<<"ghep 2 HHCN: "<<a+b<<endl;
}






