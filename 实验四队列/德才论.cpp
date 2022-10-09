#include<bits/stdc++.h>
using namespace std;
struct p{
    string no;
    int df;
    int cf;
    p(string no,int a,int b):no(no),df(a),cf(b){}
    
};
bool operator<(const p&lhs,const p&rhs){
        if(lhs.df+lhs.cf!=rhs.df+rhs.cf){
            return lhs.df+lhs.cf<rhs.df+rhs.cf;
        }else if(lhs.df!=rhs.df){
            return lhs.df<rhs.df;
        }else{
            return lhs.no>rhs.no;
        }
}
// struct cmp{
//     bool operator()(const p&lhs,const p&rhs){
//         if(lhs.df!=rhs.df){
//             return lhs.df<rhs.df;
//         }else if(lhs.cf!=rhs.cf){
//             return lhs.cf<rhs.cf;
//         }else{
//             return lhs.no>rhs.no;
//         }
//     }
// };
int main(){
    int n,l,h;
    cin>>n>>l>>h;
    priority_queue<p,vector<p>,less<>> qu;
    priority_queue<p,vector<p>,less<>>qu1;
    priority_queue<p,vector<p>,less<>>qu2;
    priority_queue<p,vector<p>,less<>>qu3;

    for(int i=0;i<n;i++){
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(a>=h&&b>=h){
            qu.push(p(s,a,b));
        }else if(a>=h&&b>=l){
            qu1.push(p(s,a,b));
        }else if(a>=l&&b>=l&&a>b){
            qu2.push(p(s,a,b));
        }else if(a>=l&&b>=l){
            qu3.push(p(s,a,b));

        }
        // cout<<s<<" "<<a<<" "<<b<<endl;
    }
    cout<<qu.size()+qu1.size()+qu2.size()+qu3.size()<<endl;
    while(!qu.empty()){
        auto q=qu.top();
        cout<<q.no<<" "<<q.df<<" "<<q.cf<<endl;
        qu.pop();
    }
    while(!qu1.empty()){
        auto q=qu1.top();
        cout<<q.no<<" "<<q.df<<" "<<q.cf<<endl;
        qu1.pop();
    }
    while(!qu2.empty()){
        auto q=qu2.top();
        cout<<q.no<<" "<<q.df<<" "<<q.cf<<endl;
        qu2.pop();
    }
    while(!qu3.empty()){
        auto q=qu3.top();
        cout<<q.no<<" "<<q.df<<" "<<q.cf<<endl;
        qu.pop();
    }
}