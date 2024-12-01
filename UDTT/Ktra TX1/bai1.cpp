#include<bits/stdc++.h>
using namespace std;

struct HANGHOA{
	string tenhh;
	float khoiluong;
	int giaban;
};
void khoitao(HANGHOA hanghoa[], int& sohanghoa){
	hanghoa[0]={"but",0.1, 5000};
	hanghoa[1]={"sach",0.3, 20000};
	hanghoa[2]={"vo",0.2, 10000};
	hanghoa[3]={"thuoc",0.1, 4000};
	hanghoa[4]={"ban",10, 200000};
	hanghoa[5]={"ghe",9, 150000};
	hanghoa[6]={"bang",0.6, 7000};
	hanghoa[7]={"hopbut",0.6, 20000};
	hanghoa[8]={"hopphan",0.3, 11000};
	hanghoa[9]={"phan",0.1, 5000};
	sohanghoa=10;
}
int tonggiaban(HANGHOA hanghoa[], int sohanghoa){
	if(sohanghoa==0)
		return 0;
	else
		return hanghoa[sohanghoa-1].giaban + tonggiaban(hanghoa,sohanghoa-1);
}
int demsohanghoathap(HANGHOA hanghoa[], int sohanghoa, int p){
	if(sohanghoa==0){
		return 0;
	}
	else if(hanghoa[sohanghoa-1].giaban<p){
		return 1+demsohanghoathap(hanghoa, sohanghoa-1,p);
	}
	else{
		return demsohanghoathap(hanghoa, sohanghoa-1,p);
	}
}


int main(){
	int max=10;
	HANGHOA hanghoa[max];
	int sohanghoa;
	khoitao(hanghoa,sohanghoa);
	cout<<"Tong gia ban cua tat ca hang hoa la: "<<tonggiaban(hanghoa, sohanghoa)<<endl;
	int p=50000;
	cout<<"So luong hang hoa co gia thap hon 30000 la: "<<demsohanghoathap(hanghoa, sohanghoa,p)<<endl;
}

