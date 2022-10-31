#include<bits/stdc++.h>
#include <functional>
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
    void print(){
        queue<pair<Node*,int>> qu;
        vector<pair<char,int>> vt;
        if(!root){
            return;
        }
        qu.push(make_pair(root, -1));
        while(!qu.empty()){
            int m = qu.size();
            for(int i = 0; i < m; i++){
                auto p = qu.front();
                qu.pop();
                vt.push_back(make_pair(p.first->val, p.second));
                int b = vt.size() -1;
                if(p.first->left){
                    qu.push(make_pair(p.first->left, b));
                }
                if(p.first->right){
                    qu.push(make_pair(p.first->right, b));
                }
            }
        }
        for(int i = 0; i < vt.size(); i++){
            if(i < vt.size()-1){
                cout<<vt[i].first<<" ";
            }else{
                cout<<vt[i].first<<endl;
            }
        }
        for(int i = 0; i < vt.size(); i++){
            if(i < vt.size()-1){
                cout<<vt[i].second<<" ";
            }else{
                cout<<vt[i].second<<endl;
            }
        }
    }

};

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        Tree ts(s);
        ts.print();


    }
}