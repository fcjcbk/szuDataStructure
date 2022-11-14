#include<bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
struct edge{
    int to;
    double val;
    edge(int to, double val):to(to), val(val){}
};
int main(){
    int t;
    cin>>t;
    for(int l = 0; l < t; l++){
        int n, m;
        cin>>n>>m;
        unordered_map<string, int> mp;
        vector<vector<edge>> vt(n);
        for(int i = 0; i < n; i++){
            string s;
            cin>>s;
            mp[s] = i;
        }
        for(int i = 0; i < m; i++){
            string a, b;
            double val;
            cin>>a>>val>>b;
            int from = mp[a];
            int to = mp[b];
            vt[from].push_back(edge(to, val));
            // double v = 1.0/val;
            // vt[to].push_back(edge(from, v));
        }
        bool flag = false;
        function<void(int,unordered_set<int>,double)> dfs = [&](int index, unordered_set<int> st, double it){

            if(st.count(index)){
                
                // for(auto e : st){
                //         cout<<e<<" ";
                //     }
                //     cout<<endl;
                if(it > 1){
                    // cout<<it<<endl;
                    flag = true;
                    
                }
                
                return;

            }else{
                st.insert(index);
            }
            for(auto& e: vt[index]){
                
                double gh = it * e.val;
                dfs(e.to, st, gh);
                
            }
        };
        for(int i = 0; i < n; i++){
            unordered_set<int> st;

            flag = false;
            dfs(i, st, 1.0);
            
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
}