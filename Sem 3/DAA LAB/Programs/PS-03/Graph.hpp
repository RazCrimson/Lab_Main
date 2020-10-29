#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

class EdgeTo
{
public:
    int content, weight;
    EdgeTo(int c, int w) : content(c), weight(w) {}
    friend bool operator<(const EdgeTo one, const EdgeTo two)
    {
        return one.weight < two.weight;
    }
    friend bool operator==(const EdgeTo one, const EdgeTo two)
    {
        return one.weight == two.weight && one.content == two.content;
    }
};

class Graph
{
protected:
    map<int, set<EdgeTo>> adjacencyLists;
    static void makeset(map<int, set<int>> &sets, int srcRep, int destRep);
    static void joinSets(map<int, set<int>> &, int srcRep, int destRep);

public:
    void insert(int, set<EdgeTo>);
    set<EdgeTo> returnAdjacentVertices(int);
    set<int> verticesWithDegree(int);
    long int totalDegree();
    bool hasPathTo(int, int, set<int> &);
    bool hasPath(int, int);
    void BFS(int node);
    void DFS(int node);
    map<int, set<int>> kruskalMinSpanTree();
};

void Graph::insert(int value, set<EdgeTo> connectedNodes)
{
    map<int, set<EdgeTo>>::iterator iterator = adjacencyLists.find(value);
    if (iterator == adjacencyLists.end())
        adjacencyLists.insert(pair<int, set<EdgeTo>>(value, connectedNodes));
    else
        iterator->second.insert(connectedNodes.begin(), connectedNodes.end());

    for (EdgeTo connectedVertex : connectedNodes)
    {
        map<int, set<EdgeTo>>::iterator iterator = adjacencyLists.find(connectedVertex.content);
        if (iterator != adjacencyLists.end())
            iterator->second.insert({value, connectedVertex.weight});
        else
        {
            set<EdgeTo> connected;
            connected.insert({value, connectedVertex.weight});
            adjacencyLists.insert(pair<int, set<EdgeTo>>(connectedVertex.content, connected));
        }
    }
}

set<EdgeTo> Graph::returnAdjacentVertices(int value)
{
    map<int, set<EdgeTo>>::iterator iterator = adjacencyLists.find(value);
    if (iterator == adjacencyLists.end())
        return set<EdgeTo>();
    else
        return set<EdgeTo>(iterator->second);
}

set<int> Graph::verticesWithDegree(int degree)
{
    set<int> verticesMatchingDegree;
    for (auto keyValuePair : adjacencyLists)
    {
        if (keyValuePair.second.size() == degree)
            verticesMatchingDegree.insert(keyValuePair.first);
    }
    return verticesMatchingDegree;
}

long int Graph::totalDegree()
{
    long int totalDegreeOfGraph = 0;
    for (auto pair : adjacencyLists)
        totalDegreeOfGraph += pair.second.size();
    return totalDegreeOfGraph;
}

bool Graph::hasPathTo(int src, int dest, set<int> &visited)
{
    map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyLists.find(src);
    for (EdgeTo connectedVertex : iteratorToSrc->second)
    {
        if (connectedVertex.content == dest)
            return true;
        else
        {
            if (visited.find(connectedVertex.content) == visited.end())
            {
                visited.insert(connectedVertex.content);
                if (hasPathTo(connectedVertex.content, dest, visited))
                    return true;
            }
        }
    }
    return false;
}

bool Graph::hasPath(int src, int dest)
{
    set<int> visited;
    bool isConnected = hasPathTo(src, dest, visited);
    return isConnected;
}

void Graph::BFS(int node)
{
    set<int> visited;
    queue<int> q;

    visited.insert(node);
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        cout << node << " ";
        q.pop();

        map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyLists.find(node);
        for (EdgeTo connectedVertex : iteratorToSrc->second)
        {
            if (visited.find(connectedVertex.content) == visited.end())
            {
                visited.insert(connectedVertex.content);
                q.push(connectedVertex.content);
            }
        }
    }
}

void Graph::DFS(int node)
{
    set<int> visited;
    stack<int> s;

    visited.insert(node);
    s.push(node);

    while (!s.empty())
    {
        node = s.top();
        cout << node << " ";
        s.pop();

        map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyLists.find(node);
        for (EdgeTo connectedVertex : iteratorToSrc->second)
        {
            if (visited.find(connectedVertex.content) == visited.end())
            {
                visited.insert(connectedVertex.content);
                s.push(connectedVertex.content);
            }
        }
    }
}

map<int, set<int>> Graph::kruskalMinSpanTree()
{
    // List of all edges to be considered
    list<pair<int, EdgeTo>> allEdges;

    // Inserting all edges into the list
    for (auto adjacencyList : adjacencyLists)
    {
        for (EdgeTo edge : adjacencyList.second)
        {
            if (find(allEdges.begin(), allEdges.end(), pair<int, EdgeTo>(edge.content, {adjacencyList.first, edge.weight})) == allEdges.end())
                allEdges.push_back(pair<int, EdgeTo>(adjacencyList.first, edge));
        }
    }

    // Sorting the edges with a lambda funtion based on weight of edge
    allEdges.sort([](const std::pair<int, EdgeTo> &left, const std::pair<int, EdgeTo> &right) {
        return left.second < right.second;
    });

    // A map to store the resulting minimum spanning tree
    map<int, set<int>> minSpanTree;

    // Return if we have no edges
    if (allEdges.size() == 0)
        return minSpanTree;

    // Union find

    // map with will store all the representatives as keys and elements in the sets
    map<int, set<int>> sets;

    // Trying to insert each edge
    for (auto srcAndEdge : allEdges)
    {
        int srcRep = -1, destRep = -1;
        for (auto setWithKey : sets)
        {
            std::set<int>::iterator it;

            it = setWithKey.second.find(srcAndEdge.first);
            if (it != setWithKey.second.end() && srcRep == -1)
                srcRep = setWithKey.first;

            it = setWithKey.second.find(srcAndEdge.second.content);
            if (it != setWithKey.second.end())
                destRep = setWithKey.first;

            if (srcRep != -1 && destRep != -1)
                break;
        }
        if (srcRep == destRep)
        {
            if (srcRep == -1 && destRep == -1)
            {
                makeset(sets, srcAndEdge.first, srcAndEdge.second.content);
                minSpanTree.insert(pair<int, set<int>>(srcAndEdge.first, {srcAndEdge.second.content}));
            }
        }
        else
        {
            if (srcRep == -1)
            {
                sets.find(destRep)->second.insert(srcAndEdge.first);

                map<int, set<int>>::iterator iterator = minSpanTree.find(srcAndEdge.second.content);
                if (iterator == minSpanTree.end())
                    minSpanTree.insert(pair<int, set<int>>(srcAndEdge.second.content, {srcAndEdge.first}));
                else
                    iterator->second.insert(srcAndEdge.first);
            }
            else if (destRep == -1)
            {

                sets.find(srcRep)->second.insert(srcAndEdge.second.content);

                map<int, set<int>>::iterator iterator = minSpanTree.find(srcAndEdge.first);
                if (iterator == minSpanTree.end())
                    minSpanTree.insert(pair<int, set<int>>(srcAndEdge.first, {srcAndEdge.second.content}));
                else
                    iterator->second.insert(srcAndEdge.second.content);
            }
            else
            {

                map<int, set<int>>::iterator iterator = minSpanTree.find(srcRep);
                iterator->second.insert(destRep);

                joinSets(sets, srcRep, destRep);
            }
        }
    }

    return minSpanTree;
}

void Graph::makeset(map<int, set<int>> &sets, int srcRep, int destRep)
{
    sets.insert(pair<int, set<int>>(srcRep, {srcRep, destRep}));
}

void Graph::joinSets(map<int, set<int>> &sets, int srcRep, int destRep)
{
    std::map<int, set<int>>::iterator src = sets.find(srcRep);
    std::map<int, set<int>>::iterator dest = sets.find(destRep);

    src->second.insert(dest->second.begin(), dest->second.end());
    sets.erase(dest);
}
