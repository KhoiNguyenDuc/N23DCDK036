#include <iostream>
#include <algorithm>
using namespace std;

double tim_median(int *arr, int size) {
    sort(arr, arr + size);

    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

int main() {
    int arr[] = {1, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    double median = tim_median(arr, size);

    cout << "Median la: " << median << endl;

    return 0;
}
