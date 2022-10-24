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
    int get_height(vector< pair<char, int> > vt){
        for(auto & v: vt){
            mp[v.first] = v.second;
        }
        int ans = 0;
        function<void(Node*, int)> dfs=[&](Node*p,int sum){
            if(!p){
                return;
            }
            sum +=mp[p->val];
            if(p->left==nullptr && p->right == nullptr){
                ans = max(ans,sum);
            }
            dfs(p->left, sum);
            dfs(p->right, sum);
        };
        dfs(root,0);
        
        return ans;
    }

};
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        string s;
        cin>>s;
        vector< pair<char, int> > vt;
        for(auto&c:s){
            if(c>='A'&&c<+'Z'){
                vt.push_back(make_pair(c,0));
            }
        }
        int k;
        cin>>k;
        for(int j = 0; j < k; j++){
            int g;
            cin>>g;
            vt[j].second = g;
        }
        Tree tr(s);
        cout<<tr.get_height(vt)<<endl;
    }
    

}