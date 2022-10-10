#include <bits/stdc++.h>
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
        string s,p,d;
        cin>>s>>p>>d;
        int n=p.size();
        int k=KMP(p, s);
        cout<<s<<endl;
        if(k!=-1){
            s.replace(k,n,d);
        }
        cout<<s<<endl;
    }
}