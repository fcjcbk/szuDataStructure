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
class bing {
    vector<int> fa;
public:
    int findFa(int x) {
        return fa[x] < 0 ? x : fa[x] = findFa(fa[x]);
    }

    void unit(int x, int y) {
        x = findFa(x);
        y = findFa(y);
        if (x == y) {
            return ;
        }
        if (fa[x] < fa[y]) {
            swap(x, y);
        }
        fa[x] += fa[y];
        fa[y] = x;
    }

    bool isconnect(int x, int y) {
        x = findFa(x);
        y = findFa(y);
        return x == y;
    }
    bing(int n):fa(vector<int>(n, -1)){
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
        // vector<vector<edge>> vt(n);
        vector<edge> li;
        vector<edge> ans;
        vector<int> visit(n, -1);
        for(int j = 0; j < n; j++){
            visit[j] = j;
        }
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
            li.push_back(edge(a, b, val));
            

        }
        bool f = false;
        int res = 0;
        bing bg(n+1);
        sort(li.begin(), li.end(), [](const edge&lhs, const edge&rhs){
            return lhs.val < rhs.val;
        });

        for(auto p : li){
            if(!bg.isconnect(p.start, p.end)){
                bg.unit(p.start, p.end);
                res += p.val;
                ans.push_back(p);
            }
            // if(visit[p.start] != visit[p.end]){
            //     int lk = visit[p.end];
            //     for(int k = 0; k < n; k++){
            //         if(visit[k] == lk){
            //             visit[k] = visit[p.start];
            //         }
            //     }
            //     res += p.val;
            //     ans.push_back(p);
            // }
        }
        if(ans.size() == n-1){
            cout<<res<<endl;
            for(auto b : ans){
                if(b.start < b.end){
                    cout<<c[b.start]<<" "<<c[b.end]<<" "<<b.val<<endl;

                }else{
                    cout<<c[b.end]<<" "<<c[b.start]<<" "<<b.val<<endl;

                }
            }
        }else{
            cout<<-1<<endl;
        }
        
    }
}