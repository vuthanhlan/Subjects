#include<bits/stdc++.h>
using namespace std;

struct Flight {
    string flightNumber;
    int price;
    int seatCount;
};

//khoi tao danh sach chuyen bay
void initializeFlights(Flight flights[], int& flightCount) {
    flights[0] = {"VN001", 500000, 100};
    flights[1] = {"VN002", 800000, 120};
    flights[2] = {"VN003", 700000, 80};
    flights[3] = {"VN004", 900000, 150};
    flights[4] = {"VN005", 600000, 200};
    flights[5] = {"VN006", 750000, 90};
    flightCount = 6;
}

// hien thi tat ca cac chuyen bay co gia ve trên 700000 bang phuong phap de quy
void displayFlightsAbovePrice(Flight flights[], int flightCount, int index, int price) {
    if (index >= flightCount) {
        return;
    }

    if (flights[index].price > price) {
        cout << "Flight Number: " << flights[index].flightNumber << endl;
        cout << "Price: " << flights[index].price << endl;
        cout << "Seat Count: " << flights[index].seatCount << endl;
        cout << endl;
    }

    displayFlightsAbovePrice(flights, flightCount, index + 1, price);
}

// tìm chuyen bay co gia ve thap nhat bang bang phuong phap chia de tri
int findMinimumPriceFlight(Flight flights[], int start, int end) {
    if (start == end) {
        return flights[start].price;
    }

    int mid = (start + end) / 2;
    int leftMin = findMinimumPriceFlight(flights, start, mid);
    int rightMin = findMinimumPriceFlight(flights, mid + 1, end);

    return (leftMin < rightMin) ? leftMin : rightMin;
}
//hien thi thong tin chuyen bay có gia ve thap nhat
void displayMinimumPriceFlight(Flight flights[], int flightCount) {
    int minPrice = findMinimumPriceFlight(flights, 0, flightCount - 1);

    for (int i = 0; i < flightCount; i++) {
        if (flights[i].price == minPrice) {
            cout << "Flight Number: " << flights[i].flightNumber << endl;
            cout << "Price: " << flights[i].price << endl;
            cout << "Seat Count: " << flights[i].seatCount <<endl;
            cout << endl;
            break;
        }
    }
}

// hien thi tat ca cac phuong an khac nhau de chon ra 4 chuyen bay tu ds b bang phuong phap quay lui
void findCombinations(Flight flights[], int flightCount, bool selected[], int index, int selectedCount) {
    if (selectedCount == 4) {
        for (int i = 0; i < flightCount; i++) {
            if (selected[i]) {
                cout << "Flight Number: " << flights[i].flightNumber << endl;
            }
        }
        cout << endl;
        return;
    }

    if (index >= flightCount) {
        return;
    }

    selected[index] = true;
    findCombinations(flights, flightCount, selected, index + 1, selectedCount + 1);

    selected[index] = false;
    findCombinations(flights, flightCount, selected, index + 1, selectedCount);
}

int main() {
    int MAX_FLIGHTS = 10;
    Flight flights[MAX_FLIGHTS];
    int flightCount;

    initializeFlights(flights, flightCount);

    cout << "Flights with price above 700000:" << endl;
    displayFlightsAbovePrice(flights, flightCount, 0, 700000);

    cout << "Flight with minimum price:" << endl;
    displayMinimumPriceFlight(flights, flightCount);

    cout << "All combinations of 4 flights:" << endl;
    bool selected[MAX_FLIGHTS] = {false};
    findCombinations(flights, flightCount, selected, 0, 0);

    return 0;
}


