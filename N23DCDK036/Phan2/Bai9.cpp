#include <iostream>
#include <vector>
using namespace std;

// Cấu trúc máy tính
struct ComputerConfig {
    string tenCauHinh;
    float tocDoXungNhip;  
    int soCore;           
    int dungLuongRAM;     
    int dungLuongOCung;   
    float diemHieuSuat;   
    float gia;            
};

// Hàm nhập thông tin cấu hình máy tính
void nhapComputerConfig(ComputerConfig& config) {
    cout << "Nhap ten cau hinh: ";
    cin.ignore();  // Để bỏ qua ký tự '\n' trong buffer
    getline(cin, config.tenCauHinh);

    cout << "Nhap toc do xung nhip (GHz): ";
    cin >> config.tocDoXungNhip;

    cout << "Nhap so core cua CPU: ";
    cin >> config.soCore;

    cout << "Nhap dung luong RAM (GB): ";
    cin >> config.dungLuongRAM;

    cout << "Nhap dung luong o cung (GB): ";
    cin >> config.dungLuongOCung;

    // Kiểm tra điều kiện không chấp nhận giá trị âm
    do {
        cout << "Nhap diem hieu suat: ";
        cin >> config.diemHieuSuat;
        if (config.diemHieuSuat < 0) {
            cout << "Diem hieu suat khong hop le, vui long nhap lai!\n";
        }
    } while (config.diemHieuSuat < 0);

    do {
        cout << "Nhap gia cua cau hinh (USD): ";
        cin >> config.gia;
        if (config.gia < 0) {
            cout << "Gia khong hop le, vui long nhap lai!\n";
        }
    } while (config.gia < 0);
}

// Hàm hiển thị cấu hình máy tính
void hienThiComputerConfig(const ComputerConfig& config) {
    cout << "\nTen cau hinh: " << config.tenCauHinh << endl;
    cout << "Toc do xung nhip: " << config.tocDoXungNhip << " GHz" << endl;
    cout << "So core: " << config.soCore << endl;
    cout << "Dung luong RAM: " << config.dungLuongRAM << " GB" << endl;
    cout << "Dung luong o cung: " << config.dungLuongOCung << " GB" << endl;
    cout << "Diem hieu suat: " << config.diemHieuSuat << endl;
    cout << "Gia: " << config.gia << " USD\n";
}

// Hàm thay đổi giá của một cấu hình máy tính
void thayDoiGia(vector<ComputerConfig>& configs, int index) {
    if (index >= 0 && index < configs.size()) {
        cout << "Nhap gia moi cho cau hinh " << configs[index].tenCauHinh << ": ";
        float giaMoi;
        cin >> giaMoi;
        
        // Kiểm tra giá không âm
        while (giaMoi < 0) {
            cout << "Gia khong hop le, vui long nhap lai: ";
            cin >> giaMoi;
        }
        
        configs[index].gia = giaMoi;
        cout << "Gia da duoc thay doi.\n";
    } else {
        cout << "Cau hinh khong ton tai.\n";
    }
}

// Hàm tìm kiếm các cấu hình máy tính phù hợp với yêu cầu
void timKiemCauHinh(const vector<ComputerConfig>& configs, float diemHieuSuatToiThieu, float giaToiDa) {
    bool timThay = false;

    cout << "\nDanh sach cac cau hinh may tinh thoa man dieu kien:\n";
    cout << "-----------------------------------------------------\n";
    for (const auto& config : configs) {
        if (config.diemHieuSuat >= diemHieuSuatToiThieu && config.gia <= giaToiDa) {
            hienThiComputerConfig(config);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong co cau hinh may tinh nao thoa man dieu kien da cho.\n";
    }
}

int main() {
    vector<ComputerConfig> configs;
    int soCauHinh;
    int luaChon, index;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Them cau hinh may moi\n";
        cout << "2. Thay doi gia cau hinh\n";
        cout << "3. Hien thi toan bo cau hinh\n";
        cout << "4. Tim kiem cau hinh theo diem hieu suat va gia\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Nhập cấu hình máy tính mới
                cout << "\nNhap so luong cau hinh may tinh moi: ";
                int soCauHinhMoi;
                cin >> soCauHinhMoi;
                for (int i = 0; i < soCauHinhMoi; ++i) {
                    cout << "\nNhap thong tin cho cau hinh " << i + 1 << ":\n";
                    ComputerConfig config;
                    nhapComputerConfig(config);
                    configs.push_back(config);
                }
                break;
            }

            case 2: {
                // Thay đổi giá của cấu hình máy tính
                cout << "Nhap so thu tu cau hinh can thay doi gia (bat dau tu 0): ";
                cin >> index;
                thayDoiGia(configs, index);
                break;
            }

            case 3: {
                // Hiển thị toàn bộ cấu hình máy tính
                cout << "\nDanh sach cac cau hinh may tinh:\n";
                for (int i = 0; i < configs.size(); ++i) {
                    cout << "\nCau hinh " << i + 1 << ":\n";
                    hienThiComputerConfig(configs[i]);
                }
                break;
            }

            case 4: {
                // Tìm kiếm cấu hình máy tính theo điểm hiệu suất và giá
                float diemHieuSuatToiThieu, giaToiDa;
                cout << "Nhap diem hieu suat toi thieu: ";
                cin >> diemHieuSuatToiThieu;
                cout << "Nhap gia toi da (USD): ";
                cin >> giaToiDa;
                timKiemCauHinh(configs, diemHieuSuatToiThieu, giaToiDa);
                break;
            }

            case 0:
                cout << "Thoat chuong trinh...\n";
                break;

            default:
                cout << "Lua chon khong hop le, vui long chon lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}
