#include<bits/stdc++.h>
#include <vector>
using namespace std;
void add(vector<int>& arr, int num){
    arr.push_back(num);
    int  pos = arr.size() - 1;
    int parent = (pos) / 2;
    while(arr[parent] > num){
        swap(arr[pos], arr[parent]);
        pos = parent;
        parent = (parent) / 2;
        
    }
    // arr[pos] = num;
}
int main(){
    int n,  m;
    vector<int> a;
    cin>>n>>m;
    a.push_back(INT_MIN);
    for(int i = 0; i < n; i++){
        int t;
        cin>>t;
        add(a, t);
    }
    for(int i = 0; i < m; i++){
        int pos = 0;
        int target;
        cin>>target;
        // target--;
        cout<<a[target];
        target = (target) / 2;
        while(target > 0){
            cout<<" "<<a[target];
            target = (target) / 2;
        }
        cout<<endl;

    }
    // for(auto & c : a){
    //     cout<<c<<" ";

    // }
    // cout<<endl;
}