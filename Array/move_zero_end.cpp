#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count++;
        } else if (count > 0) {
            int temp = arr[i];
            arr[i] = 0;
            arr[i - count] = temp;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}