#include <iostream>

using namespace std;

// Ham tinh (a^b) % n su dung thuat toan binh phuong nhan
long long powerMod(long long a, long long b, long long n) {
    long long result = 1;
    a = a % n; // Dua a ve gia tri nho hon n

    while (b > 0) {
        // Neu b la so le, nhan ket qua voi a
        if (b % 2 == 1) {
            result = (result * a) % n;
        }
        // b chia doi và a binh phuong
        b = b >> 1; // tuong duong voi b /= 2
        a = (a * a) % n;
    }

    return result;
}

int main() {
    long long a, b, n;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap n: ";
    cin >> n;

    cout << "Ket qua cua " << a << "^" << b << " mod " << n << " la: " << powerMod(a, b, n) << endl;

    return 0;
}

