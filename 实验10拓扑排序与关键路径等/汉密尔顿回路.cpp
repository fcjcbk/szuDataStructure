#include<bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> vt(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < m; i++){
        int a ,b;
        cin>>a>>b;
        vt[a][b] = 1;
        vt[b][a] = 1;
    }
    int k;
    cin>>k;
    for(int i = 0; i < k; i++){
        int f;
        cin>>f;
        unordered_map<int, int> mp;
        int first;
        bool ok = true;
        if(f != n + 1){
            ok = false;
        }
        
        vector<int> tmp(f, 0);
        for(int j = 0; j < f; j++){
            int c;
            cin>>c;
            tmp[j] = c;
            if(j == 0){
                first = c;
            }
            mp[c]++;
            if(mp[c] > 1 && c != first){
                ok = false;
            }
        }
        function<void(int, int)> dfs = [&](int index, int i){
            if(i>=f){
                return;
            }
            if(vt[index][tmp[i]] != 1){
                ok = false;
            }else{
                dfs(tmp[i], i+1);
            }
        };
        dfs(tmp[0], 1);
        if(!ok){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}