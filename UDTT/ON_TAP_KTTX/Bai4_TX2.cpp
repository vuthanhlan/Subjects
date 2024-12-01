#include <iostream>
#define MAX 100
using namespace std;

struct DienThoai
{
	string NhanHieu;
	int KichThuoc;
	int GiaBan;
};

void NhapDS(DienThoai DS_DT[], int SL_DT)
{
	cout << "NHAP THONG TIN CHO DIEN THOAI" << endl;
	for(int i = 1; i <= SL_DT; i++)
	{
		cout << "DIEN THOAI THU " << i << endl;
		cout << "NHAN HIEU: "; cin >> DS_DT[i].NhanHieu;
		cout << "KICH THUOC: "; cin >> DS_DT[i].KichThuoc;
		cout << "GIA BAN: "; cin >> DS_DT[i].GiaBan;
	}
}

void InDS(DienThoai DS_DT[], int SL_DT)
{
	cout << "THONG TIN DIEN THOAI" << endl;
	for(int i = 1; i <= SL_DT; i++)
	{
		cout << "DIEN THOAI THU " << i << endl;
		cout << "NHAN HIEU: " << DS_DT[i].NhanHieu << endl;
		cout << "KICH THUOC: " << DS_DT[i].KichThuoc << endl;
		cout << "GIA BAN: " << DS_DT[i].GiaBan << endl;
	}
}

void Luu_Phuong_An(DienThoai DS_DT[], int SL_DT, int KT_Tui, int Result[][MAX])
{
	for(int j = 0; j <= KT_Tui; j++) Result[0][j] = 0;
	for(int i = 1; i <= SL_DT; i++)
	{
		for(int j = 0; j <= KT_Tui; j++)
		{
			Result[i][j] = Result[i-1][j];
			if(DS_DT[i].KichThuoc <= j)
			{
				int tmp = DS_DT[i].GiaBan + Result[i-1][j-DS_DT[i].KichThuoc];
				if(Result[i][j] < tmp) 
					Result[i][j] = tmp;
			}
		}
	}
}

void In_Phuong_An(DienThoai DS_DT[], int SL_DT, int KT_Tui, int Result[][MAX])
{
	cout << "GIA TRI DIEN LON NHAT CO THE LAY: " << Result[SL_DT][KT_Tui] << endl;
	int i = SL_DT, j = KT_Tui;
	cout << "DANH SACH DIEN THOAI CO THE LAY: " << endl;
	int dem = 0;
	while(i != 0)
	{
		if(Result[i][j] != Result[i-1][j])
		{
			cout << DS_DT[i].NhanHieu << endl;
			cout << DS_DT[i].GiaBan << endl;
			j = j - DS_DT[i].KichThuoc;	
			dem++;
		}	
		i--;
	} 
	if(dem == 0) cout << "KHONG LAY DUOC DIEN THOAI NAO!";
}

int main()
{
	cout << "NHAP SO LUONG DIEN THOAI: ";
	int SL_DT; cin >> SL_DT;
	
	DienThoai DS_DT[SL_DT+1];
	NhapDS(DS_DT, SL_DT);
	
	cout << "NHAP KICH THUOC TUI: ";
	int KT_Tui; cin >> KT_Tui;
	
	cout << "\n==========\n\n";
	int Result[SL_DT+1][MAX];
	Luu_Phuong_An(DS_DT, SL_DT, KT_Tui, Result);
	In_Phuong_An(DS_DT, SL_DT, KT_Tui, Result);
}
