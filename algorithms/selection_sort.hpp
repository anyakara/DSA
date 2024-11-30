//
// Created by Ananya Karra on 3/16/24.
//

#include <iostream>
#include <string>
#include <vector>

/*
 * this is what the algorithm is intended to do:
 * loop for the range of the array at hand
 * for each index in the array we are at, set that to min value index that
 * we want to be swapped with the next minimum number in the rest of the array
 * that value and this value are going to get swapped, the cycle continues
 */

template <typename T>
inline void SelectionSort(std::vector<T> &mV) {
    int vSize = mV.size();
    for (int i=0; i < vSize-2; i++) {
        int cLoc = i; // bc it is less than any other one in the list
        for (int j = cLoc+1; j < vSize-1; j++) {
            if (mV[j] < mV[cLoc]) {
                cLoc = j;
            }
        }
        // make the swap:
        int temp = mV[i];
        mV[i] = mV[cLoc];
        mV[cLoc] = temp;
    }
};

int main() {
    // create a vector;
    std::vector<int> nums = {6, 5, 4, 3, 2, 1};
    SelectionSort(nums);
    for (auto const &num: nums) {
        std::cout << num << "\n";
    }
} 
// sorting the array and printing the elements
// time complexity fo bigO of n^2
// at max C2 to execute ...
// this statement will be executed n-1 times
