#include<bits/stdc++.h>

using namespace std;

class tamthuc
{
	private:
		int a, b,c;
	public:
		tamthuc();
		tamthuc(int a1, int a2, int a3);
		friend ostream& operator<<(ostream &out, tamthuc y);
		tamthuc operator++();
		tamthuc operator+(tamthuc x);
		tamthuc operator-(tamthuc x);
};

tamthuc::tamthuc()
{
	a=b=c=0;
}
tamthuc::tamthuc(int a1, int a2, int a3)
{
	a=a1;
	b=a2;
	c=a3;
}
ostream& operator<<(ostream &out, tamthuc y)
{
	out<<"Tam thuc: "<<y.a<<"x^2+"<<y.b<<"x+"<<y.c<<endl;
return out;
}
tamthuc tamthuc::operator++()
{
	tamthuc kq;
	kq.a=-a;
	kq.b=-b;
	kq.c=-c;
return kq;
}
tamthuc tamthuc::operator+(tamthuc x)
{
	tamthuc kq;
	kq.a=a+x.a;
	kq.b=b+x.b;
	kq.c=c+x.c;
return kq;
}
tamthuc tamthuc::operator-(tamthuc x)
{
	tamthuc kq;
	kq.a=a-x.a;
	kq.b=b-x.b;
	kq.c=c-x.c;
return kq;
}
int main()
{
	tamthuc a(3,5,9);
	tamthuc b(1,2,3);
	ofstream ghi("tamthuc.txt");
	cout<<"doi dau "<<++a;
	ghi<<"doi dau "<<++a;
	cout<<"doi dau "<<++b;
	ghi<<"doi dau "<<++b;
	cout<<"Tong 2 "<<a+b;
	ghi<<"Tong 2 "<<a+b;
	cout<<"Hieu 2 "<<a-b;
	ghi<<"Hieu 2 "<<a-b;
}






