#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Kich thuoc cua mang: " << sizeof(arr) << " bytes" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Phan tu arr[" << i << "] = " << arr[i] 
             << " tai dia chi: " << &arr[i] << endl;
    }
    return 0;
}
