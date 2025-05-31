#include <bits/stdc++.h>
using namespace std;

int smallestSubarraySum(const vector<int>& arr, int S) {
    int n = arr.size();
    if (n == 0) return 0;

    int min_length = n + 1;
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += arr[right];


        while (current_sum >= S) {
            min_length = min(min_length, right - left + 1);
            current_sum -= arr[left];
            left++;
        }
    }
    return (min_length == n + 1) ? 0 : min_length;
}

int main() {
    vector<int> A1 = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    int S1 = 15;
    cout << "Problem 1 - A1: " << smallestSubarraySum(A1, S1) << endl;
    vector<int> A2 = {1, 2, 3, 4, 5};
    int S2 = 11;
    cout << "Problem 1 - A2: " << smallestSubarraySum(A2, S2) << endl;

    return 0;
}
