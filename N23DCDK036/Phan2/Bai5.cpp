#include <iostream>
#include <string>
using namespace std;

// Cau truc de luu tru thong tin ve mot cau trich dan
struct Quote {
    string tacGia;  
    string noiDung; 
    int soLuotThich; 
};

// Ham de ghi lai thong tin cua mot cau trich dan tu nguoi dung
void ghiLaiThongTinQuote(Quote &quote) {
    cout << "Nhap ten tac gia: ";
    getline(cin, quote.tacGia);
    
    cout << "Nhap noi dung cua cau trich dan: ";
    getline(cin, quote.noiDung);
    
    do {
        cout << "Nhap so luot thich (phai la so nguyen duong): ";
        cin >> quote.soLuotThich;
        if (quote.soLuotThich < 0) {
            cout << "So luot thich khong duoc am. Vui long nhap lai." << endl;
        }
    } while (quote.soLuotThich < 0);
    
    cin.ignore(); // Loai bo ky tu xuong dong con sot lai trong bo dem
}

int main() {
    Quote quote;
   
    ghiLaiThongTinQuote(quote);

    // Hien thi thong tin da ghi lai (chi de kiem tra ket qua)
    cout << "Tac gia: " << quote.tacGia << endl;
    cout << "Noi dung: " << quote.noiDung << endl;
    cout << "So luot thich: " << quote.soLuotThich << endl;
    cout << "-------------------------------" << endl;

    return 0;
}
