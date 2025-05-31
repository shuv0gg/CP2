#include <bits/stdc++.h>
using namespace std;

bool isValid(const vector<int>& volumes, int m, long long limit) {
    int count = 1;
    long long currentSum = 0;
    for (int v : volumes) {
        if (v > limit) return false;
        if (currentSum + v > limit) {
            count++;
            currentSum = v;
        } else {
            currentSum += v;
        }
    }
    return count <= m;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> volumes(n);
        for (int i = 0; i < n; ++i) {
            cin >> volumes[i];
        }

        long long low = *max_element(volumes.begin(), volumes.end());
        long long high = accumulate(volumes.begin(), volumes.end(), 0LL);
        long long answer = high;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (isValid(volumes, m, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << endl;
    }
    return 0;
}

