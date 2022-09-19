#include<bits/stdc++.h>
using namespace std;
class List;
List* merge(List*llhs,List*rhs);
struct node;
struct node{
    friend List* merge(List&llhs,List&rhs);
    int val;
    node*next;
    node():val(0),next(nullptr){}
    node(int val):val(val),next(nullptr){}
};
class List{
    friend List* merge(List*llhs,List*rhs);
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
        // print();
    }
    List():head(new node){}
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
};
List* merge(List* lhs,List* rhs){
    List*ans=new List();
    auto p=lhs->head->next;
    auto q= rhs->head->next;
    auto h=ans->head;
    while(p||q){
        if(p&&q){
            if(p->val<q->val){
                h->next=new node(p->val);
                h=h->next;
                p=p->next;
            }else{
                h->next=new node(q->val);
                h=h->next;
                q=q->next;
            }
        }else if(p){
            h->next=new node(p->val);
            h=h->next;
            p=p->next;
        }else{
            h->next=new node(q->val);
            h=h->next;
            q=q->next;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto&e:arr){
        cin>>e;
    }
    List l = List(arr);
    cin>>n;
    vector<int> arr1(n);
    for(auto&e:arr1){
        cin>>e;
    }
    List l2= List(arr1);
    List*ans=merge(&l,&l2);
    ans->print();
    delete ans;
}