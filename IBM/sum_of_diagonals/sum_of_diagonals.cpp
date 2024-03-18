#include <iostream>
#include <math.h>

using namespace std;

// Function to calculate the absolute difference between the sums of the diagonals of a square matrix
int diagonalSum(int arr[][15], int n){
    int leftSum = 0; // Initialize sum of left diagonal
    int rightSum = 0; // Initialize sum of right diagonal

    int left = 0; // Pointer for traversing left diagonal
    int right = 0; // Pointer for traversing right diagonal

    // Traverse the matrix to calculate the sum of the left diagonal
    while(left < n && right < n){
        leftSum += arr[left++][right++]; // Increment both pointers to move diagonally
    }

    left = 0; // Reset left pointer
    right = n - 1; // Reset right pointer to the last column

    // Traverse the matrix to calculate the sum of the right diagonal
    while(left < n && right >= 0){
        rightSum += arr[left++][right--]; // Increment left pointer and decrement right pointer to move diagonally
    }

    return abs(leftSum - rightSum); // Return the absolute difference between the sums of diagonals
}

int main() {
    // Example usage of the diagonalSum function
    int arr[15][15] = {
        {1, 2, 3},
        {4, 5, 6},
        {9, 8, 9}
    };
    int n = 3; // Size of the square matrix
    int result = diagonalSum(arr, n);
    cout << "Absolute difference between the sums of diagonals: " << result << endl;

    return 0;
}
