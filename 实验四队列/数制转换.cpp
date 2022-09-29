#include<bits/stdc++.h>
using namespace std;
char num[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        double a;
        int b ;
        cin>>a>>b;
        int zh=static_cast<int>(a);
        double xh=a-zh;
        stack<int> st;
        queue<int> qu;
        while(zh>0){
            st.push(zh%b);
            zh/=b;
        }
        while(xh!=0){
            xh*=b;
            if(xh>=1){
                int c=static_cast<int>(xh);
                xh-=c;
                qu.push(c);
            }else{
                qu.push(0);
            }
        }
        string ans;
        if(!st.empty()){
            while(!st.empty()){
                ans.push_back(num[st.top()]);
                st.pop();

            }
        }else{
            ans+="0";
        }
        int l=0;
        if(!qu.empty()){
            ans+=".";
            l=ans.length();
            while(!qu.empty()){
                ans.push_back(num[qu.front()]);
                qu.pop();
            }
        }
        while(ans.length()-l<3){
            ans+="0";
        }
        cout<<ans<<endl;
        

    }
    
}
