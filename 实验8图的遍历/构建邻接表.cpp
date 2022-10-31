#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n, k;
        cin>>n>>k;
        vector<vector<int>> vt(n, vector<int>());
        vector<char> point(n); 
        unordered_map<char, int> mp;
        for(int j = 0; j < n; j++){
            cin>>point[j];
            mp[point[j]] = j;
        }
        for(int j = 0; j < k; j++){
            char a,b;
            cin>>a>>b;
            vt[mp[a]].push_back(mp[b]);
        }
        for(int j = 0; j < n; j++){
            cout<<j<<" "<<point[j]<<"-";
            for(auto & v: vt[j]){
                cout<<v<<"-";
            }
            cout<<"^"<<endl;
        }
    }
}