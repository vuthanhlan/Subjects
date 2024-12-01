#include<bits/stdc++.h>
using namespace std;

float chiadetri(float a[], int left, int right)
{
	if(left == right)
		return a[left];
		
	int mid=(left + right)/2;
	float sumleft=chiadetri(a,left,mid);
	float sumright=chiadetri(a,mid+1,right);
	
	return sumleft + sumright;
}
int main(){
	int n;
	cout<<"Nhap so phan tu mang: ";	cin>>n;
	if(n<10){
		cout<<"Nhap so phan tu >=10";
		return 0;
	}
	float* a= new float[n];
	cout<<"Nhap phan tu cua mang:\n";
	for(int i=0; i<n; i++){
		cout<<"phan tu thu "<<i<<": ";
		cin>>a[i];
	}
	float sum= chiadetri(a,0,n-1);
	cout<<"Tong: "<<sum<<endl;
	delete[] a;
}



