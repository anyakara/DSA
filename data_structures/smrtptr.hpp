#include<cstring>
#include<iostream>

template<typename T> class SharedPtr {
private:
  T* ptr;
  int * referenceCount;

  void release() {
    if (referenceCount) {
        (*referenceCount)--;
      if (*referenceCount == 0) {
        delete ptr;
        delete referenceCount;
      }
    }
  }

public:
  SharedPtr(T*p=nullptr):ptr(p), referenceCount(new int(1)) {} // Constructor
  SharedPtr(const SharedPtr<T>&other) : ptr(other.ptr), referenceCount(other.referenceCount) { (*refCount)++; } // Copy Constructor


