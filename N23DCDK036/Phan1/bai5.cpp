#include <iostream>
using namespace std;

void sap_xep(int *[], int);
void hien_thi_mang(const int [], int);
void hien_thi_con_tro(int *[], int);

int main(){
    int soluongdonggop;
    cout << "Nhap so luong dong gop: ";
    cin >> soluongdonggop;
    if (soluongdonggop <= 0) {
        cout << "So luong dong gop khong hop le." << endl;
        return 1;
    }
    int *giatri = new int[soluongdonggop];
    for (int i = 0; i < soluongdonggop; i++) {
        cout << "Nhap gia tri dong gop thu " << i + 1 << ": ";
        cin >> giatri[i];
    }
    int **arrPtr = new int*[soluongdonggop];
    for (int count = 0; count < soluongdonggop; count++) {
        arrPtr[count] = &giatri[count];
    }
    sap_xep(arrPtr, soluongdonggop);
    cout << "Danh sach dong gop da sap xep (tang dan):\n";
    hien_thi_con_tro(arrPtr, soluongdonggop);
    cout << "Danh sach dong gop ban dau:\n";
    hien_thi_mang(giatri, soluongdonggop);
    delete[] giatri;
    delete[] arrPtr;
    return 0;
}

void sap_xep(int *arr[], int size){
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++){
        minElem = arr[startScan];
        minIndex = startScan;
        for (int index = startScan + 1; index < size; index++){
            if (*(arr[index]) < *minElem){
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void hien_thi_mang(const int arr[], int size){
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

void hien_thi_con_tro(int *arr[], int size){
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}
