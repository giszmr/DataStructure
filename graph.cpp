#include <iostream>
#include <cstdio>
#include "graph.h"


using namespace DataStructureTest;




Status MyGraph::CreateLGraph(LGraph* pGraph, GraphKind graphKind)
{
	Status st = OK;
	switch (graphKind)
	{
	case DG:
		st = CreateDG(pGraph);
		break;
	case UDG:
		st = CreateUDG(pGraph);
		break;
	default:
		st = ERROR;
		break;
	}
	return st;
}

Status MyGraph::CreateDG(LGraph* pGraph)
{
	ArcNode* pAdjacencyList[VERTEX_MAX_NUM + 1] ;

	printf("Input number of vertex: ");
	std::cin >> pGraph->verNum;
	printf("Input number of arc: ");
	std::cin >> pGraph->arcNum;

	printf("Input value of each vertex: ");
	for (int i = 1; i <= pGraph->verNum; i++)
	{
		std::cin >> pGraph->vertexs[i].data;
		pGraph->vertexs[i].firstArc = nullptr;
		pAdjacencyList[i] = nullptr; //initialize
	}

	printf("Input arcs, and create adjacency: ");
	int v1 = 0;
	int v2 = 0;
	
	for (int j = 1; j < pGraph->arcNum; j++)
	{
		printf("Input neighboring nodes, separated by a space, to add an arc: ");
		std::cin >> v1 >> v2;
		int idx1 = LocateVex(pGraph, v1);
		int idx2 = LocateVex(pGraph, v2);
		ArcNode* pArcNode = new ArcNode();
		if (!pArcNode)
			return ERROR;
		pArcNode->adjvex = idx2;
		pArcNode->nextArc = nullptr;
		if (pAdjacencyList[idx1] == nullptr)
			pGraph->vertexs[idx1].firstArc = pArcNode;
		else
			pAdjacencyList[idx1]->nextArc = pArcNode;
		pAdjacencyList[idx1] = pArcNode;
	}

	return OK;
}

Status MyGraph::CreateUDG(LGraph* pGraph)
{
	ArcNode* pAdjacencyList[VERTEX_MAX_NUM + 1];

	printf("Input number of vertex: ");
	std::cin >> pGraph->verNum;
	printf("Input number of arc: ");
	std::cin >> pGraph->arcNum;

	printf("Input value of each vertex: ");
	for (int i = 1; i <= pGraph->verNum; i++)
	{
		std::cin >> pGraph->vertexs[i].data;
		pGraph->vertexs[i].firstArc = nullptr;
		pAdjacencyList[i] = nullptr;
	}

	printf("Input arcs, and create adjacency: ");
	int v1 = 0;
	int v2 = 0;
	for (int j = 1; j < pGraph->arcNum; j++)
	{
		printf("Input neighboring nodes, separated by a space, to add an arc: ");
		std::cin >> v1 >> v2;
		int idx1 = LocateVex(pGraph, v1);
		int idx2 = LocateVex(pGraph, v2);

		//add adjacenct list to pGraph->vertexs[idx1]
		ArcNode* pArcNode = new ArcNode();
		if (!pArcNode)
			return ERROR;
		pArcNode->adjvex = idx2;
		pArcNode->nextArc = nullptr;
		if (pAdjacencyList[idx1] == nullptr)
			pGraph->vertexs[idx1].firstArc = pArcNode;
		else
			pAdjacencyList[idx1]->nextArc = pArcNode;
		pAdjacencyList[idx1] = pArcNode;

		//add adjacenct list to pGraph->vertexs[idx2]
		ArcNode* pCurrArcNode = new ArcNode();
		if (!pCurrArcNode)
			return ERROR;
		pCurrArcNode->adjvex = idx1;
		pCurrArcNode->nextArc = nullptr;
		if (pAdjacencyList[idx2] == nullptr)
			pGraph->vertexs[idx2].firstArc = pCurrArcNode;
		else
			pAdjacencyList[idx2]->nextArc = pCurrArcNode;
		pAdjacencyList[idx2] = pCurrArcNode;
	}

	return OK;
}

int MyGraph::LocateVex(LGraph* pGraph, VertexType vertex)
{
	for (int i = 1; i < pGraph->verNum; i++)
	{
		if (pGraph->vertexs[i].data == vertex)
			return i;
	}
	return 0;
}

Status MyGraph::FirstAdjVex(LGraph graph, VertexType vertex)
{
	return Status();
}

Status MyGraph::NextAdjVex(LGraph graph, VertexType vertex1, VertexType vertex2)
{
	return Status();
}

Status MyGraph::PutVex(LGraph* pGraph, VertexType vertex1, VertexType vertex2)
{
	return Status();
}

Status MyGraph::InsertVex(LGraph* pGraph, VertexType vertex)
{
	if (pGraph->verNum == VERTEX_MAX_NUM)
		return ERROR;
	pGraph->verNum++;
	pGraph->vertexs[pGraph->verNum].data = vertex;
	pGraph->vertexs[pGraph->verNum].firstArc = nullptr;
	return OK;
}

Status MyGraph::InsertArc(LGraph* pGraph, VertexType vertex1, VertexType vertex2)
{
	int idx1 = LocateVex(pGraph, vertex1);
	int idx2 = LocateVex(pGraph, vertex2);
	ArcNode* pArcNode = new ArcNode;
	if (!pArcNode)
		return ERROR;
	pArcNode->adjvex = idx2;
	ArcNode* pCurrArcNode = pGraph->vertexs[idx1].firstArc;  //cursor
	if (!pCurrArcNode || pCurrArcNode->adjvex > idx2)
	{
		//Insert pArcNode before idx2
		pArcNode->nextArc = pGraph->vertexs[idx1].firstArc;
		pGraph->vertexs[idx1].firstArc = pArcNode;
	}
	else
	{
		//find the proper place for pArcNode
		while (pCurrArcNode->nextArc && pCurrArcNode->adjvex < idx2)
		{
			pCurrArcNode = pCurrArcNode->nextArc;
		}
		pArcNode->nextArc = pCurrArcNode->nextArc;
		pCurrArcNode->nextArc = pArcNode;
	}

	//If it's undirect graph, there is another path from vertex2 to vertex1
	if (pGraph->kind = UDG)
	{
		ArcNode* pArcNode = new ArcNode;
		if (!pArcNode)
			return ERROR;
		pArcNode->adjvex = idx1;
		ArcNode* pCurrArcNode = pGraph->vertexs[idx1].firstArc;  //cursor
		if (!pCurrArcNode || pCurrArcNode->adjvex > idx1)
		{
			//Insert pArcNode before idx2
			pArcNode->nextArc = pGraph->vertexs[idx1].firstArc;
			pGraph->vertexs[idx1].firstArc = pArcNode;
		}
		else
		{
			//find the proper place for pArcNode
			while (pCurrArcNode->nextArc && pCurrArcNode->adjvex < idx1)
			{
				pCurrArcNode = pCurrArcNode->nextArc;
			}
			pArcNode->nextArc = pCurrArcNode->nextArc;
			pCurrArcNode->nextArc = pArcNode;
		}
	}

	return Status();
}

void MyGraph::OutputLGraph(LGraph* pGraph)
{
	if (!pGraph->verNum && !pGraph->arcNum)
	{
		printf("Empty graph.");
	}
	else
	{
		for (int i = 1; i < pGraph->verNum; i++)
		{
			printf("%d->", pGraph->vertexs[i].data);
			ArcNode* pArcNode = pGraph->vertexs[i].firstArc;
			while (pArcNode)
			{
				printf(" %d", pGraph->vertexs[pArcNode->adjvex].data);
				pArcNode = pArcNode->nextArc;
			}
			printf("\n");
		}
	}
}

