#include <bits/stdc++.h>
using namespace std;

int soNguyenTo(int n)
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

int main() {
    int n;
    do {
        cout<<"NHap n = ";
        cin>>n;
    } while (n <= 0);

    if(soNguyenTo(n))   
        cout<<n<<" la so nguyen to";
    else cout<<n<<" khong la so nguyen to";
}