#include <iostream>
#include <vector>

using namespace std;

// Ham sang Eratosthenes de tim tat ca cac so nguyen to nho hon hoac bang n
void sieveOfEratosthenes(int n) {
    // Tao mot vecto danh dau tat ca cac so tu 0 den n la so nguyen to
    vector<bool> isPrime(n + 1, true);

    // 0 và 1 khong phai la so nguyen to
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        // Neu isPrime[p] van la true, thi p la mot so nguyen to
        if (isPrime[p]) {
            // Danh dau tat ca cac boi so cua p la khong phai so nguyen to
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    // In ra tat ca cac so nguyen to
    for (int p = 2; p <= n; p++) {
        if (isPrime[p])
            cout << p << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    cout << "Cac so nguyen to nho hon hoac bang " << n << " la: ";
    sieveOfEratosthenes(n);

    return 0;
}

