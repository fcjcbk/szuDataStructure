#include<bits/stdc++.h>
using namespace std;
constexpr int HASH_NUM = 11;
class Hash{
    vector<vector<int>> arr;
public:
    Hash(): arr(vector<vector<int>>(HASH_NUM)){}
    void push(int val){
        int pos = val % HASH_NUM;
        arr[pos].push_back(val);
    }
    void find(int val){
        int res = 0;
        int pos = val % HASH_NUM;
        int n = arr[pos].size() - 1;
        bool f = true;
        int ans = 0;
        for(int i = n; i >= 0; i--){
            res++;
            if(arr[pos][i] == val){
                f = false;
                break;
                
            }
        }
        if(f){
            arr[pos].push_back(val);
            cout<<"error"<<endl;
        }else{
            cout<<pos<<" "<<res<<endl;
        }
 
    }
};
int main(){
    int t;
    cin>>t;
    Hash h;
    for(int i = 0; i < t; i++){
        int k;
        cin >> k;
        h.push(k);
    }
    cin>>t;
    for(int i = 0; i < t; i++){
        int k; 
        cin>>k;
        h.find(k);
    }

}