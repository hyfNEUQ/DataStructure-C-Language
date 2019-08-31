#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include <queue>
#include <stack>
# define MaxVex 20
using namespace std;
//�� 
struct AcrNode
{
	int adjvex;
	AcrNode * nextarc;
};
//���� 
struct VNode
{
	char data;
	AcrNode * firstArc;
};
//�ڽӱ���ɵ�ͼ 
struct ALGraph
{
	VNode vertices[MaxVex];
	int vexNum,arcNum;
	int kind;
};
//��ʼ��һ���� 
AcrNode * initArcNode(int adjvex)
{
AcrNode * arcNode =( AcrNode *) malloc (sizeof(struct AcrNode));
arcNode->adjvex=adjvex;
arcNode->nextarc=NULL;
return 	arcNode;
} 
//��ʼ��һ������ 
VNode initVNode(char data)
{
	VNode vnode;
	vnode.data=data;
	vnode.firstArc=NULL;
	return vnode;
}
/*
�ֶ����������ڽӱ��ͼ 
*/
ALGraph * createALGraph()
{
	ALGraph * alGraph =(ALGraph *) malloc (sizeof(struct ALGraph));
	alGraph->vexNum=0;
	alGraph->arcNum=0;
	cout<<"----�����붥�����"<<endl;
	int Vexcount;
	cin>>Vexcount;
	while(Vexcount>alGraph->vexNum)
	{
		cout<<"������"<<alGraph->vexNum+1<<"���ڵ��ֵ"<<endl;
		char data;
		cin>>data; 
     	alGraph->vertices[alGraph->vexNum++]=initVNode(data);	
	}
	for(int i=0;i<alGraph->vexNum;i++)
	{
	cout<<"������"<<alGraph->vertices[i].data<<"���ڽӽڵ�ĸ���"<<endl;
	int n; int j=0;
	cin>>n;
	while(j<n)
	{
	cout<<"������"<<alGraph->vertices[i].data<<"��"<<j+1<<"���ڽӽڵ���±�"<<endl;
	int data;
	cin>>data; 
	AcrNode * acrNode=initArcNode(data);
	if(j==0) alGraph->vertices[i].firstArc=acrNode;
	else 
	{
		AcrNode * acrNodePre=alGraph->vertices[i].firstArc;
		while(acrNodePre->nextarc!=NULL) acrNodePre=acrNodePre->nextarc;
		acrNodePre->nextarc=acrNode;
	}
	j++;
	}	
	} 
	return alGraph;
}
/*
����һ������ͼ
ͼ�ĸ�ʽ����
         A
	  	/\ 
	   B  C	 
*/
ALGraph * createTreeGraph()
{
	ALGraph * alGraph=(ALGraph *) malloc (sizeof(struct ALGraph));
	alGraph->vexNum=3;
	alGraph->arcNum=2;
	for(int i=0;i<3;i++)
	{
	alGraph->vertices[i]=initVNode(char(i+'A'));
	}
	AcrNode * arcAB=initArcNode(1);
	AcrNode * arcAC=initArcNode(2);
	alGraph->vertices[0].firstArc=arcAB;
	arcAB->nextarc=arcAC;
	AcrNode * arcBA=initArcNode(0);
	alGraph->vertices[1].firstArc=arcBA;
	AcrNode * arcCA=initArcNode(0);
	alGraph->vertices[2].firstArc=arcCA;
	return alGraph;
} 
/*
����һ���̶���ͼ
ͼ�ĸ�ʽ����
      G  A--B-H
	  \	/\ /
	   C  D
	  /\ /
	 F  E  I-J
*/
ALGraph * createFixedALGraph()
{
	ALGraph * alGraph=(ALGraph *) malloc (sizeof(struct ALGraph));
	alGraph->vexNum=10;
	alGraph->arcNum=6;
	for(int i=0;i<10;i++)
	{
	alGraph->vertices[i]=initVNode(char(i+'A'));
	}
	AcrNode * arcAB=initArcNode(1);
	alGraph->vertices[0].firstArc=arcAB;
	AcrNode * arcAC=initArcNode(2);
	arcAB->nextarc=arcAC;
	AcrNode * arcAD=initArcNode(3);
	arcAC->nextarc=arcAD;
	AcrNode * arcBA=initArcNode(0);
	alGraph->vertices[1].firstArc=arcBA;
	AcrNode * arcBD=initArcNode(3);
	AcrNode * arcBH=initArcNode(7);
	arcBA->nextarc=arcBD;
	arcBD->nextarc=arcBH;
	AcrNode * arcCA=initArcNode(0);
	AcrNode * arcCE=initArcNode(4);
	AcrNode * arcCF=initArcNode(5);
	AcrNode * arcCG=initArcNode(6);
	alGraph->vertices[2].firstArc=arcCA;
	arcCA->nextarc=arcCE;
	arcCE->nextarc=arcCF; 
	arcCF->nextarc=arcCG;
	AcrNode * arcDA=initArcNode(0);
	AcrNode * arcDB=initArcNode(1);
	AcrNode * arcDE=initArcNode(4);
	alGraph->vertices[3].firstArc=arcDA;
	arcDA->nextarc=arcDB;
	arcDB->nextarc=arcDE;
	AcrNode * arcEC=initArcNode(2);
	AcrNode * arcED=initArcNode(3);
	alGraph->vertices[4].firstArc=arcEC;
	arcEC->nextarc= arcED;
	AcrNode * arcFC=initArcNode(2);
	alGraph->vertices[5].firstArc=arcFC;
	AcrNode * arcGC=initArcNode(2);
	alGraph->vertices[6].firstArc=arcGC;
	AcrNode * arcHB=initArcNode(1);
	alGraph->vertices[7].firstArc=arcHB;
	AcrNode * arcIJ=initArcNode(9);
	AcrNode * arcJI=initArcNode(8);
	alGraph->vertices[8].firstArc=arcIJ;
	alGraph->vertices[9].firstArc=arcJI;
	return alGraph;
} 
/* 
����ڵ� (�����Ƿ����ɹ�)
*/
bool insertVex(ALGraph * alGraph,VNode vNode) 
{
	if(alGraph->vexNum>=MaxVex) return false;
	else alGraph->vertices[alGraph->vexNum++]= vNode;
	return true;
}
/*
����graphͼ��v�ĵ�һ���ڽӶ��� 
*/ 
int firstAdjVex(ALGraph * alGraph,int  v)
{
return alGraph->vertices[v].firstArc->adjvex;
} 
/* 
ͼ����ȱ��� 
*/
bool visited[MaxVex];
void DFS(ALGraph *alGraph,int i)
{
	VNode v=alGraph->vertices[i]; 
	visited[i]=true;
	//����v
	printf("%c",v.data);
	AcrNode *arc=v.firstArc;
	while(arc!=NULL)
	{
	if(!visited[arc->adjvex])DFS(alGraph,arc->adjvex);
	arc=arc->nextarc;	
	}
}
void DFSTraverse(ALGraph *alGraph)
{
	for(int i=0;i<alGraph->vexNum;i++)
	{
	visited[i]=false;	
	} 
	for(int i=0;i<alGraph->vexNum;i++)
	{
		if(!visited[i]) DFS(alGraph,i);
	}
}
/*
��ȱ��� 
*/
void BFS(ALGraph * alGraph,int i)
{
	queue<VNode> queue;
	queue.push(alGraph->vertices[i]);
	visited[i]=true;
	while(!queue.empty())
	{
		VNode v=queue.front();
		queue.pop();
		cout<<v.data<<endl;
		AcrNode * acrNode= v.firstArc;
		while(acrNode!=NULL)
		{
		if(!visited[acrNode->adjvex]) {visited[acrNode->adjvex]=true;queue.push(alGraph->vertices[acrNode->adjvex]);} 
		acrNode=acrNode->nextarc;	
		} 
	}
}
void BFSTraverse(ALGraph * alGraph)
{
	 cout<<"-------��ȱ�����ʼ-------------"<<endl;
	 for(int i=0;i<alGraph->vexNum;i++)
	 {
	 	visited[i]=false;
	 }
	 for(int i=0;i<alGraph->vexNum;i++)
	 {
	 	if(!visited[i]) BFS(alGraph,i);
	 } 
	 cout<<"-------��ȱ�������-------------"<<endl;
}
/*
д��ͼ���ڽӱ��ڽӾ�����㷨 
*/
void convertToMatrix(ALGraph * alGraph)
{
	int data[alGraph->vexNum][alGraph->vexNum];
	for(int i=0;i<alGraph->vexNum;i++)
	{
		for(int j=0;j<alGraph->vexNum;j++)
		{
		data[i][j]=0;	
		}
		AcrNode * acrNode=alGraph->vertices[i].firstArc; 
		while(acrNode!=NULL)
		{
			data[i][acrNode->adjvex]=1;
			acrNode=acrNode->nextarc;
		}
	}
	cout<<"ת�����Ϊ��"<<endl;
	for(int i=0;i<alGraph->vexNum;i++)
	{
	for(int j=0;j<alGraph->vexNum;j++)
	{
	cout<<data[i][j];	
	}	
	cout<<endl;
	} 
}
/*
������ȵķǵݹ��㷨 
*/
void DFSTraverseBasedOnStack(ALGraph * alGraph)
{
	cout<<"�ǵݹ�������ȱ�����ʼ"<<endl;
	for(int i=0;i<alGraph->vexNum;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<alGraph->vexNum;i++)
	{
		if(!visited[i])
		{
			stack<int > s;
			s.push(i);
			while(!s.empty())
			{
				int top=s.top();
				s.pop();
				visited[top]=true;
				printf("%c",alGraph->vertices[top].data);
				AcrNode *acrNode=alGraph->vertices[top].firstArc; 
				while(acrNode!=NULL)
				{
					if(!visited[acrNode->adjvex])s.push(acrNode->adjvex);
					visited[acrNode->adjvex]=true;
					acrNode=acrNode->nextarc;
				}
			}
		}
	} 
	cout<<"�ǵݹ�������ȱ�������"<<endl;
}
/*
�ж�ͼ�Ƿ�Ϊ����ͼΪ�������� 1. �߱���ͨ�� 2. ����ȫ������������ ����=2*��n-1�� 
*/
void DFSForTree(ALGraph *graph,int i,int & vexNum,int & edgeNum)
{
	//����i���
	visited[i]=true;
	vexNum++;
	printf("%c",graph->vertices[i].data);
	AcrNode *arc=graph->vertices[i].firstArc;
	while(arc!=NULL)
	{
		if(!visited[arc->adjvex]) DFSForTree(graph,arc->adjvex,vexNum,edgeNum);
		edgeNum++;
		arc=arc->nextarc;
	}
}
bool isTree(ALGraph *graph)
{
//������¼�Ѿ����ʵĽ�������ߵĸ��� 
int vexNum=0;
int edgeNum=0;	
for(int i=0;i<graph->vexNum;i++)  visited[i]=false;
DFSForTree(graph,0,vexNum,edgeNum);
cout<<"vexNum : "<<vexNum<<" edgeNum :"<<edgeNum/2<<endl;
if(graph->vexNum>vexNum||edgeNum!=2*(vexNum-1)) return false;
return true;
} 
/*
����������жϽ��vi��vj֮���Ƿ����·�� 
*/ 
bool isHavePathBeteweenViAndVjByDFS(ALGraph *graph,int vi,int vj)
{
	cout<<"-----------��������ȱ����ж��Ƿ����·��------------"<<endl; 
	for(int i=0;i<graph->vexNum;i++) visited[i]=false;
	stack <int> s;
	s.push(vi);
	visited[vi]=true;
	while(!s.empty())
	{
	int v=s.top();
	s.pop();
	if(v==vj) return true;
	AcrNode * acrNode=graph->vertices[v].firstArc;	
	while(acrNode!=NULL)
	{
	if(!visited[acrNode->adjvex]) s.push(acrNode->adjvex);
	visited[acrNode->adjvex]=true;
	acrNode=acrNode->nextarc;
	}
	}	
	return false;	 
}
/*
�ù�������ж�vi��vj֮���Ƿ����·�� 
*/
bool isHavePathBetweenViAndVjByBFS(ALGraph *graph,int vi,int vj)
{
	cout<<"-------------�ù�����ȱ����ķ����ж�"<<graph->vertices[vi].data<<"��"<<graph->vertices[vj].data<<"�Ƿ����·��--------"<<endl;
	queue <int> queue;
	        for(int i=0;i<graph->vexNum;i++) visited[i]=false;
			queue.push(vi);
			visited[vi]=true;
			while(!queue.empty())
			{
				int v=queue.front();
				if(v==vj) return true;
				queue.pop();
				AcrNode * acrNode=graph->vertices[v].firstArc;	
				while(acrNode!=NULL)
				{
					if(!visited[acrNode->adjvex]) queue.push(acrNode->adjvex);
					visited[acrNode->adjvex]=true; 
					acrNode=acrNode->nextarc;
				}
			}
			return false;
}
/*
����ʹ���ڽӱ�洢��ͼ�����һ���㷨����Ӷ���Vi������Vj��ȫ��·�� 
void PrintAllPathBetweenViAndVj(ALGraph *graph,int vi,int vj,int path[],int d)
{
int w,i;
AcrNode *p;
d++;
path[d]=u;
visited[u]=1;
if(u==v) print(path[]);
p=graph->vertices[u].firstArc;
while(p!=NULL)
{
w=p->adjvex;
if(visited[w]==0) 	PrintAllPathBetweenViAndVj(graph,w,V,path,d);
p=p->nextarc;
}
visited[u]=0;	
} 
*/
/*
��Ȩͼ��Դ���·���㷨 
*/   
int main()
{
ALGraph *graph=createFixedALGraph();	
DFSTraverseBasedOnStack(graph);
}
