#include<bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Node{
    char val='0';
    Node*left= nullptr;
    Node*right= nullptr;
    Node()=default;
    Node(char v):val(v){}
};
class Tree{
    Node*root=nullptr;
    int index=0;
    string str="";
    unordered_map<char, int> mp;
    int n = 0;
    void dfs(Node* p,string s){
        if(!p){
            return;
        }
        if(p->left == nullptr && p->right == nullptr){
            s.pop_back();
            cout<<s<<endl;
        }
        dfs(p->left,s+"0 ");
        dfs(p->right,s+"1 ");
    }
    Node* ct(char ck){
        char cr;
        if(ck == '0'){
            return nullptr;
        }
        Node* p = new Node(ck);
        bool flag = true;
        for(int i = 0; i < n; i++){
            cin>>cr;
            if(cr != '0'){
                if(flag){
                    p -> left = ct(cr);
                    flag = false;
                }else{
                    auto res = p->left;
                    auto q = res;
                    while(res){
                        q = res;
                        res = res->right;
                    }
                    res = q;
                    res -> right = ct(cr);
                }
            }
        }
        return p;
    }
    void deleteNode(Node*p){
        if(!p){
            return;
        }
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
    
    Tree(char s,int n): n(n){
        root= ct(s);
    }
    void print(string s){
        dfs(root, s);
    }
    void pre(Node * p){
        if(!p){
            return;
        }
        cout<<p->val<<endl;
        pre(p->left);
        pre(p->right);
    }

};
int main(){
    int t,n;
    cin>>t>>n;
    char d;
    string s="";
    for(int i =0;i< t;i++){
        if(i!= 0){
            s.append("1 ");
        }
        cin>>d;
        Tree tr(d,n);
        tr.print(s);
    }
    
    
    

}
