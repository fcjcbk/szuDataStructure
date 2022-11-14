#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mp(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    vector<unordered_set<int>> ans(n+1);
    for(int i = 1; i <= n; i++){
        queue<int> qu;
        qu.push(i);
        for(int j = 0; j < 6; j++){
            
            int h  = qu.size();
            for(int k = 0; k < h; k++){
                auto p = qu.front();
                qu.pop();
                for(auto &e : mp[p]){
                    qu.push(e);
                    ans[i].insert(e);

                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d: %.2f%\n",i , ans[i].size()*1.0/n*100.00);
        // cout<<i<<" "<<ans[i].size()<<endl;
    }
}