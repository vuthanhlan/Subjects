#include<bits/stdc++.h>
using namespace std;


class PTB2
{
	private:
		float a,b,c;
	public:	
		friend istream& operator>>(istream &in, PTB2 &x);
		friend ostream& operator<<(ostream &out, PTB2 x);
		PTB2 operator-(PTB2 y);
		float operator--();
};
istream& operator>>(istream &in, PTB2 &x)
{
	cout<<"Nhap a: ";			in>>x.a;
	cout<<"nhap b: ";			in>>x.b;
	cout<<"Nhap c: ";			in>>x.c;
return in;
}
ostream& operator<<(ostream &out, PTB2 x)
{
	out<<x.a<<"x^2 +"<<x.b<<"x +"<<x.c<<endl;
return out;
}
PTB2 PTB2::operator-(PTB2 y)
{
	 PTB2 kq;
	 kq.a=a-y.a;
	 kq.b=b-y.b;
	 kq.c=c-y.c;
return kq;
}
float PTB2::operator--()
{
	return (a+b+c)/3;
}
int main()
{
	PTB2 P,Q;
	fstream ghi("De1.txt");
	cout<<"Nhap PTB2 P "<<endl;			cin>>P;
	cout<<"Nhap PTB2 Q "<<endl;			cin>>Q;
	PTB2 K=P-Q;
	cout<<"K= "<<K;
	ghi<<"K= "<<K;
	cout<<"Gia tri tb cua he so cua PTB2 K la: "<<--K<<endl;
	ghi<<"Gia tri tb cua he so cua PTB2 K la: "<<--K<<endl;
}

