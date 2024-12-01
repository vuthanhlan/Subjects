#include<bits/stdc++.h>
using namespace std;
void loang(int i, int j) {
	int O[i][j];
	int flag[i][j] = true;
	if (j > 0) //Loang sang o ben trai
		if ((O[i][j-1] == O[i][j]) && (!flag[i][j-1]))
			loang(i, j - 1);
	if (i > 0) //Loang o ben tren
		if ((O[i-1][j] == O[i][j]) && (!flag[i-1][j]))
			loang(i - 1, j);
	if (j < 5) //Loang o ben phai
		if ((O[i][j+1] == O[i][j]) && (!flag[i][j+1]))
			loang(i, j + 1);
	if (i < 4) //Loang o ben duoi
		if ((O[i+1][j] == O[i][j]) && (!flag[i+1][j]))
			loang(i + 1, j);
}
int main(){
	int i,j;
	cout<<"Nhap i,j: ";	cin>>i>>j;
	loang(i,j);
}



