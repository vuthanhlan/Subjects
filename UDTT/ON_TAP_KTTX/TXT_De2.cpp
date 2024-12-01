#include <iostream>
#include <string>
#define MAX 100

using namespace std;

struct CongViec
{
	string MaCV;
	float Gio_BatDau;
	float Gio_KetThuc;
};

struct List
{
	CongViec E[MAX];
	int cnt;
};

void Khoi_Tao_DS(List &DS_CV, int SoLuongCV)
{
	DS_CV.cnt = SoLuongCV - 1;
	
	DS_CV.E[0].MaCV = "CV01";
	DS_CV.E[0].Gio_BatDau = 6.0;
	DS_CV.E[0].Gio_KetThuc = 15.0;
	
	DS_CV.E[1].MaCV = "CV02";
	DS_CV.E[1].Gio_BatDau = 6.0;
	DS_CV.E[1].Gio_KetThuc = 17.0;
	
	DS_CV.E[2].MaCV = "CV03";
	DS_CV.E[2].Gio_BatDau = 7.0;
	DS_CV.E[2].Gio_KetThuc = 15.0;
	
	DS_CV.E[3].MaCV = "CV04";
	DS_CV.E[3].Gio_BatDau = 8.0;
	DS_CV.E[3].Gio_KetThuc = 17.0;
	
	DS_CV.E[4].MaCV = "CV05";
	DS_CV.E[4].Gio_BatDau = 6.0;
	DS_CV.E[4].Gio_KetThuc = 12.0;
	
	DS_CV.E[5].MaCV = "CV06";
	DS_CV.E[5].Gio_BatDau = 9.0;
	DS_CV.E[5].Gio_KetThuc = 15.0;
}

void IN_CV(List DS_CV, int i)
{
	cout<<DS_CV.E[i].MaCV<<endl;
	cout<<DS_CV.E[i].Gio_BatDau<<endl;
	cout<<DS_CV.E[i].Gio_KetThuc<<endl;
}

void IN_DS(List DS_CV, int cnt, int i)
{
	if(i == cnt)
	{
		IN_CV(DS_CV, i);
		cout<<endl;
	}
	else
	{
		IN_CV(DS_CV, i);
		cout<<endl;
		IN_DS(DS_CV, cnt, i+1);
	}
}

float Tong (List DS_CV, int left, int right, float t)
{
	if(left == right)
	{
		if(DS_CV.E[left].Gio_KetThuc < t)
		{
			return (DS_CV.E[left].Gio_KetThuc - DS_CV.E[left].Gio_BatDau);
		}
		else return 0;
	}
	else
	{
		int mid = (left + right) / 2;
		int tongLeft = Tong(DS_CV, left, mid, t);
		int tongRight = Tong(DS_CV, mid+1, right, t);
		int tong = tongLeft + tongRight;
		return tong;
	}
}

void Show(int k, int Xep[], List DS_CV)
{
	for(int i = 1; i <= k; i++)
	{
		cout << DS_CV.E[Xep[i] - 1].MaCV << " - " << DS_CV.E[Xep[i] - 1].Gio_KetThuc <<endl;
	}
	cout<<endl;
}

void Try(int i, int k, int n, int Xep[], List DS_CV)
{
	for(int j = Xep[i - 1] + 1; j <= (n - k + i); j++)
	{
		Xep[i] = j;
		if(i == k)
		{
			Show(k,Xep,DS_CV);
		}
		else
		{
			Try(i+1, k, n, Xep, DS_CV);
		}
	}
}

int main()
{
	int SoLuongCV = 6;
	List DS_CV;
	Khoi_Tao_DS(DS_CV, SoLuongCV);
	
	IN_DS(DS_CV, DS_CV.cnt, 0);
	
	float t = 17.0;
	cout<<Tong(DS_CV, 0, DS_CV.cnt, t);
	
	int Xep[SoLuongCV]; Xep[0] = 0;
	int k = 5;
	Try(1, k, SoLuongCV, Xep, DS_CV);
}
