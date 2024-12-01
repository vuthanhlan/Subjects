#include<bits/stdc++.h>

using namespace std;

class sp
{
	private:
		int ao, thuc;
	public:
		sp();
		sp(int a, int b);
		friend ostream& operator<<(ostream & out, sp y);
		sp operator+(sp a);
		sp operator-(sp a);
};

sp::sp()
{
	ao=thuc=0;
}
sp::sp(int a, int b)
{
	ao=a;
	thuc=b;
}

ostream& operator<<(ostream & out, sp y)
{
	out<<"So phuc: "<<y.thuc<<"+i*"<<y.ao<<endl;
return out;
}
sp sp::operator+(sp a)
{
	sp kq;
	kq.ao=ao+a.ao;
	kq.thuc=thuc+a.thuc;
return kq;
}
sp sp::operator-(sp a)
{
	sp kq;
	kq.ao=ao-a.ao;
	kq.thuc=thuc-a.thuc;
return kq;
}
int main()
{
	sp SP1(5,8);
	sp SP2(1,2);
	ofstream ghi("sophuc.txt");
	cout<<"SP1= "<<SP1;
	ghi<<"SP1= "<<SP1;
	cout<<"SP2= "<<SP2;
	ghi<<"SP2= "<<SP2;
	cout<<"\nSP3= "<<SP1+SP2;
	ghi<<"\nSP3= "<<SP1+SP2;
	cout<<"SP4= "<<SP1-SP2;
	ghi<<"SP4= "<<SP1-SP2;
}



