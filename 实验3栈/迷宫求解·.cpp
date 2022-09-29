#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={{0,1},{1,0},(0,-1),(-1,0)};
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        vector<vector<int>> mp(n,vector<int>(n));
        vector<vector<int>> vis(n,vector<int>(n));
        for(auto&a:mp){
            for(auto &c:a){
                cin>>c;
            }
        }
        stack<pair<int,int>> st;
        st.push({0,0});
        bool f=false;
        function<void(int,int)> dfs=[&](int x,int y){
            if(!f&&x==n-1&&y==n-1){
                f=true;
                auto p=st;
                vector<pair<int,int>> ans;
                while(!p.empty()){
                    ans.push_back(p.top());
                    p.pop();
                }
                reverse(ans.begin(),ans.end());
                for(int i=0;i<ans.size();i++){
                    cout<<"["<<ans[i].first<<","<<ans[i].second<<"]"<<"--";
                    if((i+1)%4==0){
                        cout<<endl;
                    }
                }
                cout<<"END"<<endl;
            }
            // if(x>=0&&x<n&&y>=0&&y<n&&mp[x][y]!=1&&vis[x][y]==0){
                for(int i=0;i<4;i++){
                    int tx=x+dir[i][0];
                    int ty=y+dir[i][1];
                    if(tx>=0&&tx<n&&ty>=0&&ty<n&&mp[tx][ty]!=1&&vis[tx][ty]==0){
                        st.push({tx,ty});
                        vis[tx][ty]=1;
                        dfs(tx,ty);
                        vis[tx][ty]=0;
                        st.pop();
                    }
                    
                    
                }
            // }
        };
        dfs(0,0);
        if(!f){
            cout<<"no path"<<endl;
        }
        
        // reverse(ans.begin(),ans.end());
        // int y=0;
        // for(auto &c:ans){
        //     cout<<"["<<c.first<<","<<c.second<<"]"
        // }
    }
}