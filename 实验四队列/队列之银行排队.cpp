#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<queue<int>> vt(3);
    int t;
    cin>>t;
    vector<int> in(t);
    for(auto&c:in){
        char d;
        cin>>d;
        c=d-'A';
    }
    for(int i=0;i<t;i++){
        int k;
        cin>>k;
        vt[in[i]].push(k);
    }
    for(int i=0;i<3;i++){
        int sum=0;
        int s=vt[i].size();
        while(!vt[i].empty()){
            sum+=vt[i].front();
            vt[i].pop();
        }
        cout<<sum/s<<endl;

    }
}