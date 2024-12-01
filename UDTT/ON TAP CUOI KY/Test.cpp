#include <bits/stdc++.h>
using namespace std;

struct GoiHang
{
	float KL;
	float GT;
};

void KhoiTao(GoiHang DS_GH[])
{
	DS_GH[1].KL = 12;
	DS_GH[1].GT = 4;
	
	DS_GH[2].KL = 2;
	DS_GH[2].GT = 2;
	
	DS_GH[3].KL = 1;
	DS_GH[3].GT = 1;
	
	DS_GH[4].KL = 1; 
	DS_GH[4].GT = 2;
	
	DS_GH[5].KL = 4; 
	DS_GH[5].GT = 10;
}

void SapXepTang(GoiHang DS_GH[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		float t = DS_GH[mid].GT;
		int i = left, j = right;
		do {
			while(DS_GH[i].GT < t) i++;
			while(DS_GH[j].GT > t) j--;
			if(i <= j) {
				GoiHang tmp = DS_GH[i];
				DS_GH[i] = DS_GH[j];
				DS_GH[j] = tmp;
				i++; j--;
			}
		} while(i <= j);
		SapXepTang(DS_GH, left, j);
		SapXepTang(DS_GH, i, right);
	}
}

int ThamLam(GoiHang DS_GH[], int SL, float c, int S[])
{
	SapXepTang(DS_GH, 1, SL);
	for(int i = 0; i < SL; i++) S[i] = 0;
	int sum = 0, idx = 0;
	for(int i = 1; i <= SL; i++)
	{
		if(sum + DS_GH[i].GT <= c)
		{
			S[idx] = i;
			sum += DS_GH[i].GT;
			idx++;
		}
	}
	if(sum == c) return idx;
	else return 0;
}

int main()
{
	int SL = 5;
	GoiHang DS_GH[SL];
	KhoiTao(DS_GH);
	
	float c = 8;
	int S[SL];
	cout << "SO LUONG GOI HANG CO THE LAY: " << ThamLam(DS_GH, SL, c, S) << endl;
	if(ThamLam(DS_GH, SL, c, S) > 0) 
	{
		for(int i = 0; i < SL; i++) {
			if(S[i] != 0) cout << DS_GH[S[i]].GT << " ";
		}
	}
	
	
	string p = "huu duy";
	string q = "duy";
}

   


