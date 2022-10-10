#include<bits/stdc++.h>
#include <cctype>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
int main(){
    string s;
    string a="x^2",b="x";
    while (cin>>s) {
        int n=s.size();
        int i=0;
        vector<int>ans(3);
        vector<int> flag(3);
        while(i<n){
            

            if(s[i]=='x'&&i+1<n&&s[i+1]=='^'){

                if(i==0){
                    ans[0]=1;
                }else if(i>=1&&s[i-1]=='-'){
                    ans[0]=-1;
                }else {
                    ans[0]=stoi(s.substr(0,i));
                }
                flag[0]=i+3;
                i+=2;
            }else if(s[i]=='x'){
                // cout<<i<<" "<<n<<endl;
                if(i==0||(i>=1&&s[i-1]=='+')){
                    ans[1]=1;
                }else if(i>=1&&s[i-1]=='-'){
                    ans[1]=-1;
                }else {
                    if(flag[0]<n){
                        ans[1]=stoi(s.substr(flag[0],i-flag[0]));
                    }   
                }
                flag[1]=i+1;
                break;
            }
            i++;
        }
        if(flag[1]){
            if(flag[1]<n){
                ans[2]=stoi(s.substr(flag[1]));

            }
        }else if(flag[0]){
            if(flag[0]<n){
                ans[2]=stoi(s.substr(flag[0]));
            }
        }else{
            ans[2]=stoi(s);
        }
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    }
    
}