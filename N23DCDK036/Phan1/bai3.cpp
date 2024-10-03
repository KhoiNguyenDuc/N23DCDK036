#include <iostream>
#include <algorithm>
using namespace std;

void sap_xep_mang(int *diem_kiem_tra, int size) {
    sort(diem_kiem_tra, diem_kiem_tra + size);
}


// Hàm tính toán điểm trung bình sau khi loại bỏ điểm thấp nhất
double tinh_diem_trung_binh(int *diem, int size) {
    int total = 0;
    for (int i = 1; i < size; ++i) { // Bỏ qua phần tử đầu tiên (nhỏ nhất)
        total += *(diem + i);
    }
    return static_cast<double>(total) / (size - 1);
}

int main() {
    int soluong;

    cout << "Nhap so luong diem kiem tra: ";
    cin >> soluong;

    if (soluong <= 1) {
        cout << "So luong diem khong hop le." << endl;
        return 1;
    }

    int *diem = new int[soluong];
    for (int i = 0; i < soluong; ++i) {
        do {
            cout << "Nhap diem thu " << i + 1 << ": ";
            cin >> diem[i];
            if (diem[i] < 0) {
                cout << "Diem khong hop le, vui long nhap lai." << endl;
            }
        } while (diem[i] < 0);
    }

    sap_xep_mang(diem, soluong);
    double diem_trung_binh = tinh_diem_trung_binh(diem, soluong);

    cout << "\nDanh sach diem da sap xep: ";
    for (int i = 0; i < soluong; ++i) {
        cout << *(diem + i) << " ";
    }
    cout << "\nDiem trung binh (bo qua diem thap nhat): " << diem_trung_binh << endl;

    delete[] diem;
    return 0;
}
