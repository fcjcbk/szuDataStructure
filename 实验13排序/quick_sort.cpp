#include<iostream>
using namespace std;
int partition(int arr[], int left, int right){
    
    int pivot = arr[left];
    int count = 0;
    for(int i = left + 1; i <= right; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int l =left, r = right;
    int pivot_index = left + count;
    swap(arr[left], arr[pivot_index]);
    while(l <pivot_index && r > pivot_index){
        while(arr[l] < pivot){
            l++;
        }
        while(arr[r] > pivot){
            r--;
        }
        if(l < pivot_index && r > pivot_index){
            swap(arr[l++], arr[r--]);
        }
    }
    return  pivot_index;
}
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
    int pivot_index = partition(arr, left, right);
    print(arr, n);

    quick_sort(arr, left, pivot_index - 1, n);
    quick_sort(arr, pivot_index + 1, right, n);

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
        print(arr, n);
        delete []arr;
        cout<<endl;
    }
    
}
