#include<iostream>
using namespace std;
void print(int arr[], int n){
    cout<<arr[0];
    for(int i = 1; i < n; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
void quick_sort(int arr[], int left, int right, int n){
    if(left >= right){
        return;
    }
    int pivot = arr[left];
    int l = left, r = right;
    while(l < r){
        while(r > l){
            if(arr[r] < pivot){
                arr[l++] = arr[r];
                break;
            }
            r--;
        }
        while(l<r){
            if(arr[l] > pivot){
                arr[r--] = arr[l];
                break;
            }
            l++;
        }
    }
    arr[l] = pivot;
    // cout<<pivot<<" "<<l + 1<<endl;
    print(arr, n);
    quick_sort(arr, left, l - 1, n);
    quick_sort(arr, l + 1, right, n);

}
int main(){
    int t;
    cin>>t;
    while(t-- > 0){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i  = 0; i < n; i++){
            cin>>arr[i];
        }
        quick_sort(arr, 0, n - 1, n);
        delete []arr;
        cout<<endl;
    }
    
}
