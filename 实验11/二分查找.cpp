#include<bits/stdc++.h>
using namespace std;
int find(vector<int> & a, int target){
    int left = 0;
    int right = a.size() - 1;
    while(left <= right){
        int middle = left + (right - left)/2;
        if(a[middle] == target){
            return middle;
        }else if(a[middle] > target){
            right = middle - 1;

        }else{
            left = middle + 1;

        }
    }
    return -1;
    
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto & c : a){
        cin>>c;
    }
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int k;
        cin>>k;
        int ans = find(a, k);
        if(ans >= 0){
            cout<<ans+1<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
}