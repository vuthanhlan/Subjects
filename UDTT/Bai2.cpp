#include<bits/stdc++.h>
using namespace std;
struct Fan{
	string brand;
	string color;
	int price;
};

void sapxep(Fan fan[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(fan[i].price>fan[j].price){
				Fan temp=fan[i];
				fan[i]=fan[j];
				fan[j]=temp;
			}
		}
	}
}
void greedyAlgorithm(Fan fan[], int n, int p){
	int total=0;
	int count=0;
	sapxep(fan,n);
	for(int i=0; i<n; i++){
		if(total+fan[i].price<=p){
			total+=fan[i].price;
			count++;
		}else{
			break;
		}
	}
	cout<<"Can ban it nhat "<<count<<" chiec quat ban: "<<endl;
	for(int i=0; i<count;i++)
		cout<<"Hang sx: "<<fan[i].brand<<"- price: "<<fan[i].price<<endl;
}
int main(){
	int n= 6;
	int p=1000000;
	Fan fan[10]={
		{"Hang A", "Mau den",500000},
		{"Hang B", "Mau hong",800000},
		{"Hang C", "Mau trang",700000},
		{"Hang D", "Mau nau",900000},
		{"Hang E", "Mau do",400000},
		{"Hang F", "Mau cam",1000000},
	};
	greedyAlgorithm(fan,n,p);
}
	





