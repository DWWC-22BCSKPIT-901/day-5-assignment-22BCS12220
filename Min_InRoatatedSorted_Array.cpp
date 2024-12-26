//find minimum in rotated sorted array
#include <iostream>
#include <vector>
using namespace std;
vector<int> rotateArray(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> rotated(n);
    for (int i = 0; i < n; ++i) {
        rotated[(i + k) % n] = nums[i];
    }
    return rotated;
}
int findMin(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) {
            low = mid + 1; 
        } else {
            high = mid; 
        }
    }
    return nums[low];
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the number of rotations: ";
    cin >> k;
    vector<int> rotatedArray = rotateArray(nums, k);
    cout << "Rotated Array: ";
    for (int num : rotatedArray) {
        cout << num << " ";
    }
    cout << endl;
    int minElement = findMin(rotatedArray);
    cout << "The smallest element is: " << minElement << endl;

    return 0;
}
