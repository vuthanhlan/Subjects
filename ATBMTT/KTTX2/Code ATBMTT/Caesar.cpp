#include<bits/stdc++.h>

using namespace std;

string encrypt(string text, int key) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        // Encrypt Uppercase letters
        if (isupper(text[i]) && text[i] != ' ')
            result += (text[i] + key - 65) % 26 + 65;
        // Encrypt Lowercase letters
        else if(islower(text[i]) && text[i] != ' ')
            result += (text[i] + key - 97) % 26 + 97;
        else 
            result += text[i];
    }

    return result;
}
 
string decrypt(string text, int key) {
	string result = "";

    for (int i = 0; i < text.length(); i++) {

        // Encrypt Uppercase letters
        if (isupper(text[i]) && text[i] != ' ')
            result += (text[i] - key - 65) % 26 + 65;
        // Encrypt Lowercase letters
        else if(islower(text[i]) && text[i] != ' ')
            result += (text[i] - key - 97) % 26 + 97;
        else 
            result += text[i];
    }

    return result;
}

int main()
{
    string text;
    cout<<"Input string:";
    fflush(stdin);
    getline(cin, text);

    int key = 0;
    cout<<"Input key: ";
    cin>>key;

    cout << "Text: " << text;
    cout << "\nKey: " << key;
    cout<<"\n-------------------------";
    cout << "\nCipher: " << encrypt(text, key);
    
    cout << "\nPlaintextr: " << decrypt(encrypt(text, key), key);
    return 0;
}