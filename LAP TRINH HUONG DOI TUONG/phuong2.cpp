#include<bits/stdc++.h>
using namespace std;
class NSX;
class May; 
class MayTinh;
class NSX{
	private:
	char tennsx[30];
	char diachi[20];
	friend class May;
	friend class MayTinh; 
	friend void xoa(MayTinh *a, int n);
};
class May{
	protected:
		char nhanhieu[20];
		NSX x;
		float giathanh;
	public:
		void nhap();
		void xuat();	
	friend void sx(MayTinh *a,int n);
	friend void xoa(MayTinh *a, int n); 
};

class MayTinh:public May,NSX{
	float tocdo;
	float RAM;
	float HDD;
	public: 
		void nhap();
		void xuat();
	friend void sx(MayTinh *a, int n);
	friend void xoa(MayTinh *a, int n); 
};
void May::nhap(){
	cout<<"Nhan hieu: ";		fflush(stdin);			gets(nhanhieu);
	cout<<"Ten nha sx: ";		fflush(stdin);			gets(x.tennsx);
	cout<<"Dia chi :";			fflush(stdin);			gets(x.diachi);
	cout<<"giathanh: ";									cin>>giathanh;
}
void May::xuat(){
	cout<<"Nhan hieu: "<<nhanhieu<<endl;
	cout<<"Ten nha sx: "<<x.tennsx<<endl;
	cout<<"Dia chi: "<<x.diachi<<endl;
	cout<<"Gia thanh: "<<giathanh<<endl;
}
void MayTinh::nhap(){
	May::nhap();
	cout<<"Toc do: ";							cin>>tocdo;
	cout<<"Dung luong RAM: ";					cin>>RAM;
	cout<<"Dung luong HDD: ";					cin>>HDD;
		
}
void MayTinh::xuat(){
	May::xuat();
	cout<<"Toc do: "<<tocdo<<endl;
	cout<<"DUng luong RAM: "<<RAM<<endl;
	cout<<"Dung Luong HDD: "<<HDD<<endl;
}
void sx(MayTinh *a, int n){
	int i,j; 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(a[i].giathanh>a[j].giathanh){
				MayTinh tp=a[i];
				a[i]=a[j];
				a[j]=tp;
			}
		}
	}
		cout<<"\n---------------ds sau sx------------------"<<endl;
	for(i=0; i<n; i++){
		a[i].xuat(); 
	} 
}
void xoa(MayTinh *a, int n){
	int d=0;
	  for(int i=0; i<n; i++){
	  	if(strcmp(a[i].tennsx,"Intel")==0){
	  		d++; 
		  }
		  if(d!=0){
		  		if(strcmp(a[i].tennsx,"Intel")==0){
	  				for(int j=i+1; j<n; j++){
	  						MayTinh tp= a[i];
							  a[i]=a[j];
							  a[j]=tp; 
					  } 
					 n--;	
		  } 
	  } 
	   a[i].xuat(); 
	}
} 
int main(){
	MayTinh *a;
	int n;
	cout<<"\n Nhap so may tinh :";			cin>>n;
	a=new MayTinh[n]; 
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
	cout<<"\n ---------------------THONG TIN CUA CAC MAY TINH ----------------------"<<endl;
	for(int i=0; i<n; i++){
		a[i].xuat();
		cout<<endl;
	}
	cout<<endl;	
	sx(a,n);
	cout<<endl; 
	cout<<"------------------------ds sau xoa------------------" <<endl;
	xoa(a,n); 
	
}





