#include<bits/stdc++.h>
#include <vector>
using namespace std;

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
                queue<int> qu;
                qu.push(j);
                v[j] = 1;
                while(!qu.empty()){
                    
                    int  g = qu.size();
                    for(int f = 0; f < g; f++){
                        auto p = qu.front();
                        qu.pop();
                        cout<<p<<" ";
                        for(int h = 0; h < n; h++){
                            if(vt[p][h] == 1 && v[h] == 0){
                                v[h] = 1;
                                qu.push(h);
                            }
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
}