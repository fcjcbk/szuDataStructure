#include<bits/stdc++.h>
using namespace std;
void print(const vector<int>& arr){
    int n = arr.size();
    cout<<arr[0];
    for(int i = 1; i < n; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
void shell_sort(vector<int>& arr){
    int gap = arr.size() / 2;
    int n = arr.size();
    while(gap > 0){
        for(int i = gap; i < n; i++){
            for(int j = i; j >= gap && arr[j] > arr[j - gap]; j -= gap){
                swap(arr[j], arr[j - gap]);
            }
        }
        gap /= 2;
        print(arr);
        
    }
    // print(arr);

}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto & c : arr){
            cin>>c;
        }
        shell_sort(arr);
        cout<<endl;
    }
    
}