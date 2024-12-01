#include<bits/stdc++.h>
#define MAX 100
using namespace std;

struct Quat{
	string hangsx;
	string mausac;
	int giaban;
};

void sapxeptang(Quat a[], int left, int right){
	if(left<right){
		int mid=(left+right)/2;
		int t=a[mid].giaban;
		int i=left,j=right;
		do{
			while(a[i].giaban < t) i++;
			while(a[j].giaban >t ) j--;
			if(i<=j){
				Quat tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
				i++;
				j--;
			}
		}while(i<=j);
		sapxeptang(a,left,j);
		sapxeptang(a,i,right);
	}
}
void muaquat(Quat a[], int sl, int tien, int s[]){
	sapxeptang(a,0,sl-1);
	for(int i=0; i<sl; i++) s[i]=0;
	int i=0, idx=0;
	while(tien>0 && i<sl){
		if(tien>= a[i].giaban){
			s[idx]=i+1;
			tien=tien-a[i].giaban;
			idx++;
		}
		i++;
	}
}
int main(){
	int sl=6;
	Quat a[sl+1];
	a[0]={"A","den",2000};
	a[1]={"B","den",7000};
	a[2]={"C","den",4000};
	a[3]={"D","den",5000};
	a[4]={"E","den",6000};
	a[5]={"F","den",9000};
	int tien;
	cout<<"Nhap so luong tien: "; cin>>tien;
	int s[sl];
	int dem=0;
	for(int i=0; i<sl; i++){
		if(s[i]!=0){
			dem++;
			cout<<"Quat thu "<<dem<<endl;
			cout<<"HANG SX: "<<a[i].hangsx<<endl;
			cout<<"GIA BAN: "<<a[i].giaban<<endl;
		}
	}
	if(dem == 0) cout<<"Khong mua duoc quat nao!";
	else cout<<"So luong quat can ban it nhat la: "<<dem;
}
/*
A
den
2000
B
den
7000
C
den
4000
D
den
5000
E
den
6000
F
den
9000
*/
