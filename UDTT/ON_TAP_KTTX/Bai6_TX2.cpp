#include<bits/stdc++.h>
#define MAX 100
using namespace std;

void Nhap(int &n, int &m, string &a, string &b)
{
	cout << "NHAP DO DAI CHO HAI SO NGUYEN: ";
	cin >> n >> m;
	do {
		cout << "NHAP SO NGUYEN CO DO DAI " << n << ": ";
		cin >> a;
	} while(a.length() > n);
	do {
		cout << "NHAP SO NGUYEN CO DO DAI " << m << ": ";
		cin >> b;
	} while(b.length() > m);
}

void Luu_Phuong_An(int n, int m, string a, string b, int Result[][MAX])
{
	for(int i = 0; i <= n; i++) Result[i][0] = 0;
	for(int i = 0; i <= m; i++) Result[0][i] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m ; j++)
		{
			if(a[i-1] ==  b[j-1]) 
				Result[i][j] = Result[i-1][j-1] + 1;
			else 
				Result[i][j] = max(Result[i-1][j], Result[i][j-1]);
		}
	}
}

string Tim_Phuong_An(int n, int m, string a, string b, int Result[][MAX])
{
	char kq[100];
	int i = n, j = m, k = 0;
	while(Result[i][j] != 0)
	{
		if(a[i - 1] == b[j - 1])
		{
			kq[k] = a[i-1];
			k++; i--; j--;
		}
		else
		{
			if(Result[i-1][j] > Result[i][j-1]) i--;
			else j--;
		}
	}
	kq[k] = '\0'; strrev(kq);
	return kq;
}

int main()
{
	int n, m;
	string a, b;
	Nhap(n,m,a,b);
	int Result[n + 1][MAX];
	Luu_Phuong_An(n,m,a,b,Result);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m ; j++)
		{
			cout << Result[i][j] << " ";
		}
		cout << endl;
	}
	cout << Tim_Phuong_An(n,m,a,b,Result);
}
