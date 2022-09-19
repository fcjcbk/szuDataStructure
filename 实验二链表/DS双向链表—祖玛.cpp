#include<bits/stdc++.h>
using namespace std;
struct node{
    char val='#';
    node*next=nullptr;
    node*pre=nullptr;
    node(){}
    node(int val,node*t):val(val),next(nullptr),pre(t){}
    ~node(){
        next=nullptr;
        pre=nullptr;
    }
};
class List{
    node*head;
public:
    List(string &arr):head(new node){
        auto p=head;
        for(auto&e:arr){
            p->next=new node(e,p);
            p=p->next;
        }
        // print();
    
    }
    ~List(){
        auto p=head;
        while(p){
            node*q=p->next;
            delete p;
            p=q;
        }
    }
    //从1开始
    node*find(int index){
        // if(index>length||index<0){
        //     return nullptr;
        // }
        int i=0;
        auto p=head;
        while(i<index&&p!=nullptr){
            p=p->next;
            i++;
        }
        return p;
    }
    void print(){
        auto p= head->next;
        if(p==nullptr){
            cout<<"-";
        }
        while(p){
            cout<<p->val;
            p=p->next;
        }
        
        cout<<endl;
    }
    bool insert(int index,int val){
        //默认index从1开始
        // if(index>length+1||index<1){
        //     return false;
        // }
        auto p= find(index-1);
        node*n= new node(val,p);
        n->next=p->next;
        if(n->next){
            n->next->pre=n;
        }
        p->next=n;
        // length++;
        // print();
        bool f=erase();
        while(f){
            f=erase();
        }
        return true;

    }
    bool erase(){
        auto p=head->next;
        
        bool f=false;
        while(p){
            int count=1;
            char last_val=p->val;
            auto q=p->next;
            // int t=i+1;
            while(q&&q->val==last_val){
                count++;
                q=q->next;
            }
            if(count>=3){
                f=true;
                auto h=p->pre;
                delete_some(p->pre,q);
                // print();
                p=h;
            }
            // print();
            p=p->next;
        }
        return f;
    }
    void delete_some(node*start,node*end){
        node* p=start->next;
        start->next=end;
        if(end){
            end->pre=start;
        }
        while(p!=nullptr&&p!=end){
            node* q=p->next;
            delete p;
            p=q;
        }
        
        
    }

};
int main(){
    string s;
    cin>>s;
    List l = List(s);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int index;
        char val;
        cin>>index>>val;
        l.insert(index+1,val);
        l.print();
    }
}