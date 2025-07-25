#include <iostream>
using namespace std;

void findSubarrayWithSum(int arr[], int n, int target) {
    int start = 0, currSum = 0;

    for (int end = 0; end < n; end++) {
        currSum += arr[end];

        while (currSum > target && start < end) {
            currSum -= arr[start];
            start++;
        }
        if (currSum == target) {
            cout << (start + 1) << " " << (end + 1) << endl;
            return;
        }
    }

    cout << "-1" << endl; // if no subarray found
}

int main() {
    int arr[] = {1, 2, 3, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 12;

    findSubarrayWithSum(arr, n, sum);

    return 0;
}