#include <iostream>
#include <string>
using namespace std;

void SapXepGiam(string a[], int left, int right)
{
	if(left < right) 
	{
		int k = (left + right) / 2;
		int t = a[k].length();
		int i = left, j = right;
		do
		{
			while (a[i].length() > t) i++;
			while (a[j].length() < t) j--;
			if(i <= j)
			{
				string tg = a[i]; 
				a[i] = a[j]; 
				a[j] = tg;
				i++; j--;
			}
		} while(i <= j);
		SapXepGiam(a, left, j);
		SapXepGiam(a, i, right);
	}
}

void Tao_Xau(string a[], int SL_Xau, int k, int S[])
{
	SapXepGiam(a, 0, SL_Xau-1);
	for(int i = 0; i < SL_Xau; i++) S[i] = 0;
	int i = 0, idx = 0;
	while(k > 0 && i < SL_Xau)
	{
		if(k >= a[i].length())
		{
			S[idx] = i+1;
			k = k - a[i].length();
			idx++;
		}
		i++;
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
	cout << "NHAP SO LUONG XAU: ";
	int SL_Xau; cin >> SL_Xau;
	
	fflush(stdin);
	string DS_Xau[SL_Xau];
	cout << "NHAP THONG TIN CHO XAU: " << endl;
	for(int i = 0; i < SL_Xau; i++) 
	{
		cout << "XAU " << i+1 << endl;
		getline(cin, DS_Xau[i]);
	}
	
	cout << "NHAP DO DAI XAU CAN TAO: ";
	int k; cin >> k;
	int S[SL_Xau];
	Tao_Xau(DS_Xau,SL_Xau,k,S);
	cout << "CAC XAU DUOC CHON LA: ";
	for(int i = 0; i < SL_Xau; i++) cout << S[i] <<" ";
	
	cout << "\n=========\n\n";
	cout << "CAC XAU CO TU DUY" << endl;
	for(int i = 0; i < SL_Xau; i++)
	{
		if(B_M_H("duy", DS_Xau[i]) > 0) 
			cout << DS_Xau[i] << endl;
	}
	
	cout << "\n=========\n\n";
	cout << "XAU 1 : " << DS_Xau[0] << " LA XAU CON CUA NHUNG XAU: " << endl;
	for(int i = 1; i < SL_Xau; i++)
	{
		int Z[DS_Xau[0].length() + DS_Xau[i].length() + 1];
		if(KT_XauCon(DS_Xau[0], DS_Xau[i], Z) == 1) {
			cout << DS_Xau[i] << endl;
		}
	}
}

