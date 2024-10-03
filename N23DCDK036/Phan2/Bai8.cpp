#include <iostream>
#include <string>
using namespace std;

// Cấu trúc lưu trữ thông tin về cấu hình máy tính
struct ComputerConfig {
    string tenCauHinh;         
    float tocDoXungNhip;       
    int soLoiCPU;              
    int dungLuongRAM;          
    int dungLuongOCu;          
    float diemDanhGiaHieuSuat; 
    float gia;                 
};

// Hàm thêm cấu hình máy mới vào danh sách
void themCauHinh(ComputerConfig &config) {
    cout << "Nhap ten cau hinh: ";
    getline(cin, config.tenCauHinh);

    cout << "Nhap toc do xung nhip cua bo xu ly (GHz): ";
    cin >> config.tocDoXungNhip;

    cout << "Nhap so loi cua CPU: ";
    cin >> config.soLoiCPU;

    cout << "Nhap dung luong RAM (GB): ";
    cin >> config.dungLuongRAM;

    cout << "Nhap dung luong o cung (GB): ";
    cin >> config.dungLuongOCu;

    cout << "Nhap diem danh gia hieu suat (cao hon la nhanh hon): ";
    cin >> config.diemDanhGiaHieuSuat;

    cout << "Nhap gia cua may tinh: ";
    cin >> config.gia;

    cin.ignore();  // Để tránh lỗi khi nhập chuỗi sau số
}

// Hàm thay đổi giá của một cấu hình máy tính
void thayDoiGia(ComputerConfig &config) {
    cout << "Nhap gia moi cua may tinh: ";
    cin >> config.gia;
}

// Hàm hiển thị thông tin các cấu hình máy tính
void hienThiCauHinh(ComputerConfig configs[], int n) {
    cout << "\nDanh sach cac cau hinh may tinh:\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Cau hinh " << i + 1 << ": " << endl;
        cout << "Ten cau hinh: " << configs[i].tenCauHinh << endl;
        cout << "Toc do xung nhip: " << configs[i].tocDoXungNhip << " GHz" << endl;
        cout << "So loi CPU: " << configs[i].soLoiCPU << endl;
        cout << "Dung luong RAM: " << configs[i].dungLuongRAM << " GB" << endl;
        cout << "Dung luong o cung: " << configs[i].dungLuongOCu << " GB" << endl;
        cout << "Diem danh gia hieu suat: " << configs[i].diemDanhGiaHieuSuat << endl;
        cout << "Gia: " << configs[i].gia << " VND" << endl;
        cout << "--------------------------------------------------\n";
    }
}

int main() {
    const int MAX = 5;  // Giới hạn số lượng cấu hình máy tính
    ComputerConfig configs[MAX];
    int count = 0;
    int choice;

    while (true) {
        cout << "\nMenu: \n";
        cout << "1. Them cau hinh may moi\n";
        cout << "2. Thay doi gia cua cau hinh\n";
        cout << "3. Hien thi danh sach cau hinh\n";
        cout << "4. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;
        cin.ignore();  // Loại bỏ ký tự xuống dòng còn lại

        switch (choice) {
            case 1:
                if (count < MAX) {
                    themCauHinh(configs[count]);
                    count++;
                } else {
                    cout << "Danh sach da day. Khong the them cau hinh moi!" << endl;
                }
                break;
            case 2:
                if (count == 0) {
                    cout << "Chua co cau hinh nao de thay doi gia!" << endl;
                } else {
                    int index;
                    cout << "Nhap chi so cau hinh can thay doi gia (1-" << count << "): ";
                    cin >> index;
                    if (index >= 1 && index <= count) {
                        thayDoiGia(configs[index - 1]);
                    } else {
                        cout << "Chi so cau hinh khong hop le!" << endl;
                    }
                }
                break;
            case 3:
                if (count == 0) {
                    cout << "Danh sach cau hinh rong!" << endl;
                } else {
                    hienThiCauHinh(configs, count);
                }
                break;
            case 4:
                cout << "Thoat chuong trinh." << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                break;
        }
    }

    return 0;
}
