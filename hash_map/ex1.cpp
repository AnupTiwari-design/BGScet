#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};

    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    cout << "Element Frequencies:\n";
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << " times" << endl;
    }

    return 0;
}