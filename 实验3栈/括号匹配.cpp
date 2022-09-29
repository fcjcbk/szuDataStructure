#include<bits/stdc++.h>
using namespace std;
bool isValid(char &c){
    if(c=='('||c=='['||c=='{'){
        return true;
    }
    return false;
}
bool isValid1(char c){
    if(c==')'||c==']'||c=='}'){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        stack<char> st;
        bool f=false;
        for(auto&c:s){
            if(isValid(c)){
                st.push(c);
            }
            if(isValid1(c)){
                if(c==')'){
                    if(st.top()=='('){
                        st.pop();
                    }else{
                        cout<<"error"<<endl;
                        f=true;
                        break;
                    }
                }else if(c=='}'){
                    if(st.top()=='{'){
                        st.pop();
                    }else{
                        cout<<"error"<<endl;
                        f=true;

                        break;
                    }
                }else{
                    if(st.top()=='['){
                        st.pop();
                    }else{
                        cout<<"error"<<endl;
                        f=true;

                        break;
                    }
                }
            }
            
        }
        if(!f&&st.empty()){
            cout<<"ok"<<endl;

        }else{
            cout<<"error"<<endl;
        }
    }
}