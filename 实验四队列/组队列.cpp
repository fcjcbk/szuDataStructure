#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int tmp;
        for(int j=0;j<k;j++){
            cin>>tmp;
            mp[tmp]=i;
        }

    }
    vector<queue<int>> vt(n);
    queue<int> gn;
    string s;
    unordered_set<int> hs;
    vector<int> ans;
    while(s!="STOP"){
        cin>>s;
        int g;
        if(s=="ENQUEUE"){
            cin>>g;
            int gno=mp[g];
            if(!hs.count(gno)){
                gn.push(gno);
            }
            vt[gno].push(g);
        }else if(s=="DEQUEUE"){
            auto p=gn.front();
            ans.push_back(vt[p].front());
            vt[p].pop();
            if(vt[p].empty()){
                gn.pop();
            }
        }
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans.back()<<endl;
}