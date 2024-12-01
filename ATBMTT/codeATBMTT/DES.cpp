#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

// H�m ho�n v?
bitset<32> permutation(bitset<32> input, const int* table, int size) {
    bitset<32> output;

    for (int i = 0; i < size; i++) {
        output[i] = input[table[i] - 1];
    }

    return output;
}

// H�m d?ch tr�i xoay v�ng
bitset<28> leftCircularShift(bitset<28> input, int shift) {
    return (input << shift) | (input >> (28 - shift));
}

// H�m n?i hai bitset
bitset<64> concatenate(bitset<32> left, bitset<32> right) {
    bitset<64> output;
    for (int i = 0; i < 32; i++) {
        output[i] = left[i];
        output[i + 32] = right[i];
    }
    return output;
}

// H�m chia d�i m?t bitset
void split(bitset<64> input, bitset<32>& left, bitset<32>& right) {
    for (int i = 0; i < 32; i++) {
        left[i] = input[i];
        right[i] = input[i + 32];
    }
}

// H�m m? r?ng bitset t? 32 bit l�n 48 bit
bitset<48> expand(bitset<32> input, const int* table, int size) {
    bitset<48> output;

    for (int i = 0; i < size; i++) {
        output[i] = input[table[i] - 1];
    }

    return output;
}

// H�m t�nh h�m f
bitset<32> f(bitset<32> right, bitset<48> subkey) {
    // M? r?ng right t? 32 bit l�n 48 bit
    right = expand(right, E, 48);

    // XOR v?i subkey
    right ^= subkey;

    // Chia 48 bit th�nh 8 nh�m 6 bit
    bitset<6> groups[8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            groups[i][j] = right[i * 6 + j];
        }
    }

    // �p d?ng h?p S
    bitset<4> output[8];
    for (int i = 0; i < 8; i++) {
        int row = groups[i][0] * 2 + groups[i][5];
        int col = groups[i][1] * 8 + groups[i][2] * 4 + groups[i][3] * 2 + groups[i][4];
        int value = S[i][row][col];
        output[i] = bitset<4>(value);
    }

    // N?i c�c bitset 4 bit l?i th�nh m?t bitset 32 bit
    bitset<32> outputBitset;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            outputBitset[i * 4 + j] = output[i][j];
        }
    }

    // �p d?ng ho�n v? P
    outputBitset = permutation(outputBitset, P, 32);

    return outputBitset;
}

// H�m t�nh subkeys
void generateSubkeys(bitset<64> key, bitset<48> subkeys[]) {
    // N�n kh�a t? 64 bit xu?ng 56 bit
    bitset<56> compressedKey = permutation(key, PC1, 56);

    // Chia kh�a th�nh hai n?a
    bitset<28> left, right;
    for (int i = 0; i < 28; i++) {
        left[i] = compressedKey[i];
        right[i] = compressedKey[i + 28];
    }

    // T?o 16 subkeys
    for (int i = 0; i < 16; i++) {
        // D?ch tr�i xoay v�ng
        left = leftCircularShift(left, SHIFT[i]);
        right = leftCircularShift(right, SHIFT[i]);

        // N?i l?i v� n�n xu?ng 48 bit
        bitset<56> shiftedKey =concatenate(left, right);
        subkeys[i] = permutation(shiftedKey, PC2, 48);
    }
}

// H�m m� h�a m?t kh?i 64 bit b?ng DES
bitset<64> encrypt(bitset<64> plaintext, bitset<48> subkeys[]) {
    // Kh?i t?o kh?i 64 bit ban d?u
    plaintext = permutation(plaintext, IP, 64);

    // Chia kh?i th�nh hai n?a
    bitset<32> left, right;
    split(plaintext, left, right);

    // �p d?ng 16 v�ng l?p
    for (int i = 0; i < 16; i++) {
        bitset<32> temp = right;
        right = left ^ f(right, subkeys[i]);
        left = temp;
    }

    // N?i l?i v� ho�n v?
    plaintext = concatenate(right, left);
    plaintext = permutation(plaintext, FP, 64);

    return plaintext;
}

int main() {
    cout << "CHUONG TRINH MA HOA VA GIAI MA DES\n";
    cout << "==================================\n";
    cout << "1. Ma hoa\n";
    cout << "2. Giai ma\n";
    cout << "3. Thoat\n";

    int choice;
    cout << "Nhap lua chon cua ban (1/2/3): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        return 0;
    }

    bitset<64> key;
    cout << "Nhap khao (64 bit): ";
    cin >> key;

    bitset<48> subkeys[16];
    generateSubkeys(key, subkeys);

    if (choice == 1) {
        // M� h�a
        string plaintext;
        cout << "Nhap vao van ban can ma hoa: ";
        cin.ignore();
        getline(cin, plaintext);

        // Chuy?n d?i van b?n th�nh d�y bit
        bitset<64> bitstream;
        int bitsProcessed = 0;
        for (char c : plaintext) {
            for (int i = 7; i >= 0; i--) {
                bitstream[bitsProcessed] = (c >> i) & 1;
                bitsProcessed++;
                if (bitsProcessed == 64) {
                    // �? 64 bit, m� h�a kh?i n�y
                    bitset<64> ciphertext = encrypt(bitstream, subkeys);
                    cout << "Ket qua ma hoa: " << ciphertext.to_ullong() << endl;
                    bitstream.reset();
                    bitsProcessed = 0;
                }
            }
        }

        if (bitsProcessed > 0) {
            // C�n du bit, b? sung th�m bit 0 v� m� h�a
            while (bitsProcessed < 64) {
                bitstream[bitsProcessed] = 0;
                bitsProcessed++;
            }
            bitset<64> ciphertext = encrypt(bitstream, subkeys);
            cout << "Ket qua ma hoa: " << ciphertext.to_ullong() << endl;
        }

    } else {
        // Gi?i m�
        bitset<64> ciphertext;
        cout << "Nhap vao ma hoa can giai ma: ";
        cin >> ciphertext;

        // M� h�a kh?i 64 bit
        bitset<64> plaintext = encrypt(ciphertext, subkeys);

        // Chuy?n d?i d�y bit th�nh van b?n
        string output = "";
        int bitsProcessed = 0;
        char c = 0;
        for (int i = 0; i < 64; i++) {
            c <<= 1;
            c |= plaintext[i];
            bitsProcessed++;
            if (bitsProcessed == 8) {
                output += c;
                bitsProcessed = 0;
                c = 0;
            }
        }

        cout << "Ket qua giai ma: " << output << endl;
    }

    return 0;
}
