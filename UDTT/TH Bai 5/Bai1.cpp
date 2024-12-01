#include<bits/stdc++.h>
#define MAX 100
using namespace std;
struct Package{
	int weight;
	int value;
};
void knapsack(int dp[][MAX], int n, int m, Package packages[]){
/*	int dp[n+1][m+1];
	for(int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			if(i==0||j==0)
				dp[i][j]=0;
			else if(packages[i-1].weight<=j)
				dp[i][j]=max(packages[i-1].value +dp[i-1][j-packages[i-1].weight],dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}*/
	for(int j=0; j<=m;j++){
		dp[0][j]=0;
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m;j++){
			dp[i][j]=dp[i-1][j];
			if(packages[i].weight<=j){
				int temp=packages[i].value+dp[i-1][j-packages[i].weight];
				if(dp[i][j]<temp)
					dp[i][j]=temp;
			}
		}
	}
	
}
void result(int dp[][MAX], int n, int m, Package packages[]){
	int totalValue= dp[n][m];
	cout<<"Tong so gia tri dat duoc: "<<totalValue<<endl;
	int i=n;
	int j=m;
	int numPackages=0;
	while(i>0 && j>0){
		if(dp[i][j] != dp[i-1][j]){
			cout<<"Goi hang thu "<<i<<": khoi luong= "<<packages[i-1].weight<<", Gia tri = "<<packages[i-1].value<<endl;
			j=j-packages[i-1].weight;
			numPackages++;
		}
		i--;
	}
	cout<<"Tong so goi da lay: "<<numPackages<<endl;
}	
	

int main(){
	int max=6;
	Package packages[max]=
	{
		{3,4},
		{6,5},
		{2,2},
		{7,6},
		{1,1},
		{5,3}
	};
	int n=sizeof(packages);
	int m;
	int dp[n][MAX];
	cout<<"Nhap khoi luong toi da cua tui: "; cin>>m;
	knapsack(dp,n,m,packages);
	result(dp,n,m,packages);
}




