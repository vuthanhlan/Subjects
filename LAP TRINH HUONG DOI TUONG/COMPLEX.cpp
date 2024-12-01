#include<bits/stdc++.h>

using namespace std;

class COMPLEX
{
	private:
		int pao, pthuc;
	public:
		COMPLEX();
		COMPLEX(int a, int b);
		friend istream& operator>>(istream &in, COMPLEX &x);
		friend ostream& operator<<(ostream &out, COMPLEX y);
		COMPLEX operator+(COMPLEX a);
		
};
COMPLEX::COMPLEX()
{
	pao=pthuc=0;
}
COMPLEX::COMPLEX(int a, int b)
{
	pthuc=a;
	pao=b;
}
istream& operator>>(istream &in, COMPLEX &x)
{
	cout<<"Nhap phan ao: ";			in>>x.pao;
	cout<<"Nhap phan thuc: ";		in>>x.pthuc;
return in;
}
ostream& operator<<(ostream &out,COMPLEX y)
{
	out<<"So Phuc: "<<y.pthuc<<"+ "<<y.pao<<"i "<<endl;
}
COMPLEX COMPLEX::operator+(COMPLEX a)
{
	COMPLEX kq;
	kq.pthuc=pthuc+a.pthuc;
	kq.pao=pao+a.pao;
return kq;
}
int main()
{
	COMPLEX a[100];
	int n;
	cout<<"Nhap so phan tu so ohuc trong mang: ";		cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<"Cac so phuc vua nhap la: "<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
	COMPLEX sum;
	for(int i=0; i<n; i++)
	{
		sum=sum+a[i];
	}
	cout<<"tong cac so phuc la: "<<sum;
	
}


