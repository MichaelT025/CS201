#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <queue>
#include <utility>

class Vertex {
public:
	bool visited;
	int distance;
	int previous;
	int finish;
	std::list<int> adj;
};

class Graph {
public:
	Graph(int V, int E, std::pair<int, int> *edges) {
		_V = V;
		_E = E;
		vertices = new Vertex[_V];
		for (int i = 0; i < _V; i++) {
                    vertices[i].visited = false;
                    vertices[i].distance = 65535; // Instead using INFINITY, you can use a large int number to initialize your graph
                    vertices[i].previous = -1;
		}
		for (int i = 0; i < _E; i++) {
		    addEdge(edges[i].first, edges[i].second);
		}
	}

	virtual ~Graph() {
		for (int i=0; i<_V; ++i) {
		    auto adj = vertices[i].adj;
		    adj.clear(); // clear list
		}

		delete[] vertices; // delete array of vertices
	}

	int V() {
		return _V;
	}

	int E() {
		return _E;
	}

	void addEdge(int u, int v) {
		vertices[u].adj.push_back(v);
	}

	std::list<int> getEdges(int u) {
		return vertices[u].adj;
	}

	int degree(int u) {
		return vertices[u].adj.size();
	}

	void bfs(int s) {
		for (int i = 0; i < _V; ++i) {
			vertices[i].visited = false;
			vertices[i].distance = 65535;
			vertices[i].previous = -1;
			vertices[i].finish = 0;
		}

		if (s < 0 || s >= _V) {
			return;
		}

		std::queue<int> q;
		vertices[s].visited = true;
		vertices[s].distance = 0;
		q.push(s);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (const auto& v : vertices[u].adj) {
				if (!vertices[v].visited) {
					vertices[v].visited = true;
					vertices[v].distance = vertices[u].distance + 1;
					vertices[v].previous = u;
					q.push(v);
				}
			}
		}
	}

	void dfs(int s) {
		for (int i = 0; i < _V; ++i) {
			vertices[i].visited = false;
			vertices[i].distance = 65535;
			vertices[i].previous = -1;
			vertices[i].finish = 0;
		}

		if (s < 0 || s >= _V) {
			return;
		}

		_time = 0;
		vertices[s].distance = 0;
		dfs_visit(s);
	}
	
	void dfs_visit(int u) {
		vertices[u].visited = true;
		++_time;

		for (const auto& v : vertices[u].adj) {
			if (!vertices[v].visited) {
				vertices[v].previous = u;
				vertices[v].distance = vertices[u].distance + 1;
				dfs_visit(v);
			}
		}

		vertices[u].finish = ++_time;
	}

	void print_path(int s, int v) {
		if (v == s)
		   std::cout << s;
		else if (vertices[v].previous == -1)
		   std::cout << "not connected";
		else {
		   print_path(s,vertices[v].previous);
		   std::cout << "->" << v;
		}
	}

	std::string toString() {
		std::stringbuf buffer;
		std::ostream os(&buffer);
		os << "Vertices = " << _V << ", Edges = " << _E << std::endl;
		for (int i = 0; i < _V; ++i) {
		    os << i << "(" << degree(i) << "): ";
		    for (const auto& l : vertices[i].adj) 
			os << l << " ";
		    os << std::endl;
		}

		return buffer.str();
	}
private:
	int _V; // no. of vertices
	int _E; // no. of edges
	Vertex *vertices; // array of vertices
	int _time = 0;
};

#endif
