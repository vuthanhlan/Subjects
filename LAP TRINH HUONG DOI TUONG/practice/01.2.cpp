//O1.2
#include<bits/stdc++.h>
using namespace std;
class sinhvien;
class mon;
class phieu;
class sinhvien{
	private:
		char masv[20];
		char tensv[30];
		char lop[20];
		int khoa;
	public:
		void nhap();
		void xuat();
	friend class phieu;	
	
};
class mon{
	private:
		char tenmon[20];
		int sotrinh;
		float diem;
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend void dem(phieu t);
	friend void chen( phieu &t);
	friend void tk(phieu t);
	friend void xoa(phieu &t);
	friend void hienmon(phieu t);
	
};
class phieu{
	private:
		sinhvien x;
		mon a[10];
		int n;
	public:
		void nhap();
		void xuat();
		friend void dem(phieu t);	
		friend void chen(phieu &t);	
		friend void tk(phieu t);
		friend void xoa(phieu &t);
		friend void hienmon(phieu t);
};
void sinhvien::nhap(){
	cout<<"ma sinh vien: ";		fflush(stdin);			gets(masv);
	cout<<"ten sinh vien: ";		fflush(stdin);		gets(tensv);
	cout<<"lop :";					fflush(stdin);		gets(lop);
	cout<<"khoa :";				cin>>khoa;
}
void sinhvien:: xuat(){
	cout<<"ma sinh vien: "<<masv<<setw(30)<<"ten sinh vien: "<<tensv<<endl;
	cout<<"Lop: "<<lop<<setw(50)<<"Khoa: "<<khoa<<endl;
}
void mon::nhap(){
	cout<<"ten mon: ";				fflush(stdin);				gets(tenmon);
	cout<<"so trinh: ";				cin>>sotrinh;	
	cout<<"Diem: ";					cin>>diem;		
}
void mon::xuat(){
	cout<<setw(15)<<tenmon<<setw(25)<<sotrinh<<setw(40)<<diem<<endl;
}
void phieu::nhap(){
	x.nhap();
	cout<<"\n So mon: ";		cin>>n;
	for(int i=0; i<n; i++){
		a[i].nhap();
	}
}
void phieu::xuat(){

	int t=0;
	int sum=0;
	float tb=0;
	cout<<"\n-------------------PHIEU BAO DIEM----------------------  "<<endl;
	x.xuat();
	cout<<"Bang diem: "<<endl;
	cout<<endl;
	cout<<setw(15)<<"Ten mon"<<setw(27)<<"So trinh "<<setw(35)<<"Diem"<<endl;
		for(int i=0; i<n; i++){
		sum+=a[i].sotrinh;
		t+=a[i].sotrinh*a[i].diem;
		tb=(float)t/sum;
		a[i].xuat();
	}
	cout<<setw(60)<<"Diem trung binh: "<<tb;
	
}
//dem so mon hoc co 3 tin chi
void tk(phieu t){
	int d=0;
	for(int i=0; i<t.n; i++){
		if(t.a[i].sotrinh==4){
			d++;		
		}
	}
	if(d!=0){
		cout<<"\n So mon co so trinh bang 4 la: "<<d;
	}
	else{
		cout<<"\n Khong co mon nao co so trinh bang 4";	
	}
}
//hien ten mon hoc so trinh lon hon 3
void hienmon(phieu t)
{
    for(int i=0; i<t.n;i++)
	{
        if(t.a[i].sotrinh>3)
		{
            cout<<t.a[i].tenmon<<" ";
        }
    }
    cout<<endl;
}
//chen 1 mon hoc bat ki vao 
void chen(phieu &t){
	cout<<"\n Nhap thong tin mon hoc :"<<endl;
	mon h;
	h.nhap();
	int k;
	cout<<"Nhap vitri  muon chen: ";		cin>>k;
	for(int j=t.n; j>k; j--){
		t.a[j]=t.a[j-1];
	}
	t.a[k-1]=h;
	t.n++; 
	cout<<"\n -------------------PHIEU SAU KHI CHEN--------------"<<endl;
}
//xoa mon hoa
void xoa(phieu &t){
	int d=0;
	int i; 
	for(i=0; i<t.n; i++){
		if(strcmp(t.a[i].tenmon,"hoa")==0){
			d++;
			t.a[i]=t.a[i+1]; 
		}
		t.n--; 
	}	
	if(d==0){
		cout<<"\nKhong co mon hoc hoa nao de xoa."<<endl;
	}
}
int main(){
	phieu t;
	t.nhap();
	t.xuat();
	cout<<endl;
	dem(t);
	cout<<endl;
	chen(t);
	t.xuat();
	cout<<endl;
	tk(t);
	cout<<endl;
	cout<<"\n --------------PHIEU SAU KHI XOA ------------"<<endl;
	xoa(t);
	t.xuat();
	
}
/*
sv1
lan
ktpm1
16
3
toan
4
8
anh
3
7
hoa
5
9
sinh
4
9
2
*/



