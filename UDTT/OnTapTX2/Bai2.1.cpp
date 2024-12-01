#include<bits/stdc++.h>
#include <iostream>
#include <string>

// Khai báo c?u trúc d? li?u c?a m?i chi?c qu?t
struct Fan {
    std::string manufacturer; // Tên hãng s?n xu?t
    std::string color;        // Màu s?c
    int price;                // Giá bán
};

int main() {
    int p=1000000;     // S? ti?n p
    int n=10;     // S? lu?ng chi?c qu?t
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

    // Nh?p giá tr? p
    std::cout << "Nhap so tien p: ";
    std::cin >> p;

    // Nh?p s? lu?ng và thông tin cho t?ng chi?c qu?t
    for (int i = 0; i < n; i++) {
        std::cout << "Nhap thong tin cho quat thu " << i + 1 << ": " << std::endl;
        std::cout << "Ten hang san xuat: ";
        std::cin >> fans[i].manufacturer;
        std::cout << "Mau sac: ";
        std::cin >> fans[i].color;
        std::cout << "Gia ban: ";
        std::cin >> fans[i].price;
    }

    // S?p x?p danh sách các chi?c qu?t theo giá bán tang d?n
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fans[i].price > fans[j].price) {
                Fan temp = fans[i];
                fans[i] = fans[j];
                fans[j] = temp;
            }
        }
    }

    // Tìm s? lu?ng chi?c qu?t c?n bán ít nh?t d? có s? ti?n "dúng b?ng p"
    int sum = 0; // T?ng giá tr? c?a các chi?c qu?t dã ch?n
    int count = 0; // S? lu?ng chi?c qu?t dã ch?n
    for (int i = 0; i < n; i++) {
        if (sum + fans[i].price <= p) {
            sum += fans[i].price;
            count++;
        } else {
            break;
        }
    }

    // Hi?n th? k?t qu?
    std::cout << "Can ban it nhat " << count << " chiec quat de co so tien \"dung bang p\":" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "Ten hang san xuat: " << fans[i].manufacturer << std::endl;
        std::cout << "Gia ban: " << fans[i].price << std::endl;
    }

    return 0;
}



