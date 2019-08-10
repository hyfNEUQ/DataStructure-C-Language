#include <iostream>
using namespace std;
/*
���ֲ��ҷǵݹ� ����������(����������,���鳤��,�����ҵ�Ԫ��)
*/
bool binSearch(int a[],int n,int value)
{
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==value) return true;
		if(a[mid]<value) low=mid+1;
		if(a[mid]>value) high=mid-1;
	}
	return false;
}
/*
���ֲ��ҵݹ�ģʽ 
*/
bool binSearchRecurssion(int a[],int value ,int low ,int high)
{
	int mid=(low+high)/2;
	if(a[mid]==value) return true;
	if(low>high) return false;
	else
	{
		if(a[mid]<value) return binSearchRecurssion(a,value,mid+1,high);
		else return binSearchRecurssion(a,value,low,mid-1);
	}
}
/*
K�ֲ��� (����,Ҫ���ҵ�Ԫ��ֵ,k,���鳤��)
*/
bool kSearch(int a[],int value,int k,int n)
{
	int low=0;
	int high=n-1;
	while(low<high)
	{
		int i=0;
		while(i<=k)
		{
			int mid=i*(high-low+1)/k;
			if(a[mid]==value) return true;
			else if(a[mid]<value) low=mid+1;
			else if(a[mid]>value) {high=mid-1;break;}
			i++;
		}
	}
	return false;
}

int main()
{
int arrayRandomOrder[10]={78,54,89,12,5,72,6,1,62,99};
int arrayIncreaseOrder[10]={1,5,12,16,24,26,45,55,86,99};
cout<<kSearch(arrayIncreaseOrder,16,5,10);
} 
