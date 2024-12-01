#include<bits/stdc++.h>
using namespace std;

class VECTOR{
	private:
		int n;
		float *a;
	public:
		VECTOR();
		VECTOR(int x);
		friend istream& operator>>(istream &in, VECTOR &x);
		friend ostream& operator<<(ostream &out, VECTOR x);
		float operator++();
		float operator--();	
};
VECTOR::VECTOR()
{
	n=0;
	a=NULL;
}
VECTOR::VECTOR(int x)
{
	n=x;
	a=new float[n];
	for(int i=0; i<n; i++){
		a[i]=0;
	}
}
istream& operator>>(istream &in, VECTOR &x)
{
	cout<<"Nhap so phan tu vector: ";			in>>x.n;
	x.a=new float[x.n];
	for(int i=0; i<x.n; i++){
		cout<<"vector["<<i<<"]= ";	in>>x.a[i];
	}
return in;
}
ostream& operator<<(ostream &out, VECTOR x)
{
	for(int i=0; i<x.n ;i++){
		out<<x.a[i]<<" ";
	}
return out;
}
float VECTOR::operator--()
{
	float min=a[0];
	for(int i=0; i<n; i++){
		if(a[i]<min){
			min=a[i];
		}
	}
return min;
}
float VECTOR::operator++()
{
	float max=a[0];
	for(int i=0; i<n; i++){
		if(a[i]>max){
			max=a[i];
		}
	}
return max;
}
int main()
{
	VECTOR a;
	cin>>a;
	cout<<a;
	cout<<"\nGia tri nho nhat: "<<--a<<endl;
	cout<<"Gia tri lon nhat: "<<++a<<endl;
}



