#include <iostream>
using namespace std;

int ternarySearch(int l, int r, int key, int arr[]) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key) 
            return mid1;
        
        if (arr[mid2] == key) 
            return mid2;
        
        if (key < arr[mid1]) {
            return ternarySearch(l, mid1 - 1, key, arr);
        } else if (key > arr[mid2]) {
            return ternarySearch(mid2 + 1, r, key, arr);
        } else {
            return ternarySearch(mid1 + 1, mid2 - 1, key, arr);
        }
    }
    return -1; 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = ternarySearch(0, size - 1, key, arr);
    if (index != -1) {
        cout << key << " is present at index " << index << endl;
    } else {
        cout << key << " is not present in the array" << endl;
    }

    return 0;
}
