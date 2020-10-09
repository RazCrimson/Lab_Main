#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

class Graph
{
protected:
    map<int, set<int>> adjacencyList;

public:
    void insert(int, set<int>);
    set<int> returnAdjacentVertices(int);
    set<int> verticesWithDegree(int);
    long int totalDegree();
    bool hasPathTo(int, int, set<int> &);
    bool hasPath(int, int);
    void BFS(int node);
    void DFS(int node);
};

void Graph::insert(int value, set<int> connectedNodes)
{
    map<int, set<int>>::iterator iterator = adjacencyList.find(value);
    if (iterator == adjacencyList.end())
        adjacencyList.insert(pair<int, set<int>>(value, connectedNodes));
    else
        iterator->second.insert(connectedNodes.begin(), connectedNodes.end());

    set<int>::iterator connectedNode = connectedNodes.begin();
    for (int connectedNode : connectedNodes)
    {
        map<int, set<int>>::iterator iterator = adjacencyList.find(connectedNode);
        if (iterator != adjacencyList.end())
            iterator->second.insert(value);
        else
        {
            set<int> connected({value});
            adjacencyList.insert(pair<int, set<int>>(connectedNode, connected));
        }
    }
}

set<int> Graph::returnAdjacentVertices(int value)
{
    map<int, set<int>>::iterator iterator = adjacencyList.find(value);
    if (iterator != adjacencyList.end())
        return set<int>();
    else
        return set<int>(iterator->second);
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
    map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(src);
    for (int connectedNode : iteratorToSrc->second)
    {
        if (connectedNode == dest)
            return true;
        else
        {
            if (visited.find(connectedNode) == visited.end())
            {
                visited.insert(connectedNode);
                if (hasPathTo(connectedNode, dest, visited))
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
        
        map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(node);
        for (int connectedNode : iteratorToSrc->second){
            if(visited.find(connectedNode) == visited.end()){
                visited.insert(connectedNode);
                q.push(connectedNode);
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

        map<int, set<int>>::iterator iteratorToSrc = adjacencyList.find(node);
        for (int connectedNode : iteratorToSrc->second){
            if(visited.find(connectedNode) == visited.end()){
                visited.insert(connectedNode);
                s.push(connectedNode);
            }
        }
    }
}