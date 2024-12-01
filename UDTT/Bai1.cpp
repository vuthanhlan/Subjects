#include<bits/stdc++.h>
#define MAX 100
using namespace std;
struct Package{
	int weight;
	int value;
};
void knapsack(int dp[][MAX], int n, int m, Package packages[]){

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
			//cout<<"Goi hang thu "<<i<<": khoi luong= "<<packages[i-1].weight<<", Gia tri = "<<packages[i-1].value<<endl;
			// dang xet goi hang thu i thi ghi moi i thoi
			cout<<"Goi hang thu "<<i<<": khoi luong= "<<packages[i].weight<<", Gia tri = "<<packages[i].value<<endl;
			j=j-packages[i].weight;
			numPackages++;
		}
		i--;
	}
	cout<<"Tong so goi da lay: "<<numPackages<<endl;
}	
	

int main(){
	int max=6;
	// Package packages[max]= do bai thay chay tu chi so 1 nen kich thuoc mang nen tang len 1
	Package packages[max + 1]=
	{
//		{3,4},
//		{6,5},
//		{2,2},
//		{7,6},
//		{1,1},
//		{5,3}
		
		{0,0}, // do chay tu 1 nen phan tu thu 0 coi nhu la 0
		{12,4},
		{2,2},
		{1,1},
		{1,2},
		{4,10}
	};
	// int n=sizeof(packages); sizeof tra ve kich thuoc byte cua mang (m in thu n thi no ra 48)
	int n = sizeof(packages) / sizeof(packages[0]); 
	int m;
	// int dp[n][MAX]; tuong tu ly do tren nen tang n len 1
	int dp[n+1][MAX];
	cout<<"Nhap khoi luong toi da cua tui: "; cin>>m;
	knapsack(dp,n,m,packages);
	result(dp,n,m,packages);
}




