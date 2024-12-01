#include <bits/stdc++.h>
using namespace std;

struct LapTop
{
	string HangSX;
	string CauHinh;
	float GiaBan;
};

void NhapDS(LapTop DS_LapTop[], int SL_LapTop)
{
	cout << "NHAP THONG TIN CHO LAPTOP" << endl;
	for(int i = 0; i < SL_LapTop; i++)
	{
		cout << "LAPTOP THU " << i+1 << endl;
		cout << "HANG SAN XUAT: "; cin >> DS_LapTop[i].HangSX;
		cout << "CAU HINH: "; fflush(stdin); getline(cin, DS_LapTop[i].CauHinh);
		cout << "GIA BAN: "; cin >> DS_LapTop[i].GiaBan;
	}
}

int Find_Char(char target, string str) 
{
    for(int i = 0; i < str.length(); i++) 
	{
        if (str[i] == target) return i;    	
    }
    return -1;  
}

int B_M_H(string con, string cha)
{
	int dem = 0;
	int len_con = con.length(); 
	int i = len_con - 1;
	while(i < cha.length())
	{
		int x = len_con - 1;
		while(cha[i] == con[x] && x >= 0) {
			i--; x--;
		}
		if(x < 0) {
			dem ++; 
			i = i + len_con + 1;
		}
		else {
			int k = Find_Char(cha[i], con);
			if(k < 0) i = i + len_con;
			else i = i + len_con - k - 1;
		}
	}
	return dem;
}

void TT_Z(string con, string cha, int z[])
{
	char tmp = '$';
	string s = con + tmp + cha;
	int n = s.length();
	int left = 0, right = 0;
	z[0] = -1;
	for(int i = 1; i < n; i++)
	{
		if(i > right)
		{
			left = right = i;
			while(right < n && s[right - left] == s[right]) right++;
			z[i] = right - left;
			right--;
		}
		else if(z[i - left] < (right - 1 + 1))
		{
			z[i] = z[i - left];
		}
		else
		{
			left = i;
			while(right < n && s[right - left] == s[right]) right++;
			z[i] = right - left;
			right--;
		}
	}
}

int KT_XauCon(string con, string cha, int z[])
{
	TT_Z(con, cha, z);
	int dem = 0;
	int n = con.length() + cha.length() + 1;
	for(int i = 0; i < n; i++)
	{
		if(z[i] == con.length()) dem++;
	}
	if(dem > 0) return 1;
	else return 0;
}

int main()
{
	cout << "NHAP SO LUONG LAPTOP: ";
	int SL_LapTop; cin >> SL_LapTop;
	
	LapTop DS_LapTop[SL_LapTop];
	NhapDS(DS_LapTop, SL_LapTop);
	
	int dem = 0;
	for(int i = 0; i < SL_LapTop; i++)
	{
		if(B_M_H("16GB", DS_LapTop[i].CauHinh) > 0) dem++;
	}
	cout << "SO LAPTOP CO RAM 16GB: " << dem << endl;
	
	cout << "\n=========\n\n";
	cout << "DANH SACH LAPTOP CO SSD: " << endl;
	for(int i = 0; i < SL_LapTop; i++)
	{
		// "SSD".length() = 3
		int Z[3 + DS_LapTop[i].CauHinh.length() + 1];
		if(KT_XauCon("SSD", DS_LapTop[i].CauHinh, Z) == 1) {
			cout << DS_LapTop[i].HangSX << endl;
		}
	}
}
