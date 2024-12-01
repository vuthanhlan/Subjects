#include<bits/stdc++.h>
#define MAX 100
using namespace std;

struct GoiHang{
	int stt;
	int m;
	int v;
};
void nhapds(GoiHang a[], int n){
	for(int i=1; i<=n; i++){
		a[i].stt=i+1;
		cout<<"Goi hang: "<<i<<endl;
		cout<<"KHOI LUONG: ";	cin>>a[i].m;
		cout<<"GIA TRI: ";		cin>>a[i].v;
	}
}

void MegerSort(GoiHang a[], int l, int r){
	if(r>l){
		int m=(l+r)/2;
		MegerSort(a,l,m);
		MegerSort(a,m+1,r);
		
		GoiHang b[100];
		for(int i=m; i>=l; i--){
			b[i]=a[i];
		}
		
		for(int j=m+1; j<=r; j++){
			b[r+m+1-j]= a[j];
		}
		
		int i=l,j=r;
		for(int k=l; k<=r; k++){
			if(b[i].v < b[j].v){
				a[k]=b[i];
				i++;
			}
			else{
				a[k]=b[j];
				j--;
			}
		}
	}
}

int thamlam(GoiHang a[],int n, float C, float*& b){
	MegerSort(a,1,n);
	int count=0;
	float sum=0.0;
	int index=0;
	while(index<n && sum+a[index].v <=C){
		sum += a[index].v;
		count++;
		index++;
	}
	for(int i=0; i<count; i++){
		b[i]=a[i].v;
	}
	return count;
}
void luuphuongan(GoiHang a[], int n, int M,int kq[][MAX]){
	for(int j = 0; j <= M; j++) kq[0][j]=0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= M; j++){
			kq[i][j] = kq[i-1][j];
			if(a[i].m <= j ){
				int temp= a[i].v + kq[i-1][j-a[i].m];
				if(kq[i][j] < temp){
					kq[i][j] = temp;
				}
			}
		}
	}
}

void Inphuongan(GoiHang a[], int n, int M,int kq[][MAX]){
	cout<<"GIA TRI LON NHAT CO THE LAY: "<<kq[n][M]<<endl;
	int i=n, j=M;
	int dem=0;
	cout<<"Gia tri cua cac goi hang duoc lay la: ";
	while(i != 0){
		if(kq[i][j] != kq[i-1][j]){
			cout<<a[i].v<<" ";
			j= j- a[i].m;
			dem++;
		}
		i--;
	}
	if(dem == 0) cout<<"KHONG LAY DUOC GOI HANG NAO!";
}
int main(){
	int n;
	cout<<"Nhap so luong goi: ";	cin>>n;
	GoiHang a[n+1];
	nhapds(a,n);
	
	float C=9;
	float* b;
	int D=thamlam(a,n,C,b);
	if(D==0) cout<<"KHONG LAY DUOC GOI HANG NAO!"<<endl;
	else{
		cout<<"Lay duoc nhieu nhat "<<D<<" goi hang"<<endl;
		for(int i=0; i<D; i++){
			if(b[i] == a[i].v){
				cout<<a[i].stt;
			}
		}
	}
	int M;
	cout<<"Nhap M: ";	cin>>M;
	int kq[n+1][MAX];
	luuphuongan(a,n,M,kq);
	Inphuongan(a,n,M,kq);
}

