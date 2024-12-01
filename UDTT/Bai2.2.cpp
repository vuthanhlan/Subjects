# include <bits/stdc++.h>
using namespace std;

int ThamLam(float a[], int n, float c, float S[])
{
	for(int i = 0; i < n; i++) S[i] = 0;
	int idx = n-1; int dem = 0;
	while(c >= 0 && idx >= 0)
	{
		S[n-idx-1] = a[idx];
		c = c - a[idx];
		idx--; dem++;
	}
	return dem;
}
int B_M_H(string con, string cha, int S1[])
{
	int idx = 0, len_con = con.length(), i = len_con - 1;
	while(i < cha.length())
	{
		int x = len_con - 1;
		while(cha[i] == con[x] && x >= 0) {
			i--; x--;
		}
		if(x < 0) {
			S1[idx] = i+1; idx++;
			i = i + len_con + 1;
		}
		else {
			int k = con.find(cha[i]);
			if(k < 0) i = i + len_con;
			else i = i + len_con - k - 1; 
		}
	}
	return idx;
}

int main()
{
	int n = 5;
	float a[n] = {1.1, 2.2, 3.3, 4.4, 7.7};
	float c = 6.6;	
	string P = "huu duy huu duy";
	string Q = "duy";
	
	float S[n];
	if(ThamLam(a,n,c,S) > 0) 
	{
		cout << "SO LUONG PHAN TU THOA MAN: " << ThamLam(a,n,c,S) << " BAO GOM ";
		for(int i = 0; i < n; i++) {
			if(S[i] != 0) cout << S[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "KHONG CO PHAN TU NAO THOA MAN";
	}
	
	int S1[10] = {0};
	cout << "SO LAN XUAT HIEN CUA Q TRONG P: " << B_M_H(Q, P, S1) << endl;
	cout << "CAC VI TRI XUAT HIEN CUA Q TRONG P: " ;
	for(int i = 0; i < 10 ; i++) {
		if(S1[i] !=0 ) cout << S1[i] << " ";
	}
}
