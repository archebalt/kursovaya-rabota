#pragma once
#include <iostream>
#include <string>
#include"Lists_Node_Edge.h"

#include <fstream>
using namespace std;

class FordFulkerson
{
public:
	int alghoritm(string graph)
	{
		edgeList AllEdges;
		ifstream in(graph);
		int weight1;
		string LineFromFile;
		if (in.is_open())
		{
			while (getline(in, LineFromFile))
			{
				int j = 0;
				string information[3];
				for (int i = 0; i < LineFromFile.size(); i++)
				{
					if (LineFromFile[i] == ' ')
					{
						i++;
						j++;
					}

					information[j] += LineFromFile[i];
				}
				weight1 = stoi(information[2]);
				AllEdges.push_back(information[0], information[1], weight1);
				AllEdges.push_back(information[1], information[0], 0);
			}
		}
		in.close();
		
		string Begin = "S";
		string End = "T";
		NodeList AllNodes;
		edge* MaxEdgeFromVert;
		Node* CurGraphNode;
		int result = 0;
		int sup = 0;
		do
		{
			AllNodes.push_back(Begin, 0);
			edge* CurEdge = AllEdges.MaxEdgeFromVertex(Begin,AllNodes.ShowHead());
			int maxDistToVert = CurEdge->weight;
			do
			{
				CurGraphNode = AllNodes.ShowHead();
				maxDistToVert = 0;
				while (CurGraphNode != nullptr)
				{ 
					MaxEdgeFromVert = AllEdges.MaxEdgeFromVertex(CurGraphNode->vertex, AllNodes.ShowHead()); 
					if (MaxEdgeFromVert != nullptr) 
					{
						if (MaxEdgeFromVert->weight + CurGraphNode->maxDistTo > maxDistToVert)
						{
							CurEdge = MaxEdgeFromVert; 
							maxDistToVert = MaxEdgeFromVert->weight + CurGraphNode->maxDistTo;  
						}

					}
					CurGraphNode = CurGraphNode->next;
				}
				if (maxDistToVert == 0)
					break;
				Node* previousNode = AllNodes.Find(CurEdge->from); // проверенная вершина от которой найдено минимальное расстояние
				AllNodes.push_back(CurEdge->To, previousNode->maxDistTo + CurEdge->weight); // добавляем вершину в список найденных
				CurEdge->ToVertexProcessed = true;
				maxDistToVert = previousNode->maxDistTo + CurEdge->weight;

			} while (CurEdge->To != End);
			if (maxDistToVert != 0)
			{
				maxDistToVert = AllEdges.minEdgeOfPath();
				AllEdges.newWeightOfEdges(maxDistToVert);
			}
			sup = maxDistToVert;
			result += maxDistToVert;
			AllNodes.DeleteAll();
			AllEdges.makeAllEdgesUncheked();
		} while (sup != 0);
			return result;
	}
};