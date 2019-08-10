#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <stack>
using namespace std;
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
for(int i=0;i<n;i++) cout<<data[i]<<" < ";	
cout<<endl;
}
//��������
void insertSort(int data[],int n)
{
	for(int i=0;i<n;i++)
	{
		int j=i;
		while((j-1>=0)&&(data[j]<data[j-1]))
		{
			int t=data[j];
			data[j]=data[j-1];
			data[j-1]=t;
			j--;
		}
		
	}
	print(data,n);
} 
//ѡ������
void pickMinSort(int data[],int n)
{
    for(int i=0;i<n;i++)
	{
	   int index=i;
	   int j=i+1;
	   while(j<n)
	   {
	   if(data[index]>data[j]) index=j;
	   j++;
	   }
	   int t=data[i];
	   data[i]=data[index];
	   data[index]=t;	
	}	
	print(data,n);
} 
//ð������
void bubbleSort(int data[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(data[j]<data[i])
			{
				int t=data[j];
				data[j]=data[i];
				data[i]=t;
			}
		}
	}
	print(data,n);
}
//ϣ������
void shellSort(int data[],int n)
{
for(int gap=n/2;gap>0;gap=gap/2)
{
	for(int k=0;k<n;k++)
	{
	int i=0;
	while(k+i*gap<n)
	{
		int j=i-1;
		while(j>=0)
		{
			if(data[k+(j+1)*gap]<data[k+j*gap]) 
			{
			int t=data[k+(j+1)*gap];
			data[k+(j+1)*gap]=data[k+j*gap];
			data[k+j*gap]=t;	
			j--;
			} 
			else break;
		}
		i++;
	}
   }
}
print(data,n);	
} 
//�۰��������(Ѱ�Ҳ���λ��ʱ ʹ���۰���ҷ�)
void binInsertSort(int data[],int n)
{
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
		int t=data[i];
		data[i]=data[j];
		data[j]=t;
		while(i<j)
		{
			if(data[i]>key) break;
			i++;
		}
		t=data[i];
		data[i]=data[j];
		data[j]=t;
		print(data,14);	
	}
	quickSort(data,start,i-1);
	quickSort(data,i+1,end);	 
} 
//������ (���켫С��)
void  buildMinHeap(int data[],int n)
{
	if(n==0) return;
	for(int i=n;i>=0;i--)
	{
		int x=2*i+1;int y=2*i+2;
		if(x>n) continue;
		else if(x==n)
		{
			if(data[x]<data[i]) 
			{
				int t=data[x];
				data[x]=data[i];
				data[i]=t;
			}
		}
		else 
		{
			    int index=x;
			    if(data[y]<data[x]) index=y;
			    if(data[index]>data[i]) continue; 
		        int t=data[index];
				data[index]=data[i];
				data[i]=t;
		}
	}	
} 
//������ 
void heapSort(int data[],int n)
{
	while(n>=0)
	{
		buildMinHeap(data,n);
		int t=data[n];
		data[n]=data[0];
		data[0]=t;
		n--;
	}	
	print(data,15);
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

int main()
{
	int data[15]={1,54,32,12,14,4,14,18,23,16,45,99,15,17,16};
	int data2[17]={1,54,32,12,14,4,14,18,23,16,45,99,15,17,16,39,28};
	//insertSort(data,15);
	//pickMinSort(data,15);
	//bubbleSort(data,15);
	shellSort(data,15);
	//binInsertSort(data,15);
	//quickSort(data,0,14);
	//heapSort(data,14);
	//int tempt[15];
	//mergeSort(0,14,data,tempt);
	//radixSort(data,15,2);
} 
