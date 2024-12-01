#include <iostream>
#include <cstring>
using namespace std;

// H�m t�m ngh?ch d?o c?a a modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// H�m ki?m tra t�nh d?ng du c?a a v� b modulo m
bool isCongruent(int a, int b, int m) {
    return (a % m) == (b % m);
}

// H�m m� h�a m?t k� t? b?ng ph�p affine
char encode(char c, int a, int b) {
    if ('a' <= c && c <= 'z') {
        return (char)((a * (c - 'a') + b) % 26 + 'a');
    } else if ('A' <= c && c <= 'Z') {
        return (char)((a * (c - 'A') + b) % 26 + 'A');
    } else {
        return c;
    }
}

// H�m gi?i m� m?t k� t? b?ng ph�p affine
char decode(char c, int a, int b) {
    if ('a' <= c && c <= 'z') {
        return (char)(modInverse(a, 26) * (c - 'a' - b + 26) % 26 + 'a');
    } else if ('A' <= c && c <= 'Z') {
        return (char)(modInverse(a, 26) * (c - 'A' - b + 26) % 26 + 'A');
    } else {
        return c;
    }
}

int main() {
    cout << "CHUONG TRINH MA HOA VA GIAI MA AFFINE\n";
    cout << "====================================\n";
    cout << "1. Ma hoa\n";
    cout << "2. Giai ma\n";
    cout << "3. Thoat\n";

    int choice;
    cout << "Nhap lua chon cua ban (1/2/3): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        return 0;
    }

    int a, b;
    cout << "Nhap he so a (a va 26 phai nguyen to cung nhau): ";
    cin >> a;

    if (modInverse(a, 26) == -1) {
        cout << "Nhap sai he so a. Vui long nhap lai.\n";
        return 0;
    }

    cout << "Nhap he so b: ";
    cin >> b;

    if (choice == 1) {
        // M� h�a
        string plaintext;
        cout << "Nhap vao van ban can ma hoa: ";
        cin.ignore();
        getline(cin, plaintext);

        string ciphertext = "";

        for (int i = 0; i < plaintext.length(); i++) {
            ciphertext += encode(plaintext[i], a, b);
        }

        cout << "Van ban da ma hoa: " << ciphertext << endl;

    } else {
        // Gi?i m�
        string ciphertext;
        cout << "Nhap vao van ban can giai ma: ";
        cin.ignore();
        getline(cin, ciphertext);

        string plaintext = "";

        for (int i = 0; i < ciphertext.length(); i++) {
            plaintext += decode(ciphertext[i], a, b);
        }

        cout << "Van ban da giai ma: " << plaintext << endl;
    }

    return 0;
}
