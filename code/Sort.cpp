#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <stack>
using namespace std;
//交换数组中两个元素的函数
void swap(int data[],int i,int j)
{
   int t=data[i];
   data[i]=data[j];
   data[j]=t;	
} 
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
for(int i=0;i<n;i++) cout<<data[i]<<" <= ";	
cout<<endl;
}
//插入排序
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
//选择排序
void pickMinSort(int data[],int n)
{
	cout<<"--------------------选择排序------------------------------"<<endl;
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
//冒泡排序
void bubbleSort1(int data[],int n)
{
	cout<<"--------------------冒泡排序(把最小的挪到前面)------------------------------"<<endl;
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
//冒泡排序
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
//希尔排序（插入排序） 
void shellSort(int data[],int n)
{
cout<<"--------------------希尔排序------------------------------"<<endl;
for(int gap=n/2;gap>=1;gap=gap/2)
{
//对gap进行插入排序 
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
//折半插入排序(寻找插入位置时 使用折半查找法)
void binInsertSort(int data[],int n)
{
cout<<"--------------------折半插入排序------------------------------"<<endl;
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
	cout<<"--------------------快速排序------------------------------"<<endl;
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
//堆排序 (构造极大堆)
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
//堆排序 
void heapSort(int data[],int n)
{
	cout<<"--------------------堆排序------------------------------"<<endl;
	while(n>=0)
	{
		buildMinHeap(data,n);
		swap(data,n,0);
		n--;
	}	
	print(data,17);
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
/*
双向冒泡排序 （第一趟把最大的放在后面，第二趟把最小的放在前面） 
param(待排序数组 , 数组中元素个数)
*/
void deBubbleSort(int data[],int n)
{
	cout<<"--------------双向冒泡排序-----------------------"<<endl; 
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			//最大的元素沉底 
			for(int j=i+1;j<n;j++)
			{
				if(data[j-1]>data[j]) swap(data,j-1,j);
			} 
		}
		else
		{
			//最小的元素挪到前面 
			for(int j=n-1;j>=0;j--)
			{
				if(data[j]<data[j-1]) swap(data,j-1,j);
			}
		}
		print(data,n);
	}
}
//非递归快排
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
