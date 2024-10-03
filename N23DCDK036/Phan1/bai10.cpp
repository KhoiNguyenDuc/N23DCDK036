#include <iostream>
using namespace std;

int* noi_mang(int *mang1, int kich_thuoc1, int *mang2, int kich_thuoc2) {
    int *mang_moi = new int[kich_thuoc1 + kich_thuoc2];

    for (int i = 0; i < kich_thuoc1; ++i) {
        mang_moi[i] = mang1[i];
    }
    for (int i = 0; i < kich_thuoc2; ++i) {
        mang_moi[kich_thuoc1 + i] = mang2[i];
    }

    return mang_moi;
}

int main() {
    int mang1[] = {1, 2, 3};
    int mang2[] = {4, 5, 6};
    int kich_thuoc1 = sizeof(mang1) / sizeof(mang1[0]);
    int kich_thuoc2 = sizeof(mang2) / sizeof(mang2[0]);

    int *mang_noi = noi_mang(mang1, kich_thuoc1, mang2, kich_thuoc2);

    cout << "Mang sau khi noi:\n";
    for (int i = 0; i < kich_thuoc1 + kich_thuoc2; ++i) {
        cout << mang_noi[i] << " ";
    }
    cout << endl;

    delete[] mang_noi;

    return 0;
}
