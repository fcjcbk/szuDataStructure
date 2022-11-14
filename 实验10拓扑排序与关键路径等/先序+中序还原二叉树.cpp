#include<bits/stdc++.h>
using namespace std;
struct node{
    node*left = nullptr;
    node*right = nullptr;
    char val;
    node(char val):val(val){}
};
class Tree{
    string first,middle;
    node * root;
public:
    node* build(int left, int right, string m){
        if(right < left){
            return nullptr;
        }
        if(left == right){
            return new node(first[left]);
        }
        node * p = new node(first[left]);
        int l = left + 1;
        int t = m.find(first[left]);
        int left_num = t;
        int right_num = m.size() - t -1;
        if(left_num > 0){
            p -> left = build(left + 1, left + left_num, m.substr(0, t));
        }
        if(right_num > 0){
            p ->right = build(right - right_num + 1, right, m.substr(t + 1, m.size() - t - 1));
        }
        
       
        return p;
    }
    void print(node *p){
        if(!p){
            return;
        }
        cout<<p->val;
        print(p->left);
        print(p->right);
    }
    void print1(node *p){
        if(!p){
            return;
        }
        print1(p->left);
        cout<<p->val;
        print1(p->right);
    }
    Tree(string f, string m): first(f), middle(m){
        root = build(0, f.size() - 1, middle);
        cout<<get_height(root)<<endl;
        // print(root);
        // cout<<endl;
        // print1(root);
        // cout<<endl;
    }
    int get_height(node *p){
        if(p == nullptr){
            return 0;
        }
        return max(get_height(p->left), get_height(p->right))+1;
    }
    ~Tree(){
        if(root){
            delete_node(root);
        }
    }
    void delete_node(node *p){
        if(p->left){
            delete_node(p->left);
        }
        if(p->right){
            delete_node(p->right);
        }
        delete p;
    }
};
int main(){
    int n;
    string a, b;

    cin>>n;
    cin>>a>>b;
    Tree tr(a, b);
}