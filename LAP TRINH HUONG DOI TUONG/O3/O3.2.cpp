#include<iostream>
#include<fstream>

using namespace std;

class HTG
{
	private:
		int a,b,c;
	public:
		float operator++();
		friend istream& operator>>(istream &in,HTG &x);
		friend ostream& operator<<(ostream &out,HTG y);
};
float HTG::operator++()
{
	return (float)(a+b+c);
}
istream& operator>>(istream& in,HTG &x)
{
	cout<<"canh thu nhat: ";		in>>x.a;
	cout<<"canh thu hai: ";		in>>x.b;
	cout<<"canh thu ba: ";		in>>x.c;
return in;
}

ostream& operator<<(ostream& out,HTG y)
{
	out<<"canh thu nhat: "<<y.a<<endl;
	out<<"canh thu hai: "<<y.b<<endl;
	out<<"canh thu ba: "<<y.c<<endl;
	out<<"chu vi tam giac: "<<y.a+y.b+y.c<<endl;
return out;
}

int main()
{
	HTG P,Q;
	ofstream ghi("INOUT.txt");
	cout<<"\ntam giac P\n ";	cin>>P;
	cout<<"\nTam giac Q:\n ";	cin>>Q;
	cout<<"\nthong tin tam giac P:\n"<<P<<endl;;
	ghi<<"\nthong tin tam giac P:\n"<<P<<endl;
	cout<<"Thong tin tam giac Q:\n"<<Q<<endl;
	ghi<<"Thong tin tam giac Q:\n"<<Q<<endl;
	
}


