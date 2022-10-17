#include <iostream>
#include <string>
using namespace std;
class BiTreeNode {
public:
	char  data;					//数据域
	BiTreeNode  *leftChild,  *rightChild;	//左右子树指针
	BiTreeNode():leftChild(NULL), rightChild(NULL){}
	~BiTreeNode() {}
};

class BiTree {
private:
	BiTreeNode *root;	//根结点指针
	string sTree;		//建树字符串
	int pos;			//标识建树字符串的当前字符位置
	BiTreeNode * CreateTree();//建树私有函数
	void PreOrder(BiTreeNode  *t);	//先序遍历实现
	void InOrder(BiTreeNode  *t);	//中序遍历实现
	void PostOrder(BiTreeNode  *t);	//后序遍历实现
public:
	BiTree():root(NULL) {};	
	void Create(string vArray);	//建树公有接口，参数是特定的先序遍历字符串
	void PreOrder();			//先序遍历公有接口
	void InOrder();				//中序遍历公有接口
	void PostOrder();			//后序遍历公有接口
};
//二叉树公有接口的实现
void BiTree::Create(string vArray) 
{	pos=0;
	sTree.assign(vArray);	//把参数保存到内部字符串
	root = CreateTree();	//建树成功后root指向根结点
}
void BiTree::PreOrder()
{	PreOrder(root);	}
void BiTree::InOrder()
{	InOrder(root);	}
void BiTree::PostOrder()
{	PostOrder(root);	}

//请完成上述类内部的私有函数实现
/********** Write your code here! **********/
// BiTreeNode* ct(string &str,int &i){
//     BiTreeNode* node= new BiTreeNode();
//     if(i<str.size()){
//         node->data  = str[i];
//         node->leftChild= ct(str,++i);
//         node->rightChild= ct(str,++i);
//     }
//     return node;
    
// }
BiTreeNode* BiTree::CreateTree(){
    BiTreeNode* node = nullptr;
    if(pos<sTree.size()){
        if(sTree[pos]=='0'){
            return nullptr;
        }
        node= new BiTreeNode();
        node->data  = sTree[pos];
        pos++;
        node->leftChild= CreateTree();
        pos++;
        node->rightChild= CreateTree();
    }
    return node;
}
void BiTree::PreOrder(BiTreeNode*root){
    if(!root){
        return;
    }
    cout<<root->data;
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}
void BiTree::InOrder(BiTreeNode*root){
    if(!root){
        return;
    }
    InOrder(root->leftChild);
    cout<<root->data;
    InOrder(root->rightChild);
}
void BiTree::PostOrder(BiTreeNode*root){
    if(!root){
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    cout<<root->data;
}



/*******************************************/
//主函数
int main()
{	int t;
	string vArray;
	cin>>t;
	while(t--)
	{	cin>>vArray;
		BiTree myTree;
		myTree.Create(vArray);
		myTree.PreOrder();		cout<<endl;
		myTree.InOrder();		cout<<endl;
		myTree.PostOrder();		cout<<endl;
	}
	return 0;
}
