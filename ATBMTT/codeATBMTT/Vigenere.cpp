#include <iostream>
#include <string>

using namespace std;

string Vigenere(const string& text, const string& key, bool decrypt = false)
{
    string result = "";
    int n = text.length();
    int keyLength = key.length();

    for(int i = 0; i < n; ++i)
    {
        if(isalpha(text[i]))
        {
            char ch = text[i];
            char keyChar = key[i%keyLength];
            int shift = (tolower(keyChar) - 'a');

            if(decrypt)
            {
                ch = (ch - 'a' - shift + 26) % 26 + 'a';
            } else
            {
                ch = (ch - 'a'+ shift)%26 + 'a';
            }
            result += ch;
        } else
        {
            result += text[i];
        }
    }
    return result;
}

int main()
{
    string text;
    string key;
    char choice;

    cout << "Nhap vao mot chuoi van ban: ";
    getline(cin, text);

    cout << "Nha[ vao tu khoa: ";
    getline(cin,key);

    cout << "Ban muon ma hoa (e) hay giai ma(d)?";
    cin >> choice;

    bool decrypt = (choice == 'd' || choice == 'D');

    string result = Vigenere(text, key, decrypt);
    if(decrypt)
    {
        cout << "Chuoi gia ma: " << result << endl;
    } else
    {
        cout << "Chuoi ma hoa: " << result << endl;
    }
    return 0;
}
