#include <iostream>
#include <string>
using namespace std;

// Cau truc luu tru thong tin cau trich dan
struct Quote {
    string tacGia;       
    string noiDung;      
    int luotThich;       
};

// Ham tinh tong luot thich va so luot thich trung binh
void thongKeCauTrichDan(Quote quotes[], int n) {
    int tongLuotThich = 0;
    
    // Tinh tong so luot thich
    for (int i = 0; i < n; i++) {
        if (quotes[i].luotThich < 0) {
            cout << "So luot thich khong hop le (khong chap nhan gia tri am). Vui long kiem tra lai." << endl;
            return;
        }
        tongLuotThich += quotes[i].luotThich;
    }

    // Tinh luot thich trung binh
    double luotThichTrungBinh = static_cast<double>(tongLuotThich) / n;

    // Hien thi ket qua
    cout << "\nTong so luot thich: " << tongLuotThich << endl;
    cout << "So luot thich trung binh: " << luotThichTrungBinh << endl;
    cout << "\nDanh sach cau trich dan pho bien hon muc trung binh:" << endl;
    cout << "----------------------------------------" << endl;

    // Hien thi cac cau trich dan pho bien hon muc trung binh va phan tram luot thich cua moi cau
    for (int i = 0; i < n; i++) {
        if (quotes[i].luotThich > luotThichTrungBinh) {
            double phanTram = (static_cast<double>(quotes[i].luotThich) / tongLuotThich) * 100;
            cout << "Cau trich dan: " << quotes[i].noiDung << endl;
            cout << "Tac gia: " << quotes[i].tacGia << endl;
            cout << "So luot thich: " << quotes[i].luotThich << " (" << phanTram << "%)" << endl;
            cout << "----------------------------------------" << endl;
        }
    }
}

int main() {
    const int N = 5;  // So luong cau trich dan
    Quote quotes[N];

    // Nhap du lieu cho cac cau trich dan
    for (int i = 0; i < N; i++) {
        cout << "Nhap thong tin cho cau trich dan thu " << i + 1 << ":" << endl;
        
        cout << "Nhap tac gia: ";
        getline(cin, quotes[i].tacGia);
        
        cout << "Nhap noi dung cau trich dan: ";
        getline(cin, quotes[i].noiDung);
        
        do {
            cout << "Nhap so luot thich (khong duoc am): ";
            cin >> quotes[i].luotThich;
            if (quotes[i].luotThich < 0) {
                cout << "So luot thich khong hop le. Vui long nhap lai." << endl;
            }
        } while (quotes[i].luotThich < 0);
        
        cin.ignore();  // Loai bo ky tu xuong dong con lai
        cout << endl;
    }

    // Goi ham de tinh toan va hien thi ket qua
    thongKeCauTrichDan(quotes, N);

    return 0;
}
