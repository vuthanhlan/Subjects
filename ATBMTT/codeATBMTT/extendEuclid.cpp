#include <iostream>
using namespace std;

// Ham thuat toan euclid mo rong
int extendedEuclid(int a, int b, int &x, int &y) {
    // Neu b = 0, tra ve a, x = 1, y = 0
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1; // Tim gia tri cua x và y
    int gcd = extendedEuclid(b, a % b, x1, y1);

    // Cap nhat gia tri cua x và y
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    cout << "Nhap 2 so nguyen a và b: ";
    cin >> a >> b;

    int x, y;
    int gcd = extendedEuclid(a, b, x, y);

    cout << "Uoc chung lon nhat cua " << a << " và " << b << " la: " << gcd << endl;
    cout << "Cac he so x va y thoa man phuong trinh ax + by = gcd là: " << x << " va " << y << endl;

    return 0;
}

