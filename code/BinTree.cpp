#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
struct TreeNode
{
	char data;
	TreeNode * leftChild=NULL;
	TreeNode * rightChild=NULL; 
};
TreeNode * initTreeNode(char data)
{
	TreeNode * head=(TreeNode *) malloc(sizeof(struct TreeNode));
	head->data=data;
	head->leftChild=NULL;
	head->rightChild=NULL;
	return head;
}
/*
初始化一颗二叉排序树  格式如下
          E
	   /   \
	  B     H
	 /\    / \
	A  C  G   K
	    \
         D 
*/
TreeNode * initBinSortTree()
{
	TreeNode *head=initTreeNode('E'); 
	TreeNode *headL=initTreeNode('B');
	TreeNode *headR=initTreeNode('H');
	TreeNode *headRR= initTreeNode('K');
	TreeNode *headRL= initTreeNode('G');
	TreeNode *headLL= initTreeNode('A');
	TreeNode *headLR= initTreeNode('C');
	TreeNode *headLRR= initTreeNode('D');
	head->leftChild=headL;
	head->rightChild=headR;
	headR->rightChild=headRR;
	headR->leftChild=headRL;
	headL->leftChild=headLL;
	headL->rightChild=headLR;
	headLR->rightChild=headLRR; 
	return head;
}
/*
初始化一颗二叉树 二叉树格式如下
        A
      /  \
	B     C
	\    / \
	 D	E   F
	   /
	  G 
	   \
	    H
*/ 
TreeNode * initTree() 
{
	TreeNode *head=initTreeNode('A'); 
	TreeNode *headL=initTreeNode('B');
	TreeNode *headR=initTreeNode('C');
	TreeNode *headLL= initTreeNode('T');
	head->leftChild=headL;
	head->rightChild=headR;
	TreeNode *headLR=initTreeNode('D');
	TreeNode *headRR=initTreeNode('F');
	TreeNode *headRL=initTreeNode('E');
	TreeNode *headRLL=initTreeNode('G');
	TreeNode *headRLLR=initTreeNode('H');
	headL->rightChild=headLR;
	headR->leftChild=headRL;
	headR->rightChild=headRR;
	headRL->leftChild=headRLL;
	headRLL->rightChild=headRLLR;
	headL->leftChild=headLL;
	return head;
}
/*
初始化一颗二叉树 二叉树格式如下
        A
      /  \
	B     C
	\    / \
	 D	B   F
	   /
	  G 
	   \
	    B
*/
TreeNode * initTree2() 
{
	TreeNode *head=initTreeNode('A'); 
	TreeNode *headL=initTreeNode('B');
	TreeNode *headR=initTreeNode('C');
	head->leftChild=headL;
	head->rightChild=headR;
	TreeNode *headLR=initTreeNode('D');
	TreeNode *headRR=initTreeNode('F');
	TreeNode *headRL=initTreeNode('B');
	TreeNode *headRLL=initTreeNode('G');
	TreeNode *headRLLR=initTreeNode('B');
	headL->rightChild=headLR;
	headR->leftChild=headRL;
	headR->rightChild=headRR;
	headRL->leftChild=headRLL;
	headRLL->rightChild=headRLLR;
	return head;
}
void preOrder (TreeNode * head)
{
	if(head!=NULL){
	cout<<head->data<<endl;
	preOrder(head->leftChild);
	preOrder(head->rightChild);
    }
}
void inOrder (TreeNode *head)
{
	if(head!=NULL)
	{
		inOrder(head->leftChild);
		cout<<head->data<<endl;
		inOrder(head->rightChild); 
	}
}
void  postOrder(TreeNode *head)
{
	if(head!=NULL)
	{
	postOrder(head->leftChild);	
	postOrder(head->rightChild);
	cout<<head->data<<endl;
	}
}
//借助栈来完成先序遍历 
void preOrderBasedOnStack(TreeNode *p)
{
	cout<<"------------非递归方法先序遍历开始---------"<<endl;
	stack<struct TreeNode *> s;
	while(!s.empty()||p!=NULL)
	{
		while(p!=NULL)
		{
			cout<<p->data<<endl;
			s.push(p);
			p=p->leftChild; 
		}
		p=s.top();
		s.pop();
		p=p->rightChild;
	}
	cout<<"------------非递归方法先序遍历结束---------"<<endl;
} 
void inOrderBasedOnStack(TreeNode * p)
{
	cout<<"------------非递归方法中序遍历开始---------"<<endl;
	stack<TreeNode *> s;
	while(!s.empty()||p!=NULL) 
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->leftChild;
		}
		p=s.top();
		s.pop();
		cout<<p->data<<endl;
		p=p->rightChild;
	}
	cout<<"------------非递归方法中序遍历结束---------"<<endl;
}
//非递归后续遍历 
void postOrderBasedOnStack(TreeNode *p)
{
	cout<<"------------非递归方法后序遍历开始---------"<<endl;
	stack <TreeNode *> s;
	TreeNode *r;
	while(!s.empty()||p!=NULL)
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->leftChild;
		}
		{
			p=s.top();
			if(p->rightChild!=NULL&&p->rightChild!=r) p=p->rightChild;
			else
			{
				p=s.top();
				cout<<p->data<<endl;
				s.pop();
				r=p;
				p=NULL;
			}
		}
	}
	cout<<"------------非递归方法后序遍历结束---------"<<endl;
}	
void levelOrder(TreeNode * head)
{
	queue <TreeNode *> q;
	q.push(head);
	while(!q.empty())
	{
		head=q.front();
		q.pop();
		cout<<head->data<<endl;
		if(head->leftChild!=NULL)q.push(head->leftChild);
		if(head->rightChild!=NULL)q.push(head->rightChild);
	}
} 
//递归方法获取二叉树的高度 
int  getHeight(TreeNode *p)
{
	if(p==NULL) return 0;
    int lHeight=getHeight(p->leftChild);
    int rHeight=getHeight(p->rightChild);
    return max(lHeight,rHeight)+1;
}
//非递归方法获取二叉树的高度
int  getHeightByNonRecursive(TreeNode *p)
{
	cout<<"-----------非递归方法获取二叉树的高度------------"<<endl;
	if(p==NULL) return 0;
	//100考试时应换成MAXSIZE 
	struct TreeNode * Q[100];
	//用rear和front来模拟队列 
	int rear=-1,front=-1;
	Q[++rear]=p;
	int last=0;
	int height=0;
	while(front<rear)
	{
	//出队操作 
	p=Q[++front];
	if(p->leftChild!=NULL) Q[++rear]=p->leftChild;
	if(p->rightChild!=NULL)	Q[++rear]=p->rightChild;
	if(front==last)
	{
		height++;
		last=rear;
	} 
	}
	return height; 
} 
//利用后序遍历来非递归的求树的高度
int getHeightByPostTraverse(TreeNode *p)
{
	stack<TreeNode*> s;
	TreeNode *r;
	int height=1;
	int max=0;
	while(!s.empty()||p!=NULL)
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->leftChild;
			if(p!=NULL) height++;
			if(height>max) max=height;
		}
		{
			p=s.top();
			if(p->rightChild!=NULL&&p->rightChild!=r) {
			p=p->rightChild;
			height++;
			if(height>max) max=height;
		    }
			else
			{
				p=s.top();
				s.pop();
				r=p;
				p=NULL;
				height--;
			}
		}
	}
	return max; 
} 
//二叉树自下而上，自右向左的层次遍历
void levelTraverseReverseOrder(TreeNode *p)
{
stack <TreeNode *>	s;
queue <TreeNode *>  q;
q.push(p);
while(!q.empty())
{
TreeNode * top=(struct TreeNode *) malloc (sizeof(TreeNode));
top=q.front();
s.push(top);
q.pop();
if(top->leftChild!=NULL) q.push(top->leftChild);
if(top->rightChild!=NULL) q.push(top->rightChild);
}
while(!s.empty())
{
	cout<<s.top()->data<<endl;
	s.pop();
}
} 
//判断一颗二叉树是否为完全二叉树 
bool isCompleteBinTree(TreeNode *p)
{
	queue<TreeNode *> q;
	q.push(p);
	bool isNotDoubleNodeEmerge=false;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(isNotDoubleNodeEmerge && (p->leftChild==NULL || p->rightChild==NULL)) return false; 
		if(p->leftChild==NULL || p->rightChild==NULL)  isNotDoubleNodeEmerge=true;
		if(p->leftChild!=NULL) q.push(p->leftChild);
		if(p->rightChild!=NULL) q.push(p->rightChild);
	}
	return true;
}
//计算二叉树中双分支节点个数
int getDoubleNodeNumber(TreeNode *p)
{
if(p==NULL) return 0;
else if(p->leftChild!=NULL && p->rightChild!=NULL) return getDoubleNodeNumber(p->leftChild)+getDoubleNodeNumber(p->rightChild)+1;	
else if(p->leftChild!=NULL) return getDoubleNodeNumber(p->leftChild);
else if(p->rightChild!=NULL)  return getDoubleNodeNumber(p->rightChild);
} 
//将二叉树的左右子树进行交换 
TreeNode * exchangeTreeNode(TreeNode *p)
{
TreeNode *pDuplicate= (struct TreeNode *) malloc (sizeof(struct TreeNode));
pDuplicate=p; 
if(p==NULL) ;
else
{
queue <TreeNode *> q;
q.push(p);
while(!q.empty())
{
p=q.front();	
q.pop();
if(p->leftChild!=NULL)q.push(p->leftChild);
if(p->rightChild!=NULL) q.push(p->rightChild);
TreeNode * left=(struct TreeNode *) malloc (sizeof(struct TreeNode));
TreeNode * right=(struct TreeNode *) malloc (sizeof(struct TreeNode));
left=p->leftChild;
right=p->rightChild;
if(p->leftChild==NULL) left=NULL;
if(p->rightChild==NULL) right=NULL;
p->rightChild=left;
p->leftChild=right;
}	
}
return pDuplicate;	
} 
//获取先序遍历中第K个节点的值
int alreadyTaverseNumber=0;
void preOrderGetK(TreeNode *p,int k)
{
	if(p!=NULL)
	{
	alreadyTaverseNumber++;
	if(alreadyTaverseNumber==k) cout<<"第"<<k<<"个元素的值为："<<p->data<<endl;
	preOrderGetK(p->leftChild,k);
	preOrderGetK(p->rightChild,k);
	} 
} 
//删除以x为根节点的左右子树
void deleteSonNodeOfX(TreeNode *p,char x)
{
	queue<TreeNode *> q;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p->data==x)
		{
			TreeNode *left=p->leftChild;
			TreeNode *right=p->rightChild;
			p->leftChild=NULL;
			p->rightChild=NULL;
			free(left);
			free(right);
			free(p);
		}
		else
		{
			if(p->leftChild!=NULL) {
			    q.push(p->leftChild);
			    if(p->leftChild->data==x) p->leftChild=NULL; 
			} 
			if(p->rightChild!=NULL) {
				q.push(p->rightChild);
				if(p->rightChild->data==x) p->rightChild=NULL; 
			}
		}
	}
}  
//打印值为x的所有祖先
int getXAncestors(TreeNode *p,char x)
{
	if(p==NULL) return 0;
	if(p->data==x) return 1;
	else
	{
	
			int al=getXAncestors(p->leftChild,x);
			int bl=getXAncestors(p->rightChild,x);
			if(al+bl>=1) cout<<p->data<<endl;
			return al+bl;
	}
} 
//打印x的所有祖先非递归
void getXAncestors2(TreeNode *p,char x)
{
stack<TreeNode *> s;
TreeNode *r,*t;
bool flag=false;
while(!s.empty()||p!=NULL)
{
	while(p!=NULL)
	{
		s.push(p);
		p=p->leftChild;
	}
	{
		p=s.top();
		if(p->rightChild!=NULL&&p->rightChild!=r) p=p->rightChild;
		else
		{
			p=s.top();
			s.pop();
			r=p;
			if(p->data==x)
			{
				flag=true;
				t=p;
			}
			if(flag&&(p->leftChild==t||p->rightChild==t)) 
			{
				printf("%c",p->data);
				t=p;
			}
			p=NULL;
		}
	}
}	
} 
//获取二叉树的最大宽度 （rear->front型） 
int getMaxWidth(TreeNode *p)
{
	TreeNode * nodes[100];
	int Max=0;
	int i=0;
	int rear=0;
	int front=0;
	int size=0;
	nodes[0]=p;
	while(i<=size)
	{
		//用size来记录从根到当前层所有节点和下一层的所有节点的总数 
		p=nodes[i];
		if(p==NULL) break;
		if(p->leftChild!=NULL) 
		{
			nodes[++size]=p->leftChild;
		}
		if(p->rightChild!=NULL) 
		{
			nodes[++size]=p->rightChild;
		}
		//如果遍历到当前层的结束节点时 
		if(i==front)
		{
			Max=max(front-rear+1,Max);
			//队尾为下一层的第一个节点 
			rear=front+1;
			//把队头更新到下一层的最后一个节点 
			front=size; 
		}
		i++;
	}
	return Max;
}
// 叶子节点从左到右顺序连接成单链表，表头指针为head 叶子的右指针存放next
TreeNode * leafToList(TreeNode *p,TreeNode *head)
{
	TreeNode *tail;
    stack <TreeNode *> s;
    bool isHead=true;
    while(!s.empty()||p!=NULL)
    {
    	while(p!=NULL)
    	{
    		if(p->leftChild==NULL && p->rightChild==NULL) 
    		{
    			if(isHead)
    			{
    				head->rightChild=p;
    				tail=head->rightChild;
    				isHead=false;
				}
				else
				{
					tail->rightChild=p;
					tail=tail->rightChild;
				}
			}
    		s.push(p);
    		p=p->leftChild;
		}
		p=s.top()->rightChild;
		s.pop();
	}
	return head;
}
/*
一颗满二叉树 根据前序序列求后续序列
测试代码
char a[15]={'A','B','D','H','I','E','J','K','C','F','L','M','G','N','O'};
char b[15];
toPostFromPre(a,0,14,15,b);
for(int i=0;i<15;i++)
{
cout<<b[i]<<endl;
} 
*/
void toPostFromPre(char preOrder[] ,int start,int end,int length,char postOrder[] )
{
int s=preOrder[start];
for(int i=start;i<end;i++)
{
	preOrder[i]=preOrder[i+1];
}
preOrder[end]=s;
int len=end-start; 
if(len>2)
{
	toPostFromPre(preOrder,start,start+len/2-1,length,postOrder);
	toPostFromPre(preOrder,start+len/2,end-1,length,postOrder);
}
else
{
	for(int i=0;i<length;i++)
	{
		postOrder[i]=preOrder[i];
	}
}
} 
/*
根据先序遍历和中序遍历建立二叉链表 
*/

TreeNode* ReConstructBinaryTree(char pre[],int startPre,int endPre,char in[],int startIn,int endIn)
{
	if(startPre>endPre||startIn>endIn) return NULL;
	TreeNode * root=(struct TreeNode *) malloc (sizeof(struct TreeNode));
	root->data=pre[startPre];
	for(int i=startIn;i<=endIn;i++)
	{
		if(root->data==in[i])
		{
			root->leftChild=ReConstructBinaryTree(pre,startPre+1,startPre-startIn+i,in,startIn,i-1);
			root->rightChild=ReConstructBinaryTree(pre,startPre-startIn+i+1,endPre,in,i+1,endIn);
		    break;
		}
	}
}
/*
编程求以孩子兄弟表示法存储的森林的叶子节点个数（左指针为NULL的节点的个数） 
*/ 
int coutLeafInForest(TreeNode *p)
{
if(p==NULL) return 0;
else if(p->leftChild==NULL) return 	coutLeafInForest(p->rightChild)+1;
else return coutLeafInForest(p->leftChild)+coutLeafInForest(p->rightChild);
} 
/*
判断给定的二叉树是否为二叉排序树 
调用方式如下cout<<isBinSortTree(initBinSortTree()) ; 
*/ 
bool isBinSortTree(TreeNode *p)
{
	//利用非递归的中序遍历来实现
	stack<TreeNode *> s;
	char pre,current;
	//因为'@'的ASCII码是'A'的ASCII码-1 所以用'@'做初始值 
	pre=current='@';
	while(!s.empty()||p!=NULL)
	{
		while(p!=NULL)
		{
		s.push(p);
		p=p->leftChild;	
		} 
		p=s.top();
		pre=current;
		current=p->data;
		cout<<"pre="<<pre<<"   current="<<current<<endl;
		if(pre>=current) return false;
		s.pop();
		p=p->rightChild;
	} 
	return true;
}
/*
求指定节点在二叉排序树中的层次 
*/
int getNodeLevelInBinTree(TreeNode *p,char x)
{
	if(p==NULL) return 0;
	if(p->data==x) return 1;
	else if(p->data>x) return getNodeLevelInBinTree(p->leftChild,x)+1;
	else  return getNodeLevelInBinTree(p->rightChild,x)+1;
}
/*
判断二叉树是否是平衡二叉树  用全局变量isBBT记录结果 
*/
bool isBBT=true;
int isSelfBalanceBinTree(TreeNode *p)
{
	 if(p==NULL) return 0;
     int pLeft= isSelfBalanceBinTree(p->leftChild)+1;
     int pRight=isSelfBalanceBinTree(p->rightChild)+1;
     if(abs(pLeft-pRight)>1) isBBT=false;
     cout<<p->data<<"左右子树差值为"<<abs(pLeft-pRight)<<endl;;
     return max(pLeft,pRight);
}
/*求先序第k个结点的值*/
int i=0; 
char preOrderKValue(TreeNode *p,int k)
{
	if(p==NULL) return '#';
	else
	{
		i++; 
		if(k==i) return (p->data);
		else
		{
			char x=preOrderKValue(p->leftChild,k);
			if(x!='#') return x;
			return preOrderKValue(p->rightChild,k);
		}
	}
}
/*找p和q的最近的公共结点 (递归解法)*/
bool isFindCommonNode=false;
int ANCESTOR(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *r)
{
	if(root==NULL) return 0;
	else
	{
		if(root->data==p->data)
		{
			return 1;
		}
		else if(root->data==q->data)
		{
			return 3;
		}
		int a1=ANCESTOR(root->leftChild,p,q,r);
		int a2=ANCESTOR(root->rightChild,p,q,r);
		if((a1+a2)==4&&!isFindCommonNode)
		{
		r=root;
		cout<<root->data;
		isFindCommonNode=true;	
		}
	}
}
/*找p和q的最近的公共结点 (非递归解法)*/
void ANCESTOR2(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *r)
{
	stack<TreeNode *> s;
	TreeNode *l;
	while(!s.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			root=root->leftChild; 
		}
		{
			root=s.top();
			while(root->rightChild!=NULL&&root->rightChild!=l)
			{
				
			}
		}
	}
}
int main()
{
	
} 
