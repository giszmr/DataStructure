#ifndef _GRAPH_H_
#define _GRAPH_H_


#pragma once

namespace DataStructureTest
{
	const int OK = 1;
	const int NOK = 0;
	const int ERROR = -1;
	const int VERTEX_MAX_NUM = 100;

	typedef enum
	{
		DG,   //directed graph
		UDG   //undirected graph
	}GraphKind;

	typedef int Status;
	typedef int QElementType;
	typedef int VertexType;

	typedef struct QNode
	{
		QElementType data;
		struct QNode* next;
	}QNode;

	typedef struct LinkQueue
	{
		QNode* front;
		QNode* rear;
	}LinkQueue;

	typedef struct ArcNode   //node of arc
	{
		int adjvex;         //vertex that this arc points to
		ArcNode* nextArc;   //pointer of next arc
	}ArcNode;



	typedef	struct VNode
	{
		VertexType data;
		ArcNode* firstArc;

		VNode() :data(0), firstArc(nullptr)
		{
		}
	}VNode;

	typedef struct LGraph
	{
		VNode vertexs[VERTEX_MAX_NUM + 1];
		int verNum;   //number of vertex
		int arcNum;   //number of arc
		GraphKind kind;
		LGraph() :verNum(0), arcNum(0), kind(DG)
		{
		}
	}LGraph;

	class MyGraph
	{
	public:
		Status CreateLGraph(LGraph* pGraph, GraphKind graphKind);
		Status CreateDG(LGraph* pGraph);
		Status CreateUDG(LGraph* pGraph);
		int LocateVex(LGraph* pGraph, VertexType vertex);
		Status FirstAdjVex(LGraph graph, VertexType vertex);
		Status NextAdjVex(LGraph graph, VertexType vertex1, VertexType vertex2);
		Status PutVex(LGraph* pGraph, VertexType vertex1, VertexType vertex2);
		Status InsertVex(LGraph* pGraph, VertexType vertex);
		Status InsertArc(LGraph* pGraph, VertexType vertex1, VertexType vertex2);
	private:
		LGraph lg;
		Status visisted[VERTEX_MAX_NUM + 1];
		void OutputLGraph(LGraph* pGraph);
	};




}


#endif