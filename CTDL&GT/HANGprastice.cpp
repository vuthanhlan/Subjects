#include<bits/stdc++.h>

using namespace std;

struct HANG{
	int ma;
	char ten[30];
	int sl;
};
struct Node{
	HANG infor;
	Node *next;
};
typedef Node *TRO;
TRO L;
void nhaphang(HANG &h)
{
	cout<<"Nhap ma: ";							cin>>h.ma;
	cout<<"Nhap ten: ";			fflush(stdin);	gets(h.ten);
	cout<<"Nhap so luong: ";					cin>>h.sl;
}
void nhapds(TRO &L)
{
	HANG X;
	TRO Q,P;
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
	}while(d<4);
}

void hiends(TRO L)
{
	cout<<setw(15)<<"Ma"<<setw(20)<<"Ten Hang"<<setw(20)<<"So Luong"<<endl;
	if(L==NULL){
		cout<<"DSR";
		return;
	}
	TRO Q=L;
	while(Q!=NULL){
		HANG X=Q->infor;
		cout<<setw(15)<<X.ma<<setw(20)<<X.ten<<setw(20)<<X.sl<<endl;
		Q=Q->next;
	}
}
//chen truoc vi tri thu 3

void chen(TRO L)
{
	int d=1;
	TRO M,Q=L;
	while(Q!=NULL && d<3){
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL){
		cout<<"DSR";
		return;
	}
	TRO P=new Node;
	P->infor.ma=17;
	strcpy(P->infor.ten,"Bang");
	P->infor.sl=8;
	P->next=M->next;
	M->next=P;
}
//xoa
void xoa(TRO L)
{
	int d=1;
	TRO M, Q=L;
	while(Q!=NULL && d<3){
		M=Q;
		Q=Q->next;
		d++;
	}
	if(Q==NULL){
		cout<<"DSR";
		return;
	}
	Q=M->next;
	M->next=Q->next;
	delete Q;
}
int main()
{
	TRO L;
	nhapds(L);
	hiends(L);
	chen(L);
	cout<<"---DANH SACH SAU KHI CHEN----"<<endl;
	hiends(L);
	xoa(L);
	cout<<"---DANH SACH SAU KHI XOA-----"<<endl;
	hiends(L);
}
