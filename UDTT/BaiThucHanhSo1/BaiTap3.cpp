#include<bits/stdc++.h>
using namespace std;
void next_config(int x[], int k, int i){
	x[i]+=1;
	i++;
	while(i<=k){
		x[i]=x[i-1]+1;
		i++;
	}
}
void view_config(int x[], int n){
	for(int i=1;i<=n; i++){
		cout<<x[i]<<" ";
	}cout<<endl;
}
void listing_configs(int n, int k){
	int i;
	int x[k+1]={0};
	for(int i=1; i<=n; i++){
		x[i]=i;
	}
	do{
		view_config(x,k);
		i=k;
		while(i>0 && x[i]==n-k+i){
			i--;
		}
		if(i>0)
			next_config(x,k,i);
	}while(i>0);
}
int main(){
	int n,k;
	cout<<"Nhap n= ";	cin>>n;
	cout<<"Nhap k= ";	cin>>k;
	listing_configs(n,k);
}
