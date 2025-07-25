#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements out of this window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove all smaller elements from back
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(i); // Add current element's index

        // Start adding max from the k-th element
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}