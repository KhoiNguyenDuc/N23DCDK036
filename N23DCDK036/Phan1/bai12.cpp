#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

double tim_median(int *arr, int kich_thuoc) {
    sort(arr, arr + kich_thuoc);
    if (kich_thuoc % 2 == 0) {
        return (arr[kich_thuoc / 2 - 1] + arr[kich_thuoc / 2]) / 2.0;
    } else {
        return arr[kich_thuoc / 2];
    }
}

int tim_mode(int *arr, int kich_thuoc) {
    unordered_map<int, int> tan_suat;
    int mode = -1, tan_suat_max = 1;

    for (int i = 0; i < kich_thuoc; ++i) {
        tan_suat[arr[i]]++;
        if (tan_suat[arr[i]] > tan_suat_max) {
            tan_suat_max = tan_suat[arr[i]];
            mode = arr[i];
        }
    }
    return (tan_suat_max > 1) ? mode : -1;
}

double tinh_trung_binh(int *arr, int kich_thuoc) {
    int tong = 0;
    for (int i = 0; i < kich_thuoc; ++i) {
        tong += arr[i];
    }
    return static_cast<double>(tong) / kich_thuoc;
}

int main() {
    int so_sinh_vien;
    cout << "Nhap so luong sinh vien duoc khao sat: ";
    cin >> so_sinh_vien;
    
    if (so_sinh_vien <= 0) {
        cout << "So luong khong hop le." << endl;
        return 1;
    }
    
    int *so_phim = new int[so_sinh_vien];
    
    for (int i = 0; i < so_sinh_vien; ++i) {
        do {
            cout << "Nhap so phim sinh vien thu " << i + 1 << " da xem: ";
            cin >> so_phim[i];
            if (so_phim[i] < 0) {
                cout << "So phim khong hop le, vui long nhap lai." << endl;
            }
        } while (so_phim[i] < 0);
    }
    
    double trung_binh = tinh_trung_binh(so_phim, so_sinh_vien);
    double median = tim_median(so_phim, so_sinh_vien);
    int mode = tim_mode(so_phim, so_sinh_vien);
    
    cout << "\nDiem trung binh: " << trung_binh << endl;
    cout << "Median: " << median << endl;
    
    if (mode != -1) {
        cout << "Mode: " << mode << endl;
    } else {
        cout << "Khong co mode." << endl;
    }
    
    delete[] so_phim;
    return 0;
}
