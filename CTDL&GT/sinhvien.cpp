#include<bits/stdc++.h>

using namespace std;

struct SinhVien{
	int ma;
	char hoten[30];
	float diemtk;
};
struct Node{
	SinhVien infor;
	Node *next;
};
typedef Node *TRO;
TRO L;
void nhapsv(SinhVien & sv){
	cout<<"Nhap Ma: ";								cin>>sv.ma;
	cout<<"Nhap ho ten: ";			fflush(stdin);	gets(sv.hoten);
	cout<<"Mhap diem tk: ";							cin>>sv.diemtk;
}
void nhapds(TRO &L)
{
	TRO Q, P;
	SinhVien X;
	int d=0;
	L=NULL;
	do{
		nhapsv(X);
		P=new Node;
		P->infor=X;
		P->next=NULL;
		if(L==NULL)
			L=P;
		else
			Q->next=P;
		Q=P;
		d++;
	}while(d<5);
}

void hiends(TRO L)
{
	cout<<setw(15)<<"Ma"<<setw(20)<<"Ho Ten"<<setw(25)<<"Diem TK"<<endl;
	if(L==NULL)
	{
		cout<<"Danh Sach rong!";
		return;
	}
	TRO Q=L;
	while(Q!=NULL)
	{
		SinhVien X=Q->infor;
		cout<<setw(15)<<X.ma<<setw(20)<<X.hoten<<setw(25)<<X.diemtk<<endl;
		Q=Q->next;
	}
}
//chen vi tri thu 3
void chentruoc(TRO &L)
{
	int d=1;
	TRO M,Q=L;
	while(Q!=NULL && d<3)
	{
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL)
	{
		cout<<"dsr!";
		return;
	}
	TRO P=new Node;
	P->infor.ma=6;
	strcpy(P->infor.hoten,"Doan Tra My");
	P->infor.diemtk=7.3;
	P->next=M->next;
	M->next=P;
}
//chen vao sau vi tri thu 3

void chensau(TRO &L)
{
	int d=1;
	TRO Q=L,P;
	while(Q!=NULL && d<3){
		Q=Q->next;
		d++;
	}
	if(Q==NULL)
	{
		cout<<"dsr!";
		return;
	}
	P=new Node;
	P->infor.ma=6;
	strcpy(P->infor.hoten,"Doan Tra My");
	P->infor.diemtk=7.3;
	P->next=Q->next;
	Q->next=P;
	
}

//chen vao dau danh sach
void chenvtdt(TRO &L)
{
	TRO P;
	P=new Node;
	P->infor.ma=6;
	strcpy(P->infor.hoten,"Doan Tra My");
	P->infor.diemtk=7.3;
	P->next=L;
	L=P;
}

//chen cuoi danh sach
void chencds(TRO &L)
{
	TRO P,Q;
	P=new Node;
	P->infor.ma=6;
	strcpy(P->infor.hoten,"Doan Tra My");
	P->infor.diemtk=7.3;
	P->next=NULL;
	if(L==NULL)
		L=P;
	else{
		Q=L;
		while(Q->next!=NULL)
			Q=Q->next;
		Q->next=P;
	}
		
}

//Xoa vi tri dau tien

void xoavtdt(TRO &L)
{
	TRO Q=L;
	L=L->next;
	delete Q;
}


//xoa sau vi tri thu 2

void xoasau(TRO L)
{
	int d=1;
	TRO M, Q=L;
	while(Q!=NULL && d<2){
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL)
	{
		cout<<"Danh sach rong";
		return;
	}
	Q=M->next;
	M->next=Q->next;
	delete Q;
}

void chentheoma(TRO &L)
{
	TRO P = new Node;
	P->infor.ma=11;
	strcpy(P->infor.hoten,"Ha");
	P->infor.diemtk=8.9;
	TRO Q=L;
	if(L->infor.ma==12){
		P->next=L;
		L=P;
	}
	else{
		TRO M,Q;
		while(Q!=NULL){
			R=Q;
			if(Q->next->infor.ma=12){
				P->next=Q;
				M->next=P;
				}
				Q=Q->next;
			Q=Q->next;
		}
	}
}
void xoatheoma(TRO L)
{
	TRO Q=L,M,R;
	while(Q!=NULL && Q->infor.ma!=12 ){	
		M=Q;
		Q=Q->next;
	}
	if(Q==NULL)
	{
		cout<<"dsr";
		return;
	}
	Q=M;
	delete Q;	
}
void hientt(TRO L)
{
	TRO Q=L;
	while(Q!=NULL){
		if(Q->infor.diemtk>8)
		{
		SinhVien X=Q->infor;
		cout<<setw(15)<<X.ma<<setw(20)<<X.hoten<<setw(25)<<X.diemtk<<endl;
		}			
		Q=Q->next;
	}
}
//sap xep theo ten
void sapxep(TRO &L)
{
	SinhVien tg;
	TRO M,Q,R;
	R=L;
	while(R->next!=NULL){
		M=R;
		Q=R->next;
		while(Q!=NULL){
			if(strcmp(Q->infor.hoten,M->infor.hoten)<0){
				M=Q;
			}
			Q=Q->next;
		}
		tg= R->infor;
		R->infor=M->infor;
		M->infor=tg;
		R=R->next;
	}
}
int main()
{
	TRO L;
	nhapds(L);
	hiends(L);
//	chentruoc(L);
//	cout<<"--------------"<<endl;
//	hientt(L);
	chentheoma(L);
	cout<<"--------------------------"<<endl;
	hiends(L);
}

/*
01
jjfgfd
8
12
dsggds
9
03
fsgg
7
04
fgsg
6
05
dsgsdfg
5
*/





