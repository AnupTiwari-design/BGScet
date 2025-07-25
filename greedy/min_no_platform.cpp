#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatform(vector<int> arr, vector<int> dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 0;
    int maxPlatforms = 0;

    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }

        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}

int main() {
    vector<int> arrival  = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum number of platforms required = " << findPlatform(arrival, departure) << endl;

    return 0;
}