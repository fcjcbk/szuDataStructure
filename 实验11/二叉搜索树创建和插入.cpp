#include<bits/stdc++.h>
using namespace std;

struct node{
    node*left = nullptr;
    node*right = nullptr;
    int val = 0;
    node(int val):val(val){}
};
class tree{
    node*root = nullptr;
    void delete_node(node*p){
        if(!p){
            return;
        }
        delete_node(p->left);
        delete_node(p->right);
        delete p;
    }
public:
    tree() = default;
    ~tree(){
        delete_node(root);
    }
    void insert(int key){
        if(!root){
            root = new node(key);
            return;
        }
        auto p = root;
        node* q;
        while(p != nullptr){
            q = p;
            if(key > p->val){
                p = p->right;
            }else{
                p = p->left;
            }
        }
        if(key > q->val){
            q ->right = new node(key);
        }else{
            q -> left = new node(key);
        }
    }
    void print(){
        function<void(node*)> dfs = [&](node* p){
            if(!p){
                return;
            }
            dfs(p->left);
            cout<<p->val<<" ";
            dfs(p->right);
        };
        dfs(root);
        cout<<endl;
    }
    int find(int key){
        int ans = 0;
        function<void(node*,int)> dfs = [&](node* p, int key){
            if(!p){
                ans = -1;
                return;
            }
            ans++;
            if(p->val == key){
                return;
            }
            if(p->val > key){
                dfs(p->left, key);
            }else{
                dfs(p->right, key);
            }

        };
        dfs(root, key);
        return ans;
    }
    node* delete_key(node *p, int key){
        if(!p){
            return nullptr;
        }
        if(p-> val > key){
            p->left = delete_key(p->left, key);
            return p;
        }else if(p->val < key){
            p->right = delete_key(p->right, key);
            return p;
        }
        node* res = nullptr;
        
        if(p->val == key){
                if(p->left == nullptr && p -> right == nullptr){
                delete p;
            }else if(p->left == nullptr && p ->right != nullptr){
                res = p-> right;
                delete p;
            }else if(p-> left != nullptr && p->right == nullptr){
                res  = p->left;
                delete p;
            }else{
                auto f = p->right;
                auto q = f;
                while(f != nullptr){
                    q = f;
                    f = f->left;
                }
                p -> val = q -> val;
                p->right = delete_key(p->right, p->val);
                res = p;
            }
        }
        
        return res;
    }
    void dl(int key){
        root = delete_key(root, key);
    }
};

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        tree tt;
        int k;
        cin>>k;
        for(int j = 0; j < k; j++){
            int tmp;
            cin>>tmp;
            tt.insert(tmp);
        }
        tt.print();
        cin>>k;
        for(int j = 0; j < k; j++){
            int tmp;
            cin>>tmp;
            tt.dl(tmp);
            tt.print();
        }
        
    }
}