#include<bits/stdc++.h>
using namespace std;
class List;
List* merge(List*llhs,List*rhs);
struct node;
struct node{
    friend List* merge(List&llhs,List&rhs);
    int val=0;
    int ex=0;
    node*next=nullptr;
    node(){}
    node(int val,int ex):ex(ex),val(val),next(nullptr){}
};
class List{
    friend List* merge(List*llhs,List*rhs);
    node*head;
    int length=0;
public:
    List(vector<pair<int,int>> &arr):head(new node){
        auto p=head;
        for(auto&e:arr){
            p->next=new node(e.first,e.second);
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
    void print(){
        auto p= head;
        bool f= true;
        while(p->next){
            if(p->val!=0){
                if(f){
                    f=false;
                }else{
                    cout<<"+ ";
                }
                if(p->val>0){
                    cout<<p->val;
                }else{
                    cout<<"("<<p->val<<")";
                }
                if(p->ex>0){
                    cout<<"x^"<<p->ex<<" ";
                }else if(p->ex<0){
                    cout<<"x^"<<"("<<p->ex<<") ";
                }else{
                    cout<<" ";
                }
            }
            p=p->next;
        }
        if(p->val!=0){
            if(f){
                f=false;
                
            }else{
                cout<<"+ ";
            }
            if(p->val>0){
                cout<<p->val;
            }else{
                cout<<"("<<p->val<<")";
            }
            if(p->ex>0){
                cout<<"x^"<<p->ex;
            }else if(p->ex<0){
                cout<<"x^"<<"("<<p->ex<<")";
            }
        }
        
        cout<<endl;
    }
    
};
List* merge(List* lhs,List* rhs){
    List*ans=new List();
    auto p=lhs->head->next;
    auto q= rhs->head->next;
    auto h=ans->head;
    while(p||q){
        if(p&&q){
            if(p->ex==q->ex){
                h->next=new node(p->val+q->val,p->ex);
                h=h->next;
                p=p->next;
                q=q->next;
            }else if(p->ex<q->ex){
                h->next=new node(p->val,p->ex);
                h=h->next;
                p=p->next;
            }else{
                h->next=new node(q->val,q->ex);
                h=h->next;
                q=q->next;
            }
        }else if(p){
            h->next=new node(p->val,p->ex);
            h=h->next;
            p=p->next;
        }else{
            h->next=new node(q->val,q->ex);
            h=h->next;
            q=q->next;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(auto&e:arr){
            cin>>e.first>>e.second;
        }
        List l = List(arr);
        l.print();

        cin>>n;
        vector<pair<int,int>> arr1(n);
        for(auto&e:arr1){
            cin>>e.first>>e.second;
        }
        List l2= List(arr1);
        l2.print();
        List*ans=merge(&l,&l2);
        
        ans->print();
        delete ans;
    }
    
}