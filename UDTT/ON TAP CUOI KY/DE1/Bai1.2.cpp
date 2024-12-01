#include<bits/stdc++.h>
using namespace std;

void MergeSort(float a[], int l, int r){
	if(r>l){
		int m=(l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		float c[100];
		for(int i=m; i>=l; i--)
			c[i]=a[i];
			
		for(int j=m+1; j<=r; j++){
			c[r+m+1-j]=a[j];
		}
		
		int i=l; int j=r;
		for(int k=l; k<=r; k++){
			if(c[i] < c[j]){
				a[k]= c[i]; 
				i++;
			}
			else{
				a[k]=c[j];
				j--;
			}
		}
		
	}
}
int dem(float a[], int n, int C, float& M, float*& b){
	MergeSort(a,0,n-1);
	int count=0;
	float sum=0.0;
	int index=0;
	while(index<n && sum + a[index] <= C){
		sum += a[index];
		count++;
		index++;
	}
	
	M=sum;
	b=new float[count];
	for(int i=0; i<count; i++){
		b[i]=a[i];
	}
	return count;
}

int Find_Char(char target, string str) 
{
    for(int i = 0; i < str.length(); i++) 
	{
        if (str[i] == target) return i;    	
    }
    return -1;  
}

int B_M_H(string con, string cha)
{
	int len_con = con.length(); 
	int i = len_con - 1;
	while(i < cha.length())
	{
		int x = len_con - 1;
		while(cha[i] == con[x] && x >= 0) {
			i--; x--;
		}
		if(x < 0) {
			return 1; 
			i = i + len_con + 1;
		}
		else {
			int k = Find_Char(cha[i], con);
			if(k < 0) i = i + len_con;
			else i = i + len_con - k - 1;
		}
	}
	return 0;
}
int main(){
	int n;
	cout<<"Nhap so phan tu mang: ";	cin>>n;
	float C;
	string P;
	string Q;
	if(n<8){
		cout<<"Nhap n>=8";
		return 0;
	}
	float* a= new float[n];
	cout<<"Nhap gia tri cua mang a:"<<endl;
	for(int i=0; i<n; i++){
		cout<<"Nhap phan tu thu "<<i<<": ";
		cin>>a[i];
	}
	cout<<"Nhap gia tri C: "; cin>>C;
	float M;
	float* b;
	int D=dem(a,n,C,M,b);
	cout<<"So luong phan tu nhieu nhat co the lay trong day a la: "<<D<<endl;
	cout<<"Gia tri M la: "<<M<<endl;
	cout<<"Cac phan tu da lay: ";
	for(int i=0; i<D; i++){
		cout<<b[i]<<" ";
	}
	cout<<"\n"<<endl;
	cout<<"Nhap chuoi P: ";			fflush(stdin);		getline(cin,P);
	cout<<"Nhap chuoi Q: ";			fflush(stdin);		getline(cin,Q);
	if(B_M_H(Q,P)){
		cout<<"Chuoi Q la chuoi con cua chuoi P"<<endl;
	}
	else cout<<"Chuoi Q KHONG la chuoi con cua chuoi P"<<endl;
}


