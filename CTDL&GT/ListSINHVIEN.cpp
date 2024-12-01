#include<bits/stdc++.h>

using namespace std;

struct SinhVien{
	int masv;
	char Ten[30];
	int ns;
	double DiemTK;
};
struct Node{
	SinhVien infor;
	Node *next;
};
typedef Node *TRO;
void nhapsv(SinhVien &sv)
{
	cout<<"Nhap masv: ";								cin>>sv.masv;
	cout<<"Nhap Ten: ";				fflush(stdin);		gets(sv.Ten);
	cout<<"Nhap nam sinh: ";							cin>>sv.ns;
	cout<<"Nhap Diem TK: ";								cin>>sv.DiemTK;
}
void input_list(TRO &L){
	TRO P, Q;
	SinhVien X;
	int d=0;
	L=NULL;
	do
	{
		nhapsv(X);
		P=new Node;
		P->infor=X;
		P->next=NULL;
		if(L==NULL)
			L=P;
		else
			Q->next=P;
		Q = P;
		d++;
	}while(d<3);
}
void output_list(TRO &L)
{
	cout<<"Ma";
	cout<<setw(15)<<"Ho Ten";
	cout<<setw(20)<<"Nam Sinh";
	cout<<setw(25)<<"Diem TK"<<endl;
	if(L==NULL)
	{
		cout<<"DS rong!";
		return;
	}
	TRO Q=L;
	int i=0;
	while(Q!=NULL)
	{
		SinhVien X=Q->infor;
		cout<<X.masv;
		cout<<setw(15)<<X.Ten;
		cout<<setw(20)<<X.ns;
		cout<<setw(25)<<X.DiemTK<<endl;
		Q=Q->next;
		i++;
	}
}
void xoaPtDauTien(TRO &L){
 if (L == NULL){
 cout<<"\tDanh sach rong";
 return;
 }
 TRO Q = L;
 L = L->next;
 delete Q;
}

int main()
{
	TRO L;
	input_list(L);
	output_list(L);
	xoaPtDauTien(L);
	cout<<"----Danh sach sau khi xoa sinh vien dau tien-----"<<endl;
	output_list(L);
}




