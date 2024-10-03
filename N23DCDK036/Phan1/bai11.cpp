#include <iostream>
using namespace std;

int* ham_loc_mang(int *mang, int kich_thuoc, int boi_so, int &kich_thuoc_moi) {
    kich_thuoc_moi = 0;
    for (int i = 0; i < kich_thuoc; ++i) {
        if (mang[i] % boi_so == 0) {
            kich_thuoc_moi++;
        }
    }

    int *mang_moi = new int[kich_thuoc_moi];
    int chi_so = 0;

    for (int i = 0; i < kich_thuoc; ++i) {
        if (mang[i] % boi_so == 0) {
            mang_moi[chi_so++] = mang[i];
        }
    }

    return mang_moi;
}

int main() {
    int mang[] = {7, 14, 21, 28, 35, 5, 10};
    int kich_thuoc = sizeof(mang) / sizeof(mang[0]);

    int boi_so = 7;
    int kich_thuoc_moi;
    int *mang_loc = ham_loc_mang(mang, kich_thuoc, boi_so, kich_thuoc_moi);

    cout << "Mang sau khi loc (boi so cua " << boi_so << "):\n";
    for (int i = 0; i < kich_thuoc_moi; ++i) {
        cout << mang_loc[i] << " ";
    }
    cout << endl;

    delete[] mang_loc;

    return 0;
}
