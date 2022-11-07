#include<bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
struct edge{
    int start, end, val;
    edge(int s, int e, int v):start(s), end(e), val(v){}
    // bool operator > (const edge&rhs){
    //     return val > rhs.val;
    // }

};
void change(int a, int b, vector<int>& vis){
    int lk = vis[b];
        for(int k = 0; k < vis.size(); k++){
            if(vis[k] == lk){
                vis[k] = vis[a];
            }
        }
}
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
        int n;

    while(cin>>n){
        
        vector<edge> vt;
        vector<int> vis(n);
        for(int j = 0; j < n;j++){
            vis[j] = j;
        }
        int res = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int val;
                cin>>val;
                if(j !=k ){
                    vt.push_back(edge(j, k, val));
                }
                
            }
        }
        bing bg(n);
        int k;
        cin>>k;

        for(int j = 0; j < k; j++){
            int a, b;
            cin>>a>>b;
            bg.unit(a - 1 , b - 1);
            // change(a - 1, b - 1, vis);

        }
        sort(vt.begin(), vt.end(), [](const edge&lhs, const edge&rhs){
            return lhs.val < rhs.val;
        });
        for(auto p : vt){
            if(!bg.isconnect(p.start, p.end)){
                bg.unit(p.start, p.end);
                res += p.val;
            }
            // if(vis[p.start] != vis[p.end]){
            //     change(p.start, p.end, vis);
            //     res += p.val;
            // }
        }
        cout<<res<<endl;
        
    }
}