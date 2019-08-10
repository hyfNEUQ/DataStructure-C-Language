#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <stack>
using namespace std;
//用于桶排序的桶（链表形式） 
struct node
{
int data;
node * next;	
}; 
//获取一个桶结点
node *getNode(int data)
{
	node *n=(struct node*) malloc(sizeof(struct node));
	n->data=data;
	n->next=NULL;
    return 	n;
} 
//打印排序后的结果 
void print(int data[],int n)
{
for(int i=0;i<n;i++) cout<<data[i]<<" < ";	
cout<<endl;
}
//插入排序
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
//选择排序
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
//冒泡排序
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
//希尔排序
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
//折半插入排序(寻找插入位置时 使用折半查找法)
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
//对high+1进行挪动
int t=data[i];
for(int j=i;j>high+1;j--)
{
	data[j]=data[j-1];
}
data[high+1]=t;
}
print(data,n);	
}
//快速排序
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
//堆排序 (构造极小堆)
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
//堆排序 
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
//合并两数组 
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
//归并排序 (开始数组的下标,结束数组的下标,待排数组,临时存放数据的数组)
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
基数排序（桶排序） param(待排数组,数组大小,最大数的位数)
*/
void radixSort(int data[],int n,int maxSize)
{
	node * nodes[10];
	int j=1; int k=1; 
	while(j<=maxSize)
	{
		//把桶清空 
		for(int i=0;i<10;i++)
	    {
		    node * n=NULL;
		    nodes[i]=n; 
	    }
	    //数据装到相应的桶中 
		for(int i=0;i<n;i++)
		{
			int index=(data[i]/k)%10;
			node * n=getNode(data[i]);
			n->next=nodes[index];
			nodes[index]=n;
		}
		//从桶中取出数据来回填到数组中去 
		int t=0;
		for(int i=0;i<10;i++)
		{
			//由于前面使用的是尾插法 所以这里使用栈 使链表恢复正序 
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
