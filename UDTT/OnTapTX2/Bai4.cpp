#include<bits/stdc++.h>
#define MAX 100
using namespace std;
struct Phone{
	string brand;
	int size;
	int price;
};
void nhapds(Phone phone[], int sl){
	cout<<"Nhap thong tin cho dien thoai"<<endl;
	for(int i=1; i<=sl; i++){
		cout<<"Nhap dien thoai thu "<<i<<endl;
		cout<<"Brand: "; cin>>phone[i].brand;
		cout<<"Size: "; cin>>phone[i].size;
		cout<<"Price: ";	cin>>phone[i].price;	
	}
}
void algorithm(int sl, int kt, Phone phone[], int F[][MAX]){
	for(int j = 0; j <= sl; j++) F[0][j] = 0;
	
	for(int i = 1; i <= sl; i++){
		for(int j = 0; j<= kt; j++){
			F[i][j]=F[i-1][j];
			if(phone[i].size<=j){
				int temp= phone[i].price+ F[i-1][j-phone[i].size];
				if(F[i][j]<temp)
					F[i][j]=temp;
			}
		}
	}
}
void result(int sl, int kt, Phone phone[], int F[][MAX]){
	cout<<"\n\nGia tri lon nhat co the lay: "<<F[sl][kt]<<endl;
	int i=sl,j=kt;
	int dem=0;
	cout<<"----DANH SACH DIEN THOAI CO THE LAY-----"<<endl;	
	while(i!=0){
		if(F[i][j]!=F[i-1][j]){
			cout<<"Brand: "<<phone[i].brand;
			cout<<" -Price: "<<phone[i].price<<endl;
			j=j-phone[i].size;
			dem++;
		}
		i--;
	}
	if(dem<0) cout<<"Khong lay duoc dien thoai nao!";
}
int main(){
/*	int sl,kt;
	cout<<"Nhap so luong tui: ";	cin>>sl;
	
	Phone phone[sl+1];
	nhapds(phone,sl);
*/
	int sl=7;
	Phone phone[sl+1];
	phone[0]={"O",0,0};
	phone[1]={"A",3,4};
	phone[2]={"B",6,5};
	phone[3]={"C",2,2};
	phone[4]={"D",7,6};
	phone[5]={"E",1,1};
	phone[6]={"F",5,3};
	int kt;
	cout<<"Nhap kich thuoc tui: ";	cin>>kt;
	
	int F[sl+1][MAX];
	algorithm(sl,kt,phone,F);
	result(sl,kt,phone,F);
	return 0;
}
/*
6
a
3
4
b
6
5
c
2
2
d
7
6
e
1
1
f
5
3
12 
*/
