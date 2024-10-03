#include <iostream>
using namespace std;

int* tach_vi_tri_chan(int *mang, int kich_thuoc, int &kich_thuoc_moi) {
    kich_thuoc_moi = (kich_thuoc + 1) / 2; // Tính số phần tử ở vị trí chẵn
    int *mang_moi = new int[kich_thuoc_moi];

    for (int i = 0, j = 0; i < kich_thuoc; i += 2, ++j) {
        mang_moi[j] = mang[i]; // Lấy phần tử ở vị trí chẵn
    }

    return mang_moi;
}

int main() {
    int mang[] = {1, 2, 3, 4, 5, 6};
    int kich_thuoc = sizeof(mang) / sizeof(mang[0]);
    int kich_thuoc_moi;
    int *mang_chan = tach_vi_tri_chan(mang, kich_thuoc, kich_thuoc_moi);
    
    cout << "Mang moi voi cac gia tri o vi tri chan:\n";
    for (int i = 0; i < kich_thuoc_moi; ++i) {
        cout << mang_chan[i] << " ";
    }
    cout << endl;

    delete[] mang_chan;

    return 0;
}
