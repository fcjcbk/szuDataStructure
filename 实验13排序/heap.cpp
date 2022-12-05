#include<bits/stdc++.h>
using namespace  std;
void shift(vector<int>& arr, int start, int end){
    int parent = start;
    int child = 2 * parent + 1;
    while(child <= end){
        if(child+ 1 <= end && arr[child+ 1] < arr[child]){
            child++;
        }
        if(arr[parent] < arr[child]){
            break;
        }
        swap(arr[parent], arr[child]);
        parent = child;
        child = 2 * parent + 1;
    }
}
void build_heap(vector<int>& arr){
    int len = arr.size() - 1;
    for(int i = len/2; i >= 0; i--){
        shift(arr, i, len);
    }
}
void print(const vector<int>& arr);
void heap_sort(vector<int>& arr){
    build_heap(arr);
    print(arr);
    int len = arr.size() - 1;
    for(int i = arr.size() - 1; i >= 1 ; i--){
        swap(arr[i], arr[0]);
        len--;
        shift(arr, 0, len);
        print(arr);
    }
    
}
void print(const vector<int>& arr){
    cout<<arr.size()<<" ";
    cout<<arr[0];
    for(int i = 1; i < arr.size(); i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto& c : arr){
        cin>>c;
    }
    heap_sort(arr);
}