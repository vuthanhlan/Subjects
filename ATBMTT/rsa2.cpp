#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Hàm tìm ước chung lớn nhất (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm tìm số nghịch đảo modulo
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

int modpow(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent / 2;
        base = (base * base) % modulus;
    }
    return result;
}

char encrypt(char c, int e, int n) {
    int m = static_cast<int>(c);
    return static_cast<char>(modpow(m, e, n));
}

char decrypt(char c, int d, int n) {
    int m = static_cast<int>(c);
    return static_cast<char>(modpow(m, d, n));
}

int main() {
    int p, q, n, e, d;
    string plaintext, ciphertext;

    // Nhập hai số nguyên tố p và q
    cout << "Nhap so nguyen to p: ";
    cin >> p;
    cout << "Nhap so nguyen to q: ";
    cin >> q;

    // Tính n = p * q
    n = p * q;
    cout << "n = " << n << endl;

    // Tính số Euler của n
    int phi = (p - 1) * (q - 1);
    cout << "Phi(n) = " << phi << endl;

    // Chọn số e sao cho 1 < e < phi(n) và gcd(e, phi(n)) = 1
    e = 65537; // Một số phổ biến
    while (gcd(e, phi) != 1) {
        e++;
    }
    cout << "e = " << e << endl;

    // Tính số d sao cho d * e ≡ 1 (mod phi(n))
    d = modInverse(e, phi);
    cout << "d = " << d << endl;

    // Nhập văn bản gốc
    cout << "Nhap van ban goc: ";
    cin.ignore();
    getline(cin, plaintext);

    // Mã hóa văn bản gốc
    for (char c : plaintext) {
        ciphertext += encrypt(c, e, n);
    }
    cout << "Van ban ma hoa: " << ciphertext << endl;

    // Giải mã văn bản mã hóa
    string decryptedText;
    for (char c : ciphertext) {
         decryptedText += decrypt(c, d, n);
    }
    cout << "Van ban giai ma: " << decryptedText << endl;

    return 0;
}