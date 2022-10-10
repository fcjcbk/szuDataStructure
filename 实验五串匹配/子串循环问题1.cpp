#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int KMP(string pattern){
    int n=pattern.size();
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
    return next[n-1];
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        int k=KMP(s);
        int n=s.size();
        // cout<<k<<" "<<n<<endl;
        int l=n-k;
        if(n%l==0&&k){
            cout<<0<<endl;
        }else{
            cout<<l-n%l<<endl;
        }
        
        
    }
}