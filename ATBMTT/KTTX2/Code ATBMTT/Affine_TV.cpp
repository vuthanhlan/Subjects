#include <iostream>
#include <string>
#include <locale>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

wstring encryptMessage(const wstring &msg, int a, int b) {
    wstring cipher = L"";
    for (size_t i = 0; i < msg.length(); i++) {
        wchar_t ch = msg[i];
        if (iswalpha(ch)) {
            if (iswupper(ch))
                cipher += (wchar_t)((((a * (ch - 'A')) + b) % 26) + 'A');
            else
                cipher += (wchar_t)((((a * (ch - 'a')) + b) % 26) + 'a');
        } else {
            cipher += ch;
        }
    }
    return cipher;
}

int main() {
    setlocale(LC_ALL, "");
    
    wstring msg;
    wcout << "Nhap thong diep: ";
    getline(wcin, msg);

    wcout << "Nhap khoa: " << endl;
    int a, b;
    do {
        wcout << "a = ";
        wcin >> a;
    } while (a < 0 || a >= 26 || gcd(a, 26) != 1);

    wcout << "b = ";
    wcin >> b;

    wcout << "Thong diep: " << msg << endl;

    wstring cipherText = encryptMessage(msg, a, b);
    wcout << "Thong diep da ma hoa: " << cipherText << endl;

    return 0;
}

