#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> node(n);
    vector<bool> visit(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int start; 
    cin >> start;
    queue<int> qu;
    qu.push(start);
    cout<<"BFS from "<<start<<":";
    while(!qu.empty()){
        int n = qu.size();
        for(int i = 0; i < n; i++){
            auto p = qu.front();
            qu.pop();
            if(!visit[p]){
                visit[p] = true;
                cout<<" "<<p;
                for(auto & x : node[p]){
                    qu.push(x);
                }
            }
        }
    }
    
}