#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, r;
    cin >> n >> r;
    unordered_map<int, char> mp;
    vector<vector<int>> tree(n);
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        mp[i] = c;
        while(1){
            int t;
            cin >> t;
            if(t == -1){
                break;
            }
            tree[i].push_back(t);
        }
    }
    function<void(int)> dfs = [&](int index){
        for(auto & c : tree[index]){
            dfs(c);
        }
        cout<<mp[index];
    };
    dfs(r );
    cout<<endl;
}