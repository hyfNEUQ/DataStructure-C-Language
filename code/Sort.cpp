#include <iostream>
using namespace std;
//´òÓ¡ÅÅĞòºóµÄ½á¹û 
void print(int data[],int n)
{
for(int i=0;i<n;i++) cout<<data[i]<<" < ";	
cout<<endl;
}
//²åÈëÅÅĞò
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
//Ñ¡ÔñÅÅĞò
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
//Ã°ÅİÅÅĞò
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
//Ï£¶ûÅÅĞò
void shellSort(int data[],int n)
{
for(int gap=n/2;gap>0;gap=gap/2)
{
	int i=0;
	while(i*gap<n)
	{
		int j=i-1;
		while(j>=0)
		{
			if(data[(j+1)*gap]<data[j*gap]) 
			{
			int t=data[(j+1)*gap];
			data[(j+1)*gap]=data[j*gap];
			data[j*gap]=t;	
			j--;
			} 
			else break;
		}
		i++;
	}
}
print(data,n);	
} 
//ÕÛ°ë²åÈëÅÅĞò(Ñ°ÕÒ²åÈëÎ»ÖÃÊ± Ê¹ÓÃÕÛ°ë²éÕÒ·¨)
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
//¶Ôhigh+1½øĞĞÅ²¶¯
int t=data[i];
for(int j=i;j>high+1;j--)
{
	data[j]=data[j-1];
}
data[high+1]=t;
}
print(data,n);	
}
//¿ìËÙÅÅĞò
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
//¶ÑÅÅĞò (¹¹Ôì¼«Ğ¡¶Ñ)
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
//¶ÑÅÅĞò 
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
int main()
{
	int data[15]={1,54,32,12,14,4,14,18,23,16,45,99,15,17,16};
	//insertSort(data,15);
	//pickMinSort(data,15);
	//bubbleSort(data,15);
	//shellSort(data,15);
	//binInsertSort(data,15);
	//quickSort(data,0,14);
	heapSort(data,14);
} 
