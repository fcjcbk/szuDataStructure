#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val = 0;
    char c = '0';
    Node*left = nullptr;
    Node*right = nullptr;
    Node()=default;
    Node(int val, Node*left, Node*right ):val(val),left(left), right(right){}
    Node(int val, char c):val(val), c(c){}
};

class Huffman{
    unordered_map<char, string> mp;
    priority_queue<pair<int, Node*>,vector<pair<int, Node*>>, greater<>> qu;
    Node* root = nullptr;
    void deleteNode( Node*p ){
        if(!p){
            return;
        }
        if(p->left){
            deleteNode(p->left);
        }
        if(p->right){
            deleteNode(p->right);
        }
        delete p;
    }
public:
    Huffman(vector<pair<char, int>> &v){
        for(const auto&a:v){
            qu.push(make_pair(a.second, new Node(a.second,a.first)));
        }
        while(qu.size()>1){
            auto p = qu.top();
            qu.pop();
            auto q = qu.top();
            qu.pop();
            Node* tmp = new Node(p.first+q.first, p.second,q.second);
            qu.push(make_pair(tmp->val,tmp));
        }
        assert(qu.size() == 1);
        auto r = qu.top();
        root = r.second;
        qu.pop();
        calculate();
        // dfs(root);
        for(int i= 0;i< v.size();i++){
            cout<<v[i].first<<" :"<<mp[v[i].first]<<endl;
        }
    }
    ~Huffman(){
        deleteNode(root);
    }
    void dfs(Node * root){
        if(!root){
            return;
        }
        cout<<root->c<<" "<<root->val<<endl;
        dfs(root->left);
        dfs(root->right);
    }

    void calculate(){
        auto p = root;
        function <void(Node*,string)> dfs = [&](Node* q,string s){
            if(!q){
                return;
            }
            if(q != root){
                dfs(q->left, s + "0");
                dfs(q->right, s + "1");
                if(q->left == nullptr && q->right == nullptr){
                    mp[q->c] = s;
                }
            }else{
                dfs(q->left, "0");
                dfs(q->right, "1");
            }
        };
        dfs(p,"");
        // for(auto&c:mp){
        //     cout<<c.first<<" "<<c.second<<endl;
        // }

    }
    string solve(string s){
        string ans;
        for(auto&c: s){
            ans.append(mp[c]);
        }
        return ans;
    }
    string get(string s){
        string ans;
        bool f = false;
        function <void(Node*,int)> dfs = [&](Node* q, int i){
            if(!q){
                return;
            }
            if(q->left == nullptr && q->right == nullptr){
                ans.push_back(q->c);
                if(i==s.length()){
                    f = true;
                }
                dfs(root, i);
            }else{
                if(s[i] == '0'){
                    dfs(q->left, i+1);
                }else if(s[i] == '1'){
                    dfs(q->right, i+1);
                }
            }
            
        };
        dfs(root, 0);
        // cout<<ans<<endl;
        if(!f){
            return "error!";
        }
        return ans;
    }

};
int main(){
    int q;
    cin>>q;
    for(int j = 0; j < q; ++j){
        int t;
        cin>>t;
        vector<pair<char, int>> v(t);
        for(int i=0;i<t;i++){
            char g;
            cin>>g;
            v[i].first = g;
        }
        for(int i=0;i<t;i++){
            int k;
            cin>>k;
            v[i].second = k;
        } 
        Huffman hf(v);
        string a,b;
        cin>>a;
        cout<<hf.solve(a)<<endl;
        cin>>b;
        cout<<hf.get(b)<<endl;
    }
    

}