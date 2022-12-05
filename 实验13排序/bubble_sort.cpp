#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& arr){
    int count = 0;
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j + 1]){
                count++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout<<count<<endl;
}
int main(){
    
    int n;
        while(cin>>n){
            vector<int> arr(n);
            for(auto & c : arr){
                cin>>c;
            }
            bubble_sort(arr);
        }
        
}