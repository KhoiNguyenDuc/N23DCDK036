#include <iostream>
#include <string>
using namespace std;

// Cau truc de luu tru thong tin ve tran dong dat
struct Earthquake {
    string ten;           
    string viTri;          
    int namXayRa;          
    float doLon;           
    int soNguoiThietMang;  
};

// Ham ghi lai thong tin cua mot tran dong dat
void ghiLaiThongTinDongDat(Earthquake &dongDat) {
    cout << "Nhap ten tran dong dat: ";
    getline(cin, dongDat.ten);
    
    cout << "Nhap vi tri cua tran dong dat: ";
    getline(cin, dongDat.viTri);
    
    cout << "Nhap nam xay ra: ";
    cin >> dongDat.namXayRa;
    
    cout << "Nhap do lon cua tran dong dat theo thang Richter: ";
    cin >> dongDat.doLon;
    
    do {
        cout << "Nhap so nguoi thiet mang (phai la so nguyen duong): ";
        cin >> dongDat.soNguoiThietMang;
        if (dongDat.soNguoiThietMang < 0) {
            cout << "So nguoi thiet mang khong duoc am. Vui long nhap lai." << endl;
        }
    } while (dongDat.soNguoiThietMang < 0);

    cin.ignore(); // Loai bo ky tu xuong dong con sot lai trong bo dem
}

// Ham hien thi thong tin cua tran dong dat
void hienThiThongTinDongDat(const Earthquake &dongDat) {
    cout << "Thong tin tran dong dat:" << endl;
    cout << "Ten tran dong dat: " << dongDat.ten << endl;
    cout << "Vi tri: " << dongDat.viTri << endl;
    cout << "Nam xay ra: " << dongDat.namXayRa << endl;
    cout << "Do lon: " << dongDat.doLon << " theo thang Richter" << endl;
    cout << "So nguoi thiet mang: " << dongDat.soNguoiThietMang << endl;
    cout << "-------------------------------" << endl;
}

int main() {
    const int SO_TRAT_DONG_DAT = 3;
    Earthquake dongDat[SO_TRAT_DONG_DAT];

    for (int i = 0; i < SO_TRAT_DONG_DAT; i++) {
        cout << "Nhap thong tin cho tran dong dat thu " << i + 1 << ":" << endl;
        ghiLaiThongTinDongDat(dongDat[i]);
        cout << endl;
    }

    cout << "Thong tin cac tran dong dat da ghi lai:" << endl;
    for (int i = 0; i < SO_TRAT_DONG_DAT; i++) {
        hienThiThongTinDongDat(dongDat[i]);
    }

    return 0;
}
