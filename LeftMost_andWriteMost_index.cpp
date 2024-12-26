//Left most and write most index
#include <iostream>
#include <vector>
using namespace std;

// Function to find the leftmost index
int findLeftmost(const vector<int>& v, int X) {
    int low = 0, high = v.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == X) {
            result = mid;  // Possible answer
            high = mid - 1; // Move left
        } else if (v[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Function to find the rightmost index
int findRightmost(const vector<int>& v, int X) {
    int low = 0, high = v.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == X) {
            result = mid;  // Possible answer
            low = mid + 1; // Move right
        } else if (v[mid] < X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Main function to find both indices
pair<int, int> findOccurrences(const vector<int>& v, int X) {
    int left = findLeftmost(v, X);
    if (left == -1) { // If the element is not found
        return {-1, -1};
    }
    int right = findRightmost(v, X);
    return {left, right};
}

int main() {
    int N, X;
    cout << "Enter the size of the array (N): ";
    cin >> N;
    vector<int> v(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    cout << "Enter the element to find (X): ";
    cin >> X;

    pair<int, int> result = findOccurrences(v, X);
    cout << result.first << " " << result.second << endl;

    return 0;
}
