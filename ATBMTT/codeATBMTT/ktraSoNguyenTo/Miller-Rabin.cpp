#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Ham tinh (a^b) % c
long long powerMod(long long a, long long b, long long c) {
    long long result = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % c;
        b = b >> 1;
        a = (a * a) % c;
    }
    return result;
}

// Ham kiem ho tro tra Miller-Rabin
bool millerTest(long long d, long long n) {
    // Chon mot so ngau nhien trong khoang [2, n-2]
    long long a = 2 + rand() % (n - 4);

    // Tinh a^d % n
    long long x = powerMod(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Lien tuc binh phuong x cho den khi d dat n-1
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    // Tra ve composite
    return false;
}

// Ham kiem tra so nguyen to theo thuat toan Miller-Rabin
bool isPrimeMillerRabin(long long n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Tim d sao cho n-1 = d * 2^r
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Kiem tra k lan
    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main() {
    srand(time(0)); // Khoi tao seed cho ham rand()

    long long n;
    int k;
    cout << "Nhap so can kiem tra: ";
    cin >> n;
    cout << "Nhap so lan kiem tra: ";
    cin >> k;

    if (isPrimeMillerRabin(n, k))
        cout << n << " la so nguyen to." << endl;
    else
        cout << n << " khong phai la so nguyen to." << endl;

    return 0;
}
