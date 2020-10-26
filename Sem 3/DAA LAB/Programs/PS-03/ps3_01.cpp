#include "Graph.hpp"

int main()
{
    Graph graph;
    set<EdgeTo> one;
    one.insert({3,2});
    graph.insert(1, one);
    graph.insert(3, {{2,1}, {4,1}, {8,1}});
    graph.insert(2, {{5,1}});
    graph.insert(4, {{5,1}, {8,1}});
    graph.insert(5, {{6,1}, {9,1}, {10,1}});
    graph.insert(6, {{7,1}});
    graph.insert(7, {{8,1}});
    graph.insert(8, {{4,1}});
    graph.DFS(1);

}
