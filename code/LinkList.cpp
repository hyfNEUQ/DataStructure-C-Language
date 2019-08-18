#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std; 
/*�Ե������һЩ�ṹ��Ķ����Լ�һЩ����*/
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
/*ͷ�巨����������,����һ����ͷ���ĵ������ͷ*/
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
/*β�巨����������,����һ����ͷ�ڵ�ĵ������ͷ*/
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
/*��ӡ��ͷ�ڵ������*/
void printLinkedListHaveHead(Node * node)
{
	while(node->next!=NULL)
	{
		cout<<node->next->data<<" ";
		node=node->next;
	}
	cout<<endl;
}
/*��ӡ����ͷ��������*/
void printLinkedListHaveNotHead(Node * node)
{
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node=node->next;
	}
	cout<<endl;
}
/*����Ų��� */
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
1 ���һ���ݹ��㷨ɾ������ͷ���ĵ�����L������ֵΪX�Ľ�� (head ��������ɾ��֮���ͷ���)
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
2 �ڴ�ͷ�ڵ�ĵ�����L�У�ɾ������ֵΪx�Ľ�㣬���ͷſռ� 
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
/*3 ��LΪ��ͷ�ڵ�ĵ����� ��β��ͷ�������ÿ������ֵ*/
void inverselyPrintLinkedList(Node * head)
{
	if(head->next!=NULL)
	{
	inverselyPrintLinkedList(head->next);
	}
	cout<<head->data<<" ";
}
/*
4 ɾ����ͷ���ĵ�����L����Сֵ�ĸ�Ч�㷨 
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
5 �͵����ô�ͷ�ڵ�ĵ�����ռ临�Ӷ�o(1) 
!!!ע��  p->next=NULL ��һ�� 
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
6 ��һ����ͷ���ĵ��������һ���㷨ʹ��Ԫ�ص������� (���ò�������)
!!!�ؼ��� ��������ʱ ��Ҫ���������һ���� �� �������һ���ֶϿ� 
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
/*7 ��ͷ�ڵ�ĵ��������� ɾ������ ����������ֵ֮���Ԫ��*/
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
/*8 ����������������д�㷨����������Ĺ������*/
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
/*9 ����һ����ͷ���ĵ�������headΪͷָ�룬
������˳���������������Ԫ�أ����ͷŽ����ռ�Ĵ洢�ռ�*/
void increasePrintValues(Node * head)
{
	//�ȶ�������в�������
	Node *p,*r,*pre,*rear;
	pre=head;
	if(head==NULL) return ;
	rear=head->next; 
	if(rear==NULL) return ;
	//pre�ǵ�һ��Ԫ�� 
	pre=rear;
	//rear�ǵڶ���Ԫ�� 
	rear=rear->next;
	pre->next=NULL;
	//��head���ֻ����һ������ͷ��� 
	head->next=pre;
	while(rear!=NULL)
	{
		//��ǰ����rear����һ����� 
		Node * p=rear->next;
		Node * start=head;
		while(start->next!=NULL&&rear->data>start->next->data)
		{
			start=start->next;
		}
		//����
		rear->next=start->next;
		start->next=rear; 
		rear=p;
	}
	//����������ͷſռ�
	head=head->next;
	while(head!=NULL)
	{
	Node * p=head;
	head=head->next;
	cout<<p->data<<" ";
	free(p);
	} 
} 
/*10 ��ͷ�ڵ�ĵ�����ֽ�Ϊ������ͷ�ڵ�ĵ�����A,B ʹ��A�к���ԭ�ȵ�����Ԫ�أ�B�к���ԭ�ȵ�ż��Ԫ��*/
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
			//ż��Ԫ�ز���B
			b->next=head;
			b=b->next;
			b->next=NULL; 
		}
		else
		{
		    //����Ԫ�ز���A
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
/*11 ��C={a1,b1,a2,b2,....an,bn}���� ���þ͵��㷨 ��ֳ�A={a1....an},B={bn.....b1}*/
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
			//��bִ��ͷ�巨 
			head->next=b1->next;
			b1->next=head;
		}
		else
		{
			//��aִ��β�巨
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
/*12 ��ȥһ����������ĵ������е���ͬԪ�أ�ʹ�䲻����ͬԪ��*/
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
			//�������ͬԪ�� 
			if(pre->data==node->data)
			{
				pre->next=node->next;
				node=pre->next;
			}
			//���������ͬԪ��
			else
			{
			pre=node;
			node=node->next;	
			} 
		}
	}
	return head;
}  
/*13 ��������Ԫ��ֵ������������Ա� �ϲ���һ���ݼ���������Ա� 
Ҫ������ԭ��������������Ľ���Ź鲢��ĵ����� 
!!!ͷ�巨 ���Ըı�Ԫ�ص�˳�� 
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
	//ͷ�巨�� a2	
	Node * a2=a1;
	a1=a1->next;
	a2->next=h->next;
	h->next=a2;
	}
	else
	{
	//ͷ�巨�� b1	
	Node * b2=b1;
	b1=b1->next;
	b2->next=h->next;
	h->next=b2;
	}	
	} 
	while(a1!=NULL)
	{
	//ͷ�巨�� a2	
	Node * a2=a1;
	a1=a1->next;
	a2->next=h->next;
	h->next=a2;
	} 
	while(b1!=NULL) 
	{
	//ͷ�巨�� b1	
	Node * b2=b1;
	b1=b1->next;
	b2->next=h->next;
	h->next=b2;	
	}
	return head; 
}
/*14 A,B������������ Ԫ�ص������� ���һ���㷨��A,B�Ĺ���Ԫ���в�������C Ҫ���ƻ� A��B�Ľ��
!!!ע��β��ʱ��β���ÿ� 
*/
Node * getCommonLNode(Node *a,Node *b)
{
	Node *head=initNode(-1);
	Node *h=head;
	Node *a1=a->next;
	Node *b1=b->next;
	while(a1!=NULL&&b1!=NULL)
	{
		//���ʱ��β�巨 ���빫����� 
		if(a1->data==b1->data)
		{
			Node *n=a1;
			a1=a1->next;
			b1=b1->next;
			h->next=n;
			h=h->next;
			h->next=NULL; 
		}
		//a1<b1ʱ ��a1����
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
/*15 ������A,B�������� ��A��B�Ľ�����ŵ�A��*/
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
			//ɾ��a1�ĵ�ǰ���
			preA1->next=a1->next;
			a1=preA1->next;
		}
		else
		{
			//��b1����
			b1=b1->next; 
		}
	}
	return a;
}
/*16 ������A a1.....am,����B b1......bn �ж�B�Ƿ�ΪA������������*/
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
    			//bBegin�ĺ��ΪNULLʱ˵��B����A
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
/*��˫��ѭ�������һЩ���弰�ṹ��*/
struct DNode
{
int data;
DNode *prior;
DNode *next;	
}; 
//��ӡѭ������NEXT�����ӡ 
void printDNLinkList(DNode *head)
{
	cout<<"-----------��ӡ˫��ѭ������-------------"<<endl;
    DNode * h=head->next;
	while(h!=NULL&&h!=head)
	{
	cout<<h->data<<" ";	
	h=h->next;
	}	
	cout<<endl;
}
//��ʼ����� 
DNode * initDNode(int data)
{
	DNode *dNode=(struct DNode *) malloc(sizeof(struct DNode));
	dNode->data=data;
	dNode->prior=NULL;
	dNode->next=NULL;
	return  dNode;
}
//��ͷ�ڵ��˫��ѭ���������Ԫ�� 
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
	//v��ǰ����β��� 
	v->prior=head->prior;
	//β�ڵ�ĺ����v 
	head->prior->next=v;
	//v�ĺ����ͷָ��
	v->next=head;
	//ͷָ���ǰ����v
	head->prior=v; 
	}
	return head;
}
//��ͷ�ڵ��˫��ѭ������ɾ��Ԫ��
DNode * deleteDNode(DNode *head,int index)
{
	int i=1;
	DNode *node=head->next;
	while(node!=NULL)
	{
		if(index==i)
		{
			//��ǰ���ĺ��ָ�� ��ǰ�ĺ��
			node->prior->next=node->next; 
			//����̽���ǰ��ָ�� ��ǰ����ǰ�� 
			node->next->prior=node->prior;
			return head;
		}
		i++;
		node=node->next;
	}
	return  head;
} 
/*17 �ж�һ��ѭ�������Ƿ�Գ�*/
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
/*���嵥ѭ�������һЩ����*/
//�����鹹��һ������ͷ�ĵ�ѭ������ 
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
//��ӡһ����ѭ������
void printSingleCirleLinkList(Node *head)
{
Node * node=head->next;
while(node!=head)
{
cout<<node->data<<" ";	
node=node->next;	
}	
} 
/*18 ������ѭ������ ��ͷ�ֱ�Ϊh1��h2��д������h2�ӵ�h1֮�� Ҫ����Ȼ��ѭ������*/
Node * mergeH1H2(Node *h1,Node *h2)
{
	Node *s1=h1;
	Node *s2=h2;
	while(s1->next!=h1)
	{
		s1=s1->next;
	}
	//��ʱs1Ϊh1��β���
	s1->next=h2->next;
	while(s1->next!=h2)
	{
	    s1=s1->next;	
	} 
	s1->next=h1;
	return h1;
}
/*19 ��һ����ͷ�ڵ��ѭ������������ֵ��Ϊ�����������һ���㷨�������ҳ�ֵ��С��㲢���
��Ȼ��ɾ�� ֱ��������Ϊ��Ϊֹ����ɾ��ͷ���*/
void printAndDeleteNode(Node *head)
{ 
	Node *node=head->next;
	//�������ֻʣ��һ��ͷ����ѭ�� 
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
		//ɾ��minPreNode�ĺ�̽��
		cout<<minPreNode->next->data<<" ";
		Node *n=minPreNode->next;
		minPreNode->next=minPreNode->next->next; 
		free(n);
	}
	free(head);
}
/*20 ��ͷָ��ΪL �Ĵ�ͷ���ķ�ѭ��˫������ÿ��������prior,data,next֮�⻹��һ��freq 
��������ǰ��ֵ����ʼ��Ϊ0��ÿ�������н���һ��locate(L,X)ʱ��Ԫ��ֵΪx�Ľ����freq��1
��ʹ�ô������еĽ�㰴�շ���Ƶ�ȣ��ݼ������У��Է���Ƶ����ͬ�Ľ�� ���շ���˳�� �������ʵ�
����ǰ�棬ʹ�÷���Ƶ���Ľ�㿿����ͷ ���ű�дlocate(L,X)�㷨 
Node * locate(Node *head,int x)
{
	Node *node=head->next;
	while(node!=NULL)
	{
		//�����ǰ�����x���
		if(node->data==x)
		{
			//�ȱ��浱ǰ������һ����� 
			Node * r=node->next; 
			//��node��Ƶ��+1
			node->freq+=1; 
			//��������ɾ����ǰ���
			node->prior->next=node->next;
			node->next->prior=node->prior;
			//ɾ��node������鵽�����к��ʵ�λ��
			Node *h=head;
			while(h->next!=NULL||h->next->freq>node->freq)
			{
				h=h->next;
			} 
			//���� node(��h��)
			h->next->prior=node;
			node->next=h->next;
			node->prior=h;
			h->next=node;
			//����������nodeָ��ԭ������һ�����
			node=r; 
		}
		//�����ǰ��㲻��x��� 
		else
		{
			node=node->next;
		}
	}
	return head;
}
*/
/*21 ��������ֻ������ͷָ�룬�ڲ��ı������ǰ���£���Ƴ�һ�������ܸ�Ч���㷨���ұ��е�����k��λ�õĽ��
�����ҳɹ������data���ֵ��������1 ���� ֻ����0*/
int getKValueBackWards(Node * head,int k)
{
	//!!!���������ǲ���ͷ���� 
	//ʹ��kNode ����¼ Ǳ�ڵ�k���
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
/*22 ��ͷ�ڵ�ĵ������浥�� ��loading,being ��i�����㼰�Ժ�����ȫ��ȣ�
�����һ����Ч�㷨��s1,s2�Ĺ���������ʼλ��
���ֽⷨ 
1 ������ջ�ֱ����洢s1��s2��Ԫ�� ���ε���
2 ��¼��������ĳ���l1,l2 Ų��Ԫ��ֱ��l1=l2��ʱͬ����Ų�ҹ������ 
���õڶ��ַ���ȥ�� 
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
/*23 �õ�������m������(��ͷ�ڵ�) ���һ��ʱ�临�ӶȾ����ܸߵ��㷨�Ծ���ֵ��ȵ�Ԫ��
��������һ�γ��ֵ�Ԫ�ض�ɾ�������������ֵ��ȵĽ�� (�����е�Ԫ�ؾ�С��n)
��ΪҪ��ʱ��Ⱦ����ܸ������ʱ�任�ռ�*/
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
			//�Ѿ����� ɾ����ǰԪ�� 
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
