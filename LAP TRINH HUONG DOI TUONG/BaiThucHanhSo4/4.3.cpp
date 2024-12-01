#include<iostream>
#include<stdio.h>

using namespace std;

class VEHICLE
{
	protected:
		char nhanhieu[20];
		int namsx;
		char hang[20];
	public:
		void nhap();
		void xuat();
};
class CAR: public VEHICLE
{
	private:
		int sochongoi;
		float dungtich;
	public:
		void nhap();
		void xuat();
		friend void sua_DT(CAR &a);
};
class MOTO:public VEHICLE
{
	private:
		char phanphoi[10];
	public:
		void nhap();
		void xuat();
		
};
void VEHICLE::nhap()
{
	cout<<"Nhap Nhan Hieu: ";			fflush(stdin);	gets(nhanhieu);
	cout<<"Nhap Nam SX: ";								cin>>namsx;
	cout<<"Nhap Hang: ";				fflush(stdin);	gets(hang);
}
void VEHICLE::xuat()
{
	cout<<"Nhan Hieu: "<<nhanhieu<<endl;
	cout<<"Nam SX: "<<namsx<<endl;
	cout<<"Hang: "<<hang<<endl;
}
void CAR::nhap()
{
	VEHICLE::nhap();
	cout<<"Nhap so cho ngoi: ";							cin>>sochongoi;
	cout<<"Nhap dung tich: ";							cin>>dungtich;
}
void CAR::xuat()
{
	cout<<"\n----THONG TIN CAR-----"<<endl;
	VEHICLE::xuat();
	cout<<"So cho ngoi: "<<sochongoi<<endl;
	cout<<"Dung tich: "<<dungtich<<endl;
}
void MOTO::nhap()
{
	VEHICLE::nhap();
	cout<<"Nhap phan phoi: ";			fflush(stdin);	gets(phanphoi);
}
void MOTO::xuat()
{
	cout<<"\n----THONG TIN MOTO-----"<<endl;
	VEHICLE::xuat();
	cout<<"Phan Phoi: "<<phanphoi;
}

void sua_DT(CAR &a)
{
	a.dungtich=3.0;
}
int main()
{
	CAR a;
	MOTO b;
	cout<<"NHAP THONG TIN XE OTO"<<endl;
	a.nhap();
	cout<<"NHAP THONG TIN XE MOTO"<<endl;
	b.nhap();
	a.xuat();
	b.xuat();
	sua_DT(a);
	cout<<"******THONG TIN SAU KHI SUA*******"<<endl;
	a.xuat();
	
}



