#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> mp(n, vector<int>(n));

    for(auto & a : mp){
        for(auto & b : a){
            cin>>b;
        }
    }
    int start;
    cin >> start;
    cout<<"DFS from "<<start<<":";
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int index){
        if(vis[index]){
            return;
        }
        vis[index] = true;
        cout<<" "<<index;
        for(int i = 0; i < n; i++){
            if(mp[index][i]){
                dfs(i);
            }
        }
    };
    dfs(start);
}