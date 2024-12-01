#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MATRIX_SIZE = 2; // kích thu?c ma tr?n khóa

// Hàm tìm ma tr?n ngh?ch d?o
void inverseMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int det = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
    if (det < 0) det += 26;
    int detInv = -1;
    for (int i = 1; i < 26; i++)
    {
        if ((det * i) % 26 == 1)
        {
            detInv = i;
            break;
        }
    }
    if (detInv == -1)
    {
        cout << "Ma tran khong kha nghich!" << endl;
      return;
    }

    int temp = matrix[0][0];
    matrix[0][0] = matrix[1][1];
    matrix[1][1] = temp;
    matrix[0][1] = (-matrix[0][1]) % 26;
    matrix[1][0] = (-matrix[1][0]) % 26;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = (matrix[i][j] * detInv) % 26;
            if (matrix[i][j] < 0) matrix[i][j] += 26;
        }
    }
}

int getIndexFromChar(char c){
	string alphabet="abcdefghijklmnopqrstuvwxyz";
	
	c= tolower(c);
		
	for(int i=0; i<alphabet.length(); i++){
		if(c== alphabet[i]){
			return i;
		}
	}
}

char getCharFormIndex(int index){
	string alphabet="abcdefghijklmnopqrstuvwxyz";
	if(index >=0 && index <alphabet.length()){
		return alphabet[index];
	}
	else{
		return ' ';
	}
}

// Hàm mã hóa van b?n
string encrypt(string text, int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int n = text.length();
    if (n % MATRIX_SIZE != 0)
    {
        int padding = MATRIX_SIZE - (n % MATRIX_SIZE);
        for (int i = 0; i < padding; i++)
        {
            text += ' ';
        }
        n += padding;
    }

    string result = "";
    for (int i = 0; i < n; i += MATRIX_SIZE)
    {
        int block[MATRIX_SIZE] = {getIndexFromChar(text[i]), getIndexFromChar(text[i+1])};
        int cipherBlock[MATRIX_SIZE] = {0, 0};
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                cipherBlock[j] += matrix[j][k] * block[k];
            }
            cipherBlock[j] %= 26;
            result += getCharFormIndex(cipherBlock[j] );
        }
    }

    return result;
}

// Hàm gi?i mã van b?n
string decrypt(string text, int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
    int n = text.length();
    if (n % MATRIX_SIZE != 0)
    {
        cout << "Loi: Van b?n mã hóa không h?p l?!" << endl;
        return "";
    }

    inverseMatrix(matrix);

    string result = "";
    for (int i = 0; i < n; i += MATRIX_SIZE)
    {
        int block[MATRIX_SIZE] = {getIndexFromChar(text[i]), getIndexFromChar(text[i+1])};
        int plainBlock[MATRIX_SIZE] = {0, 0};
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                plainBlock[j] += matrix[j][k] * block[k];
            }
            plainBlock[j] %= 26;
            result += getCharFormIndex(plainBlock[j] );
        }
    }

    return result;
}

int main()
{
    string text, mahoa, giaima;
    int matrix[MATRIX_SIZE][MATRIX_SIZE], choice;
	int leng;
	do{
		cout << "Nhap vao van ban voi so ky tu là chan: ";
    	getline(cin, text);
    	leng= text.length();
	}while(leng%2!=0);
    

    cout << "Nhap vao cac phan tu cua ma tran khóa theo thu tu tu tren xuong duoi, tu trai sang phai: ";
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cin >> matrix[i][j];
        }
    }

//    cout << "Nhap vaomenu:\n";
//    cout << "1. Ma hoa van ban.\n";
//    cout << "2. Giai ma van ban.\n";
//    cout << "Nhap lua chon cua ban: ";
//    cin >> choice;

	mahoa = encrypt(text, matrix);
	cout << "Van ban da duoc ma hoa: " << mahoa << endl;
	giaima = decrypt(mahoa, matrix);
	cout << "Van ban da duoc giai ma: " << giaima << endl;
	

//    switch (choice)
//    {
//        case 1:
//            result = encrypt(text, matrix);
//            cout << "Van ban da duoc ma hoa: " << result << endl;
//            break;
//        case 2:
//            result = decrypt(text, matrix);
//            cout << "Van ban da duoc giai ma: " << result << endl;
//            break;
//        default:
//            cout << "Lua chon khong hop le!" << endl;
//            break;
//    }

    return 0;
}
