#include<bits/stdc++.h>

using namespace std;
class Array{
	private:
		int *a;
		int n;
	public:
		Array();
		Array(int x);
		void nhap();
		friend ostream& operator<<(ostream &out, Array x);
		Array operator++();
};
Array::Array()
{
	n=0;
	a=NULL;
}
Array::Array(int x)
{
	x=n;
	a=new int[n];
	for(int i=0; i<n; i++){
		a[i]=0;
	}
}
void Array::nhap()
{
	cout<<"Nhap so phan tu mang: ";			cin>>n;
	a=new int[n];
	for(int i=0; i<n; i++){
		cout<<"a["<<i<<"]= ";  cin>>a[i];
	}
}

ostream& operator<<(ostream &out, Array x)
{
	for(int i=0; i<x.n; i++){
		out<<x.a[i]<<" ";
	}
return out;
}

bool kt(int a[100], int n){
	for(int i=0; i<n; i++){
		if(a[i]%2==0) return true;
	}
	return false;
	
}
Array Array::operator++()
{
	int min=a[0];
	for(int i=1; i<n; i++){
		if(a[i]<min){
			min=a[i];
		}
	}
	
	if(kt(a,n)==true){
		for(int i=0; i<n; i++){
			a[i]=a[i]+min;
		}
	}
	else{
		for(int i=0; i<n; i++){
			a[i]=a[i]+2;
		}
	}
return *this;
}
int main()
{
	Array a;
	a.nhap();
	cout<<++a;
}



