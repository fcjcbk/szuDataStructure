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
class Tree;
bool is_same1(const Tree&lhs, const Tree&rhs);
class Tree{
    friend bool is_same1(const Tree&lhs, const Tree&rhs);
    int index=0;
    string str="";
    unordered_map<char, int> mp;
    Node*root=nullptr;
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

     string bfs(int m){
        queue<Node*> qu;
        qu.push(root);
        int j = 0;
        string ans;
        while(j<m){
            int n=qu.size();
            for(int i=0;i<n;i++){
                auto p =qu.front();
                qu.pop();
                j++;
                if(p){
                    ans.push_back(p->val);
                    
                    qu.push(p->left);
                    
                    
                    qu.push(p->right);
                    
                }else{
                    ans.push_back('#');
                    qu.push(nullptr);
                    qu.push(nullptr);
                }
                
            }
        }
        return ans;
    }

    

};

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        string a,b;
        cin>>a>>b;
        Tree t1(b);
                int n = a.size();
        string k = t1.bfs(n);
        // cout<<k<<endl;
        if(k.substr(0,n) == a){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    

}