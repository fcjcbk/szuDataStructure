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
    int index=0;
    string str="";
    unordered_map<char, int> mp;
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
    Node*root=nullptr;

    Tree()=default;
    ~Tree(){
        if(root){
            deleteNode(root);
        }
    }
    
    Tree(string s):str(s){
        root= create_tree();
    }
    void reverse(){
        function<void(Node*)> dfs =[&](Node* p){
            if(!p){
                return;
            }
            swap(p->left,p->right);
            dfs(p->left);
            dfs(p->right);
        };
        dfs(root);
    }
    void pre(Node * p){
        if(p == nullptr){
            return;
        }
        cout<<p->val<<" ";
        pre(p->left);
        pre(p->right);
    }
    void mid(Node *p){
        if(p == nullptr){
            return;
        }
        mid(p->left);
        cout<<p->val<<" ";
        mid(p->right);
    }
    void back(Node * p){
        if(p == nullptr){
            return;
        }
        back(p->left);
        back(p->right);
        cout<<p->val<<" ";
    }
    void bfs(){
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto p =qu.front();
                qu.pop();
                if(p){
                    cout<<p->val<<" ";
                    if(p->left){
                        qu.push(p->left);
                    }
                    if(p->right){
                        qu.push(p->right);
                    }
                }
                
            }
        }
        cout<<endl;
    }

};
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        string s;
        cin>>s;
        Tree tr(s);
        tr.reverse();
        if(tr.root){
            tr.pre(tr.root);
            cout<<endl;
            tr.mid(tr.root);
            cout<<endl;
            tr.back(tr.root);
            cout<<endl;
            tr.bfs();
        }else{
            cout<<"NULL"<<endl;
            cout<<"NULL"<<endl;
            cout<<"NULL"<<endl;
            cout<<"NULL"<<endl;

        }
        
    }
    

}