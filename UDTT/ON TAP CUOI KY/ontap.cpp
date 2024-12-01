#include<bits/stdc++.h>
#define MAX 100
using namespace std;

struct GoiHang{
	int m;
	int v;
};

void khoitao(GoiHang a[]){
	a[1].m=5;
	a[1].v=2;

	a[2].m=8;
	a[2].v=6;
	
	a[3].m=8;
	a[3].v=4;
	
	a[4].m=8;
	a[4].v=9;
	
	a[5].m=1;
	a[5].v=3;
}

void luuphuongan(GoiHang a[], int SL, int M, int kq[][MAX]){
	for(int j=0; j<=M; j++) kq[0][j]=0;
	
	for(int i=1; i<=SL; i++)
	{
		for(int j=0; j<=M; j++){
			kq[i][j]=kq[i-1][j];
			if(a[i].m <=j ){
				int temp= a[i].v + kq[i-1][j-a[i].m];
				if(kq[i][j] < temp)
					kq[i][j]=temp;
			}
		}
	}
}

void Inphuongan(GoiHang a[], int SL, int M, int kq[][MAX]){
	cout<<"Gia tri lon nhat co the lay: "<<kq[SL][M];
	int i=SL,j=M;
	int dem=0;
	cout<<"\nGia tri cac goi da lay la: ";
	while(i!=0){
		if(kq[i][j] != kq[i-1][j]){
			cout<<a[i].v<<" ";
			j=j-a[i].m;
			dem++;
		}
	}
	if(dem==0) cout<<"KHONG LAY DUOC GOI HANG NAO!"<<endl;
}

int main(){
	int SL=5;
	GoiHang a[SL];
	khoitao(a);
	int kq[SL+1][MAX];
	int M=5;
	luuphuongan(a,SL,M,kq);
	Inphuongan(a,SL,M,kq);
}
