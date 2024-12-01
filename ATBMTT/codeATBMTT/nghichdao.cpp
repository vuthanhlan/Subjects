#include <iostream>
using namespace std;

// Ham thuat toan euclid mo rong
int extendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// ham nghic dao
int modInverse(int a, int n) {
    int x, y;
    int gcd = extendedEuclid(a, n, x, y);

    if (gcd != 1) {
        //kiem tra nguyen to cung nhau
        cout << "Nghich dao khong ton tai vi a va n khong nguyen to cung nhau." << endl;
        return -1;
    }
	
    int result = (x % n + n) % n;
    return result;
}

int main() {
    int a, n;
    cout << "Nhap a va n: ";
    cin >> a >> n;

    int inverse = modInverse(a, n);
    if (inverse != -1) {
        cout << "Nghich dao cua " << a << " tren modulo " << n << " la: " << inverse << endl;
    }

    return 0;
}
