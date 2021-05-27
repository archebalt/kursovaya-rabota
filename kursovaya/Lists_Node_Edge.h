#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
	string vertex;
	int maxDistTo;
	Node* next;
	Node()
	{
		vertex = "";
		maxDistTo = 0;
		next = nullptr;
	}
};

class NodeList
{
	Node* head;
	Node* tail;
	int size;
public:
	NodeList()
	{
		tail = head = nullptr;
		size = 0;
	}
	void push_back(string NodeGraph, int max)
	{
		Node* current = new Node();
		if (head == nullptr)
		{
			tail = head = current;
			current->vertex = NodeGraph;
			current->maxDistTo = max;
		}
		else
		{
			tail->next = current;
			tail = current;
			current->vertex = NodeGraph;
			current->maxDistTo = max;
		}
		size++;
	}
	void DeleteAll()
	{
		Node* current = head;
		while (current != tail)
		{
			Node* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
		tail = head = nullptr;
		size = 0;
	}
	Node* ShowHead()
	{
		return head;
	}
	Node* Find(string From)
	{
		Node* current = head;
		while (current->vertex != From)
		{
			current = current->next;
		}
		return current;
	}
	~NodeList()
	{
		if (head != nullptr)
		{
			Node* current = head;
			while (current != tail)
			{
				Node* sup = current->next;
				delete current;
				current = sup;
			}
			delete tail;
		}
	}
};

class edge
{
public:
	string from;
	string To;
	int weight;
	edge* next;
	bool ToVertexProcessed;
	edge()
	{
		from = "";
		To = "";
		weight = 0;
		next = nullptr;
		ToVertexProcessed = false;
	}
};

class edgeList
{
	edge* head;
	edge* tail;
	int Size;
public:
	edgeList()
	{
		tail = head = nullptr;
		Size = 0;
	}
	void push_back(string from, string To, int weight)
	{
		edge* current = new edge();
		current->from = from;
		current->To = To;
		current->weight = weight;
		if (head == nullptr)
		{
			tail = head = current;
			current->next = nullptr;
		}
		else
		{
			tail->next = current;
			tail = current;
		}
		Size++;
	}
	bool IsCheckedVertex(string To, Node *Head) 
	{
		Node* current = Head;
		while (current != nullptr) 
		{
			if (current->vertex == To) 
				return true;
			current = current->next;
		}
		return false;
	}
	int minEdgeOfPath()
	{
		int min = INT_MAX;
		edge* current = head;
		while (current != nullptr)
		{
			if (current->ToVertexProcessed == true) 
			{
				if (current->weight < min)
					min = current->weight;
			}
			current = current->next;
		}
		return min;
	}
	edge* reverseDirection(string To, string From)
	{
		edge* current = head;
		while (current != nullptr)
		{
			if ((current->To == To) && (current->from == From))
				break;
			current = current->next;
		}
		return current;
	}
	void newWeightOfEdges(int changesTheWeight)
	{
		edge* current = head;
		while (current != nullptr)
		{
			if ((current->ToVertexProcessed == true)) 
			{
				edge* reverseEdge = reverseDirection(current->from, current->To);
				reverseEdge->weight += changesTheWeight;
				current->weight = current->weight - changesTheWeight; 
			}
			current = current->next;
		}
	}
	void makeAllEdgesUncheked()
	{
		edge* current = head;
		while (current != nullptr)
		{
			current->ToVertexProcessed = false;
			current = current->next;
		}
	}
	edge* MaxEdgeFromVertex(string from, Node *Head)
	{
		edge* current = head;
		edge* SearchMaxTo = nullptr;
		int min = -1;
		
		for (int i = 0; i < Size; i++)
		{
			if (current->from == from)
			{
				if (current->weight > min && (IsCheckedVertex(current->To, Head) == false))
				{
					min = current->weight;
					SearchMaxTo = current;
				}
			}
			current = current->next;
		}
		return SearchMaxTo;
	}

	~edgeList()
	{
		edge* current = head;
		while (current != tail)
		{
			edge* sup = current->next;
			delete current;
			current = sup;
		}
		delete tail;
		Size = 0;
	}
};