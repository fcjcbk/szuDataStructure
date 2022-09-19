#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*next;
    node():val(0),next(nullptr){}
    node(int val):val(val),next(nullptr){}
};
class List{
    node*head;
    int length=0;
public:
    List(vector<int> &arr):head(new node){
        auto p=head;
        for(auto&e:arr){
            p->next=new node(e);
            p=p->next;
            length++;
        }
        print();
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
        if(index>length||index<0){
            return nullptr;
        }
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
        while(p){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    bool insert(int index,int val){
        //默认index从1开始
        if(index>length+1||index<1){
            return false;
        }
        auto p= find(index-1);
        node*n= new node(val);
        n->next=p->next;
        p->next=n;
        length++;
        return true;
    }
    bool delete_node(int index){
        if(index>length||index<1){
            return false;
        }
        auto p =find(index-1);
        node*q=p->next;
        p->next=p->next->next;
        delete q;
        length--;
        return true;
    }
    int serarch(int index){
        if(index>length||index<1){
            return INT_MAX;
        }
        auto p= find(index);
        return p->val;
    }
    bool swap(int a,int b){
        if(a>b){
            swap(a,b);
        }
        if(b>length||a<1){
            cout<<"error"<<endl;
            return false;
        }
        auto p=find(a-1);
        auto q=find(b-1);
        auto x=p->next;
        auto y=q->next;
        auto z=y->next;
        y->next=x->next;
        x->next=z;
        p->next=y;
        q->next=x;
        return true;
    }
};
int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto&e:arr){
            cin>>e;
        }
        List l = List(arr);
    for(int i=0;i<2;i++){
        
        int a,b;
        cin>>a>>b;
        if(l.swap(a,b)){
            l.print();
        }
    }
}