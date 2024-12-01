#include<bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;


string numberToString(long long num) {
    string str;
    while (num > 0) {
        str = static_cast<char>(num % 256) + str;
        num /= 256;
    }
    return str;
}

long long stringToNumber(const string& str) {
    long long num = 0;
    for (int i=0; i<str.length(); i++) {
        num = num * 256 + static_cast<unsigned char>(str[i]);
    }
    return num;
}
// Hàm tính uoc chung lon nhat
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm kiem tra so nguyen to
bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
// Hàm random mot so nguyên to trong khoang [min, max]
int random_prime(int min, int max) {
    static bool first_time = true;
    if (first_time) {
        srand(time(NULL));
        first_time = false;
    }
    
    int num;
    do {
        num = min + (rand() % (max - min + 1));
    } while (!is_prime(num));
    
    return num;
}

// Hàm tính n
int generatePublicKey(int p, int q) {
    return p * q;
}

// Hàm tính phi
int generateEulerFunction(int p, int q) {
    return (p - 1) * (q - 1);
}
// Hàm tìm so nguyên to e
bool is_valid_e(int phi, int e) {
    if (e < 2 || e >= phi) return false;
    if (gcd(e, phi) != 1) return false;
    return true;
}

// Hàm tìm so nguyên to d
int findD(int e, int phi) {
    int a1=1, a2=0, a3=phi;
	int b1=0, b2=1, b3=e;
	while(b3>0){
		
		int Q = a3/b3;
		int R1= a1-Q*b1;
		int R2= a2-Q*b2;
		int R3= a3-Q*b3;
		
		a1 = b1;
		a2 = b2;
		a3 = b3;
		
		b1 = R1;
		b2 = R2; 
		b3 = R3;
		
		if(b3 == 1){
			if(b2 >0) return b2;
			else return phi+b2;
		}
	}
}
// Hàm tính a^b mod m
int modExp(int a, int b, int m) {
    int res = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

// MaHoa
int encrypt(int m, int e, int n) {
    
	return modExp(m, e, n);
}

// GiaiMa
int decrypt(int c, int d, int n) {
	
    return modExp(c, d, n);
}

int main() {
    int  n, phi, e, d;
    int plaintext, ciphertext;

    int p = random_prime(1,100);
    int q = random_prime(1,100);
    
    cout<<"q = "<<q<<endl;
	cout<<"p = "<<p<<endl;
   
    n = generatePublicKey(p,q);
    phi = generateEulerFunction(p,q);
    
    cout<<"n = "<<n<<endl;
	cout<<"phi= "<<phi<<endl;
    do{
    	e = random_prime(2,phi);
	}while(is_valid_e(phi,e)==false);	  
    
    cout<<"e = "<< e <<endl;
	d = findD(e, phi);
	cout<<"d = "<<d<<endl;

    // Nhap thông diep can mã hóa
//    cout << "Nhap thong diep can ma hoa (so nguyen): ";
//    cin >> plaintext;
	plaintext = random_prime(1,1000);
	cout<<"plaintext = "<<plaintext<<endl;
	
    // Mã hóa
    ciphertext = encrypt(plaintext, e, n);
    cout << "Ban ma: " << ciphertext << endl;

    // Giai mã
    int decrypted = decrypt(ciphertext, d, n);
    cout << "Ban ro: " << decrypted << endl;

    return 0;
}



