#include<bits/stdc++.h>
using namespace std;
void next_config(int x[],int n, int i){
	x[i]=1;
	i++;
	while(i<=n){
		x[i]=0;
		i++;
	}
}
void view_config(int x[], int n){
	for(int i=1; i<=n; i++){
		if(x[i]==0)
			cout<<"a";
		else cout<<"b";
	}cout<<endl;
}
void listing_configs(int n){
	int i;
	int x[n+1]={0};
	do{
		view_config(x,n);		
		i=n;
		while(i>0 && x[i]==1)
			i--;
		if(i>0)
			next_config(x,n,i);
	}while(i>0);
}
int main()
{
	int n;
	cout<<"Nhap n= ";	cin>>n;
	listing_configs(n);
}



