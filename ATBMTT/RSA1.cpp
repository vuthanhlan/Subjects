#include <iostream>
#include <cmath>
#include <vector>
#include <sstream> // Include <sstream> for std::stringstream
#include <cstdlib>
#include <ctime>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long modInverse(long long e, long long phi) {
    long long m0 = phi, t, q;
    long long x0 = 0, x1 = 1;
    if (phi == 1)
        return 0;
    while (e > 1) {
        q = e / phi;
        t = phi;
        phi = e % phi, e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

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
void generateKeys(long long &n, long long &e, long long &d) {
    long long p, q;
//    cout << "Enter two prime numbers p and q:\n";
//    cin >> p >> q;
	
	p=random_prime(1,100);
	q=random_prime(1,100);
    n = p * q;
    long long phi = (p - 1) * (q - 1);

    e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    d = modInverse(e, phi);
}

string encryptMessage(string message, long long e, long long n) {
    vector<long long> encryptedMessage;
    for (char c : message) {
        long long m = (long long)c;
        encryptedMessage.push_back(power(m, e, n));
    }
    string encryptedString = "";
    for (long long c : encryptedMessage) {
        encryptedString += to_string(c) + " ";
    }
    return encryptedString;
}

string decryptMessage(vector<long long> encryptedMessage, long long d, long long n) {
    string decryptedMessage = "";
    for (long long c : encryptedMessage) {
        long long m = power(c, d, n);
        decryptedMessage += (char)m;
    }
    return decryptedMessage;
}

int main() {
    long long n, e, d;
    int choice;
    string message;

    do {
        cout << "\nRSA Encryption System\n";
        cout << "1. Enter message to encrypt\n";
        cout << "2. Generate keys\n";
        cout << "3. Encrypt message\n";
        cout << "4. Decrypt message\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the message: ";
                cin.ignore();
                getline(cin, message);
                break;
            case 2:
                generateKeys(n, e, d);
                cout << "Public Key: (" << e << ", " << n << ")\n";
                cout << "Private Key: (" << d << ", " << n << ")\n";
                break;
            case 3: {
                string encryptedMessage = encryptMessage(message, e, n);
                cout << "Encrypted message: " << encryptedMessage << "\n";
                break;
            }
            case 4: {
cout << "Enter the encrypted message (space separated integers): ";
                cin.ignore();
                string encryptedInput;
                getline(cin, encryptedInput);
                vector<long long> encryptedMessage;
                long long num;
                stringstream ss(encryptedInput); // Ensure stringstream is used correctly
                while (ss >> num) {
                    encryptedMessage.push_back(num);
                }
                string decryptedMessage = decryptMessage(encryptedMessage, d, n);
                cout << "Decrypted message: " << decryptedMessage << "\n";
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}