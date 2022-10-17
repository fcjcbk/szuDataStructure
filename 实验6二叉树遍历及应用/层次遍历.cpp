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
class Tree{
    Node*root=nullptr;
    int index=0;
    string str="";
    Node*create_tree(){
        Node* node = nullptr;
        if(index<str.size()){
            
            if(str[index]=='0'){
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
    void bfs(){
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto p =qu.front();
                qu.pop();
                cout<<p->val;
                if(p->left){
                    qu.push(p->left);
                }
                if(p->right){
                    qu.push(p->right);
                }
            }
        }
        cout<<endl;
    }
    

};
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        Tree ts(s);
        ts.bfs();
    }
}