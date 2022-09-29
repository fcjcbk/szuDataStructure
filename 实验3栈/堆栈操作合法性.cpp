#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int MAX;
    cin>>t>>MAX;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        stack<char> st;
        bool f=false;
        for(auto&c:s){
            if(c=='S'){
                st.push(c);
                if(st.size()>MAX){
                    f=true;
                    break;
                }
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    f=true;
                    break;
                }
            }
        }
        if(f||!st.empty()){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}