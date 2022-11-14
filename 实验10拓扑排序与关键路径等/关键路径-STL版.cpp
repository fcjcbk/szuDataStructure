#include<bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
struct edge{
    int to;
    int val;
    edge(int to, int val):to(to), val(val){}
};

int main(){
    int n;
    cin>>n;
    vector<int> early(n);
    vector<int> latest(n, INT_MAX);
    vector<int> in(n);
    vector<int> in1(n);

    vector<vector<edge>> mp(n);
    vector<vector<edge>> mp1(n);

    queue<int> qu;
    queue<int> qu1;

    vector<int> time(n);
    vector<int> topo;
    int t;
    cin>>t;
    int total_time = 0;
    for(int i = 0; i < t; i++){
        int from, to, val;
        cin>>from>>to>>val;
        mp[from].push_back(edge(to, val));
        mp1[to].push_back(edge(from, val));
        in[to]++;
        in1[from]++;
    }
    for(int i = 0; i < n; i++){
        if(in[i] == 0){
            qu.push(i);
        }
        if(in1[i] == 0){
            qu1.push(i);
        }
    }
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        topo.push_back(p);
        for(auto e: mp[p]){
            in[e.to]--;
            if(in[e.to] == 0){
                qu.push(e.to);
            }
            early[e.to] = max(early[e.to], e.val + early[p]);
        }
    }
    total_time = early[topo.back()];
    qu1.push(topo.back());
    while(!qu1.empty()){
        auto p = qu1.front();
        qu1.pop();
        if(p == topo.back()){
            latest[p] = total_time;

            // for(auto &e : mp1[p]){
            //     latest[p] = min(latest[p], total_time - e.val);
            // }
        }
        for(auto e: mp1[p]){
            in1[e.to]--;
            if(in1[e.to] == 0){
                qu1.push(e.to);
            }
        
            latest[e.to] = min(latest[e.to], latest[p] - e.val);
            // latest[p] = min(latest[p], tmp - e.val);
        }
    }
    // for(int i = topo.size() - 1; i >=0; i--){
    //     int u = topo[i];
    //     if(mp[u].size() == 0){
    //         latest[u] = total_time - 
    //     }else if(mp[u].size() > 0){
    //         latest[u] = INT_MAX;
    //     }
    //     for(auto & c : mp[u]){
    //         latest[u] = min(latest[u], latest[c] - time[u]);
    //     }
    // }
    
    for(auto & c : early){
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto & c : latest){
        cout<<c<<" ";
    }
    cout<<endl;
}