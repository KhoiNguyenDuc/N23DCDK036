#include <iostream>
using namespace std;

// Cấu trúc để lưu trữ thông tin về bộ phim bao gồm cả chi phí sản xuất và doanh thu
struct MovieData {
    string tenPhim;
    string daoDien;
    int namPhatHanh;
    int thoiLuong; 
    double chiPhiSanXuat; 
    double doanhThu; 
};

// Hàm để hiển thị thông tin về bộ phim và tính toán lợi nhuận hoặc thua lỗ
void hienThiThongTinPhim(const MovieData &phim) {
    cout << "Ten phim: " << phim.tenPhim << endl;
    cout << "Dao dien: " << phim.daoDien << endl;
    cout << "Nam phat hanh: " << phim.namPhatHanh << endl;
    cout << "Thoi luong: " << phim.thoiLuong << " phut" << endl;
    
    // Tính toán lợi nhuận hoặc thua lỗ
    double loiNhuan = phim.doanhThu - phim.chiPhiSanXuat;
    
    if (loiNhuan >= 0) {
        cout << "Loi nhuan: $" << loiNhuan << endl;
    } else {
        cout << "Thua lo: $" << -loiNhuan << endl;
    }
}

int main() {
    // Tạo hai biến cấu trúc DuLieuPhim
    MovieData phim1 = {"Ke Huy Diet", "James Cameron", 1984, 107, 6.4e6, 78.3e6};
    MovieData phim2 = {"Cuoc Chien Giua Cac Vi Sao", "George Lucas", 1977, 121, 11e6, 775.4e6};

    // Hiển thị thông tin về từng bộ phim
    hienThiThongTinPhim(phim1);
    cout << endl;
    hienThiThongTinPhim(phim2);

    return 0;
}
