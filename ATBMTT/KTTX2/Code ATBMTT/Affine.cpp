#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {	
	if(b == 0 )
		return a;
	if(a % b == 0)
		return b;
	return gcd(b, a % b);
}

int modInverse(int a, int n) {
	if(gcd(a, n) != 1)
		return 0;
	else {
		int r[50], q[50], x[50], y[50];
	
		r[0] = n; 
		r[1] = a;				
		x[0] = 0; 
		x[1] = 1;
		y[0] = 1; 
		y[1] = 0;
	 
		int i = 1;
		while (r[i] > 1) {
			r[i+1] = r[i-1] % r[i];
			q[i+1] = r[i-1] / r[i];
			x[i+1] = x[i-1] - q[i+1] * x[i];
			y[i+1] = y[i-1] - q[i+1] * y[i];
			i++;
		}
		
		if(x[i] < 0){
			x[i] += n;
		}	
		return x[i];
	}
	
}


string encryptMessage(string msg, int a, int b)
{
    string cipher = ""; 
    for (int i = 0; i < msg.length(); i++)
    {
        if (isupper(msg[i]) && msg[i] != ' ')
            cipher += ((((a * (msg[i] - 65) ) + b) % 26) + 65);
        else if(islower(msg[i]) && msg[i] != ' ')
            cipher += ((((a * (msg[i] - 97) ) + b) % 26) + 97);
        else 
            cipher += msg[i];   
    }
    return cipher;
}

string decryptCipher(string cipher, int a, int b)
{
    string msg = "";
    int a_inv = modInverse(a, 26);
     
    for (int i = 0; i < cipher.length(); i++)
    {
        if(isupper(cipher[i]) && cipher[i] != ' ')
			msg += ((a_inv * (cipher[i] - 65 - b + 26) % 26) + 65);
		else if(islower(cipher[i]) && cipher[i] != ' ')
			msg += ((a_inv * (cipher[i] - 97 - b + 26) % 26 ) + 97);
		else
			msg += cipher[i];						
    }
    return msg;
}
 
int main()
{
    string msg;
    cout<<"Input message: ";
    getline(cin, msg);

    cout<<"Input key: "<<endl;
    int a, b;
    do{ 
        cout<<"a = "; 
        cin>>a;
    } while(gcd(a, 26) != 1);

    cout<<"b = "; 
    cin>>b;

    cout<<"Message: "<<msg<<endl;

    string cipherText = encryptMessage(msg, a, b);
    cout << "Encrypted Message is : " <<cipherText<<endl;  
    cout << "Decrypted Message is: " << decryptCipher(cipherText, a, b);
 
    return 0;
}