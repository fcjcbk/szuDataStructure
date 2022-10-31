#include<bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &mp, vector<int>&v, int index){
    v[index] = 1;
    for(int i = 0; i < mp.size(); i++){
        if(mp[index][i] == 1 && v[i] == 0){
            dfs(mp, v, i);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mp(n,vector<int>(n,0));
    vector<int> visit(n,0);
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    int l = 0;
    for(int i = 0; i < n; i++){
        if(visit[i] == 0){
            dfs(mp, visit, i);
            l++;
        }
    }
    cin>>m;
    vector<int> destory;
    unordered_set<int> gu;
    for(int i = 0; i < m; i++){
        int s;
        int z = 0;
        vector<int> visit1 = vector<int>(n,0);
        cin>>s;
        destory.push_back(s);
        
        for(auto& y: destory){
            visit1[y] = 1;
        }
        for(int j = 0; j < n;j++){
            bool flag1 =false;
            for(int k = 0; k < n; k++){
                if(mp[k][j] == 1){
                    flag1 = true;
                    break;
                }
            }
            if(!flag1){
                gu.insert(j);
            }
        }
        for(int j = 0; j < n; j++){
            mp[j][s] = 0;
            mp[s][j]= 0;
        }
        if(gu.count(s)!=0){
            l--;
            gu.erase(s);
            cout<<"City "<<s<<" is lost."<<endl;
            continue;
        }
        for(int j = 0; j < n;j++){
            if(visit1[j] == 0){
                dfs(mp, visit1, j);
                z++;
            }
            
        }
        
        if(l != z){
            l = z;
            cout<<"Red Alert: City "<<s<<" is lost!"<<endl;
        }else{
            cout<<"City "<<s<<" is lost."<<endl;
        }
        
    }
    if(destory.size() == n){
        cout<<"Game Over."<<endl;
    }
}