#include <iostream>
using namespace std;

int sqrtFloor(int x) {
    if (x == 0 || x == 1) return x;

    int low = 0, high = x, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= x / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x = 2147395599;
    cout << "Square root (floor) of " << x << " is " << sqrtFloor(x) << endl;
    return 0;
}