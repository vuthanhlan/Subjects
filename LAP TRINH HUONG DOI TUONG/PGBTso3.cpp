#include<iostream>
#include<fstream>
using namespace std;

class PS
{
	private:
		int ts,ms;
	public:
		PS();
		PS(int a, int b);
		PS operator+(PS c);
		float operator++();
		friend istream& operator>>(istream& in, PS &x);
		friend ostream& operator<<(ostream& out, PS y);
};

PS::PS()
{
	ts=1;
	ms=2;
}
PS::PS(int a, int b)
{
	ts=a;
	ms=b;
}
PS PS::operator+(PS c)
{
	PS kq;
	kq.ts=ts*c.ts;
	kq.ms=ms*c.ms;
return kq;
}
float PS::operator++()
{
	return (float)ts/ms;
}
istream& operator>>(istream& in, PS &x)
{
	cout<<"tu so: ";		in>>x.ts;
	cout<<"mau so: ";		in>>x.ms;
return in;
}

ostream& operator<<(ostream& out, PS y)
{
	out<<y.ts<<"/"<<y.ms;
return out;
}

int main()
{
	PS a,b;
	ofstream ghi("PHANSO.txt");
	cout<<"\nNhap phan so a:\n ";  cin>>a;
	cout<<a<<endl;
	
//	ghi<<a;
	cout<<"\nNhap phan so b:\n ";	cin>>b;
	cout<<b<<endl;
	
//	ghi<<b;
	PS k;
	k=a+b;
	cout<<"\n Tich hai phan so: "<<k<<endl;
	cout<<"\n gia tri cua ps la tich cua 2 ps vua nhap: "<<++k;
	ghi<<"\gia tri cua ps la tich cua 2 ps vua nhap: "<<++k;
	
}

