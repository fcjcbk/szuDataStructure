#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        stack<char> st;
        for(auto&c:s){
            st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        cout<<ans<<endl;
    }
}