#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int KMP(string pattern,string s){
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
    cout<<"-1 ";
    for(int i=0;i<next.size()-1;i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        int k=KMP(b, a);
        cout<<k+1<<endl;

    }
}