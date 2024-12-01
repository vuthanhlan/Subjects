#include<bits/stdc++.h>

using namespace std;

/*void MergeSort(int a[], int l, int r){
	if(r>l){
		int m=(l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		int b[100];
		for(int i=m; i>=l; i--){
			b[i] = a[i];
		}
		
		for(int j=m+1; j<=r; j++){
			b[r+m+1-j]=a[j];
		}
		
		int i=l,j=r;
		for(int k=l; k<=r; k++){
			if(b[i]<b[j]){
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
*/
int dem(int a[], int n, int C, int& M, int*& b){
//	MergeSort(a,0,n-1);
	int count=0;
	int sum=0;
	int index=0;
	while(index<n && sum+a[index] <= C){
		sum += a[index];
		count++;
		index++;
	}
	
	M=sum;
	b=new int[count];
	for(int i=0; i<count; i++){
		b[i] = a[i];
	}
	return count;
}

int B_M_H(string con, string cha, int S1[])
{
	int idx = 0, len_con = con.length(), i = len_con - 1;
	while(i < cha.length())
	{
		int x = len_con - 1;
		while(cha[i] == con[x] && x >= 0) {
			i--; x--;
		}
		if(x < 0) {
			S1[idx] = i+1; idx++;
			i = i + len_con + 1;
		}
		else {
			int k = con.find(cha[i]);
			if(k < 0) i = i + len_con;
			else i = i + len_con - k - 1; 
		}
	}
	return idx;
}
int main(){
/*	int n;
	do{
		cout<<"Nhap n= ";	cin>>n;
	}while(n<8);
	
	int* a=new int[n];

	cout<<"Nhap gia tri cua cac phan tu"<<endl;
	for(int i=0; i<n; i++){
		cout<<"Nhap phan tu thu["<<i<<"]= ";
		cin>>a[i];
	}*/
	int n=8;
	int a[n]={2,5,6,7,8,9,10,12};
	
	int M, C;
	int* b;
	cout<<"Nhap gia tri C: ";	cin>>C;
	int D=dem(a,n,C,M,b);
	cout<<"Gia tri M= "<<M<<endl;
	cout<<"Lay duoc nhieu nhat "<<D<<" phan tu trong day a"<<endl;
	cout<<"Cac phan tu duoc lay: ";
	for(int i=0; i<D; i++){
		cout<<b[i]<<" ";
	}
	cout<<"\n"<<endl;
	string P, Q;
/*	cout<<"Nhap chuoi P: ";		fflush(stdin);		getline(cin,P);
	cout<<"Nhap chuoi Q: ";		fflush(stdin);		getline(cin,Q);*/
	P="Vu Thanh Lan Lan";
	Q="Lan";
	
	int S[10]={0};
	cout<<"So lan Chuoi Q xuat hien trong Chuoi P la: "<<B_M_H(Q,P,S)<<endl;
	cout<<"Cac vi tri xuat hien cua Q trong P la: ";
	for(int i=0 ;i<10; i++){
		if(S[i] != 0) cout<<S[i]<<" ";
	}	
}

