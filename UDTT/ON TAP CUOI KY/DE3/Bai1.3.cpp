#include<bits/stdc++.h>

using namespace std;

float chiadetri(float a[], int l, int r){
	if(l == r ){
		if(a[l]>0) 
			return a[l];
		else return 0;
	}
	else{
		int m=(l+r)/2;
		float sumleft = chiadetri(a,l,m);
		float sumright = chiadetri(a,m+1,r);
		return sumleft + sumright;
	}
}
int main(){
	int n;
	do{
		cout<<"Nhap n= ";	cin>>n;
	}while(n<8);
	
	float* a=new float[n];
	cout<<"Nhap gia tri cac phan tu mang"<<endl;
	for(int i=0; i<n; i++){
		cout<<"Nhap a["<<i<<"]= ";
		cin>>a[i];
	}
	
	float sum= chiadetri(a,0,n-1);
	if(sum == 0) cout<<"Khong co so duong nao trong mang !"<<endl;
	else cout<<"Tong so duong trong mang"<<sum<<endl;
}

