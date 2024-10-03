#include <iostream>
using namespace std;

void sap_xep_giam_dan(int *[], int);
void hien_thi_mang(const int [], int);
void hien_thi_con_tro(int *[], int);

int main(){
    const int so_luong_dong_gop = 15; 
    int gia_tri[so_luong_dong_gop] = { 5, 100, 5, 25, 10, 5, 25, 5, 5, 100, 10, 15, 10, 5, 10 };
    int *mang_con_tro[so_luong_dong_gop] = { nullptr };
    for (int dem = 0; dem < so_luong_dong_gop; dem++)
        mang_con_tro[dem] = &gia_tri[dem];
    sap_xep_giam_dan(mang_con_tro, so_luong_dong_gop);
    cout << "Danh sach dong gop da sap xep (giam dan):\n";
    hien_thi_con_tro(mang_con_tro, so_luong_dong_gop);
    cout << "Danh sach dong gop ban dau:\n";
    hien_thi_mang(gia_tri, so_luong_dong_gop);

    return 0;
}

void sap_xep_giam_dan(int *mang[], int kich_co){
    int bat_dau_quet, vi_tri_max;
    int *phan_tu_max;
    for (bat_dau_quet = 0; bat_dau_quet < (kich_co - 1); bat_dau_quet++){
        phan_tu_max = mang[bat_dau_quet];
        vi_tri_max = bat_dau_quet;
        for (int chi_so = bat_dau_quet + 1; chi_so < kich_co; chi_so++){
            if (*(mang[chi_so]) > *phan_tu_max){
                phan_tu_max = mang[chi_so];
                vi_tri_max = chi_so;
            }
        }
        mang[vi_tri_max] = mang[bat_dau_quet];
        mang[bat_dau_quet] = phan_tu_max;
    }
}
void hien_thi_mang(const int mang[], int kich_co){
    for (int dem = 0; dem < kich_co; dem++)
        cout << mang[dem] << " ";
    cout << endl;
}

void hien_thi_con_tro(int *mang[], int kich_co){
    for (int dem = 0; dem < kich_co; dem++)
        cout << *(mang[dem]) << " ";
    cout << endl;
}
