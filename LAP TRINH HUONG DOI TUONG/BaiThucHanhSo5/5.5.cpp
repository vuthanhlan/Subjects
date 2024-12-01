#include<bits/stdc++.h>

using namespace std;
class array
{
	private:
		int *a;
		int n;
	public:
		array();
		array(int x);
		friend istream& operator>>(istream &in, array &x);
		friend ostream& operator<<(ostream &out, array x);
		array operator--();
		array operator++();
		
};

array::array()
{
	n=0;
	a=NULL;
}
array::array(int x)
{
	n=x;
	a=new int[n];
	for(int i=0; i<n; i++){ 
		a[i]=0;
	}
}
istream& operator>>(istream &in, array &x)
{
	cout<<"Nhap so phan tu trong mang: ";			in>>x.n;
	x.a=new int[x.n];
	for(int i=0; i<x.n;i++){
			cout<<"a["<<i<<"]= ";
			in>>x.a[i];
	}
}
ostream& operator<<(ostream &out, array x)
{
	for(int i=0; i<x.n; i++){
		out<<x.a[i]<<" ";
	}
}
array array::operator++()
{
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){
				int tmp =a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
return *this;
}
array array::operator--()
{
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++)
		{
			if(a[i]<a[j]){
				double tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
return *this;
}
int main()
{
	array a;
	cin>>a;
	cout<<a;
	cout<<"\nMang sau khi sap xep tang dan: "<<++a;
	cout<<"\nMang sau khi sap xep giam dan: "<<--a;
}
