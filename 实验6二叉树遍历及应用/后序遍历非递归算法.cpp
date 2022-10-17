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
    void back(){
        stack<pair<bool,Node*>> st;
        st.push({true,root});
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            if(p.second==nullptr){
                continue;
            }
            if(!p.first){
                cout<<p.second->val;
            }else{
                st.push({false,p.second});
                st.push({true,p.second->right});
                st.push({true,p.second->left});
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
        ts.back();
    }
}