#include<bits/stdc++.h>

using namespace std;

class PHIEU;
class SINHVIEN
{
	private:
		char masv[10];
		char tensv[20];
		char lop[10];
		int khoa;
	public:
		void input();
		void output();
};

class MON
{
	private:
		char tenm[30];
		int sotrinh;
		int diem;
	public:
		void input();
		void output();
		friend class PHIEU;
		friend void search(PHIEU t);
		
};

class PHIEU
{
	private:
		SINHVIEN x;
		MON y[100];
		int n;
	public:
		void input();
		void output();
		friend void search(PHIEU t);
		friend void chen(PHIEU &t);
		friend void chenvtri2(PHIEU &t);
};
void SINHVIEN::input()
{
	cout<<"Nhap Ma sinh vien: ";			fflush(stdin);	gets(masv);
	cout<<"Nhap ten sinh vien: ";			fflush(stdin);	gets(tensv);
	cout<<"Nhap lop: ";						fflush(stdin);	gets(lop);
	cout<<"Nhap khoa: ";									cin>>khoa;
}
void SINHVIEN::output()
{
	cout<<setw(15)<<"Ma sinh vien: "<<setw(15)<<masv;
	cout<<setw(25)<<"Ten sinh vien: "<<setw(15)<<tensv<<endl;
	cout<<setw(15)<<"Lop: "<<setw(15)<<lop;
	cout<<setw(25)<<"Khoa: "<<setw(15)<<khoa<<endl;
}
void MON::input()
{
	cout<<"Nhap Ten Mon: ";			fflush(stdin);	gets(tenm);
	cout<<"Nhap so trinh: ";						cin>>sotrinh;
	cout<<"Nhap diem: ";							cin>>diem;
}
void MON::output()
{
	cout<<setw(15)<<tenm<<setw(15)<<sotrinh<<setw(15)<<diem<<endl;
}
void PHIEU::input()
{
	x.input();
	cout<<"Nhap so mon: ";							cin>>n;
	for(int i=0; i<n; i++){
		y[i].input();
	}
}
void PHIEU::output()
{
	x.output();
	for(int i=0; i<n; i++){
		y[i].output();
	}
	float sum1=0,sum2=0;
	for(int i=0; i<n; i++){
		sum1+=y[i].sotrinh*y[i].diem;
		sum2+=y[i].sotrinh;
	}
	cout<<setw(30)<<"Diem trung binh"<<setw(15)<<sum1/sum2<<endl;
}

void search(PHIEU t)
{
	for(int i=0; i<t.n; i++){
		if(t.y[i].sotrinh>3)
			cout<<t.y[i].tenm<<"    ";
	}
}
void chen(PHIEU &t)
{
	t.y[t.n].input();
	t.n++;
}
void chenvtri2(PHIEU &t)
{
	for(int i=t.n-1; i>=1; i--){
		t.y[i+1]=t.y[i];
	}
	t.y[1].input();
	t.n++;
}
int main()
{
	PHIEU t;
	t.input();
	t.output();
	cout<<"\nTen cac mon hoc co so tring lon hon 3 la: ";
	search(t);
	cout<<"\n";
//	chen(t);
//	t.output();
	cout<<"\n";
	chenvtri2(t);
	t.output();
}


