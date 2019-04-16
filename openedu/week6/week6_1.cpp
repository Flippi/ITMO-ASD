#include <iostream>
#include <string>
#include "edx-io.hpp"

using namespace std;


int binSearch(const int *arr, int n, int value){
    int l = -1;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] < value) {
            l = m;
        } else {
            r = m;
        }
    }
    if (r < n  &&  arr[r] == value){
        return r;
    } else {
        return -1;
    }
}


int searchMax(int *arr, int n, int value, int leftIndex){
    int l = leftIndex;
    int r = n;
    while ( r > l + 1){
        int m = (l + r) / 2;
        if (arr[m] == value){
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int n;
    io >> n;
    int* arr = new int[n+1];
    for (int i = 0; i < n; ++i) {
        io >> arr[i];
    }

    int requestCount;
    io >> requestCount;
    for (int i = 0; i < requestCount; ++i) {
        int value;
        io >> value;
        int indexMin = binSearch(arr, n, value);
        if (indexMin == -1){
            io << indexMin << ' ' << indexMin << '\n';
        } else {
            int indexMax = searchMax(arr, n, value, indexMin);
            io << indexMin + 1 << ' ' << indexMax + 1 << '\n';
        }
    }
    return 0;
}