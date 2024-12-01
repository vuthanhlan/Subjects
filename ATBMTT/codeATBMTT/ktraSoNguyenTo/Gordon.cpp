#include <iostream>
#include <vector>

using namespace std;

// Ham tinh (a^b) % c khong dung ham ho tro
long long powerMod(long long a, long long b, long long c) {
    long long result = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return result;
}

// Kiem tra xem n co phai la so nguyen to khong
bool isPrime(long long n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Thuat toan kiem tra tinh nguyen to Gordon
bool gordonPrimeTest(long long n) {
    // Neu n la so nho, kiem tra truc tiep
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Tim s sao cho n-1 = 2^s * d voi d le
    long long s = 0;
    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // Kiem tra dieu kien Gordon
    for (long long a = 2; a <= min(n-2, 50LL); a++) {
        if (powerMod(a, d, n) != 1) {
            bool composite = true;
            for (long long r = 0; r < s; r++) {
                if (powerMod(a, (1LL << r) * d, n) == n - 1) {
                    composite = false;
                    break;
                }
            }
            if (composite)
                return false;
        }
    }
    return true;
}

int main() {
    long long n;
    cout << "Nhap so can kiem tra: ";
    cin >> n;

    if (gordonPrimeTest(n))
        cout << n << " la so nguyen to." << endl;
    else
        cout << n << " khong phai la so nguyen to." << endl;

    return 0;
}

