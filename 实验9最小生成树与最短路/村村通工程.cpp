#include<bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
struct edge{
    int start, end, val;
    edge(int s, int e, int v):start(s), end(e), val(v){}
    bool operator > (const edge&rhs){
        return val > rhs.val;
    }
};

int main(){
    int t;
     t = 1;
    for(int i = 0; i < t; i++){
        unordered_map<string,int> mp;
        int n;
        cin>>n;
        vector<string> c(n);
        vector<vector<edge>> vt(n);
        vector<edge> ans;
        vector<bool> visit(n, false);
        for(int j = 0; j < n; j++){
            cin>>c[j];
            mp[c[j]] = j;
        }
        int m;

        cin>>m;
        for(int j = 0; j < m; j++){
            string d, e;
            int val;
            cin>>d>>e>>val;
            int a = mp[d];
            int b = mp[e];
            vt[a].push_back(edge(a, b, val));
            vt[b].push_back(edge(b,a,val));
        }
        string st;
        cin>>st;

        priority_queue<edge, vector<edge>, greater<>> qu; 
        vector<int> dis(n, 1000000);
        dis[mp[st]] = 0;
        qu.push(edge(mp[st], mp[st], 0));
        bool f = false;
        int res = 0;

        while(!qu.empty()){
            auto p = qu.top();
            qu.pop();
            if(visit[p.end]){
                continue;
            }
            visit[p.end] = true;
            // for(auto& u : vt[p.start]){
            //     if(u.end == p.end){
            //         res += u.val;
            //         if(f){
            //             ans.push_back(u);
            //         }
            //         break;
            //     }
            // }
            if(f){
            ans.push_back(p);

            }
            res += p.val;
            f = true;
            for(auto & g : vt[p.end]){
                // if(g.val + dis[p.end] < dis[g.end]){
                    // dis[g.end] = g.val + dis[p.end];
                    qu.push(edge(g.start, g.end, g.val));
                // }
            }
        }
        cout<<res<<endl;

        for(auto & h: ans){
            cout<<c[h.start]<<" "<<c[h.end]<<" "<<h.val<<endl;
        }
    }
}