#include<bits/stdc++.h>
using namespace std;

class Trie{
    bool isEnd;
    vector<Trie*> child;
public:
    Trie():child(vector<Trie*>(26, nullptr)), isEnd(false){}
    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(child[i] != nullptr){
                delete child[i];
            }
        }
    }
    void add(string word){
        int n = word.size();
        int i = 0;
        auto p = this;
        
        while(i < n){
            if(p -> child[word[i] - 'a'] == nullptr){
                p -> child[word[i] - 'a'] = new Trie();
            }
            p = p -> child[word[i] - 'a'];
            i++;
        }
        p -> isEnd = true;
    }
    void ceng(){
        queue<Trie*> qu;
        qu.push(this);
        while(!qu.empty()){
            Trie* p = qu.front();
            qu.pop();
            for(int i = 0; i < 26; i++){
                if(p -> child[i] != nullptr){
                    cout<<static_cast<char>(i + 'a');
                    qu.push(p -> child[i]);
                }
            }

        }
        cout<<endl;
    }
    int find(string s){
        int n = s.size();
        int i = 0;
        auto p = this;
        int ans = 0;
        bool f = false;
        while(i < n){
            if(p -> child[s[i] - 'a'] != nullptr){
                p = p -> child[s[i] - 'a'];
                i++;
            }else{
                f = true;
                break;
            }
        }
        if(f){
            return ans;
        }else{

            function<void(Trie*)> dfs = [&](Trie* p){
                if(p == nullptr){
                    return;
                }
                if(p -> isEnd == true){
                    ans++;
                }
                for(auto q : p -> child){
                    dfs(q);
                }
            };
            dfs(p);
        }
        return ans;
    }

};
int main(){
    
    
    string s;
    
    while(getline(cin, s)){
        Trie tr;
        vector<string> str;
        int j = 0, q = 0;
        while(q < s.size()){
            while(s[q] != ' ' && q < s.size()){
                q++;
            }

            str.push_back(s.substr(j, q - j));
            q++;
            j = q;   
        }
        for(auto &c : str){
            tr.add(c);
        }
        tr.ceng();
        int t;
        cin>>t;
        for(int i = 0; i < t; i++){
            string k;
            cin>>k;
            cout<<tr.find(k)<<endl;
        }
    }
    
}