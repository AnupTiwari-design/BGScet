#include<iostream>
using namespace std;

int max_length_subarray(int arr[], int n) {
    int count = 1, max_count = 1;

    for(int i = 1; i < n; i++) {
        if((arr[i] % 2 == 0 && arr[i-1] % 2 != 0) || 
        (arr[i] % 2 != 0 && arr[i-1] % 2 == 0)) {
            count++;
            max_count = max(max_count, count);
        } else {
            count = 1;
        }
    }

    return max_count;
}

int main() {
    int arr[] = {5, 10, 20, 6, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << max_length_subarray(arr, n) << endl;

    return 0;
}