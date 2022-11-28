#include<bits/stdc++.h>
using namespace  std;
int main(){
    int n;
    cin>>n;
    vector<int> t(n);
    for(int j = 0; j < n; j++){
        cin>>t[j];
    }
    sort(t.begin(), t.end());
    vector<int> q(n + 1);
    int index = 0;
    function<void(int)> dfs = [&](int x){
        if(2* x <= n){
            dfs(2 * x);

        }
        q[x] = t[index++];
        if(2*x + 1 <= n){
            dfs(2 * x  + 1);
        }
    };
    dfs(1);
    cout<<q[1];
    for(int i = 2; i <= n; i++){
        cout<<" "<<q[i];
    }
};