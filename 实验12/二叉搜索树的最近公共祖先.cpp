#include<bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
struct node{
    node*left = nullptr;
    node*right = nullptr;
    int val;
    node(char val):val(val){}
};
class Tree{
    vector<int> first,middle;
public:
    node * root;

    node* build(int left, int right, vector<int> m){
        if(right < left){
            return nullptr;
        }
        if(left == right){
            return new node(first[left]);
        }
        node * p = new node(first[left]);
        int l = left + 1;
        // int t = m.find(first[left]);
        int t = std::find(m.begin(), m.end(), first[left]) - m.begin();
        int left_num = t;
        int right_num = m.size() - t -1;
        if(left_num > 0){
            p -> left = build(left + 1, left + left_num, vector<int>(m.begin(), m.begin() + t));
        }
        if(right_num > 0){ // m.substr(t + 1, m.size() - t - 1)
            p ->right = build(right - right_num + 1, right,vector<int>(m.begin() + t +1, m.end()));
        }
        
       
        return p;
    }
    vector<int> print(){
        vector<int> ans;
        bool f = true;
        function<void(node*)> dfs = [&](node *p){
            if(!p){
                return;
            }
            if(p->left){
                if(p->val >= p->left->val){
                    dfs(p->left);
                    
                }else{
                    f =false;
                    return;
                }
            }
            if(p->right){
                if(p->val <= p->right ->val){
                    dfs(p->right);

                }else{
                    f =false;
                    return;
                }
            }   
            ans.push_back(p->val);
        };
        dfs(root);
        if(!f){
            ans = vector<int>();
        }
        return ans;
    }
    Tree(vector<int> f, vector<int> m): first(f), middle(m){
        root = build(0, f.size() - 1, middle);
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
    bool find(node* p, int val){
        if(p == nullptr){
            return false;
        }
        if(p -> val == val){
            return true;
        }
        if(p -> val > val){
            return find(p -> left, val);
        }
        return find(p -> right, val);

    }
    void get_ans(int a, int b, node* p){
        if(!p){
            cout<<"ERROR: "<< a << " and "<< b <<" are not found."<<endl;
            return;
        }
        if(a < p -> val && b < p -> val){
            get_ans(a, b, p -> left);
        }
        if(a > p -> val && b > p -> val){
            get_ans(a, b, p -> right);
        }
        if((a < p -> val && b > p -> val) || (a > p -> val && b < p -> val)){
            bool f1 = find(p, a);
            bool f2 = find(p, b);
            if(f1 && f2){
                cout<<"LCA of "<< a<< " and "<< b << " is "<< p -> val<<"."<<endl;
            }else if(f1){
                cout<<"ERROR: "<< b <<" is not found."<<endl;
                
            }else if(f2){
                cout<<"ERROR: "<< a <<" is not found."<<endl;
            }else{
                cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
            }
        }
        if(a == p -> val){
            bool f1 = find(p, b);
            if(f1){
                cout<<a<<" is an ancestor of "<<b<<"."<<endl;
            }else{
                cout<<"ERROR: "<< b <<" is not found."<<endl;
            }
        }
        if(b == p -> val){
            bool f1 = find(p, a);
            if(f1){
                cout<<b<<" is an ancestor of "<<a<<"."<<endl;
            }else{
                cout<<"ERROR: "<< a <<" is not found."<<endl;
            }
        }
    }
};
int main(){
    int n, m;
    cin>>m>>n;
    vector<int> tmp(n);
    for(auto & c: tmp){
        cin>>c;
        
    }
    vector<int> k(tmp);
    sort(tmp.begin(), tmp.end());
    Tree tr(k, tmp);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        tr.get_ans(a, b, tr.root);
    }
}