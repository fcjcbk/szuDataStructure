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
    int get_height(){
        function<int(Node*)> dfs=[&](Node*p){
            if(!p){
                return 0;
            }
            return max(dfs(p->left),dfs(p->right))+1;
        };
        return dfs(root);
    }

};
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        Tree ts(s);
        cout<<ts.get_height()<<endl;
    }
}