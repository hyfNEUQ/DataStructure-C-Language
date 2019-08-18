#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std; 
/*对单链表的一些结构体的定义以及一些操作*/
struct Node
{
	int data;
	Node * next;
};
Node * initNode (int data)
{
	Node * node=(struct Node *) malloc (sizeof(struct Node));
	node->data=data;
	node->next=NULL;
	return node;
}
/*头插法建立单链表,返回一个带头结点的单链表表头*/
Node * headInsert(int data[],int n)
{
	Node * head= initNode(-1);
	for(int i=0;i<n;i++)
	{
		Node * node=initNode(data[i]);
		node->next=head->next;
		head->next=node;
	}
	return head;
}
/*尾插法建立单链表,返回一个带头节点的单链表表头*/
Node * tailInsert(int data[],int n)
{
	Node * head =initNode(-1);
	Node * tail=head;
	for(int i=0;i<n;i++)
	{
		Node * node=initNode(data[i]);
		tail->next=node;
		tail=tail->next;
	}
	return head;
}
/*打印带头节点的链表*/
void printLinkedListHaveHead(Node * node)
{
	while(node->next!=NULL)
	{
		cout<<node->next->data<<" ";
		node=node->next;
	}
	cout<<endl;
}
/*打印不带头结点的链表*/
void printLinkedListHaveNotHead(Node * node)
{
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node=node->next;
	}
	cout<<endl;
}
/*按序号查找 */
Node * getElemById(Node * head,int i)
{
int j=0;
while(head!=NULL&&j<i)
{
j++;
head=head->next;	
}
return head;	
}  
/*
1 设计一个递归算法删除不带头结点的单链表L中所有值为X的结点 (head 用来返回删除之后的头结点)
*/
bool isFindHead=false;
Node * deleteXNode(Node * node,Node * preNode,int x,Node * head)
{
	if(node==NULL) return head;
	if(node!=NULL&&node->data!=x&&(!isFindHead)) {head=node;isFindHead=true;}
	else if(node->data==x) 
	{
		if(preNode==NULL)
		{
			Node * n=node;
			node=node->next;
			free(n);
		}
		else
		{
			preNode->next=node->next;
			Node * n=node;
			node=node->next;
			free(n);
		}
	}
	else
	{
		preNode=node;
		node=node->next;
	}
	return deleteXNode(node,preNode,x,head);
}
/*
2 在带头节点的单链表L中，删除所有值为x的结点，并释放空间 
*/
Node * deletXNodeWithHead(Node * head,int x)
{
	if(head==NULL) return head;
	Node * pre=head;
	Node * node=head->next;
	while(node!=NULL)
	{
		if(node->data==x)
		{
			pre->next=node->next;
			Node * n=node;
			node=node->next;
			free(n);
		}
		else
		{
			pre=node;
			node=node->next;
		}
	}
	return head;
}
/*3 设L为带头节点的单链表 从尾到头反向输出每个结点的值*/
void inverselyPrintLinkedList(Node * head)
{
	if(head->next!=NULL)
	{
	inverselyPrintLinkedList(head->next);
	}
	cout<<head->data<<" ";
}
/*
4 删除带头结点的单链表L中最小值的高效算法 
*/
Node* quickDeleteLMinValue(Node * head)
{
	if(head==NULL) return NULL;
	if(head->next==NULL) return NULL;
	Node * minPre=head;
	int minValue=head->next->data;
	Node * node=head;
	while(node->next!=NULL)
	{
		if(node->next->data<minValue)
		{
			minValue=node->next->data;
			minPre=node;
		}
		node=node->next;
	}
	node=minPre->next;
	minPre->next=minPre->next->next;
	free(node);
	return head;
}
/*
5 就地逆置带头节点的单链表空间复杂度o(1) 
!!!注意  p->next=NULL 这一句 
*/
Node* inverseLinkList(Node * head)
{
	Node * p,*r;
	Node * node=head->next;
	if(node==NULL) return head;
	p=node;
	node=node->next;
	p->next=NULL;
	while(node!=NULL)
	{
		r=node->next;
		node->next=p;
		p=node;
		node=r;
	} 
	head->next=p;
	return head;	
}
/*
6 设一个带头结点的单链表设计一个算法使其元素递增有序 (采用插入排序)
!!!关键是 插入排序时 需要把有序的那一部分 与 无序的那一部分断开 
*/
Node * orderizationLinkList(Node * head)
{
	Node * pre, * rear;
	if(head==NULL) return head;
	pre=head->next;
	if(pre==NULL) return head;
	rear=pre->next;
	pre->next=NULL;
	while(rear!=NULL)
	{
		Node * t=rear->next;
		Node * h=head;
		while((h->next!=NULL)&&(rear->data>h->next->data)&&(h->next!=rear))
		{
			h=h->next;
		}
		rear->next=h->next;
		h->next=rear;
		rear=t;
	}
	return head;
}
/*7 带头节点的单链表无序 删除介于 给定的两个值之间的元素*/
Node*  deleteValueBetweenLowAndHigh(Node * head,int low,int high)
{
	Node * pre=head;
	if(head==NULL||low>high) return head;
	Node * node=head->next;
	while(node!=NULL)
	{
		if(node->data>=low&&node->data<=high) 
		{
			pre->next=node->next;
	        Node * n=node;
	        node=node->next;
	        free(n);
		}
		else
		{
			pre=node;
			node=node->next;
		}
	}
	return head;
}
/*8 给定两个单链表，编写算法求两个链表的公共结点*/
Node * getCommonNode(Node * node1,Node * node2)
{
	stack<Node *> s1;
	stack<Node *> s2;
	while(node1!=NULL)
	{
		s1.push(node1);
		node1=node1->next;
	}
	while(node2!=NULL)
	{
		s1.push(node2);
		node2=node2->next;
	}
	Node * n1,*n1Pre,*n2,*n2Pre;
	n1Pre=s1.top();
	s1.pop();
	n2Pre=s2.top();
	s2.pop();
	if(n1Pre!=n2Pre) return NULL;
	while((!s1.empty())&&(!s2.empty()))
	{
	n1=s1.top();
	s1.pop();
	n2=s2.top();
	s2.pop();
	if(n1==n2) {n1Pre=n1;n2Pre=n2;}
	else break;
	}
	return n1Pre;
}
/*9 给定一个带头结点的单链表，设head为头指针，
按递增顺序输出各结点的数据元素，并释放结点所占的存储空间*/
void increasePrintValues(Node * head)
{
	//先对链表进行插入排序
	Node *p,*r,*pre,*rear;
	pre=head;
	if(head==NULL) return ;
	rear=head->next; 
	if(rear==NULL) return ;
	//pre是第一个元素 
	pre=rear;
	//rear是第二个元素 
	rear=rear->next;
	pre->next=NULL;
	//把head变成只带第一个结点的头结点 
	head->next=pre;
	while(rear!=NULL)
	{
		//提前保存rear的下一个结点 
		Node * p=rear->next;
		Node * start=head;
		while(start->next!=NULL&&rear->data>start->next->data)
		{
			start=start->next;
		}
		//插入
		rear->next=start->next;
		start->next=rear; 
		rear=p;
	}
	//依次输出并释放空间
	head=head->next;
	while(head!=NULL)
	{
	Node * p=head;
	head=head->next;
	cout<<p->data<<" ";
	free(p);
	} 
} 
/*10 带头节点的单链表分解为两个带头节点的单链表A,B 使得A中含有原先的奇数元素，B中含有原先的偶数元素*/
void splitLinkListToTwoLinkList(Node *head,Node * a,Node *b)
{
	Node *a1=a;
	Node *b1=b;
	head=head->next; 
	int count=1;
	while(head!=NULL)
	{
		Node * r=head->next;
		if(count%2==0)
		{
			//偶数元素插入B
			b->next=head;
			b=b->next;
			b->next=NULL; 
		}
		else
		{
		    //奇数元素插入A
			a->next=head;
			a=a->next;
			a->next=NULL;	
		} 
		head=r;
		count++;
	}
	printLinkedListHaveHead(a1);
	printLinkedListHaveHead(b1);
}
/*11 将C={a1,b1,a2,b2,....an,bn}链表 采用就地算法 拆分成A={a1....an},B={bn.....b1}*/
void separateLinkList(Node * head,Node *a,Node *b)
{
	int count=1;
	head=head->next;
	Node * a1=a;
	Node * b1=b;
	while(head!=NULL)
	{
		Node * r=head->next;
		if(count%2==0)
		{
			//对b执行头插法 
			head->next=b1->next;
			b1->next=head;
		}
		else
		{
			//对a执行尾插法
			a1->next=head;
			a1=a1->next;
			a1->next=NULL;
		}
		head=r;
		count++;
	}
	printLinkedListHaveHead(a);
	printLinkedListHaveHead(b);
} 
/*12 除去一个递增有序的单链表中的相同元素，使其不含相同元素*/
Node * removeDuplicate(Node * head)
{
	if(head==NULL) return head;
	Node * pre=head;
	Node * node=head->next;
	while(node!=NULL)
	{
		if(pre==head)
		{
			pre=node;
			node=node->next;
		}
		else
		{
			//如果是相同元素 
			if(pre->data==node->data)
			{
				pre->next=node->next;
				node=pre->next;
			}
			//如果不是相同元素
			else
			{
			pre=node;
			node=node->next;	
			} 
		}
	}
	return head;
}  
/*13 假设两个元素值递增有序的线性表 合并成一个递减次序的线性表 
要求利用原来的两个单链表的结点存放归并后的单链表 
!!!头插法 可以改变元素的顺序 
*/
Node * mergeLinkList(Node *a,Node *b)
{
	Node *head=initNode(-1);
	Node *h=head;
	Node *a1=a->next;
	Node *b1=b->next;
	while(a1!=NULL&&b1!=NULL)
	{
	if(a1->data<b1->data)
	{
	//头插法插 a2	
	Node * a2=a1;
	a1=a1->next;
	a2->next=h->next;
	h->next=a2;
	}
	else
	{
	//头插法插 b1	
	Node * b2=b1;
	b1=b1->next;
	b2->next=h->next;
	h->next=b2;
	}	
	} 
	while(a1!=NULL)
	{
	//头插法插 a2	
	Node * a2=a1;
	a1=a1->next;
	a2->next=h->next;
	h->next=a2;
	} 
	while(b1!=NULL) 
	{
	//头插法插 b1	
	Node * b2=b1;
	b1=b1->next;
	b2->next=h->next;
	h->next=b2;	
	}
	return head; 
}
/*14 A,B是两个单链表 元素递增有序 设计一个算法从A,B的公共元素中产生链表C 要求不破坏 A，B的结点
!!!注意尾插时把尾部置空 
*/
Node * getCommonLNode(Node *a,Node *b)
{
	Node *head=initNode(-1);
	Node *h=head;
	Node *a1=a->next;
	Node *b1=b->next;
	while(a1!=NULL&&b1!=NULL)
	{
		//相等时用尾插法 插入公共结点 
		if(a1->data==b1->data)
		{
			Node *n=a1;
			a1=a1->next;
			b1=b1->next;
			h->next=n;
			h=h->next;
			h->next=NULL; 
		}
		//a1<b1时 将a1右移
		else if(a1->data<b1->data)
		{
		    a1=a1->next;	
		} 
		else
		{
			b1=b1->next;
		}
	}
	return head;
}
/*15 单链表A,B递增排列 求A与B的交集存放到A中*/
Node* getCommonNodeSaveToA(Node *a,Node *b)
{
	Node *a1=a->next;
	Node *b1=b->next;
	Node *preA1=a;
	while(a1!=NULL)
	{
		if(b1==NULL) preA1->next=NULL;
		if(a1->data==b1->data)
		{
			preA1=a1;
			a1=a1->next;
			b1=b1->next;
		}
		else if(a1->data<b1->data)
		{
			//删除a1的当前结点
			preA1->next=a1->next;
			a1=preA1->next;
		}
		else
		{
			//将b1后移
			b1=b1->next; 
		}
	}
	return a;
}
/*16 设链表A a1.....am,链表B b1......bn 判断B是否为A的连续子序列*/
bool isBContainsToA(Node *a,Node *b)
{
    Node *a1=a->next;
    Node *b1=b->next;
    while(a1!=NULL)
    {
    	Node *aBegin=a1;
    	Node *bBegin=b1;
    	while(aBegin!=NULL&&bBegin!=NULL)
    	{
    		if(aBegin->data==bBegin->data) 
    		{
    			//bBegin的后继为NULL时说明B属于A
				if(bBegin->next==NULL) return true;
				else {aBegin=aBegin->next;bBegin=bBegin->next;}
			}
			else
			{
				break;
			}
		}
		a1=a1->next;
	}
	return false;
}
/*对双向循环链表的一些定义及结构体*/
struct DNode
{
int data;
DNode *prior;
DNode *next;	
}; 
//打印循环链表NEXT正向打印 
void printDNLinkList(DNode *head)
{
	cout<<"-----------打印双向循环链表-------------"<<endl;
    DNode * h=head->next;
	while(h!=NULL&&h!=head)
	{
	cout<<h->data<<" ";	
	h=h->next;
	}	
	cout<<endl;
}
//初始化结点 
DNode * initDNode(int data)
{
	DNode *dNode=(struct DNode *) malloc(sizeof(struct DNode));
	dNode->data=data;
	dNode->prior=NULL;
	dNode->next=NULL;
	return  dNode;
}
//带头节点的双向循环链表插入元素 
DNode * insertDNode(int data[],int n)
{
	DNode *head=initDNode(-1);
	DNode *v=initDNode(data[0]);
	head->next=v;
	head->prior=v;
	v->next=head;
	v->prior=head; 
	for(int i=1;i<n;i++)
	{
	DNode * v=initDNode(data[i]);
	//v的前驱是尾结点 
	v->prior=head->prior;
	//尾节点的后继是v 
	head->prior->next=v;
	//v的后继是头指针
	v->next=head;
	//头指针的前驱是v
	head->prior=v; 
	}
	return head;
}
//带头节点的双向循环链表删除元素
DNode * deleteDNode(DNode *head,int index)
{
	int i=1;
	DNode *node=head->next;
	while(node!=NULL)
	{
		if(index==i)
		{
			//将前驱的后继指向 当前的后继
			node->prior->next=node->next; 
			//将后继结点的前驱指向 当前结点的前驱 
			node->next->prior=node->prior;
			return head;
		}
		i++;
		node=node->next;
	}
	return  head;
} 
/*17 判断一个循环链表是否对称*/
bool isSymmetry(DNode *head)
{
	DNode* p=head->prior;
	DNode* r=head->next;
	while(p!=NULL&&r!=NULL&&p!=head)
	{
		if(p->data==r->data) 
		{
			p=p->prior;
			r=r->next;
		}
		else
		{
			return false;
		}
	}
	return true;
} 
/*定义单循环链表的一些操作*/
//由数组构建一个带表头的单循环链表 
Node * insertNode(int data[],int n)
{
	Node *head=initNode(-1);
	Node *node=initNode(data[0]);
	head->next=node;
	for(int i=1;i<n;i++)
	{
	Node *n=initNode(data[i]);
	node->next=n;
	node=node->next;	
	} 
	node->next=head;
	return head; 
}
//打印一个单循环链表
void printSingleCirleLinkList(Node *head)
{
Node * node=head->next;
while(node!=head)
{
cout<<node->data<<" ";	
node=node->next;	
}	
} 
/*18 两个单循环链表 表头分别为h1和h2编写函数将h2接到h1之后 要求依然是循环链表*/
Node * mergeH1H2(Node *h1,Node *h2)
{
	Node *s1=h1;
	Node *s2=h2;
	while(s1->next!=h1)
	{
		s1=s1->next;
	}
	//此时s1为h1的尾结点
	s1->next=h2->next;
	while(s1->next!=h2)
	{
	    s1=s1->next;	
	} 
	s1->next=h1;
	return h1;
}
/*19 有一个带头节点的循环单链表，其结点值均为正整数，设计一个算法，反复找出值最小结点并输出
，然后删除 直到单链表为空为止，再删除头结点*/
void printAndDeleteNode(Node *head)
{ 
	Node *node=head->next;
	//如果不是只剩下一个头结点就循环 
	while(!((node->data==head->data)&&(node->next->data==head->data)))
	{
		Node *minPreNode=head;
		node=head->next;
		while(!(node->next->data==head->data))
		{
			//cout<<minPreNode->next->data<<"  "<<node->next->data<<endl;
			if(node->next->data<minPreNode->next->data) minPreNode=node;
			node=node->next;
		}
		//删除minPreNode的后继结点
		cout<<minPreNode->next->data<<" ";
		Node *n=minPreNode->next;
		minPreNode->next=minPreNode->next->next; 
		free(n);
	}
	free(head);
}
/*20 设头指针为L 的带头结点的非循环双向链表，每个结点除了prior,data,next之外还有一个freq 
键表被调用前其值均初始化为0，每当链表中进行一次locate(L,X)时令元素值为x的结点中freq加1
并使得此链表中的结点按照访问频度（递减）排列，对访问频度相同的结点 按照访问顺序 把最后访问的
放在前面，使得访问频繁的结点靠近表头 试着编写locate(L,X)算法 
Node * locate(Node *head,int x)
{
	Node *node=head->next;
	while(node!=NULL)
	{
		//如果当前结点是x结点
		if(node->data==x)
		{
			//先保存当前结点的下一个结点 
			Node * r=node->next; 
			//将node的频度+1
			node->freq+=1; 
			//在链表中删除当前结点
			node->prior->next=node->next;
			node->next->prior=node->prior;
			//删除node后把它查到链表中合适的位置
			Node *h=head;
			while(h->next!=NULL||h->next->freq>node->freq)
			{
				h=h->next;
			} 
			//插入 node(在h后)
			h->next->prior=node;
			node->next=h->next;
			node->prior=h;
			h->next=node;
			//插入结束后把node指向原本的下一个结点
			node=r; 
		}
		//如果当前结点不是x结点 
		else
		{
			node=node->next;
		}
	}
	return head;
}
*/
/*21 假设链表只给出了头指针，在不改变链表的前提下，设计出一个尽可能高效的算法查找表中倒数第k个位置的结点
若查找成功则输出data域的值，并返回1 否则 只返回0*/
int getKValueBackWards(Node * head,int k)
{
	//!!!按照题意是不带头结点的 
	//使用kNode 来记录 潜在的k结点
	Node *kNode=NULL;
	Node *node=head;
	while(node!=NULL)
	{
		if(k>0)
		{
			k--;
		}
		if(k==0)
		{
		if(kNode==NULL)	kNode=head;
		else
		{
		kNode=kNode->next;	
		}
		} 
		node=node->next;
	}
	if(k>0)  return 0;
	else 
	{
		cout<<kNode->data<<endl;
		return 1; 
	}
}
/*22 带头节点的单链表保存单词 如loading,being 在i这个结点及以后结点完全相等，
现设计一个高效算法求s1,s2的公共结点的起始位置
两种解法 
1 用两个栈分别来存储s1与s2的元素 依次弹出
2 记录两个链表的长度l1,l2 挪动元素直到l1=l2此时同步后挪找公共结点 
采用第二种方法去解 
int locateCommonNode(Node *s1,Node *s2)
{
	int len1,len2;
	len1=len2=0;
	Node *n1=s1;
	Node *n2=s2;
	while(n1->next!=NULL)
	{
	n1=n1->next;
	len1++;
    }
    while(n2->next!=NULL)
    {
    n2=n2->next;
    len2++;
	}
	n1=s1->next;n2=s2->next;
	while(len1!=len2)
	{
	if(len1>len2)
	{
	n1=n1->next;
	len1--;
    }
    else
    {
    n2=n2->next;
    n2--;
	}
    }
    int i=1;
    while(n1!=NULL&&n2!=NULL)
    {
    if(n1==n2) return n1;
    }
    return NULL;
} 
*/ 
/*23 用单链表保存m个整数(带头节点) 设计一个时间复杂度尽可能高的算法对绝对值相等的元素
仅保留第一次出现的元素而删除所有其余绝对值相等的结点 (链表中的元素均小于n)
因为要求时间度尽可能高则采用时间换空间*/
Node* removeAbsoluteEqualNodes(Node* head,int n)
{
	bool  isHave[n+1];
	for(int i=0;i<n+1;i++)
	{
		isHave[i]=false;
	}
	Node *pre=head;
	Node *current=pre->next;
	while(current!=NULL)
	{
		if(isHave[abs(current->data)])
		{
			//已经有了 删除当前元素 
			pre->next=current->next;
			current=pre->next; 
		}
		else
		{
			isHave[abs(current->data)]=true;
			pre=current;
			current=pre->next;
		}
	}
	return head;
}
int main()
{
	int data1[7]={-1,2,3,5,3,2,1};
	int data2[5]={3,5,5,6,6};
    Node *n1=tailInsert(data1,7);
	printLinkedListHaveHead(n1);
	printLinkedListHaveHead(removeAbsoluteEqualNodes(n1,7));
}
