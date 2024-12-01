#include<bits/stdc++.h>

using namespace std;

struct hang{
	int mahang;
	char ten[20];
	int sl;
	hang* next;
};

struct Node{
	hang infor;
	Node *next;
};
typedef Node *TRO;
TRO L;

void nhaphang(hang &h)
{
	cout<<"Nhap ma hang: ";						cin>>h.mahang;
	cout<<"Nhap ten hang: ";	fflush(stdin);	gets(h.ten);
	cout<<"Nhap so luong: ";					cin>>h.sl;
}
void nhapds(TRO &L)
{
	TRO Q,P;
	hang X;
	int d=0;
	L=NULL;
	do{
		nhaphang(X);
		P=new Node;
		P->infor=X;
		P->next=NULL;
		if(L==NULL)
			L=P;
		else
			Q->next=P;
		Q=P;
		d++;
	}while(d<3);
}
void hiends(TRO L)
{
	cout<<setw(15)<<"Ma"<<setw(20)<<"Ten Hang"<<setw(20)<<"So Luong"<<endl;;
	if(L==NULL){
		cout<<"DSR!";
		return;
	}
	TRO Q=L;
	while(Q!=NULL){
		hang X=Q->infor;
		cout<<setw(15)<<X.mahang<<setw(20)<<X.ten<<setw(20)<<X.sl<<endl;
		Q=Q->next;
	}
}

void chen(TRO &L)
{
	TRO Q,P;
	P=new Node;
	P->infor.mahang=15;
	strcpy(P->infor.ten,"sach");
	P->infor.sl=25;
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
void timmin(TRO L)
{
	int min=L->infor.sl;
	TRO Q=L;
	while(Q!=NULL){
		if(Q->infor.sl<min){
			min=Q->infor.sl;
		}
		Q=Q->next;
	}
	while(Q!=NULL){
		if(Q->infor.sl==min){
			hiends(Q);
		}
		Q=Q->next;
	}
}
int main()
{
	TRO L;
	nhapds(L);
	hiends(L);
	chen(L);
	cout<<"\n\n===========\n";
	hiends(L);
	cout<<"\n\n===========\n";
	timmin(L);
}




