#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int N) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < N; ++i) {
        string curr = q.front();
        q.pop();

        cout << curr << " ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Binary numbers from 1 to " << N << ":\n";
    generateBinary(N);

    return 0;
}