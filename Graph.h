/*
*****************************************
Jason Katz
ECE-165 Project 3: Dijkstra's Algorithm

Graph implementation
with Dijkstra's algorithm built in

File: Graph.h
*****************************************
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <list>
#include "Hash.h"

class graph {

public:

	// Default constructor
	// Initializes graph with no nodes or edges
	graph();

	// Checks if the graph contains specified vertex
	bool contains(std::string);

	// Inserts a vertex into the graph
	// Returns 0 on success
	// 1 if the vertex already exists in the graph
	// 2 if there is some other error
	int insertVertex(std::string);

	// Inserts an edge into the graph between two vertices with a given cost
	// Returns 0 on success
	// 1 if either vertex doesn't exist in the graph
	int insertEdge(std::string, std::string, int);

	// Execute Dijkstra's algorithm on the graph
	// Rearranges the state of the graph according to the algorithm
	// Finds shortest paths from provided starting vertex
	void shortestPathDijkstra(std::string);

	// Generates graph object from provided file
	static graph generateFromFile(std::string);

	// Writes graph data to provided file, with an indicator of the startingVertex
	void writeToFile(std::string);

private:

	// vertex class
	// Represents a vertex in the graph
	class vertex {
	public:
		// edge struct
		// Represents an edge in the graph with a destination and a cost
		class edge {
		public:
			edge(vertex *, int);

			vertex * destination;
			int cost;
		};

		vertex();
		vertex(std::string);
		void insertEdge(vertex *, int);
		
		std::string name;
		std::list<edge> adjacentEdges;

		// Dijkstra's algorithm utility variables
		bool known;
		int distance;
		vertex * lastVertex;
	};

	hashTable vertexLookup;
	std::list<vertex *> vertexList;

};

#endif