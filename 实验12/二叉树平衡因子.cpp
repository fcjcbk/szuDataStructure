#include<iostream> 
using namespace std;
struct Node{
    char val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(char val) : val(val){}
};
class Tree{
    Node* root = nullptr;
public:
    Tree(char a[], int n){
        root = create(a, n, 1);
        back(root);
    }
    ~Tree(){
        delete_node(root);
    }
    void delete_node(Node* p){
        if(!p){
            return;
        }
        delete_node(p -> left);
        delete_node(p -> right);
        delete p;
    }
    Node* create(char a[], int n, int i){
        if(i >= n){
            return nullptr;
        }
        if(a[i] == '0'){
            return nullptr;
        }
        Node* p = new Node(a[i]);
        p -> left = create(a, n, 2 * i);
        p -> right = create(a, n, 2 * i + 1);
        return p;
    }
    int get_height(Node* p){
        if(!p){
            return 0;
        }
        return max(get_height(p -> left), get_height(p -> right)) + 1;
    }
    void back(Node* p){
        if(!p){
            return;
        }
        back(p -> left);
        back(p -> right);
        cout<<p -> val<<" "<<get_height(p ->left) - get_height(p -> right)<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        n++;
        char *a = new char[n];
        a[0] = '0';
        for(int j = 1; j < n; j++){
            cin>>a[j];
        }
        Tree tr(a, n);
        delete []a;
    }
}