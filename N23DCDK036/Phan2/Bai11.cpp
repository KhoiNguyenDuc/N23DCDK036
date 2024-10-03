#include <iostream>
#include <string>
using namespace std;

// Cấu trúc để lưu thông tin diễn giả
struct Speaker {
    string ten;             
    string soDienThoai;     
    string chuDe;           
    float phiDienThuyet;    
};

// Hàm hiển thị toàn bộ danh sách diễn giả
void hienThiDanhSach(Speaker speakers[], int soLuong) {
    cout << "\nDanh sach cac dien gia:\n";
    for (int i = 0; i < soLuong; i++) {
        cout << "\nDien gia " << i + 1 << ":\n";
        cout << "Ten: " << speakers[i].ten << endl;
        cout << "So dien thoai: " << speakers[i].soDienThoai << endl;
        cout << "Chu de bai phat bieu: " << speakers[i].chuDe << endl;
        cout << "Phi dien thuyet: " << speakers[i].phiDienThuyet << " VND" << endl;
    }
}

// Hàm thêm một diễn giả mới vào danh sách
void themDienGia(Speaker speakers[], int& soLuong) {
    if (soLuong >= 10) {
        cout << "Danh sach dien gia da day. Khong the them moi.\n";
        return;
    }

    cout << "\nNhap ten dien gia: ";
    cin.ignore();  // Để bỏ qua ký tự '\n' sau khi đọc số
    getline(cin, speakers[soLuong].ten);

    cout << "Nhap so dien thoai: ";
    getline(cin, speakers[soLuong].soDienThoai);

    cout << "Nhap chu de bai phat bieu: ";
    getline(cin, speakers[soLuong].chuDe);

    do {
        cout << "Nhap phi dien thuyet (VND): ";
        cin >> speakers[soLuong].phiDienThuyet;
        if (speakers[soLuong].phiDienThuyet < 0) {
            cout << "Phi dien thuyet khong the la so am. Vui long nhap lai.\n";
        }
    } while (speakers[soLuong].phiDienThuyet < 0);

    soLuong++;  // Tăng số lượng diễn giả đã thêm
}

// Hàm thay đổi thông tin của một diễn giả
void thayDoiThongTin(Speaker speakers[], int soLuong) {
    int index;

    cout << "\nNhap index (1-" << soLuong << ") cua dien gia can thay doi: ";
    cin >> index;

    if (index < 1 || index > soLuong) {
        cout << "Index khong hop le.\n";
        return;
    }

    cout << "Nhap ten dien gia moi: ";
    cin.ignore();  // Để bỏ qua ký tự '\n' sau khi đọc số
    getline(cin, speakers[index - 1].ten);

    cout << "Nhap so dien thoai moi: ";
    getline(cin, speakers[index - 1].soDienThoai);

    cout << "Nhap chu de bai phat bieu moi: ";
    getline(cin, speakers[index - 1].chuDe);

    do {
        cout << "Nhap phi dien thuyet moi (VND): ";
        cin >> speakers[index - 1].phiDienThuyet;
        if (speakers[index - 1].phiDienThuyet < 0) {
            cout << "Phi dien thuyet khong the la so am. Vui long nhap lai.\n";
        }
    } while (speakers[index - 1].phiDienThuyet < 0);
}

// Hàm hiển thị menu và thực hiện các chức năng
void menu(Speaker speakers[], int& soLuong) {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Them dien gia\n";
        cout << "2. Thay doi thong tin dien gia\n";
        cout << "3. Hien thi danh sach dien gia\n";
        cout << "4. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                themDienGia(speakers, soLuong);
                break;
            case 2:
                thayDoiThongTin(speakers, soLuong);
                break;
            case 3:
                hienThiDanhSach(speakers, soLuong);
                break;
            case 4:
                cout << "Thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (choice != 4);
}

int main() {
    Speaker speakers[10];  // Mảng chứa tối thiểu 10 diễn giả
    int soLuong = 0;       // Số lượng diễn giả đã thêm vào

    menu(speakers, soLuong);

    return 0;
}
