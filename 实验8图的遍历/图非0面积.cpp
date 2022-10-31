#include<bits/stdc++.h>
#include <vector>
using namespace std;
int step[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n, m;
        int c;
        int sum = 0;
        int one = 0;
        int count = 0;
        cin>>n>>m;
        sum = n * m;
        vector<vector<int>> vt(n, vector<int>(m, 0));
        vector<int> v(n, 0);
        for(auto&a : vt){
            for(auto& b: a){
                cin>>b;
                if(b == 1){
                    one++;
                }
            }
        }
        // vector<vector<int>> book(n,vector<int>(n,0));
        function<void(int,int)> dfs = [&](int x, int y){
            if(vt[x][y] == 1 || vt[x][y] == 2){
                return;
            }
            vt[x][y] = 2;
            count ++;
            for(int j = 0; j < 4; j++){
                int nx = x + step[j][0];
                int ny = y + step[j][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    dfs(nx, ny);
                }
            }
        };
        for(int j = 0; j < n; j++){
            dfs(j, 0);
            dfs(j, m-1);
        }
        for(int j = 0; j < m; j++){
            dfs(0,j);
            dfs(n-1, j);
        }
        cout<<sum - one -count<<endl;
    }
}