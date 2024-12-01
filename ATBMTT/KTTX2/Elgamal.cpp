#include <bits/stdc++.h>
using namespace std;

//Tinh a^b mod n
long mod(int a, int b, int n) {
	int temp[50];
	int k = 0; 
	
    while (b > 0) {  
        temp[k] = b % 2; 
        b = b / 2; 
        k++; 
    }

    long f = 1;  
    for(int i = k-1; i >= 0; i--) {
    	f = (f * f) % n;
    	if(temp[i] == 1)
    		f = (f * a) % n;
	}
    return f;
}

//Ham kiem tra so nguyen to
int soNguyenTo(long n)
{
    if (n < 2)    
        return 0;
	if(n == 2)
		return 1;
    for (int i = 2; i <= sqrt((float)n); i ++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

//Tinh a^-1 mod n
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

int main() {
    long p, a, x, k;
    do {
        cout<<"Nhap so nguyen to: p = ";
        cin>>p;
    } while(!soNguyenTo(p));

    cout <<"Co so: a =  "; 
    cin>>a;

    cout <<"Khoa bi mat x (1 < x < p-1): "; 
    cin>>x;

	long y = mod(a, x, p);
    cout <<"Khoa cong khai y: " << y << endl;

    cout<<"Ta co cap khoa: "<<endl;
    cout<<"Khoa bi mat (p, a, x) = ("<<p<<", "<<a<<", "<<x<<")"<<endl;
    cout<<"Khoa cong khai (p, a, y) = ("<<p<<", "<<a<<", "<<y<<")"<<endl;

    //Ma hoa
    long m; 
    cout <<"Nhap m: ";
    cin >> m;
    
    cout <<"Chon ngau nhien k (1 < k < p-1): "; 
    cin>>k; 
    long c1 = mod(a, k, p);
    long c2 = (m * mod(y, k, p)) % p;

    cout << "Cap ma (c1, c2): (" << c1 << ", " << c2 << ")" << endl;

    //Giai ma M = c2 * K^-1 mod p
    long K = mod(c1, x, p);
    long giaiMa = (c2 * modInverse(K, p)) % p;
    cout << "Tin mat sau khi giai ma: " << giaiMa << endl;

    return 0;
}

