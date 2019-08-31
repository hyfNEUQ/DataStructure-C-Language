#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include <queue>
#include <stack>
# define MaxVex 20
using namespace std;
//边 
struct AcrNode
{
	int adjvex;
	AcrNode * nextarc;
};
//顶点 
struct VNode
{
	char data;
	AcrNode * firstArc;
};
//邻接表组成的图 
struct ALGraph
{
	VNode vertices[MaxVex];
	int vexNum,arcNum;
	int kind;
};
//初始化一条边 
AcrNode * initArcNode(int adjvex)
{
AcrNode * arcNode =( AcrNode *) malloc (sizeof(struct AcrNode));
arcNode->adjvex=adjvex;
arcNode->nextarc=NULL;
return 	arcNode;
} 
//初始化一个定点 
VNode initVNode(char data)
{
	VNode vnode;
	vnode.data=data;
	vnode.firstArc=NULL;
	return vnode;
}
/*
手动建立基于邻接表的图 
*/
ALGraph * createALGraph()
{
	ALGraph * alGraph =(ALGraph *) malloc (sizeof(struct ALGraph));
	alGraph->vexNum=0;
	alGraph->arcNum=0;
	cout<<"----请输入顶点个数"<<endl;
	int Vexcount;
	cin>>Vexcount;
	while(Vexcount>alGraph->vexNum)
	{
		cout<<"请输入"<<alGraph->vexNum+1<<"个节点的值"<<endl;
		char data;
		cin>>data; 
     	alGraph->vertices[alGraph->vexNum++]=initVNode(data);	
	}
	for(int i=0;i<alGraph->vexNum;i++)
	{
	cout<<"请输入"<<alGraph->vertices[i].data<<"的邻接节点的个数"<<endl;
	int n; int j=0;
	cin>>n;
	while(j<n)
	{
	cout<<"请输入"<<alGraph->vertices[i].data<<"第"<<j+1<<"个邻接节点的下标"<<endl;
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
返还一个树的图
图的格式如下
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
返还一个固定的图
图的格式如下
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
插入节点 (返回是否插入成功)
*/
bool insertVex(ALGraph * alGraph,VNode vNode) 
{
	if(alGraph->vexNum>=MaxVex) return false;
	else alGraph->vertices[alGraph->vexNum++]= vNode;
	return true;
}
/*
返回graph图中v的第一个邻接定点 
*/ 
int firstAdjVex(ALGraph * alGraph,int  v)
{
return alGraph->vertices[v].firstArc->adjvex;
} 
/* 
图的深度遍历 
*/
bool visited[MaxVex];
void DFS(ALGraph *alGraph,int i)
{
	VNode v=alGraph->vertices[i]; 
	visited[i]=true;
	//访问v
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
广度遍历 
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
	 cout<<"-------广度遍历开始-------------"<<endl;
	 for(int i=0;i<alGraph->vexNum;i++)
	 {
	 	visited[i]=false;
	 }
	 for(int i=0;i<alGraph->vexNum;i++)
	 {
	 	if(!visited[i]) BFS(alGraph,i);
	 } 
	 cout<<"-------广度遍历结束-------------"<<endl;
}
/*
写出图从邻接表到邻接矩阵的算法 
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
	cout<<"转换结果为："<<endl;
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
深度优先的非递归算法 
*/
void DFSTraverseBasedOnStack(ALGraph * alGraph)
{
	cout<<"非递归深度优先遍历开始"<<endl;
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
	cout<<"非递归深度优先遍历结束"<<endl;
}
/*
判断图是否为树（图为树的条件 1. 具备连通性 2. 满足全部顶点遍历完后 边数=2*（n-1） 
*/
void DFSForTree(ALGraph *graph,int i,int & vexNum,int & edgeNum)
{
	//访问i结点
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
//用来记录已经访问的结点个数与边的个数 
int vexNum=0;
int edgeNum=0;	
for(int i=0;i<graph->vexNum;i++)  visited[i]=false;
DFSForTree(graph,0,vexNum,edgeNum);
cout<<"vexNum : "<<vexNum<<" edgeNum :"<<edgeNum/2<<endl;
if(graph->vexNum>vexNum||edgeNum!=2*(vexNum-1)) return false;
return true;
} 
/*
用深度优先判断结点vi与vj之间是否存在路径 
*/ 
bool isHavePathBeteweenViAndVjByDFS(ALGraph *graph,int vi,int vj)
{
	cout<<"-----------用深度优先遍历判断是否存在路径------------"<<endl; 
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
用广度优先判断vi与vj之间是否存在路径 
*/
bool isHavePathBetweenViAndVjByBFS(ALGraph *graph,int vi,int vj)
{
	cout<<"-------------用广度优先遍历的方法判断"<<graph->vertices[vi].data<<"与"<<graph->vertices[vj].data<<"是否存在路径--------"<<endl;
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
对于使用邻接表存储的图，设计一个算法输出从定点Vi到定点Vj的全部路径 
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
无权图单源最短路径算法 
*/   
int main()
{
ALGraph *graph=createFixedALGraph();	
DFSTraverseBasedOnStack(graph);
}
