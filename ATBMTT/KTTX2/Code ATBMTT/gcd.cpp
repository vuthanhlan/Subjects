#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {	
	if(b == 0 )
		return a;
	if(a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main() {
    int a, b;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;

    cout<<"gcd("<<a<<", "<<b<<") = "<<gcd(a,b);
}