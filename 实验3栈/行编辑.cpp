#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        stack<char> st;
        for(auto&c:s){
            if(c=='#'&&!st.empty()){
                st.pop();
            }else if(c=='#'){
                continue;
            }else{
                st.push(c);
            }
        }
        if(st.empty()){
            cout<<"NULL"<<endl;
            continue;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }

}