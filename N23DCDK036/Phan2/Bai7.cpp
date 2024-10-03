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

// Hàm lưu trữ cấu hình máy tính vào mảng (truyền tham chiếu để thay đổi trực tiếp)
void luuCauHinh(ComputerConfig &configs) {
    cout << "Nhap ten cau hinh: ";
    getline(cin, configs.tenCauHinh);

    cout << "Nhap toc do xung nhip cua bo xu ly (GHz): ";
    cin >> configs.tocDoXungNhip;

    cout << "Nhap so loi cua CPU: ";
    cin >> configs.soLoiCPU;

    cout << "Nhap dung luong RAM (GB): ";
    cin >> configs.dungLuongRAM;

    cout << "Nhap dung luong o cung (GB): ";
    cin >> configs.dungLuongOCu;

    cout << "Nhap diem danh gia hieu suat (cao hon la nhanh hon): ";
    cin >> configs.diemDanhGiaHieuSuat;

    cout << "Nhap gia cua may tinh: ";
    cin >> configs.gia;

    cin.ignore();  // Để tránh lỗi khi nhập chuỗi sau số
}

// Hàm hiển thị cấu hình máy tính
void hienThiCauHinh(const ComputerConfig &configs) {
    cout << "\n--- Thong tin cau hinh may tinh ---" << endl;
    cout << "Ten cau hinh: " << configs.tenCauHinh << endl;
    cout << "Toc do xung nhip: " << configs.tocDoXungNhip << " GHz" << endl;
    cout << "So loi CPU: " << configs.soLoiCPU << endl;
    cout << "Dung luong RAM: " << configs.dungLuongRAM << " GB" << endl;
    cout << "Dung luong o cung: " << configs.dungLuongOCu << " GB" << endl;
    cout << "Diem danh gia hieu suat: " << configs.diemDanhGiaHieuSuat << endl;
    cout << "Gia cua may tinh: " << configs.gia << " VND" << endl;
}

int main() {
    // Tạo đối tượng cấu hình máy tính
    ComputerConfig configs;

    // Lưu cấu hình máy tính
    luuCauHinh(configs);

    // Hiển thị cấu hình máy tính
    hienThiCauHinh(configs);

    return 0;
}
