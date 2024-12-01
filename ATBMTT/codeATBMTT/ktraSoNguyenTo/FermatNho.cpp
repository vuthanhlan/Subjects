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

// Hàm kiem tra so nguyen to theo dinh ly Fermat nho
bool isPrimeFermat(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Kiem tra k lan
    for (int i = 0; i < k; i++) {
        // Chon mot so ngau nhien trong khoang [2, n-2]
        // Luu y: rand() % (n-4) + 2 se sinh ra so trong khoang [2, n-3]
        int a = 2 + rand() % (n - 4);
        if (powerMod(a, n-1, n) != 1)
            return false;
    }
    return true;
}

int main() {
    srand(time(0)); // Khoi tao seed cho ham rand()

    int n, k;
    cout << "Nhap so can kiem tra: ";
    cin >> n;
    cout << "Nhap so lan kiem tra: ";
    cin >> k;

    if (isPrimeFermat(n, k))
        cout << n << " la so nguyen to." << endl;
    else
        cout << n << " khong phai la so nguyen to." << endl;

    return 0;
}
