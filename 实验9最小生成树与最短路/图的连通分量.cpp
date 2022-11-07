#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        unordered_map<string,int> mp;
        int n;
        cin>>n;
        vector<string> c(n);

        vector<vector<int>> vt(n, vector<int>(n, 0));
        for(int j = 0; j < n; j++){
            cin>>c[j];
            mp[c[j]] = j;
        }
        int m;

        cin>>m;
        for(int j = 0; j < m; j++){
            string d, e;
            cin>>d>>e;
            int a = mp[d], b = mp[e];
            vt[a][b] = 1;
            vt[b][a] = 1;
        }
        vector<bool> visit(n, false);
        function<void(int)> dfs = [&](int index){
            if(visit[index]){
                return;
            }
            visit[index] = true;
            for(int f = 0; f < n; f++){
                if(vt[index][f] == 1){
                    dfs(f);
                }
            }
        };
        int count = 0;
        for(int j = 0; j < n; j++){
            if(!visit[j]){
                count++;
                dfs(j);
            }
        }
        for(int j = 0; j < n; j++){
            if(j != n - 1){
                cout<<c[j]<<" ";

            }else{
                cout<<c[j]<<endl;
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(k != n - 1){
                    cout<<vt[j][k]<<" ";
                }else{
                    cout<<vt[j][k]<<endl;
                }
            }
        }
        cout<<count<<endl;
        cout<<endl;

    }
}