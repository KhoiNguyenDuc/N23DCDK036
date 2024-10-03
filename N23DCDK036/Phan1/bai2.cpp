#include <iostream>
#include <algorithm>
using namespace std;

void sap_xep_mang(int *diem_kiem_tra, int size) {
    sort(diem_kiem_tra, diem_kiem_tra + size); // Sắp xếp mảng bằng con trỏ
}

double tinh_diem_trung_binh(int *diem_kiem_tra, int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += *(diem_kiem_tra + i); // Sử dụng con trỏ
    }
    return static_cast<double>(total) / size;
}

int main() {
    int soluong;

    cout << "Nhap so luong diem kiem tra: ";
    cin >> soluong;

    if (soluong <= 0) {
        cout << "So luong diem khong hop le." << endl;
        return 1;
    }

    // Phân bố động mảng
    int *diem_kiem_tra = new int[soluong];
    for (int i = 0; i < soluong; ++i) {
        do {
            cout << "Nhap diem thu " << i + 1 << ": ";
            cin >> diem_kiem_tra[i];
            if (diem_kiem_tra[i] < 0) {
                cout << "Diem khong hop le, vui long nhap lai." << endl;
            }
        } while (diem_kiem_tra[i] < 0);
    }

    sap_xep_mang(diem_kiem_tra, soluong);
    double diem_trung_binh = tinh_diem_trung_binh(diem_kiem_tra, soluong);

    cout << "\nDanh sach diem da sap xep: ";
    for (int i = 0; i < soluong; ++i) {
        cout << *(diem_kiem_tra + i) << " ";
    }
    cout << "\nDiem trung binh: " << diem_trung_binh << endl;

    // Giải phóng bộ nhớ
    delete[] diem_kiem_tra;

    return 0;
}
