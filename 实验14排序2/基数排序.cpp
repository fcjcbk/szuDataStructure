#include<bits/stdc++.h>
#include <vector>
using namespace std;
bool flag = false;
int minn = INT_MAX;

int get_max(const vector<int>& arr){
    int big = INT_MIN;
    for(auto x : arr){
        int sum = 0;
        while(x > 0){
            x /= 10;
            sum++;
            
        }
        big = max(big, sum);
    }
    return big;
}
void base_sort(vector<int>& arr){
    int m = get_max(arr);
    int radix = 1;
    for(int i = 0; i < m; i++){
        vector<vector<int>> nums(10);
        for(auto x : arr){
            int g = x;
            x /= radix;
            int t = x % 10;
            nums[t].push_back(g);
        }
        int index = 0;
        for(int j = 0; j < 10; j++){
            if(nums[j].size() > 0){
                cout<<j<<":->";
                for(auto & y : nums[j]){
                    cout<<y<<"->";
                    arr[index++] = y;
                }
                cout<<"^"<<endl;
            }else{
                cout<<j<<":NULL"<<endl;
            }
        }
        radix *= 10;
        if(!flag){
            cout<<arr[0];
            for(int k = 1; k < arr.size(); k++){
                
                cout<<" "<<arr[k];
            }
            cout<<endl;
        }else{
            cout<<arr[0] -minn;
            for(int k = 1; k < arr.size(); k++){
                
                cout<<" "<<arr[k]-minn;
            }
            cout<<endl;
        }
        
    }
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int j = 0; j < n; j++){
            cin>>arr[j];
            if(arr[j] < 0){
                flag = true;
                minn = min(arr[j], minn);
            }
        }
        if(flag){
            for(int j = 0; j < n; j++){
                arr[j] -= minn;
            }
        }
        base_sort(arr);
        cout<<endl;
        
        
    }
}