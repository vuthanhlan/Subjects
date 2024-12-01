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
		void nhap();
		friend ostream& operator<<(ostream &out, array x);
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

void array::nhap()
{
	cout<<"Nhap so phan tu trong mang: ";					cin>>n;
	a=new int[n];
	for(int i=0; i<n; i++)
	{
		cout<<"a["<<i<<"]= ";
		cin>>a[i];
	}
}
ostream& operator<<(ostream &out, array x)
{
	for(int i=0; i<x.n; i++){
		out<<x.a[i]<<" ";
	}
return out;
}
array array::operator++()
{
	int min=a[0];
	for(int i=1; i<n; i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]%2==0){
			a[i]=a[i]+min;
		}
		else{
			a[i]=a[i]+2;
		}
	}
return *this;
}
int main()
{
	array a;
	a.nhap();
	cout<<a;
	cout<<"\nMang sau khi cong them: "<<++a;
}

