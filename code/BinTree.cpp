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
��ʼ��һ�Ŷ����� ��������ʽ����
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
	//headL->leftChild=headLL;
	return head;
}
/*
��ʼ��һ�Ŷ����� ��������ʽ����
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
//����ջ������������ 
void preOrderBasedOnStack(TreeNode *p)
{
	cout<<"------------�ǵݹ鷽�����������ʼ---------"<<endl;
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
	cout<<"------------�ǵݹ鷽�������������---------"<<endl;
} 
void inOrderBasedOnStack(TreeNode * p)
{
	cout<<"------------�ǵݹ鷽�����������ʼ---------"<<endl;
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
	cout<<"------------�ǵݹ鷽�������������---------"<<endl;
}
//�ǵݹ�������� 
void postOrderBasedOnStack(TreeNode *p)
{
	cout<<"------------�ǵݹ鷽�����������ʼ---------"<<endl;
	stack <TreeNode *> s;
	TreeNode *r;
	while(!s.empty()||p!=NULL)
	{
		if(p!=NULL)
		{
			s.push(p);
			p=p->leftChild;
		}
		else
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
	cout<<"------------�ǵݹ鷽�������������---------"<<endl;
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
//�ݹ鷽����ȡ�������ĸ߶� 
int  getHeight(TreeNode *p)
{
	if(p==NULL) return 0;
    int lHeight=getHeight(p->leftChild);
    int rHeight=getHeight(p->rightChild);
    return max(lHeight,rHeight)+1;
}
//�ǵݹ鷽����ȡ�������ĸ߶�
int  getHeightByNonRecursive(TreeNode *p)
{
	cout<<"-----------�ǵݹ鷽����ȡ�������ĸ߶�------------"<<endl;
	if(p==NULL) return 0;
	struct TreeNode* a[100];
	int front,i,height,size;
	front=i=height=size=0;
	a[front]=p;
	while(i<=front)
	{
		if(a[i]->leftChild!=NULL)  a[++size]=a[i]->leftChild;
		if(a[i]->rightChild!=NULL) a[++size]=a[i]->rightChild; 
		if(i==front)
		{
		front=size;
		height++;	
		}
		i++;
	}
	cout<<"-----------�������ĸ߶�Ϊ: "<<height<<"--------------"<<endl;
	return height;
} 
//���������¶��ϣ���������Ĳ�α���
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
//�ж�һ�Ŷ������Ƿ�Ϊ��ȫ������ 
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
//�����������˫��֧�ڵ����
int getDoubleNodeNumber(TreeNode *p)
{
if(p==NULL) return 0;
else if(p->leftChild!=NULL && p->rightChild!=NULL) return getDoubleNodeNumber(p->leftChild)+getDoubleNodeNumber(p->rightChild)+1;	
else if(p->leftChild!=NULL) return getDoubleNodeNumber(p->leftChild);
else if(p->rightChild!=NULL)  return getDoubleNodeNumber(p->rightChild);
} 
//���������������������н��� 
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
//��ȡ��������е�K���ڵ��ֵ
int alreadyTaverseNumber=0;
void preOrderGetK(TreeNode *p,int k)
{
	if(p!=NULL)
	{
	alreadyTaverseNumber++;
	if(alreadyTaverseNumber==k) cout<<"��"<<k<<"��Ԫ�ص�ֵΪ��"<<p->data<<endl;
	preOrderGetK(p->leftChild,k);
	preOrderGetK(p->rightChild,k);
	} 
} 
//ɾ����xΪ���ڵ����������
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
//��ӡֵΪx����������
int getXAncestors(TreeNode *p,char x)
{
	if(p==NULL) return 0;
	else
	{
		if(p->data==x) return 1;
		else
		{
			int al=getXAncestors(p->leftChild,x);
			int bl=getXAncestors(p->rightChild,x);
			if(al+bl) cout<<p->data<<endl;
			return al+bl;
		}
	}
} 
//��ȡ������������� ��rear->front�ͣ� 
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
		//��size����¼�Ӹ�����ǰ�����нڵ����һ������нڵ������ 
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
		//�����������ǰ��Ľ����ڵ�ʱ 
		if(i==front)
		{
			Max=max(front-rear+1,Max);
			//��βΪ��һ��ĵ�һ���ڵ� 
			rear=front+1;
			//�Ѷ�ͷ���µ���һ������һ���ڵ� 
			front=size; 
		}
		i++;
	}
	return Max;
}
// Ҷ�ӽڵ������˳�����ӳɵ�������ͷָ��Ϊhead Ҷ�ӵ���ָ����next
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
һ���������� ����ǰ���������������
���Դ���
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
�������������������������������� 
*/

TreeNode* ReConstructBinaryTree(char pre[],int startpre,int endpre,char in[],int startin,int endin)
{
        if(startpre>endpre||startin>endin) return NULL;
        TreeNode* root=(struct TreeNode *) malloc (sizeof(struct TreeNode));
		root->data=pre[startpre];
        for(int i=startin;i<=endin;i++)
        {
            if(in[i]==root->data){
            root->leftChild=ReConstructBinaryTree(pre,startpre+1,startpre-startin+i,in,startin,i-1);
            root->rightChild=ReConstructBinaryTree(pre,startpre-startin+i+1,endpre,in,i+1,endin);
            break;
            }
        }
        return root;
}

int main()
{
	char preOrder[3]={'A','B','C'};
	char inOrder[3]={'B','C','A'};
    levelOrder(ReConstructBinaryTree(preOrder,0,2,inOrder,0,2));
} 
