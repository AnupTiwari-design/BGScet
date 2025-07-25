#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void activitySelection(const vector<int>& start, const vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; ++i) {
        activities.push_back({end[i], start[i]});
    }

    sort(activities.begin(), activities.end());

    int last_end = activities[0].first;
    cout << activities[0].second << " " << activities[0].first << endl;

    for (int i = 1; i < n; ++i) {
        if (activities[i].second >= last_end) {
            cout << activities[i].second << " " << activities[i].first << endl;
            last_end = activities[i].first;
        }
    }
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    activitySelection(start, end);
    return 0;
}