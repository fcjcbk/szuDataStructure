#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<char> q1;
    stack<int> q2;
    string s;
    cin>>s;
    char a=s[0];
    int i=0;
    for(auto&c:s){
        if(!q1.empty()&&q1.top()!=c){
            q1.pop();
            auto p=q2.top();
            q2.pop();
            cout<<p<<" "<<i<<endl;
        }else{
            q1.push(c);
            q2.push(i);
        }
        i++;
    }
}