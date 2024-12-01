#include<bits/stdc++.h>

using namespace std;
class PhieuDiem;
class SinhVien
{
private:
    char MaSV[10];
    char TenSV[30];
    char Lop[20];
    int Khoa;
public:
    void nhap();
    void xuat();
};
void SinhVien::nhap()
{
    cout<<"Ma sinh vien: ";					fflush(stdin);		gets(MaSV);
    cout<<"Ten sinh vien: ";				fflush(stdin);		gets(TenSV);
    cout<<"Lop: ";							fflush(stdin);		gets(Lop);
    cout<<"Khoa: ";												cin>>Khoa;
}
void SinhVien::xuat()
{
    cout<<setw(15)<<"Ma Sinh vien: "<<setw(15)<<MaSV;
    cout<<setw(15)<<"Ten sinh vien: "<<setw(15)<<TenSV<<endl;
    cout<<setw(15)<<"Lop: "<<setw(15)<<setw(15)<<Lop;
    cout<<setw(15)<<"Khoa: "<<setw(15)<<setw(15)<<Khoa<<endl;
}
class DiemMon
{
private:
    char TenMon[20];
    int SoTrinh;
    int Diem;
public:
    void nhap();
    void xuat();
//    int getSoTrinh() { return SoTrinh; }
//    char* getTenMon() { return TenMon; }
    friend class PhieuDiem;
    friend void kt(PhieuDiem t);
    friend void chen(PhieuDiem &t);
    friend void xoa(PhieuDiem &t);
    friend void chensau(PhieuDiem &t);

};
void DiemMon::nhap()
{
    cout<<"Ten Mon: ";				fflush(stdin);		gets(TenMon);
    cout<<"So Trinh: ";									cin>>SoTrinh;
    cout<<"Diem: ";										cin>>Diem;
}
void DiemMon::xuat()
{
    cout<<setw(15)<<TenMon<<setw(15)<<SoTrinh<<setw(15)<<Diem<<endl;
}
class PhieuDiem
{
private:
    SinhVien x;
    DiemMon y[10];
    int n;
public:
    void nhap();
    void xuat();
    friend void kt(PhieuDiem t);
    friend void chen(PhieuDiem &t);
    friend void xoa(PhieuDiem &t);
    friend void chensau(PhieuDiem &t);
};
void PhieuDiem::nhap()
{
    x.nhap();
    cout<<"So Mon:";
    cin>>n;
    for(int i=0; i<n; i++){
        y[i].nhap();
    }
}
void PhieuDiem::xuat()
{
	cout<<setw(40)<<"--------PHIEU BAO DIEM---------"<<endl;
    x.xuat();
    cout<<"BANG DIEM"<<endl;
    cout<<setw(15)<<"Ten Mon"<<setw(15)<<"So Trinh"<<setw(15)<<"Diem"<<endl;
    for(int i=0; i<n; i++)
        y[i].xuat();
    float t=0,ts=0;
    for(int i=0; i<n; i++){
        t+=y[i].SoTrinh;
        ts+=y[i].Diem*y[i].SoTrinh;
    }
    cout<<setw(30)<<"Diem trung binh"<<setw(15)<<ts/t<<endl;
}
void kt(PhieuDiem t)
{
    for(int i=0; i<t.n;i++)
	{
        if(t.y[i].SoTrinh>3)
		{
            cout<<t.y[i].TenMon<<" ";
        }
    }
    cout<<endl;
}
void chen(PhieuDiem &t)
{
	t.y[t.n].nhap();
	t.n++;
}
void xoa(PhieuDiem &t)
{
	int d=0;
	for(int i=0; i<t.n;i++)
	{
		if(strcmp(t.y[i].TenMon,"He dieu hanh")==0){
			d++;
		}
	}
	if(d==0) cout<<"Khong co mon hoc nay!";
	else{
		for(int i=0 ; i<t.n; i++)
		{
			if(strcmp(t.y[i].TenMon,"He dieu hanh")==0){
				for(int j=i; j<t.n-1; j++){
						t.y[j]=t.y[j+1];
					}
					t.n--;
			}
		}
	}
	
}

// chen vao sau mon co so du lieu
void chensau(PhieuDiem &t)
{
	int d,count=0;
	for(int i=0; i<t.n; i++){
		if(strcmp(t.y[i].TenMon,"co so du lieu")==0){
			d=i;
			count++;
		}
	}
	if(count==0) cout<<"Khong co mon hoc nay!";
	else{
		for(int i=t.n-1; i>=d+1; i--){
			t.y[i+1]=t.y[i];
		}
		t.y[d+1].nhap();
		t.n++;
	}
	
}
int main()
{
    PhieuDiem a;
    a.nhap();
    a.xuat();
    cout<<"cac mon co so trinh lon hon 3 la: ";
    kt(a);
    chen(a);
    cout<<"\n-------PHIEU SAU KHI CHEN--------"<<endl;
    a.xuat();
    xoa(a);
    cout<<"\n-------PHIEU SAU KHI XOA--------"<<endl;
    a.xuat();
    chensau(a);
    cout<<"\n-------PHIEU SAU KHI CHEN SAU--------"<<endl;
    a.xuat();
    
}
/*
Sv001
Nguyen Hai Ha
CNTT1
10
3
co so du lieu
4
8
lap trinh HDT
3
7
He dieu hanh
5
9
*/



