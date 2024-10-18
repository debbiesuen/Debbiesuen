#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void firstNegativeInteger(int arr[], int n, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        // Remove elements not within the window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Add current element's index if it's negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // If we have filled the first window
        if (i >= k - 1) {
            if (!dq.empty()) {
                result.push_back(arr[dq.front()]);
            } else {
                result.push_back(0);
            }
        }
    }

    for (int neg : result) {
        cout << neg << " ";
    }
}

int main() {
    int arr[] = {-8, 2, 3, -6, 10};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    firstNegativeInteger(arr, n, k);
    return 0;
}
