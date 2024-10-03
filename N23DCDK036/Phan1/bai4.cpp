#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void sap_xep(string *tenhs, int *diem, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (diem[i] > diem[j]) {
                swap(diem[i], diem[j]);
                swap(tenhs[i], tenhs[j]);
            }
        }
    }
}

double tinh_diem_trung_binh(int *diem, int size) {
    int tong = 0;
    for (int i = 0; i < size; ++i) {
        tong += *(diem + i);
    }
    return static_cast<double>(tong) / size;
}

int main() {
    int soluonghocsinh;

    cout << "Nhap so luong hoc sinh: ";
    cin >> soluonghocsinh;

    if (soluonghocsinh <= 0) {
        cout << "So luong khong hop le." << endl;
        return 1;
    }

    string *tenhs = new string[soluonghocsinh];
    int *diem = new int[soluonghocsinh];

    for (int i = 0; i < soluonghocsinh; ++i) {
        cout << "Nhap ten hoc sinh thu " << i + 1 << ": ";
        cin >> tenhs[i];
        do {
            cout << "Nhap diem cua " << tenhs[i] << ": ";
            cin >> diem[i];
            if (diem[i] < 0) {
                cout << "Diem khong hop le, vui long nhap lai." << endl;
            }
        } while (diem[i] < 0);
    }

    sap_xep(tenhs, diem, soluonghocsinh);
    
    double diem_trung_binh = tinh_diem_trung_binh(diem, soluonghocsinh);

    cout << "\nDanh sach hoc sinh va diem sau khi sap xep: \n";
    for (int i = 0; i < soluonghocsinh; ++i) {
        cout << tenhs[i] << ": " << *(diem + i) << endl;
    }

    cout << "Diem trung binh: " << diem_trung_binh << endl;

    delete[] tenhs;
    delete[] diem;

    return 0;
}
