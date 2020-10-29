#include "Graph.hpp"

int main()
{
    Graph graph;
    // graph.insert(0, {{1, 4}, {7, 8}});
    // graph.insert(1, {{2, 8}, {7, 11}});
    // graph.insert(7, {{6, 1}, {8, 7}});
    // graph.insert(2, {{8, 2}, {3, 7}, {5, 4}});
    // graph.insert(8, {{6, 6}});
    // graph.insert(6, {{5, 2}});
    // graph.insert(3, {{5, 14}, {4, 9}});
    // graph.insert(5, {{4, 10}});

    graph.insert(1, {{6,5}, {2,2}, {5,6}});
    graph.insert(2, {{3,1},{6,4}});
    graph.insert(6, {{3,4}, {4,5},{5,2}});
    graph.insert(3, {{4,6}});
    graph.insert(5, {{4,8}});
    //graph.DFS(1);

    graph.kruskalMinSpanTree();
}
