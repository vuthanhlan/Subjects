#include <iostream>
#include <string>
#define MAX 100
using namespace std;

// KHAI BAO DL HANG HOA
struct HangHoa 
{
	string TenHangHoa;
	float KhoiLuong;
	float GiaBan;
};

// KHAI BAO DL DANH SACH
struct List 
{
	HangHoa E[MAX];
	int cnt;
};

// KHOI TAO DANH SACH
void Khoi_Tao_DS(List &DS_HangHoa, int SoLuongHangHoa)
{
	DS_HangHoa.cnt = SoLuongHangHoa - 1;
    
    DS_HangHoa.E[0].TenHangHoa = "Product 1";
    DS_HangHoa.E[0].KhoiLuong = 10.5;
    DS_HangHoa.E[0].GiaBan = 10.7;
    
    DS_HangHoa.E[1].TenHangHoa = "Product 2";
    DS_HangHoa.E[1].KhoiLuong = 11.5;
    DS_HangHoa.E[1].GiaBan = 11.7;
    
    DS_HangHoa.E[2].TenHangHoa = "Product 3";
    DS_HangHoa.E[2].KhoiLuong = 9.5;
    DS_HangHoa.E[2].GiaBan = 9.7;
    
    DS_HangHoa.E[3].TenHangHoa = "Product 4";
    DS_HangHoa.E[3].KhoiLuong = 12.5;
    DS_HangHoa.E[3].GiaBan = 12.7;
    
    DS_HangHoa.E[4].TenHangHoa = "Product 5";
    DS_HangHoa.E[4].KhoiLuong = 8.5;
    DS_HangHoa.E[4].GiaBan = 8.7;
    
    DS_HangHoa.E[5].TenHangHoa = "Product 6";
    DS_HangHoa.E[5].KhoiLuong = 13.5;
    DS_HangHoa.E[5].GiaBan = 13.7;
}

// TINH TONG GIA BAN
float Tong_Gia_Ban(List DS_HangHoa, int SoLuongHangHoa)
{
	if(SoLuongHangHoa == 0) return 0;	
	else
	{
		return DS_HangHoa.E[SoLuongHangHoa - 1].GiaBan + Tong_Gia_Ban(DS_HangHoa, SoLuongHangHoa - 1);
	}
}

// DEM SO LUONG HANG HOA CO GIA THAP HON P
int Dem_Gia_Ban(List DS_HangHoa, int left, int right, float p)
{
	if(left == right) 
	{
		if(DS_HangHoa.E[left].GiaBan < p) 
			return 1;
		else 
			return 0;
	}
	else
	{
		int mid = (left + right) / 2;
		int count_left = Dem_Gia_Ban(DS_HangHoa, left, mid, p);
		int count_right = Dem_Gia_Ban(DS_HangHoa, mid + 1, right, p);
		int count = count_left + count_right;
		return count;
	}
}

void show(int Xep[], int SoKe, List DS_HangHoa) {
    int Ke[SoKe];
    for (int i = 1; i <= SoKe; i++) Ke[i] = i;
    for (int i = 1; i <= SoKe; i++) 
	{
        cout << DS_HangHoa.E[Xep[i] - 1].TenHangHoa << " xep tai ke " << Ke[i] << endl;
    }
    cout << endl;
}

void Try(int k, int SoKe, int DD[], int Xep[], List DS_HangHoa) {
    for (int i = 1; i <= SoKe; i++) {
        if (DD[i] == 0) 
		{ 
            Xep[k] = i;
            if (k == SoKe) 
			{
            	show(Xep, SoKe, DS_HangHoa); 
            } 
			else 
			{
                DD[i] = 1; 
                Try(k + 1, SoKe, DD, Xep, DS_HangHoa);
                DD[i] = 0; 
            }
        }
    }
}

int main()
{
    // KHOI TAO SO LUONG HANG HOA
    int SoLuongHangHoa = 6;
    
    // KHAI BAO & KHOI TAO DANH SACH 
    List DS_HangHoa;
    Khoi_Tao_DS(DS_HangHoa, SoLuongHangHoa);
    
    // HIEN THI TONG GIA BAN
    cout << "TONG GIA BAN CUA DS HANG HOA: " << Tong_Gia_Ban(DS_HangHoa, SoLuongHangHoa) << endl;
    
    // KHOI TAO GIA TIEN P
    float p = 11.0;
    
    // HIEN THI SO LUONG GIA NHO HON P
    cout << "SO LUONG HANG HOA CO GIA BAN NHO HON "<< p << ": " << Dem_Gia_Ban(DS_HangHoa, 0, DS_HangHoa.cnt, p) << endl;
    
    // 
    cout << "CAC PHUONG AN XEP HANG LEN KE" << endl;
    int Xep[SoLuongHangHoa + 1];
    int DD[SoLuongHangHoa + 1];
    for(int i = 0; i <= SoLuongHangHoa; i++) DD[i] = 0;
    Try(1, SoLuongHangHoa, DD, Xep, DS_HangHoa);
}#include <iostream>
#include <string>
#define MAX 100
using namespace std;

// KHAI BAO DL HANG HOA
struct HangHoa 
{
	string TenHangHoa;
	float KhoiLuong;
	float GiaBan;
};

// KHAI BAO DL DANH SACH
struct List 
{
	HangHoa E[MAX];
	int cnt;
};

// KHOI TAO DANH SACH
void Khoi_Tao_DS(List &DS_HangHoa, int SoLuongHangHoa)
{
	DS_HangHoa.cnt = SoLuongHangHoa - 1;
    
    DS_HangHoa.E[0].TenHangHoa = "Product 1";
    DS_HangHoa.E[0].KhoiLuong = 10.5;
    DS_HangHoa.E[0].GiaBan = 10.7;
    
    DS_HangHoa.E[1].TenHangHoa = "Product 2";
    DS_HangHoa.E[1].KhoiLuong = 11.5;
    DS_HangHoa.E[1].GiaBan = 11.7;
    
    DS_HangHoa.E[2].TenHangHoa = "Product 3";
    DS_HangHoa.E[2].KhoiLuong = 9.5;
    DS_HangHoa.E[2].GiaBan = 9.7;
    
    DS_HangHoa.E[3].TenHangHoa = "Product 4";
    DS_HangHoa.E[3].KhoiLuong = 12.5;
    DS_HangHoa.E[3].GiaBan = 12.7;
    
    DS_HangHoa.E[4].TenHangHoa = "Product 5";
    DS_HangHoa.E[4].KhoiLuong = 8.5;
    DS_HangHoa.E[4].GiaBan = 8.7;
    
    DS_HangHoa.E[5].TenHangHoa = "Product 6";
    DS_HangHoa.E[5].KhoiLuong = 13.5;
    DS_HangHoa.E[5].GiaBan = 13.7;
}

// TINH TONG GIA BAN
float Tong_Gia_Ban(List DS_HangHoa, int SoLuongHangHoa)
{
	if(SoLuongHangHoa == 0) return 0;	
	else
	{
		return DS_HangHoa.E[SoLuongHangHoa - 1].GiaBan + Tong_Gia_Ban(DS_HangHoa, SoLuongHangHoa - 1);
	}
}

// DEM SO LUONG HANG HOA CO GIA THAP HON P
int Dem_Gia_Ban(List DS_HangHoa, int left, int right, float p)
{
	if(left == right) 
	{
		if(DS_HangHoa.E[left].GiaBan < p) 
			return 1;
		else 
			return 0;
	}
	else
	{
		int mid = (left + right) / 2;
		int count_left = Dem_Gia_Ban(DS_HangHoa, left, mid, p);
		int count_right = Dem_Gia_Ban(DS_HangHoa, mid + 1, right, p);
		int count = count_left + count_right;
		return count;
	}
}

void show(int Xep[], int SoKe, List DS_HangHoa) {
    int Ke[SoKe];
    for (int i = 1; i <= SoKe; i++) Ke[i] = i;
    for (int i = 1; i <= SoKe; i++) 
	{
        cout << DS_HangHoa.E[Xep[i] - 1].TenHangHoa << " xep tai ke " << Ke[i] << endl;
    }
    cout << endl;
}

void Try(int k, int SoKe, int DD[], int Xep[], List DS_HangHoa) {
    for (int i = 1; i <= SoKe; i++) {
        if (DD[i] == 0) 
		{ 
            Xep[k] = i;
            if (k == SoKe) 
			{
            	show(Xep, SoKe, DS_HangHoa); 
            } 
			else 
			{
                DD[i] = 1; 
                Try(k + 1, SoKe, DD, Xep, DS_HangHoa);
                DD[i] = 0; 
            }
        }
    }
}

int main()
{
    // KHOI TAO SO LUONG HANG HOA
    int SoLuongHangHoa = 6;
    
    // KHAI BAO & KHOI TAO DANH SACH 
    List DS_HangHoa;
    Khoi_Tao_DS(DS_HangHoa, SoLuongHangHoa);
    
    // HIEN THI TONG GIA BAN
    cout << "TONG GIA BAN CUA DS HANG HOA: " << Tong_Gia_Ban(DS_HangHoa, SoLuongHangHoa) << endl;
    
    // KHOI TAO GIA TIEN P
    float p = 11.0;
    
    // HIEN THI SO LUONG GIA NHO HON P
    cout << "SO LUONG HANG HOA CO GIA BAN NHO HON "<< p << ": " << Dem_Gia_Ban(DS_HangHoa, 0, DS_HangHoa.cnt, p) << endl;
    
    // 
    cout << "CAC PHUONG AN XEP HANG LEN KE" << endl;
    int Xep[SoLuongHangHoa + 1];
    int DD[SoLuongHangHoa + 1];
    for(int i = 0; i <= SoLuongHangHoa; i++) DD[i] = 0;
    Try(1, SoLuongHangHoa, DD, Xep, DS_HangHoa);
}
