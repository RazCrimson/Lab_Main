#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

//template <class T>
class EdgeTo
{
public:
    int content, weight;
    EdgeTo(int c, int w) : content(c), weight(w) {}
};

class Graph
{
protected:
    map<int, set<EdgeTo>> adjacencyList;

public:
    void insert(int, set<EdgeTo>);
    set<EdgeTo> returnAdjacentVertices(int);
    set<int> verticesWithDegree(int);
    long int totalDegree();
    bool hasPathTo(int, int, set<int> &);
    bool hasPath(int, int);
    void BFS(int node);
    void DFS(int node);
};

void Graph::insert(int value, set<EdgeTo> connectedNodes)
{
    map<int, set<EdgeTo>>::iterator iterator = adjacencyList.find(value);
    if (iterator == adjacencyList.end())
        adjacencyList.insert(pair<int, set<EdgeTo>>(value, connectedNodes));
    else
        iterator->second.insert(connectedNodes.begin(), connectedNodes.end());

    set<EdgeTo>::iterator connectedNode = connectedNodes.begin();
    for (EdgeTo connectedVertex : connectedNodes)
    {
        map<int, set<EdgeTo>>::iterator iterator = adjacencyList.find(connectedVertex.content);
        if (iterator != adjacencyList.end())
            iterator->second.insert({value, connectedVertex.weight});
        else
        {
            set<EdgeTo> connected;
            connected.insert({value, connectedVertex.weight});
            adjacencyList.insert(pair<int, set<EdgeTo>>(connectedVertex.content, connected));
        }
    }
}

set<EdgeTo> Graph::returnAdjacentVertices(int value)
{
    map<int, set<EdgeTo>>::iterator iterator = adjacencyList.find(value);
    if (iterator != adjacencyList.end())
        return set<EdgeTo>();
    else
        return set<EdgeTo>(iterator->second);
}

set<int> Graph::verticesWithDegree(int degree)
{
    set<int> verticesMatchingDegree;
    for (auto pair : adjacencyList)
    {
        if (pair.second.size() == degree)
            verticesMatchingDegree.insert(pair.first);
    }
    return verticesMatchingDegree;
}

long int Graph::totalDegree()
{
    long int totalDegreeOfGraph = 0;
    for (auto pair : adjacencyList)
        totalDegreeOfGraph += pair.second.size();
    return totalDegreeOfGraph;
}

bool Graph::hasPathTo(int src, int dest, set<int> &visited)
{
    map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyList.find(src);
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

        map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyList.find(node);
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

        map<int, set<EdgeTo>>::iterator iteratorToSrc = adjacencyList.find(node);
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