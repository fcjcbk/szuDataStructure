#include<iostream>
using namespace std;
void print(int arr[], int n){
    cout<<arr[0];
    for(int i = 1; i < n; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
void insert_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j =  i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        print(arr, n);
    }
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i  = 0; i < n; i++){
        cin>>arr[i];
    }
    insert_sort(arr, n);
    delete []arr;
}