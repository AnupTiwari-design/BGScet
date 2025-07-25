#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 1, 2};

    // Step 1: XOR of all elements
    int xorAll = 0;
    for (int num : arr)
        xorAll ^= num;

    // Step 2: Find rightmost set bit (differs in the two unique numbers)
    int setBit = xorAll & ~(xorAll - 1);

    // Step 3: Divide elements in two groups and XOR separately
    int x = 0, y = 0;
    for (int num : arr) {
        if (num & setBit)
            x ^= num;
        else
            y ^= num;
    }

    // x and y are the two unique numbers
    cout << "Unique elements are: " << x << " and " << y << endl;

    return 0;
}