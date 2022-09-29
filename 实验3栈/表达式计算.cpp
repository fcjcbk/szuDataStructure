#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <iomanip>
using namespace std;

#define OPSETSIZE 7
unsigned char Prior[7][7] = { //运算符间的优先关系
  	  '>','>','<','<','<','>','>',
	  '>','>','<','<','<','>','>',
	  '>','>','>','>','<','>','>',
	  '>','>','>','>','<','>','>',	
	  '<','<','<','<','<','=',' ',
	  '>','>','>','>',' ','>','>',
	  '<','<','<','<','<',' ','='
};		
char OPSET[OPSETSIZE]={'+' , '-' , '*' , '/' ,'(' , ')' , '#'}; //运算符集合

double Operate(double a, unsigned char theta, double b);	//计算类似a+b的表达式结果
bool In(char Test, char* TestOp); //判断字符Test是否是运算符，是则返回true
char precede(char Aop, char Bop); //返回两个运算符优先级的比较结果 

//以下完成算术表达式求值函数EvaluateExpression(string MyExp)的填空
double EvaluateExpression(string MyExp) //算术表达式求值算法
//设OPTR和OPND分别为运算符栈和运算数栈
//参数MyExp是表达式字符串
{	stack<char> OPTR;		//运算符栈，字符元素
	stack<double> OPND;	//运算数栈，实数元素
	char TempData[20];
	double Data,a,b, r;
	char theta, c,x,Dr[2];
	OPTR.push('#');
	strcpy(TempData,"\0");
	int i=0;		//表达式字符串的当前字符位置
	c = MyExp[i];	//表达式字符串的当前字符

	//逐个读入表达式字符串的字符到变量c，并识别为数值或运算符，做相应处理
/********** Write your code here! **********/
    int weight(char c);
    void eval(stack<double>&num,char c);
    OPTR.pop();
    int start=0;
    int count=0;
    for(int i=0;i<MyExp.length()-1;i++){
        if(isdigit(MyExp[i])||MyExp[i]=='.'){
            if(count==0){
                start=i;
                count=1;
            }else{
                count++;

            }
        }else{
            if(count!=0){
                OPND.push(stod(MyExp.substr(start,count)));
                count=0;
            }
            if(MyExp[i]=='('){
                OPTR.push(MyExp[i]);
            }else if(MyExp[i]!=')'){
                while(!OPTR.empty()&&weight(MyExp[i])<=weight(OPTR.top())&&OPTR.top()!='('){
                    auto c=OPTR.top();
                    eval(OPND,c);
                    OPTR.pop();
                }
                OPTR.push(MyExp[i]);
            }else if(MyExp[i]==')'){
                while(OPTR.top()!='('){
                    auto c=OPTR.top();
                    eval(OPND,c);
                    OPTR.pop();
                }
                OPTR.pop();
            }

        }
        
    }
    if(count!=0){
        OPND.push(stod(MyExp.substr(start,count)));
        count=0;
    }
    while(OPND.size()>1){
        auto c=OPTR.top();
        eval(OPND,c);
        OPTR.pop();
    }
    return OPND.top();
    



/*******************************************/
} //这是函数EvaluateExpression的右花括号
//函数EvaluateExpression的代码到此结束


//以下填空完成其他函数的定义，包括函数Operate\函数In\函数precede
//可以参考教材光盘中文件夹CHAP03的源代码ALGO0304.cpp，几乎照抄
/********** Write your code here! **********/

void eval(stack<double>&num,char c){
    auto b=num.top();
    num.pop();
    auto a=num.top();
    num.pop();
    if(c=='+'){
        num.push(a+b);
    }else if(c=='-'){
        num.push(a-b);
    }else if(c=='*'){
        num.push(a*b);
    }else{
        num.push(a/b);
    }
    // cout<<num.top()<<endl;
}
int weight(char c){
    if(c=='*'||c=='/'){
        return 2;
    }
    return 1;
}


/*******************************************/
//主函数
int main()
{	string Exp;
	int t;
	double result;
	cin>>t;
	while (t--)
	{	cin>>Exp;
		result=EvaluateExpression(Exp);
		cout<<fixed<<setprecision(2)<<result<<endl;
	}	

	return 0;
}
