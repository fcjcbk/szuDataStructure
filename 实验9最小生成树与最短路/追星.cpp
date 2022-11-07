#include<bits/stdc++.h>
#include <cmath>
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
        int m;
        cin>>m;
        for(int j = 0; j < m; j++){
            int a, b, c;
            cin>>a>>b>>c;
            vt[a-1].push_back(edge(a -1, b-1, c));
            vt[b-1].push_back(edge(b-1, a-1, c));
        }


        priority_queue<edge, vector<edge>, greater<>> qu; 
        vector<int> dis(n, 1000000);
        vector<string> road(n);
        dis[0] = 0;
        qu.push(edge(0, 0, 0));

        bool f = false;
        int res = 0;
        
        while(!qu.empty()){
            auto p = qu.top();
            qu.pop();
            if(visit[p.end]){
                continue;
            }
            visit[p.end] = true;
            
            for(auto & g : vt[p.end]){
                if(g.val + dis[p.end] < dis[g.end]){
                    dis[g.end] = g.val + dis[p.end];
                    qu.push(edge(g.start, g.end, dis[g.end]));
                }
            }
            
        }
        // for(auto& gh : dis){
        //     cout<<gh<<endl;
        // }
        cout<<dis[n-1]<<endl;
    }
}