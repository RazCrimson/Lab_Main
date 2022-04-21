from queue import PriorityQueue

from graph import Graph


def heuristic(n):
    return {"a": 10, "b": 8, "c": 5, "d": 7, "e": 3, "g": 5, "i": 1, "j": 0, "h": 3, "f": 6}[n]


def a_star(graph: Graph, start: int, end: int):
    visited = set()
    nodes = [start]
    costs = {start: 0}

    parents = {}

    while len(nodes) != 0:
        node = min(nodes, key=lambda node: costs[node] + heuristic(node))
        if node == end:
            return parents

        nodes.remove(node)
        visited.add(node)

        for successor, distance in graph.get_neighbours(node):
            current_cost = costs[node] + distance
            if successor not in costs:
                costs[successor] = current_cost

            if successor in nodes and current_cost < costs[successor]:
                nodes.remove(successor)

            if successor in visited and current_cost < costs[successor]:
                visited.remove(successor)

            if successor not in nodes and successor not in visited:
                nodes.append(successor)
                costs[successor] = current_cost
                parents[successor] = node

    return None


if __name__ == "__main__":
    g = Graph()
    g.add_edge("a", "f", 3)
    g.add_edge("a", "b", 6)

    g.add_edge("b", "a", 6)
    g.add_edge("b", "d", 2)
    g.add_edge("b", "c", 3)

    g.add_edge("c", "b", 3)
    g.add_edge("c", "d", 1)
    g.add_edge("c", "e", 5)

    g.add_edge("d", "b", 2)
    g.add_edge("d", "c", 1)
    g.add_edge("d", "e", 8)

    g.add_edge("e", "d", 8)
    g.add_edge("e", "c", 5)
    g.add_edge("e", "i", 5)
    g.add_edge("e", "j", 5)

    g.add_edge("f", "h", 7)
    g.add_edge("f", "g", 1)

    g.add_edge("g", "i", 3)
    g.add_edge("g", "f", 1)

    g.add_edge("h", "i", 2)
    g.add_edge("h", "f", 7)

    g.add_edge("i", "e", 5)
    g.add_edge("i", "j", 3)
    g.add_edge("i", "h", 2)
    g.add_edge("i", "g", 3)

    g.add_edge("j", "e", 5)
    g.add_edge("j", "i", 3)

    start = "a"
    end = "j"
    result, parent = a_star(g, start, end)
    node = end
    path = [node]
    while node != start:
        node = parent[node]
        path.append(node)

    path.reverse()
    print(result, path)
