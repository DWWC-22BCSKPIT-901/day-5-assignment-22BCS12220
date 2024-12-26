//Square of a sorted array(easy).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int pos = n - 1; 
    
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            ++left;
        } else {
            result[pos] = rightSquare;
            --right;
        }
        --pos; 
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = sortedSquares(nums);
    cout << "Sorted squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
