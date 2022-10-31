#include<bits/stdc++.h>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &vt, int index, vector<int>& v){
    v[index] = 1;
    cout<<index<<" ";
    for(int i = 0; i < vt[index].size(); i++){
        if(vt[index][i] == 1 && v[i] == 0){
            dfs(vt, i, v);
        }
    }
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<vector<int>> vt(n, vector<int>(n, 0));
        vector<int> v(n, 0);
        for(int j = 0; j< n; j++){
            for(int k = 0; k < n; k++){
                cin>>vt[j][k];
            }
        }
        for(int j = 0; j < n; j++){
            if(v[j] == 0){
                dfs(vt, j, v);
            }
        }
        cout<<endl;
    }
}