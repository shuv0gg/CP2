#include <bits/stdc++.h>
using namespace std;

int findFirst(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] >= target) high = mid - 1;
        else low = mid + 1;
        if (nums[mid] == target) result = mid;
    }
    return result;
}

int findLast(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] <= target) low = mid + 1;
        else high = mid - 1;
        if (nums[mid] == target) result = mid;
    }
    return result;
}

vector<int> searchRange(const vector<int>& nums, int target) {
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target;
    cin >> target;

    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
