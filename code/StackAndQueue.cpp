#include<stack>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
/*用两个栈来模拟队列的算法*/ 
stack<int> s1;
stack<int> s2;
//判断队列是否为空 
bool queueEmpty()
{
if(s2.empty()) return true;
return false;	
} 
//进队 
void enQueue(int data)
{
	//先把s2中的元素存入s1
	while(!s2.empty()) 
	{
		s1.push(s2.top());
		s2.pop();
	}
	s1.push(data);
	while(!s1.empty())
	{
		s2.push(s1.top());
		s1.pop(); 
	}
}
bool deQueue(int data)
{
    if(queueEmpty())  return false;
    else
    {
    	data=s2.top();
    	s2.pop();
    	cout<<data<<" ";
    	return true;
	}
}
/*栈的应用*/
//1 数制转换
void conversion(int data,int n)
{
cout<<"十进制数: "<<data<<" 转化为"<<n<<"进制数 :";
stack<int > s;
while(data!=0)
{
int m=data%n;
data=data/n;
s.push(m);	
}
while(!s.empty())
{
cout<<s.top();	
s.pop();
}	
cout<<endl;
} 
//2括号匹配检验
bool bracketsMatching(char datas[],int n)
{
	stack<char> s;
	for(int i=0;i<n;i++)
	{
		if(datas[i]=='['||datas[i]=='{'||datas[i]=='(')
		{
			s.push(datas[i]);
		}
		else
		{
			switch(datas[i])
			{
				case ']':
					if(s.top()=='[') s.pop();
					else return false;
					break;
				case '}':
				    if(s.top()=='{') s.pop();
					else return false;
					break;
				case ')':
					if(s.top()=='(') s.pop();
					else return false;
					break;
			}
		}
	}
	return true;
} 
//3 行编辑程序(#代表前一个字符无效，@代表当前字符均是无效的)
void lineEdit(char data[],int n)
{
stack<char> s;
for(int i=0;i<n;i++)
{
	if(data[i]=='#') s.pop();
	else if(data[i]=='@') 
	{
	   while(!s.empty())
	   {
	    s.pop();	
	   }	
	}
	else
	{
	s.push(data[i]);	
	} 
}	
} 
//4 后缀表达式求值
int postfixExpression(char datas[],int n)
{
	stack<int >s;
	for(int i=0;i<n;i++)
	{
		int a,b;
		switch(datas[i])
		{
		case '+' :
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		s.push(a+b);
		break;
		case '-' :
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		s.push(b-a);
		break;
		case '*':
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		s.push(a*b);
		break;
		case '/':
		a=s.top();
		s.pop();
		b=s.top();
		s.pop();
		s.push(b/a);
		break;
		default:
		s.push(datas[i]-'0');	
		} 
	}
	return s.top(); 
} 
/*
栈的非递归运算求 
         1  n=0
pn(x)=  2*x n=1
        2*x*pn-1(x)-2(n-1)pn-2(x)
*/ 
int pnx(int n,int x)
{
	if(n==0) return 1;
	else if(n==1) return 2*x; 
	else
	{
		stack< int >s;
		s.push(1);
		s.push(2*x);
		int i=2;
		while(i<=n)
		{
			int i_1=s.top();
			s.pop();
			int i_2=s.top();
			s.pop();
			int pni=2*x*i_1-2*(i-1)*i_2;
			if(i==n) return pni;
			else
			{
				s.push(i_1);
				s.push(pni);
			}
			i++;
		} 
	}
	return -1;
}
/*模拟渡口管理
void manger()
{
//q为目前船上的队列 q1为客车队列 q2为货车队列	
Queue q;
Queue q1;
Queue q2;
int i=0;
int j=0;
while(j<10)
{
//优先上客车 
if(!q1.empty()&&i<4)
{
DeQueue(q1,x);
EnQueue(q,x);
i++;	
j++;
}
else if(i==4&&!q2.empty())
{
i=0;
Dequeue(q2,x);
EnQueue(q,x);
j++;	
}
else
{
while(j<10&&i<4&&!q2.empty())
{
Dequeue(q2,x);
EnQueue(q,x);
i++;
j++;	
}
i=0;	
}
if(q1.empty()&&q2.empty()) j=11;	
}	
} 
*/
int main()
{
	cout<<pnx(2,1)<<endl;
}
