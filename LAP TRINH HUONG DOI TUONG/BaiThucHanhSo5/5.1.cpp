#include<bits/stdc++.h>

using namespace std;
class ps
{
	private:
		int ts,ms;
	public:
		friend istream& operator>>(istream &in, ps &x);
		friend ostream& operator<<(ostream &out, ps y);
		ps operator+(ps a);
		ps operator-(ps a);
		ps operator*(ps a);
		ps operator/(ps a);
		float operator--();
};

istream& operator>>(istream &in, ps &x)
{
	cout<<"Nhap tu so: ";			in>>x.ts;
	cout<<"Nhap mau so: ";			in>>x.ms;
return in;
}
ostream& operator<<(ostream &out, ps y)
{
	out<<"Phan so la: "<<y.ts<<"/"<<y.ms<<endl;
return out;
}

ps ps::operator+(ps a)
{
	ps kq;
	kq.ts=ts*a.ms+ms*a.ts;
	kq.ms=ms*a.ms;
return kq;
}
ps ps::operator-(ps a)
{
	ps kq;
	kq.ts=ts*a.ms-ms*a.ts;
	kq.ms=ms*a.ms;
return kq;
}

ps ps::operator*(ps a)
{
	ps kq;
	kq.ts=ts*a.ts;
	kq.ms=ms*a.ms;
return kq;
}

ps ps::operator/(ps a)
{
	ps kq;
	kq.ts=ts*a.ms;
	kq.ms=ms*a.ts;
return kq;
}

float ps::operator--()
{
	return (float)ts/ms;//(float) là ep kieu;
}
int main()
{
	ps a,b;
	ofstream ghi("phanso.txt");
	cout<<"Nhap phan so a\n";			cin>>a;
	cout<<"nhap phan so b\n";			cin>>b;
	cout<<"Tong 2 "<<a+b;
	cout<<"gia tri cua tong 2 phan so la: "<<--(a+b)<<endl;
	ghi<<"Tong 2 "<<a+b;
	ghi<<"gia tri cua tong 2 phan so la: "<<--(a+b)<<endl;
	cout<<"\nHieu 2 "<<a-b;
	cout<<"gia tri cua hieu 2 phan so la: "<<--(a-b)<<endl;
	ghi<<"Hieu 2 "<<a-b;
	ghi<<"gia tri cua hieu 2 phan so la: "<<--(a-b)<<endl;
	cout<<"\nTich 2 "<<a*b;
	cout<<"gia tri cua tich 2 phan so la: "<<--(a*b)<<endl;
	ghi<<"Tich 2 "<<a*b<<endl;
	ghi<<"gia tri cua tich 2 phan so la: "<<--(a*b)<<endl;
	cout<<"\nThuong 2 "<<a/b;
	cout<<"gia tri cua thuong 2 phan so la: "<<--(a/b)<<endl;
	ghi<<"Thuong 2 "<<a/b<<endl;
	ghi<<"gia tri cua thuong 2 phan so la: "<<--(a/b)<<endl;
}


