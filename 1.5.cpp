#include<iostream>
using namespace std;
void searchMatrix(int arr[][4], int rows, int cols, int target)
{
    int start=0;
    int row = rows-1;
    int col = cols-1;
    int ind = -1;

    while(start<=row)
    {
        int mid = start + (row-start)/2;
        if(arr[mid][0]<=target && arr[mid][col]>=target)
        {
            ind = mid;
            break;
        }
        else if(arr[mid][0]<target)
        {
            start = mid +1;
        }
        else
        {
            row = mid -1;
        }
    }

    if(ind == -1)
    {
        cout<<"Element not Found";
    }

    while(start<=col)
    {
        int mid = start + (col-start)/2;
        if(arr[ind][mid]==target)
        {
            cout<<"["<<ind<<","<<mid<<"]";
            return;
        }
        else if(arr[ind][mid]<target)
        {
            start = mid + 1;
        }
        else
        {
            col = mid - 1;
        }
    }
}
int main()
{
    int m,n;
    int arr[4][4] ={
                    {1,3,5,7},
                    {10,11,16,20},
                    {23,30,34,50},
                    {60,62,63,64} };

    cout<<"Enter the target to search for: ";
    int target;
    cin>>target;

    searchMatrix(arr, 4, 4, target);

    /*
    #include <iostream>

void searchMatrix(int rows, int cols, int matrix[][10], int target, int &rowIndex, int &colIndex) {
    int left = 0;
    int right = rows * cols - 1;
    rowIndex = -1; // Default to -1 (not found)
    colIndex = -1; // Default to -1 (not found)

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols]; // Convert 1D index to 2D coordinates

        if (midValue == target) {
            rowIndex = mid / cols;  // Set the found row index
            colIndex = mid % cols;  // Set the found column index
            return; // Exit on finding the target
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;

    int matrix[10][10]; // Assuming maximum size of 10x10 as per constraints
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int target;
    std::cin >> target;

    int rowIndex, colIndex;
    searchMatrix(rows, cols, matrix, target, rowIndex, colIndex);

    if (rowIndex != -1) {
        std::cout << "(" << rowIndex << "," << colIndex << ")" << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}
*/
}
