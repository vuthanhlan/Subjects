#include <iostream>
#include <string>
using namespace std;
struct Fan {
    string manufacturer;
    string color;
    int price;
};

void greedyAlgorithm(Fan fans[], int n, int p) {
    int count = 0;
    int totalCost = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (totalCost + fans[i].price <= p) {
            count++;
            totalCost += fans[i].price;
            cout << fans[i].manufacturer << " - Price: " << fans[i].price << endl;
        }
    }

    cout << "Total fans sold: " << count << endl;
}

int main() {
    int p = 1000000; 
    int n = 10; 

    Fan fans[n];

    fans[0] = {"Manufacturer A", "Red", 500000};
    fans[1] = {"Manufacturer B", "Blue", 200000};
    fans[2] = {"Manufacturer C", "Green", 300000};
    fans[3] = {"Manufacturer D", "Yellow", 400000};
    fans[4] = {"Manufacturer E", "White", 100000};
    fans[5] = {"Manufacturer F", "Black", 150000};
    fans[6] = {"Manufacturer G", "Gray", 250000};
    fans[7] = {"Manufacturer H", "Pink", 350000};
    fans[8] = {"Manufacturer I", "Purple", 450000};
    fans[9] = {"Manufacturer J", "Orange", 550000};

    greedyAlgorithm(fans, n, p);

    return 0;
}




