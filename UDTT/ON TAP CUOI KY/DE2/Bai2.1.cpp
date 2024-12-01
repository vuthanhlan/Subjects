#include<bits/stdc++.h>
using namespace std;

int tinh(int arr[], int n){
	if(n==1 && arr[0]%2 != 0){
		return arr[0];
	}
	if(arr[n-1] %2 !=0){
		return arr[n-1]+ tinh(arr, n-1);
	}
	else{
		return tinh(arr, n-1);
	}
}

int main(){
	int n;
	do{
		cout<<"Nhap n= ";	cin>>n;
	}while(n<10);
	int arr[n];
	cout<<"Nhap gia tri cua cac phan tu mang"<<endl;
	for(int i=0; i<n; i++){
		cout<<"Nhap phan tu thu ["<<i<<"]= ";
		cin>>arr[i];
	}
	
	int count=0;
	for(int i=0; i<n; i++){
		if(arr[i]%2!= 0) count++;
	}
	if(count <=0) cout<<"KHONG CO SO LE TRONG MANG";
	else{
		int sum=tinh(arr,n);
		cout<<"Tong cac so le la: "<<sum;
	}
	
}

