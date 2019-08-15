#include<iostream>
#include<stdio.h>
#include<stdlib.h>
# define MaxSize 100
using namespace std;
struct SqList
{
	int data[MaxSize];
	int length;
};
//初始化一个为空的线性表 
SqList * initList()
{
	SqList * sq=(struct SqList *) malloc (sizeof(struct SqList));
	sq->length=0;
	return sq; 
}
//求表长
int length(SqList * sq)
{
	return sq->length;
} 
//插入元素 param(链表,插入位置,插入的值) 
bool listInsert(SqList *sq,int i,int value)
{
	if(i<=0||i>=MaxSize) return false;
	for(int j=sq->length;j>=i;j--)
	{
		sq->data[j]=sq->data[j-1];
	}
	sq->data[i-1]=value;
	sq->length++;
	return true;
}
//删除元素 (待删除的表,删除的位置,用e来返回)
bool listDelete(SqList * sq,int i,int & e)
{
	if(i<=0||i>sq->length) return false;
	e=sq->data[i-1];
	for(int j=i-1;j<sq->length-1;j++)
	{
		sq->data[j]=sq->data[j+1];
	}
	sq->length--;
	return true;
} 
//打印链表
void printList(SqList *sq)
{
for(int i=0;i<sq->length;i++)
{
cout<<sq->data[i]<<" ";	
}	
cout<<endl;
} 
/*
2.2.3 算法题部分解答 
*/
// 1 (删除最小的元素，并由函数返回被删除的元素值，空出的位置由最后一个元素填补)
bool deleteMinValue(SqList * sq,int & minValue)
{
	if(sq->length==0) {printf("表为空");return false;}
	int minIndex=0;
	for(int i=0;i<sq->length;i++)
	{
		if(sq->data[i]<sq->data[minIndex]) minIndex=i;
	}
	minValue=sq->data[minIndex];
	if(sq->length!=1) sq->data[minIndex]=sq->data[sq->length-1];
	sq->length--;
	return true; 
}
// 2 顺序表L 所有元素逆置 空间复杂度o(1)
void invertSqList(SqList * sq)
{
int i=0;
int j=sq->length-1;
while(i<j)
{
int t;	
t=sq->data[i];
sq->data[i]=sq->data[j];
sq->data[j]=t;
i++;j--;	
}	
} 
// 3 对长度为n的顺序表L，编写一个时间复杂度为o(n)，空间复杂度为o(1)的算法删除线性表中所有值为x的数据
void quickDeleteValue(SqList *sq,int x)
{
int k=0;
for(int i=0;i<sq->length;i++)
{
if(sq->data[i]==x)	k++;
else sq->data[i-k]=sq->data[i];
} 
sq->length=sq->length-k;
}	
//4 有序顺序表中删除 s t之间的所有元素 
bool deleteValueBetweenSAndTOnOrderedList(SqList * sq,int s,int t)
{
	if(sq->length==0||!(t>s)) return false;
	int k=0;
	for(int i=0;i<sq->length;i++)
	{
		if(sq->data[i]>=s &&sq->data[i]<=t) k++;
		else
		{
			sq->data[i-k]=sq->data[i];
		}
	}
	sq->length=sq->length-k;
	return true;
}
//5 顺序表中删除 s 和 t 之间的所有元素
bool deleteValueBetweenSAndTOnInOrderedList(SqList * sq,int s,int t)
{
    if(sq->length==0||!(t>s)) return false;
    int k=0;
	for(int i=0;i<sq->length;i++)
	{
	if(sq->data[i]>=s && sq->data[i]<=t) k++;
	else sq->data[i-k]=sq->data[i];	
	}	
	sq->length=sq->length-k;
	return true;
} 
// 6 有序顺序表中 删除所有重复的元素
void removeDuplicateValue(SqList * sq)
{
	int k=0;
	for(int i=0;i<sq->length;i++)
	{
		if(i>0&&sq->data[i]==sq->data[i-1]) k++;
		else sq->data[i-k]=sq->data[i];
	}
	sq->length=sq->length-k; 
} 
// 7 将两个有序的顺序表合成一个有序的顺序表 
SqList * mergeToOrderList(SqList *sq1,SqList *sq2)
{
	SqList * sq3=initList();
	int i=0;
	int j=0;
	int k=0;
	while(i<sq1->length&&j<sq2->length)
	{
		if(sq1->data[i]>sq2->data[j]) 
		{
			sq3->data[k++]=sq2->data[j++];
		}
		else sq3->data[k++]=sq1->data[i++];
	}
	while(i<sq1->length)
	{
		sq3->data[k++]=sq1->data[i++];
	}
	while(j<sq2->length)
	{
		sq3->data[k++]=sq2->data[j++];
	}
	sq3->length=sq3->length+sq1->length+sq2->length;
	return sq3; 
} 
//8  已知一维数组 a[m+n]中依次存放两个线性表(a1,,,,,am)和(b1,,,,,bn) 试编写函数使(b1,,,,,bn)在 (a1,,,,,am)前
void inverseArrayAAndArrayB(int data[],int m,int n)
{
//(a1-am)逆置成(am-a1) 
for(int i=0;i<m/2;i++)
{
int t=data[i];
data[i]=data[m-i-1];
data[m-i-1]=t;	
}
for(int i=m;i<(2*m+n)/2;i++)
{
int t=data[i];
data[i]=data[m+n-1-(i-m)];
data[m+n-1-(i-m)]=t;	
} 
for(int i=0;i<(m+n)/2;i++)
{
	int t=data[i]; 
	data[i]=data[m+n-i-1];
	data[m+n-i-1]=t;
}
for(int i=0;i<m+n;i++)
{
	cout<<data[i]<<" ";
}
}
/* 9 线性表 (a1,,,an) 递增有序且顺序存储在计算机内 
设计算法最少的时间查找值为x的元素若找到与后继元素交换 否则插入 使顺序表依然有序 
*/ 
void findXAndOperate(SqList * sq,int x)
{
	bool isFind=false;
	int start=0;
	int end=sq->length-1;
	int mid; 
	while(end>=start)
	{
		mid=(start+end)/2;
		if(sq->data[mid]==x) {isFind=true;break;}
		else if(sq->data[mid]<x) {start=mid+1;}
		else end=mid-1;
	}
	if(isFind)
	{
	    if(mid+1<sq->length) 
	    {
	    	int t=sq->data[mid];
	    	sq->data[mid]=sq->data[mid+1];
	    	sq->data[mid+1]=t;
		}
	}
	else
	{
		int i;
		for( i=sq->length-1;i>=0;i--)
		{
			if(sq->data[i]>x) sq->data[i+1]=sq->data[i];
			else break;
		}
		sq->data[i+1]=x;
		sq->length++;
	}
	printList(sq);
}
/*
10 将数组中的元素顺序由(x0,x1......xn-1)变为(xp...xn-1,x0,x1...xp-1) 
*/
void reverse(int array[],int begin,int end)
{
for(int i=0;i<=(end-begin)/2;i++)
{
	int t=array[begin+i];
	array[begin+i]=array[end-i];
	array[end-i]=t;
}
}
void changeSortOfArray(int array[],int n,int p)
{
	reverse(array,0,n);
	reverse(array,0,n-1-p);
	reverse(array,n-p,n);
	for(int i=0;i<=n;i++)
	{
		cout<<array[i]<<" ";
	}
}
/*
11 有两个等长的升序序列a,b要求尽快找到a与b的中位数 
*/
int quickFindMidValue(int a[],int b[],int n)
{
	int i=0;
	int j=0;
	int count=0;
	int sum=0;
	while(true)
	{
	if(a[i]<b[j]) {
	count++;
	if(count==n) sum+=a[i];
	if(count==n+1) {sum+=a[i];break;}
    i++;
	}
	else 
	{
	count++;
	if(count==n) sum+=b[j];
	if(count==n+1) {sum+=b[j];break;}
    j++;
	}
	}
	return sum/2;
}
/* 12 （ai >0 && ai<n (0<=i<n)） 若x的元素个数为m个 m>n/2则称x为主元素
若存在主元素则输出主元素 否则输出-1 
*/ 
int getMainValue(int data[],int n)
{
	//因为ai有界采用哈希的散列思想  时间复杂度为 n 空间复杂度为 n 
	int count[n];
	for(int i=0;i<n;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		count[data[i]%n]++;
	}
	for(int i=0;i<n;i++)
	{
		if(count[data[i]%n]>n/2) return  data[i];
	}
	return -1;
}
/*
13 设定一个含n个整数的数组 求数组中未出现的最小整数 
*/
int findNotOccurenceValue(int data[],int n)
{
	bool isOccurenced[n+2];
	for(int i=1;i<=n+2;i++) isOccurenced[i]=false;
	for(int i=0;i<n;i++)
	{
		if(data[i]<=n+2) isOccurenced[data[i]]=true;
	}
	for(int i=1;i<=n+2;i++) 
	{
		if(!isOccurenced[i]) return i;
	}
} 
int main()
{
   int data[10]={1,-1,0,2,3,4,6,10,11,8};
   cout<<findNotOccurenceValue(data,10);
} 
