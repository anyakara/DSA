#include <vector>
#include <iostream>
#include <string>

/*
 * algorithm intuition:
 * go through the vector's values comparing the current index
 * to the value in the next index: if the current index value
 * is greater than the next index value, swap the two elements
 * repeat this till that value bubbles up to the top of the array
 * for n-2 number of times
 */

template<typename T>
inline void BubbleSort(std::vector<T> &mV) {
    size_t vSize = mV.size();
    for (int k=1; k < vSize-1; k++) {
        int flag = 0;
        for (int i=0; i < vSize-k-1; i++) {
            if (mV[i] > mV[i+1]) { // these statements will execute in constant time
                std::swap(mV[i], mV[i+1]); // (n-1) times Cn^2 -2Cn + 1 = O(n^2) algorithm
                flag = 1;
            }
        }
        if (flag == 1) {
            break; // if we input an already sorted array - then time taken would be taking some constant time
                    // this will be the best case our algorithm -- we are midway - n/2 passes
        }
    }
} // total time taken = n-1*n-1*c = polynomial expression
// there is no point in passing the sorted part - n-2, n-3

int main() {
  std::vector<std::string> strVec;
  BubbleSort(strVec);
}
