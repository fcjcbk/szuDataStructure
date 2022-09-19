#include<bits/stdc++.h>
using namespace std;
struct room{
    int no=0;
    string name="";
    room(int no,string name=""):no(no),name(name){}
    
};
bool operator==(const room&lhs,const room&rhs){
    return lhs.no==rhs.no;
}
bool operator!=(const room&lhs,const room&rhs){
    return lhs.no!=rhs.no;
}
bool operator<(const room&lhs,const room&rhs){
    return lhs.no<rhs.no;
}
int main(){
    int n;
    cin>>n;
    list<room> lived;
    list<room> unlived;
    vector<bool> book(20);
    for(int i=0;i<n;i++){
        int no;
        string name;
        cin>>name>>no;
        lived.push_back(room(no,name));
        book[no-101]=true;
    }
    for(int i=0;i<20;i++){
        if(!book[i]){
            unlived.push_back(room(i+101));
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string work;
        cin>>work;
        if(work=="assign"){
            string name;
            cin>>name;
            int no=unlived.front().no;
            unlived.pop_front();
            auto p=upper_bound(lived.begin(),lived.end(),room(no,name));
            lived.insert(p,room(no,name));
        }else if(work=="return"){
            int no;
            cin>>no;
            auto p=find(lived.begin(),lived.end(),room(no));
            lived.erase(p);
            unlived.push_back(room(no));
        }else if(work=="display_used"){
            for(auto&it:lived){
                if(it!=lived.back()){
                    cout<<it.name<<"("<<it.no<<")"<<"-";
                }else{
                    cout<<it.name<<"("<<it.no<<")"<<endl;
                }
            }
        }else{
            for(auto&it:unlived){
                if(it!=unlived.back()){
                    cout<<it.no<<"-";
                }else{
                    cout<<it.no<<endl;
                }
            }
        }
    }
}