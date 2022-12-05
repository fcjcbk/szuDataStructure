#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int> & arr, int left, int right){
    if(left > right){
        return;
    }
    int pivot = left;
    
    int l = left, r = right;
    
    while(l != r){
        while(arr[r] > arr[pivot] && l < r){
            r--;
        }
        while(arr[l] < arr[pivot] && l < r){
            l++;
        }
        
        if(l < r){
            swap(arr[l++], arr[r--]);
        }
    }
    swap(arr[pivot], arr[l]);
    cout<<arr[l]<<" "<<l + 1 <<endl;
    quicksort(arr, left, l - 1);
    quicksort(arr, l + 1, right);
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto& c : arr){
            cin>>c;

        }
        quicksort(arr, 0, arr.size() - 1);
        cout<<endl;
    }
}