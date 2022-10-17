#include<bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
struct Node{
    char val='0';
    Node*left= nullptr;
    Node*right= nullptr;
    Node()=default;
    Node(char v):val(v){}
};
void PostOrder(Node*root,string &s);
class Tree{
    Node*root=nullptr;
    int index=0;
    string str="";
    Node*create_tree(){
        Node* node = nullptr;
        if(index<str.size()){
            
            if(str[index]=='#'){
                return nullptr;
            }
            node=new Node(str[index]);
            index++;
            node->left= create_tree();
            index++;
            node->right= create_tree();
        }
        return node;
    }
    void deleteNode(Node*p){
        if(p->left){
            deleteNode(p->left);
        }
        if(p->right){
            deleteNode(p->right);
        }
        // cout<<"delete "<<p->val<<endl;
        delete p;
    }
public:
    Tree()=default;
    ~Tree(){
        deleteNode(root);
    }
    
    Tree(string s):str(s){
        root= create_tree();
    }
    void get_height(){
        int ans=1;
        // function<int(Node*)> dfs=[&](Node*p){
        //     if(!p){
        //         return 0;
        //     }
        //     int a= dfs(p->left);
        //     int b= dfs(p->right);
        //     if(a==0&&b==0){
        //         mp.insert({p->val,0});
        //     }
        //     if(a!=0&&b!=0){
        //         ans=max(ans,a+b);
        //     }
        
        //     return max(a,b)+1;
        // };
        // dfs(root);
        char c='0',d='0';
        dp(root,ans,c,d);
        if(ans==1){
            cout<<"0:"<<endl;
        }else{
            cout<<ans<<":"<<c<<" "<<d<<endl;
        }

    }
    
    pair<char,int> dp(Node*p,int &ans,char&c,char&d){
        if(!p){
            return make_pair('0',0);
        }
        pair<char,int> a= dp(p->left,ans,c,d),b= dp(p->right,ans,c,d),res;
        if(a.second==0&&b.second==0){
            return make_pair(p->val,1);
        }
        if(a.second!=0&&b.second!=0){
            if(ans<a.second+b.second){
                ans=a.second+b.second;
                c=a.first;
                d=b.first;
            }
            
            
            
        }
        if(a.second==0||b.second==0){
            
            if(ans<a.second+b.second){
                ans=a.second+b.second;
                if(a.second!=0){
                    c=a.first;
                    d=p->val;
                }
                if(b.second!=0){
                    d=b.first;
                    c=p->val;
                }
            }
            
            
        }
        if(a.second>b.second){
            a.second+=1;
            res=a;
        }else{
            b.second+=1;
            res=b;
        }
        return res;
        // return max(a,b)+1;
    }

};

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        Tree ts(s);
        ts.get_height();


    }
}