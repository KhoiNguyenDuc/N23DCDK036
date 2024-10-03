#include <iostream>
using namespace std;

// Hàm sử dụng con trỏ thay vì tham chiếu
int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

int main() {
    int a = 5, b = 10;
    cout << "Truoc khi goi ham: a = " << a << ", b = " << b << endl;
    int result = doSomething(&a, &b);
    cout << "Sau khi goi ham: a = " << a << ", b = " << b << endl;
    cout << "Ket qua cua ham: " << result << endl;
    return 0;
}
