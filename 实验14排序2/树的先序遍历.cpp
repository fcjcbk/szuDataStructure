#include<bits/stdc++.h>
#include <vector>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int r = -1;
        unordered_map<int, char> mp;
        vector<vector<int>> tree(n);
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            mp[j] = c;
        }
        for(int j = 0; j < n; j++){
            int t;
            cin >> t;
            if(t == -1){
                r = j;
            }else{
                tree[t].push_back(j);

            }
        }
        function<void(int)> dfs = [&](int index){
            cout<<mp[index];

            for(auto & c : tree[index]){
                dfs(c);
            }
        };
        dfs(r);
        cout<<endl;
    }
}