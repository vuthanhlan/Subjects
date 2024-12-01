#include<bits/stdc++.h>
using namespace std;

// khai bao cau truc hang hoa
struct HangHoa {
    char ten[100];
    float khoiLuong;
    int giaBan;
};

// Tinh tong gia ban
int TinhTongGiaBan(HangHoa* danhSach, int n) {
    if (n == 0) {
        return 0;
    } else {
        return danhSach[n - 1].giaBan + TinhTongGiaBan(danhSach, n - 1);
    }
}

// Thuat toan chia de tri dem so hang hoa co gia thap hon p
int DemHangHoaGiaThap(HangHoa* danhSach, int n, int p) {
    if (n == 0) {
        return 0;
    } else if (danhSach[n - 1].giaBan < p) {
        return 1 + DemHangHoaGiaThap(danhSach, n - 1, p);
    } else {
        return DemHangHoaGiaThap(danhSach, n - 1, p);
    }
}

// kiem tra xem hang hoa co the xep vao ke hang duoc danh so tu 1 den n hay không
bool CoTheXepVaoKeHang(HangHoa* danhSach, int n, int* keHang, int hangHoaIndex) {
    for (int i = 0; i < n; i++) {
        if (keHang[i] == hangHoaIndex) {
            return false;  // Hang hoa da duoc xep vao ke hang khac
        }
    }
    return true;
}

// Phuong pháp quay lui de xep hang hoa vao ke hang
void XepHangHoaVaoKeHang(HangHoa* danhSach, int n, int* keHang, int hangHoaIndex) {
    if (hangHoaIndex == n) {
        //hien thi phuong an xep hang hoa vao ke hang
        for (int i = 0; i < n; i++) {
            cout << "Hang hoa " << danhSach[i].ten << " xep vao ke hang " << keHang[i] << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (CoTheXepVaoKeHang(danhSach, n, keHang, i)) {
            keHang[hangHoaIndex] = i;
            XepHangHoaVaoKeHang(danhSach, n, keHang, hangHoaIndex + 1);
            keHang[hangHoaIndex] = 0;
        }
    }
}

int main() {
    
    // Khoi tao hang hoa
    int n = 6; // so hang hoa
    HangHoa danhSach[] = {
        {"Hang hoa 1", 2.5, 10000},
        {"Hang hoa 2", 1.8, 8000},
        {"Hang hoa 3", 3.2, 15000},
        {"Hang hoa 4", 2.0, 12000},
        {"Hang hoa 5", 2.7, 9000},
        {"Hang hoa 6", 1.5, 7000}
    };

    // Tinh gia ban cua tat ca hang hoa
    int tongGiaBan = TinhTongGiaBan(danhSach, n);
    cout << "Tong gia ban cua tat ca hang hoa: " << tongGiaBan << " VND" << endl;

    // Khoi tao so tien p
    int p = 10000;

    // Dem so hang hang hoa co gia thap hon p
    int soHangHoaGiaThap = DemHangHoaGiaThap(danhSach, n, p);
    cout << "So hang hoa co gia thap hon " << p << ": " << soHangHoaGiaThap << endl;

    // khoi tao mang luu ke
    int keHang[n];
    memset(keHang, 0, sizeof(keHang));

    // hien thi tat ca cac phuong an xep hang hoa vao ke hang
    XepHangHoaVaoKeHang(danhSach, n, keHang, 0);

    return 0;
}




