#include <iostream>
using namespace std;

// Cấu trúc để lưu thông tin ngày giờ
struct dateTime {
    int nam;   
    int thang;  
    int ngay;   
    int gio;    
    int phut;   
    int giay;   
};

// Hàm nhập ngày giờ
void nhapDateTime(dateTime& dt) {
    do {
        cout << "Nhap nam (>= 0): ";
        cin >> dt.nam;
    } while (dt.nam < 0);

    do {
        cout << "Nhap thang (1-12): ";
        cin >> dt.thang;
    } while (dt.thang < 1 || dt.thang > 12);

    do {
        cout << "Nhap ngay (1-31): ";
        cin >> dt.ngay;
    } while (dt.ngay < 1 || dt.ngay > 31);

    do {
        cout << "Nhap gio (0-23): ";
        cin >> dt.gio;
    } while (dt.gio < 0 || dt.gio > 23);

    do {
        cout << "Nhap phut (0-59): ";
        cin >> dt.phut;
    } while (dt.phut < 0 || dt.phut > 59);

    do {
        cout << "Nhap giay (0-59): ";
        cin >> dt.giay;
    } while (dt.giay < 0 || dt.giay > 59);
}

// Hàm so sánh hai ngày giờ
int soSanhNgayGio(const dateTime& dt1, const dateTime& dt2) {
    if (dt1.nam < dt2.nam) return -1;
    if (dt1.nam > dt2.nam) return 1;
    
    if (dt1.thang < dt2.thang) return -1;
    if (dt1.thang > dt2.thang) return 1;
    
    if (dt1.ngay < dt2.ngay) return -1;
    if (dt1.ngay > dt2.ngay) return 1;
    
    if (dt1.gio < dt2.gio) return -1;
    if (dt1.gio > dt2.gio) return 1;
    
    if (dt1.phut < dt2.phut) return -1;
    if (dt1.phut > dt2.phut) return 1;
    
    if (dt1.giay < dt2.giay) return -1;
    if (dt1.giay > dt2.giay) return 1;
    
    return 0;  // Hai thời điểm giống nhau
}

int main() {
    dateTime dt1, dt2;

    cout << "Nhap thong tin cho thoi diem 1:\n";
    nhapDateTime(dt1);
    
    cout << "\nNhap thong tin cho thoi diem 2:\n";
    nhapDateTime(dt2);

    int ketQua = soSanhNgayGio(dt1, dt2);
    
    if (ketQua == 0) {
        cout << "\nNgay gio giong nhau.\n";
    } else if (ketQua < 0) {
        cout << "\nThoi diem 1 den truoc thoi diem 2.\n";
    } else {
        cout << "\nThoi diem 2 den truoc thoi diem 1.\n";
    }

    return 0;
}
