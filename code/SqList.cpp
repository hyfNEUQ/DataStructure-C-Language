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
//��ʼ��һ��Ϊ�յ����Ա� 
SqList * initList()
{
	SqList * sq=(struct SqList *) malloc (sizeof(struct SqList));
	sq->length=0;
	return sq; 
}
//���
int length(SqList * sq)
{
	return sq->length;
} 
//����Ԫ�� param(����,����λ��,�����ֵ) 
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
//ɾ��Ԫ�� (��ɾ���ı�,ɾ����λ��,��e������)
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
//��ӡ����
void printList(SqList *sq)
{
for(int i=0;i<sq->length;i++)
{
cout<<sq->data[i]<<" ";	
}	
cout<<endl;
} 
/*
2.2.3 �㷨�ⲿ�ֽ�� 
*/
// 1 (ɾ����С��Ԫ�أ����ɺ������ر�ɾ����Ԫ��ֵ���ճ���λ�������һ��Ԫ���)
bool deleteMinValue(SqList * sq,int & minValue)
{
	if(sq->length==0) {printf("��Ϊ��");return false;}
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
// 2 ˳���L ����Ԫ������ �ռ临�Ӷ�o(1)
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
// 3 �Գ���Ϊn��˳���L����дһ��ʱ�临�Ӷ�Ϊo(n)���ռ临�Ӷ�Ϊo(1)���㷨ɾ�����Ա�������ֵΪx������
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
//4 ����˳�����ɾ�� s t֮�������Ԫ�� 
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
//5 ˳�����ɾ�� s �� t ֮�������Ԫ��
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
// 6 ����˳����� ɾ�������ظ���Ԫ��
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
// 7 �����������˳���ϳ�һ�������˳��� 
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
//8  ��֪һά���� a[m+n]�����δ���������Ա�(a1,,,,,am)��(b1,,,,,bn) �Ա�д����ʹ(b1,,,,,bn)�� (a1,,,,,am)ǰ
void inverseArrayAAndArrayB(int data[],int m,int n)
{
//(a1-am)���ó�(am-a1) 
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
/* 9 ���Ա� (a1,,,an) ����������˳��洢�ڼ������ 
����㷨���ٵ�ʱ�����ֵΪx��Ԫ�����ҵ�����Ԫ�ؽ��� ������� ʹ˳�����Ȼ���� 
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
10 �������е�Ԫ��˳����(x0,x1......xn-1)��Ϊ(xp...xn-1,x0,x1...xp-1) 
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
11 �������ȳ�����������a,bҪ�󾡿��ҵ�a��b����λ�� 
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
/* 12 ��ai >0 && ai<n (0<=i<n)�� ��x��Ԫ�ظ���Ϊm�� m>n/2���xΪ��Ԫ��
��������Ԫ���������Ԫ�� �������-1 
*/ 
int getMainValue(int data[],int n)
{
	//��Ϊai�н���ù�ϣ��ɢ��˼��  ʱ�临�Ӷ�Ϊ n �ռ临�Ӷ�Ϊ n 
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
13 �趨һ����n������������ ��������δ���ֵ���С���� 
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
