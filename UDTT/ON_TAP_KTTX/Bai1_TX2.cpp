#include <iostream>
using namespace std;

struct Quat
{
	string HangSX;
	string MauSac;
	int GiaBan;
};

void NhapDS(Quat DS_Quat[], int SL_Quat)
{
	cout << "NHAP THONG TIN CHO QUAT" << endl;
	for(int i = 0; i < SL_Quat; i++)
	{
		cout << "CHIEC QUAT THU " << i+1 << endl;
		cout << "HANG SAN XUAT: "; cin >> DS_Quat[i].HangSX;
		cout << "MAU SAC: "; cin >> DS_Quat[i].MauSac;
		cout << "GIA BAN: "; cin >> DS_Quat[i].GiaBan;
	}
}

void InDS(Quat DS_Quat[], int SL_Quat)
{
	cout << "THONG TIN QUAT" << endl;
	for(int i = 0; i < SL_Quat; i++)
	{
		cout << "CHIEC QUAT THU " << i+1 << endl;
		cout << "HANG SAN XUAT: " << DS_Quat[i].HangSX << endl;
		cout << "MAU SAC: " << DS_Quat[i].MauSac << endl;
		cout << "GIA BAN: " << DS_Quat[i].GiaBan << endl;
	}
}

void SapXepTang(Quat a[], int left, int right)
{
	if(left < right) 
	{
		int mid = (left + right) / 2;
		int t = a[mid].GiaBan;
		int i = left, j = right;
		do
		{
			while (a[i].GiaBan < t) i++;
			while (a[j].GiaBan > t) j--;
			if(i <= j)
			{
				Quat tg = a[i]; 
				a[i] = a[j]; 
				a[j] = tg;
				i++; j--;
			}
		} while(i <= j);
		SapXepTang(a, left, j);
		SapXepTang(a, i, right);
	}
}

void MuaQuat(Quat DS_Quat[], int SL_Quat, int Tien, int S[])
{
	SapXepTang(DS_Quat, 0, SL_Quat-1);
	for(int i = 0; i < SL_Quat; i++) S[i] = 0;
	int i = 0, idx = 0;
	while(Tien >= DS_Quat[i].GiaBan && i < SL_Quat)
	{
		S[idx] = i+1;
		Tien = Tien - DS_Quat[i].GiaBan;
		i++; idx++;
	}
}

int main()
{
	cout << "NHAP SO TIEN DANG CO: ";
	int Tien; cin >> Tien;
	
	cout << "NHAP SO LUONG QUAT: ";
	int SL_Quat; cin >> SL_Quat;
	
	Quat DS_Quat[SL_Quat];
	NhapDS(DS_Quat, SL_Quat);
	
	int S[SL_Quat];
	MuaQuat(DS_Quat, SL_Quat, Tien, S);
	
	cout << "\n==========\n\n";
	cout << "DS QUAT CO THE MUA LA: " << endl;
	int dem = 0;
	for(int i = 0; i < SL_Quat; i++)
	{
		if(S[i] != 0) 
		{
			dem++; cout << "QUAT THU " << dem << endl;
			cout << "HANG SAN XUAT: " << DS_Quat[i].HangSX << endl;
			cout << "GIA BAN: " << DS_Quat[i].GiaBan << endl;
			
		}
	}
	if(dem == 0) cout << "KHONG MUA DUOC QUAT NAO!";
	else cout << "SO LUONG QUAT NHIEU NHAT CO THE MUA LA: " << dem;
}
/*
10
3
a
do
6
s
s
5
s
s
6
*/
