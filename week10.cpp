#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>

using namespace std;

template <typename Vertex>
struct Graph {
	typedef pair<Vertex, Vertex> Edge;
	set<Vertex> vlist;
	map<Vertex, set<Vertex>> adjlist;
	void addVertex(Vertex v) {
		vlist.insert(v);
	}
	void addEdge(Vertex first, Vertex second) {
		vlist.insert(first);
		vlist.insert(second);
		// directed graph
		adjlist[first].insert(second);
		// undirected graph
		adjlist[second].insert(first);
	}
	int getDegree(Vertex v) {
		return adjlist[v].size();
	}
	void printDegrees() {
		for (const auto& v : adjlist)
			cout << v.first << ": " << getDegree(v.first) << endl;
	}
};

int main() {
	Graph<string> G;
	G.addEdge("Lan", "Khang");
	G.addEdge("Lan", "Van");
	G.addEdge("Lan", "Mai");
	G.addEdge("Khang", "Mai");
	G.printDegrees();
}


