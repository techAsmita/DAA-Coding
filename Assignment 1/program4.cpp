//max sub array using divide and conquer approach
#include <iostream>
#include <climits>
using namespace std;
// Function to find the maximum crossing subarray sum
int maxCrossingSum(int arr[], int left, int mid, int right) 
{
    // Calculate maximum sum on the left of mid
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    // Calculate maximum sum on the right of mid
    int rightSum = INT_MIN; 
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    // Combine both halves
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubArraySum(int arr[], int left, int right) {
    // Base case: only one element
    if (left == right) {
        return arr[left];
    }
    int mid = left + (right - left) / 2;
    int maxLeftSum = maxSubArraySum(arr, left, mid);
    int maxRightSum = maxSubArraySum(arr, mid + 1, right);
    int maxCrossSum = maxCrossingSum(arr, left, mid, right);
    return max(maxLeftSum, max(maxRightSum, maxCrossSum));
}
int main() 
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << maxSum << endl;
}
