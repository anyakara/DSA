#include <vector>
#include <string>

/*
 * assume th 0th index is "sorted"
 * start with the first index value and store that in val, store index
 * now we have a "hole" in the array
 * now run a while loop that compares the value we are at to a value before, until
 * we are at index whose value is just less than the value we are trying to
 * insert the value in the next slot
 */


template<typename T>
inline void InsertionSort(std::vector<T> &A) {
    // dealing with vectors:
    for (int i =1; i<A.size()-1; i++) {
        T value = A[i]; // store current location
        int loc = i; // store current index

        while (loc > 0 && A[loc-1] > value) {
            A[loc] = A[loc-1];
            loc = loc - 1;
        }
        A[loc] = value;
    }
}


int main() {
  std::vector<int> vecA;
  InsertionSort(vecA);
}
