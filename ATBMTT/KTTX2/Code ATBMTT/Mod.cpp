#include<bits/stdc++.h>

using namespace std;

int binaryNum[1000]; 

long mod(int a, int b, int n) {
	int temp[50];
	int k = 0; 
	
    while (b > 0) {  
        temp[k] = b % 2; 
        b = b / 2; 
        k++; 
    }
    
//  int index = 0;
//	for(int j = k - 1; j >= 0; j--){
//    	cout<<temp[j]<<endl;
//	}
    
    long f = 1;
    
    for(int i = k-1; i >= 0; i--) {
    	f = (f * f) % n;
    	if(temp[i] == 1)
    		f = (f * a) % n;
	}

    return f;
}

int main() {
	int a, b, n;
	
	cout<<"a = "; cin>>a;
	cout<<"b = "; cin>>b;
	cout<<"n = "; cin>>n;	

	cout<< a <<"^"<< b <<" mod "<< n <<" = "<<mod(a, b, n);
}






