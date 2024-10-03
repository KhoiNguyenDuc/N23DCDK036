#include <iostream>
using namespace std;

// Cấu trúc để lưu trữ thông tin về bộ phim
struct MovieData {
    string tenPhim;
    string daoDien;
    int namPhatHanh;
    int thoiLuong; 
};

// Hàm để hiển thị thông tin về bộ phim
void hienThiThongTinPhim(const MovieData &phim) {
    cout << "Ten phim: " << phim.tenPhim << endl;
    cout << "Dao dien: " << phim.daoDien << endl;
    cout << "Nam phat hanh: " << phim.namPhatHanh << endl;
    cout << "Thoi luong: " << phim.thoiLuong << " phut" << endl;
}

int main() {
    // Tạo hai biến cấu trúc DuLieuPhim
    MovieData phim1 = {"Ke Huy Diet", "James Cameron", 1984, 107};
    MovieData phim2 = {"Cuoc chien giua cac vi sao", "George Lucas", 1977, 121};

    // Hiển thị thông tin về từng bộ phim
    hienThiThongTinPhim(phim1);
    cout << endl;
    hienThiThongTinPhim(phim2);

    return 0;
}
