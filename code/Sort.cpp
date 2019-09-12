#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <stack>
using namespace std;
//��������������Ԫ�صĺ���
void swap(int data[],int i,int j)
{
   int t=data[i];
   data[i]=data[j];
   data[j]=t;	
} 
//����Ͱ�����Ͱ��������ʽ�� 
struct node
{
int data;
node * next;	
}; 
//��ȡһ��Ͱ���
node *getNode(int data)
{
	node *n=(struct node*) malloc(sizeof(struct node));
	n->data=data;
	n->next=NULL;
    return 	n;
} 
//��ӡ�����Ľ�� 
void print(int data[],int n)
{
for(int i=0;i<n;i++) cout<<data[i]<<" <= ";	
cout<<endl;
}
//��������
void insetSort(int data[],int n)
{
for(int i=0;i<n;i++)
{
for(int j=i;j>0;j--)
{
	if(data[j]<data[j-1]) swap(data,j,j-1);
	else break;
}
}
print(data,n);	
} 
//ѡ������
void pickMinSort(int data[],int n)
{
	cout<<"--------------------ѡ������------------------------------"<<endl;
    for(int i=0;i<n;i++)
	{
	int min=data[i];
	int minIndex=i;
	for(int j=i;j<n;j++)
	{
	if(data[j]<min)
	{
	min=data[j];
	minIndex=j;	
	}	
	}
	swap(data,i,minIndex);	
	} 
	print(data,n);
} 
//ð������
void bubbleSort1(int data[],int n)
{
	cout<<"--------------------ð������(����С��Ų��ǰ��)------------------------------"<<endl;
	for(int i=0;i<n;i++)
	{
		bool isOver=true;
		for(int j=n-1;j>=i;j--)
		{
			if(data[j]<data[j-1]) {
			swap(data,j,j-1);
			isOver=false;
		    }
		}
		print(data,n);
		if(isOver) break;
	}
	print(data,n);
}
//ð������
void bubbleSort2(int data[],int n)
{
for(int i=n-1;i>=0;i--)
{
for(int j=0;j<i;j++)
{
if(data[j]>data[j+1]) swap(data,j,j+1);	
}
}
	print(data,n);
} 
//ϣ�����򣨲������� 
void shellSort(int data[],int n)
{
cout<<"--------------------ϣ������------------------------------"<<endl;
for(int gap=n/2;gap>=1;gap=gap/2)
{
//��gap���в������� 
for(int i=0;i<gap;i++)
{
int j=0;
while(j*gap+i<n)
{	
for(int k=j;k>0;k--)
{
	if(data[k*gap+i]<data[(k-1)*gap+i])
	{
		swap(data,k*gap+i,(k-1)*gap+i);
	}
	else break;
}	
j++;	
}	
}	
}
print(data,n); 
print(data,n);	
} 
//�۰��������(Ѱ�Ҳ���λ��ʱ ʹ���۰���ҷ�)
void binInsertSort(int data[],int n)
{
cout<<"--------------------�۰��������------------------------------"<<endl;
for(int i=1;i<n;i++)
{
int low=0;int high=i-1;
while(low<=high)
{
	int mid=(low+high)/2;
	if(data[mid]>data[i]) high=mid-1;
	else low=mid+1;
}	
//��high+1����Ų��
int t=data[i];
for(int j=i;j>high+1;j--)
{
	data[j]=data[j-1];
}
data[high+1]=t;
}
print(data,n);	
}
//��������
void quickSort(int data[],int start,int end)
{
	cout<<"--------------------��������------------------------------"<<endl;
	if(!(end>start)) return;
	int i=start;
	int j=end;
	int key=data[start];
	while(i<j)
	{
		while(i<j)
		{
			if(data[j]<key) break;
			j--;
		}
		swap(data,i,j);
		while(i<j)
		{
			if(data[i]>key) break;
			i++;
		}
		swap(data,i,j);
		print(data,15);	
	}
	quickSort(data,start,i-1);
	quickSort(data,i+1,end);	 
} 
//������ (���켫���)
void  buildMinHeap(int data[],int n)
{
	if(n==0) return;
	for(int i=n;i>=0;i--)
	{
		int x=2*i+1;int y=2*i+2;
		if(x>n) continue;
		else if(x==n)
		{
			if(data[x]>data[i]) 
			{
				swap(data,x,i);
			}
		}
		else 
		{
			    int index=x;
			    if(data[y]>data[x]) index=y;
			    if(data[index]<data[i]) continue; 
		        swap(data,index,i);
		}
	}	
} 
//������ 
void heapSort(int data[],int n)
{
	cout<<"--------------------������------------------------------"<<endl;
	while(n>=0)
	{
		buildMinHeap(data,n);
		swap(data,n,0);
		n--;
	}	
	print(data,17);
}
//�ϲ������� 
void merge(int start,int mid,int end,int data[],int tempt[])
{
int start1=start;
int start2=mid+1;
int j=0;
while(start1<=mid&&start2<=end)
{
	if(data[start1]>data[start2]) tempt[j++]=data[start2++];
	else tempt[j++]=data[start1++];
}	
while(start1<=mid)
{
	tempt[j++]=data[start1++];
}
while(start2<=end)
{
	tempt[j++]=data[start2++];
}
for(int i=start;i<=end;i++)
{
	data[i]=tempt[i-start];
}
}
//�鲢���� (��ʼ������±�,����������±�,��������,��ʱ������ݵ�����)
void mergeSort(int start,int end,int data[],int tempt[])
{
 if(end>start)
 {
 int mid=(end+start)/2;
 mergeSort(start,mid,data,tempt);
 mergeSort(mid+1,end,data,tempt);
 merge(start,mid,end,data,tempt);
 }	
 print(data,15);
} 
/*
��������Ͱ���� param(��������,�����С,�������λ��)
*/
void radixSort(int data[],int n,int maxSize)
{
	node * nodes[10];
	int j=1; int k=1; 
	while(j<=maxSize)
	{
		//��Ͱ��� 
		for(int i=0;i<10;i++)
	    {
		    node * n=NULL;
		    nodes[i]=n; 
	    }
	    //����װ����Ӧ��Ͱ�� 
		for(int i=0;i<n;i++)
		{
			int index=(data[i]/k)%10;
			node * n=getNode(data[i]);
			n->next=nodes[index];
			nodes[index]=n;
		}
		//��Ͱ��ȡ�����������������ȥ 
		int t=0;
		for(int i=0;i<10;i++)
		{
			//����ǰ��ʹ�õ���β�巨 ��������ʹ��ջ ʹ����ָ����� 
			stack <int> s;
			node *n=nodes[i];
			while(n!=NULL)
			{
				s.push(n->data);
				n=n->next;
			}
			while(!s.empty())
			{
				data[t++]=s.top();
				s.pop();
			}
		}
		j++;
		k*=10;
		print(data,15);
	}
	print(data,15);
}
/*
˫��ð������ ����һ�˰����ķ��ں��棬�ڶ��˰���С�ķ���ǰ�棩 
param(���������� , ������Ԫ�ظ���)
*/
void deBubbleSort(int data[],int n)
{
	cout<<"--------------˫��ð������-----------------------"<<endl; 
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			//����Ԫ�س��� 
			for(int j=i+1;j<n;j++)
			{
				if(data[j-1]>data[j]) swap(data,j-1,j);
			} 
		}
		else
		{
			//��С��Ԫ��Ų��ǰ�� 
			for(int j=n-1;j>=0;j--)
			{
				if(data[j]<data[j-1]) swap(data,j-1,j);
			}
		}
		print(data,n);
	}
}
//�ǵݹ����
void quickSort2(int data[],int n)
{
stack <int> stack;
int start=0;
int end=n-1;
stack.push(start);
stack.push(end);
while(!stack.empty())
{
	end=stack.top();
	stack.pop();
	start=stack.top();
	stack.pop();
    if(end>start){
	int i=start;
	int j=end;
	int key=data[i];
	while(i<j)
	{
	while(i<j)
	{
	if(data[j]<key) break;
	j--;	
	}
	swap(data,i,j);
	while(i<j){
	if(data[i]>key) break;
	i++;	
    }
    swap(data,i,j);
	}
	stack.push(start);
	stack.push(i-1);
	stack.push(i+1);
	stack.push(end);
    }
	print(data,17);	
}
} 
int main()
{
	int data[15]={13,54,32,12,1,4,14,18,23,16,45,99,15,17,16};
	int data2[17]={13,54,32,12,14,4,14,18,23,16,45,99,15,17,16,39,28};
	int data3[5]={3,1,5,2,4};
	//insertSort(data2,17);
	//pickMinSort(data2,17);
	//bubbleSort(data,15);
	//shellSort(data2,17);
	//binInsertSort(data2,17);
	//quickSort(data,0,14);
	//heapSort(data,14);
	//int tempt[15];
	//mergeSort(0,14,data,tempt);
	//radixSort(data,15,2);
	quickSort2(data2,17);
} 
