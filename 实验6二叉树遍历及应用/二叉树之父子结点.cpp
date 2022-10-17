#include<bits/stdc++.h>
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
    void find_father(){
        int res=0;
        vector<char> le,father;
        function<bool(Node*)> dfs = [&](Node*p){
            bool f=false;
            if(p->left==nullptr&&p->right==nullptr){
                le.push_back(p->val);
                return true;
            }else{
                if(p->left){
                    f=dfs(p->left);
                    if(f){
                        father.push_back(p->val);
                    }
                }
                if(p->right){
                    f=dfs(p->right);
                    if(f){
                        father.push_back(p->val);
                    }
                }
            }
            return false;
        };
        bool f= dfs(root);
        if(f){
            father.push_back(root->val);
        }
        for(auto &a:le){
            cout<<a<<" ";
        }
        cout<<endl;
        for(auto &b:father){
            cout<<b<<" ";
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
        ts.find_father();

    }
}