#include<bits/stdc++.h>
using namespace std;
struct date{
    int s1,s2;
    string s;
    date(string s,int s1,int s2):s1(s1),s2(s2),s(s){}
};
int main(){
    vector<date> open;
    vector<date> close;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s,c;
        int a,b;
        cin>>s>>c>>a>>b;
        
        if(c=="open"){
            open.emplace_back(date(s,a,b));
        }else{
            close.emplace_back(date(s,a,b));
        }
    }
    auto p=[](const date&lhs,const date&rhs){
        return lhs.s<rhs.s;
    };
    sort(open.begin(),open.end(),p);
    sort(close.begin(),close.end(),p);
    for(int i=0;i<open.size();i++){
        // cout<<open[i].s<<" "<<open[i].year<<" "<<open[i].month<<" "<<open[i].day<<" "<<endl;
    }
    for(int i=m-1;i<open.size();i++){
        int s1a=0,s2a=0;
        for(int j=0;j<m;j++){
            s1a+=open[i-j].s1;
            s2a+=open[i-j].s2;
        }
        s1a/=m;
        s2a/=m;
        cout<<open[i].s<<" open "<<s1a<<" "<<s2a<<endl;
    }
    for(int i=m-1;i<close.size();i++){
        int s1a=0,s2a=0;
        for(int j=0;j<m;j++){
            s1a+=close[i-j].s1;
            s2a+=close[i-j].s2;
        }
        s1a/=m;
        s2a/=m;
        cout<<close[i].s<<" close "<<s1a<<" "<<s2a<<endl;
    }
}