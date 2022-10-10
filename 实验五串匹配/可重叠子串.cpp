#include<bits/stdc++.h>
#include <memory>
#include <unordered_map>
#include <vector>
using namespace std;
int KMP(string pattern,string s){
    // cout<<pattern<<" "<<s<<endl;
    int n=pattern.size(),m=s.size();
    vector<int> next(n);
    for(int i=1,j=0;i<n;i++){
        while(j>0&&pattern[i]!=pattern[j]){
            j=next[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
        }
        next[i]=j;
    }
    // cout<<"-1 ";
    // for(int i=0;i<next.size()-1;i++){
    //     cout<<next[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0,j=0;i<m;i++){
        while(j>0&&s[i]!=pattern[j]){
            j=next[j-1];
        }
        if(s[i]==pattern[j]){
            j++;
        }
        if(j==n){
            return i-n+1;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        unordered_map<string, int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=n-i;j>0;j--){
                if(i+j>n){
                    continue;
                }
                string ko=s.substr(i,j);
                mp[ko]++;
            }
        }
        int f;
        cin>>f;
        string kl;
        for(int k=0;k<f;k++){
            cin>>kl;
            cout<<kl<<":"<<mp[kl]<<endl;
        }
        
    }
}