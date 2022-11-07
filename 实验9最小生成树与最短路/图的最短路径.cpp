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
    cin>>t;
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

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int tp;
                cin>>tp;
                if(tp){
                    vt[j].push_back(edge(j, k, tp));
                }
            }
        }
        string st;
        cin>>st;

        priority_queue<edge, vector<edge>, greater<>> qu; 
        vector<int> dis(n, 1000000);
        vector<string> road(n);
        dis[mp[st]] = 0;
        qu.push(edge(mp[st], mp[st], 0));
        road[mp[st]] = "["+ st + " ";
        bool f = false;
        int res = 0;
        
        while(!qu.empty()){
            auto p = qu.top();
            qu.pop();
            if(visit[p.end]){
                continue;
            }
            visit[p.end] = true;
            
            f = true;
            for(auto & g : vt[p.end]){
                if(g.val + dis[p.end] < dis[g.end]){
                    dis[g.end] = g.val + dis[p.end];
                    qu.push(edge(g.start, g.end, dis[g.end]));
                    road[g.end] = road[p.end] + c[g.end] + " ";
                }
            }
            
        }
        for(int j = 0; j < n; j++){
            if(j == mp[st]){
                continue;
            }
            cout<<st<<"-"<<c[j]<<"-";
            if(dis[j] == 1000000){
                cout<<"-1"<<endl;
                continue;
            }
            cout<<dis[j]<<"----"<<road[j]<<"]"<<endl;
        }
    }
}