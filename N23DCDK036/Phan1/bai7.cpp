#include <iostream>
#include <unordered_map>
using namespace std;

int tim_gia_tri_thinh_hanh(int *mang, int kich_co) {
    unordered_map<int, int> tan_so;
    int gia_tri_thinh_hanh = -1, tan_so_max = 1;
    for (int i = 0; i < kich_co; ++i) {
        tan_so[mang[i]]++;
        if (tan_so[mang[i]] > tan_so_max) {
            tan_so_max = tan_so[mang[i]];
            gia_tri_thinh_hanh = mang[i];
        }
    }

    return (tan_so_max > 1) ? gia_tri_thinh_hanh : -1;
}

int main() {
    int mang[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int kich_co = sizeof(mang) / sizeof(mang[0]);
    int gia_tri_thinh_hanh = tim_gia_tri_thinh_hanh(mang, kich_co);
    if (gia_tri_thinh_hanh != -1) {
        cout << "Gia tri thinh hanh la: " << gia_tri_thinh_hanh << endl;
    } else {
        cout << "Khong co gia tri thinh hanh." << endl;
    }
    return 0;
}
