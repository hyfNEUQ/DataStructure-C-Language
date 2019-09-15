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
	}
	cout<<"--------------------快速排序------------------------------"<<endl;
	print(data,15);	
	quickSort(data,start,i-1);
	quickSort(data,i+1,end);	 
} 
//(向下调整成极小堆 param 数组,当前结点的下标,数组元素个数 
void  adjustDown(int data[],int index,int n)
{
	for(int i=index;i<n;) 
	{ 
		int low=2*i+1;
		int high=2*i+2;
		if(low>=n) return ;
		if(high>=n)
		{
		if(data[low]<data[index]) swap(data,index,low);	
		return;
		} 
		else
		{
			int j=low;
			if(data[high]<data[low]) j=high;
			//j 为子节点中较小的结点
			if(data[j]<data[i]) 
			{
				swap(data,i,j);
				i=j; 
			}
			else
			{
			return ;	
			} 
		}
	}
} 
//建立小根堆 
void builHeap(int data[],int n)
{
	for(int i=n/2+1;i>=0;i--)
	{
		adjustDown(data,i,n);
	}
}
//堆排序
void heapSort(int data[],int n)
{
	//建立极小堆 
	for(int i=n/2+1;i>=0;i--)
	{
		adjustDown(data,i,n);
	}
	for(int i=n-1;i>0;i--)
	{
		swap(data,i,0);
		adjustDown(data,0,i-1);
	}
	print(data,n);
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
//把所有奇数移到所有偶数前面(奇数，偶数内部的相对顺序改变)
void moveSingleBeforeDouble(int data[],int n)
{
	int start=0;
	int end=n-1;
	while(start<end)
	{
		while(start<end)
		{
		//奇数	
		if(data[end]%2!=0)	break;
		end--;
		}
		while(start<end)
		{
		//偶数 
		if(data[start]%2==0) break;	
		start++;
		}
		swap(data,start,end);
		print(data,15); 
	}
	
} 
//把所有奇数移到所有偶数前面(奇数，偶数内部的相对顺序不变)
void staticMoveSingleBeforeDouble(int data[],int n) 
{
	
}
//快排算法 中轴元素随机取
void quickSortRandomAxis(int data[],int low,int high)
{
	if(low>=high) return;
	int index=low+(rand())%(high-low);
	swap(data,index,low); 
	int i=low;
	int j=high;
	int axis=data[i];
	while(i<j)
	{
		while(i<j)
		{
			if(data[j]<axis) break;
			j--;
		}
	    swap(data,i,j);
		while(i<j)
		{
			if(data[i]>axis) break;
			i++;
		}
		swap(data,i,j);
	}
	print(data,17);
	quickSortRandomAxis(data,low,i-1);
	quickSortRandomAxis(data,i+1,high);
} 
//找出数组第k小的元素
void getKMinValue(int data[],int low,int high,int k)
{
if(low>high) return;	
int i=low;
int j=high;
int key=data[low];
while(i<j)
{
while(i<j)
{
if(key>data[j]) break;
j--;	
}
swap(data,i,j);
while(i<j)
{
if(key<data[i])	break;
i++; 
}
swap(data,i,j);	
}
//此时i为 数组中第i+1个小的元素
if(i+1==k) printf("%d",data[i]);
else if(i+1<k)
{
getKMinValue(data,i+1,high,k);	
}
else
{
getKMinValue(data,low,i-1,k);	
} 	
} 
/*已知有n个正整数构成的集合A={ak|0<=k<n} 将其划分为两个不相交的子集A1 A2 
元素的个数分别 n1,n2, A1和A2中的元素之和分别为s1,s2 满足n1-n2最小且s1-s2最大 
题意为  从A中选取 n/2个最大的元素放到一边 选取n/2个最小的放到一边  
*/ 
void segArray(int data[],int low,int high,int n)
{
    if(low>high) return ;
    int i=low;
    int j=high;
    int key=data[i];
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
	}
	if(i-1==n/2) return; 
	else if(i-1<n/2)segArray(data,i+1,high,n);	
	else segArray(data,low,i-1,n);
}
//判断数组是否为极小堆
bool isHeap(int data[],int i,int n) 
{
	int low=i*2+1;
	int high=i*2+2;
	if(low>=n) return true;
	if(high>=n) 
	{
		if(data[low]>data[i]) return true;
		else return false;
	}
	else
	{
		int j=low;
		if(data[low]>data[high]) j=high;
		if(data[j]<data[i]) return false;
		return isHeap(data,low,n)&&isHeap(data,high,n);
	}
} 
int main()
{
	int data[15]={17,2,32,5,1,4,14,3,23,16,45,99,15,17,16};
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
	//heapSort(data,15);
	builHeap(data,15);
	cout<<isHeap(data2,0,17)<<endl;
	print(data,15);
	cout<< isHeap(data,0,15)<<endl;
} 
