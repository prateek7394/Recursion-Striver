#include<bits/stdc++.h>
using namespace std;

// ****************** Method 1 ************************
void reverseArray1(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    swap(arr[l], arr[r]);
    reverseArray1(arr, l+1, r-1);
}

// ****************** Method 2 ************************

void reverseArray2(int idx, int arr[], int size){
    if(idx==size/2){
        return;
    }
    swap(arr[idx], arr[size-1-idx]);
    reverseArray2(idx+1, arr, size);
}

int main()
{
    int arr[] = {-1, 4, 0, 2, -6, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    // reverseArray1(arr, 0, size-1);
    reverseArray2(0, arr, size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}