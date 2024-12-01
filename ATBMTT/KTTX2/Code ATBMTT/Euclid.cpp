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

int main() {
	int a, n;
	cout<<"a = "; cin>>a;
	cout<<"n = "; cin>>n;

	if(modInverse(a, n) == 0)
		cout<<"Khong ton tai phan tu nghich dao"<<endl;
	else cout<<"Ptu nghich dao = "<<modInverse(a, n);
}