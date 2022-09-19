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
        cout<<length<<": ";
        while(p->next){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<p->val;
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
    int search(int index){
        if(index>length||index<1){
            return INT_MAX;
        }
        auto p= find(index);
        return p->val;
    }
    void delete_same_ele(){
        // auto p=head->next->next;
        // // int k=INT_MIN;
        // auto q=head->next;
        // while(p){
        //     if(p->val==q->val){
        //         q->next=p->next;
        //         delete p;
        //         length--;
        //         p=q->next;
        //         continue;
        //     }
        //     p=p->next;
        //     q=q->next;
        // }
        // q->next=nullptr;
        auto p=head->next;
        int i=1;
        while(p){
            auto q=p->next;
            int t=i+1;
            while(q){
                if(q->val==p->val){
                    q=q->next;
                    delete_node(t);
                    // cout<<t<<endl;
                    continue;
                }
                q=q->next;
                t++;
            }
            // print();
            p=p->next;
            i++;
        }
    }
};
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto&e:arr){
            cin>>e;
        }
        List l = List(arr);
        l.delete_same_ele();
        l.print();
    }
    
}