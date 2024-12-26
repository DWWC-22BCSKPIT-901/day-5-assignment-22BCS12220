//Pair sum closest to zero
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int closestToZero(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    int closestSum = INT_MAX;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(closestSum) || (abs(sum) == abs(closestSum) && sum > closestSum)) {
            closestSum = sum;
        }
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    return closestSum;
}
int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    int result = closestToZero(arr, N);
    cout << "Maximum sum closest to zero: " << result << endl;
    return 0;
}
