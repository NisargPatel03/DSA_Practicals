#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int findSpecialX(int N, int nums[]) {
    // If there are no elements, return -1
    if (N == 0) return -1;

   sort(nums, nums+N);

    for (int x = 0; x <= N; ++x) {
        int count = 0;
        // Count numbers greater than or equal to x
        for (int i = 0; i < N; ++i) {
            if (nums[i] >= x) count++;
        }
        if (count == x) return x; // Found a valid x
    }

    return -1; // No special x found
}

int main() {
    int N;
    cout<<"Enter the size of an array: ";
    cin >> N;

    int nums[N];
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    int result = findSpecialX(N, nums);
    cout << result << endl;


}
