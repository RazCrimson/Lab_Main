from typing import List, Optional, Union


class Graph:
    def __init__(self):
        self.adj_list = {}
        self.edges = []

    def add_edge(self, start, end):
        if start not in self.adj_list:
            self.adj_list[start] = []

        self.adj_list[start].append(end)


class AStar:
    def __init__(self, graph: Graph) -> None:
        self.graph = graph
        self._costs = {}
        self._heuristics = {}

    def calculate_utility(self, start: int, end: int) -> None:
        self.calculate_cost(start, end)
        self.calculate_heuristic(start, end)

    def calculate_cost(self, start: int, end: int, dist: int = 0) -> None:
        self._costs[start] = dist

        if start == end or start not in self.graph.adj_list:
            return

        for neighbour in self.graph.adj_list[start]:
            self.calculate_cost(neighbour, end, dist + 1)

    def calculate_heuristic(self, start: int, end: int) -> Union[None, int]:
        if start in self._heuristics:
            return self._heuristics[start]

        if start == end:
            self._heuristics[start] = 0
            return self._heuristics[start]

        if start not in self.graph.adj_list:
            self._heuristics[start] = None
            return None

        distances = []
        for neighbour in self.graph.adj_list[start]:
            result = self.calculate_heuristic(neighbour, end)
            if result is not None:
                distances.append(self._heuristics[neighbour])

        if len(distances) == 0:
            self._heuristics[start] = None
            return None

        self._heuristics[start] = min(distances) + 1
        return self._heuristics[start]

    def find(self, start: int, end: int) -> List[int]:
        self.calculate_heuristic(start, end)
        path = []
        path.append(start)
        current_node = start

        while current_node != end:
            neighbours_heuristic = {
                key: value
                for (key, value) in self._heuristics.items()
                if key in self.graph.adj_list[current_node] and value is not None
            }
            neighbours_utility = {key: value + self._costs[key] for (key, value) in neighbours_heuristic.items()}
            current_node = min(neighbours_utility, key=neighbours_utility.get)
            path.append(current_node)

        return path


class HillClimbing:
    def __init__(self, graph: Graph) -> None:
        self.graph = graph
        self.utility = {}

    def calculate_utility(self, start: int, end: int) -> Optional[int]:
        if start in self.utility:
            return self.utility[start]

        if start == end:
            self.utility[start] = 0
            return self.utility[start]

        if start not in self.graph.adj_list:
            self.utility[start] = None
            return None

        distances = []
        for neighbour in self.graph.adj_list[start]:
            result = self.calculate_utility(neighbour, end)
            if result is not None:
                distances.append(self.utility[neighbour])

        if len(distances) == 0:
            self.utility[start] = None
            return None

        self.utility[start] = min(distances) + 1
        return self.utility[start]

    def find(self, start: int, end: int) -> List[int]:
        self.calculate_utility(start, end)
        path = []
        path.append(start)
        current_node = start

        while current_node != end:
            neighbours_utility = {
                key: value
                for (key, value) in self.utility.items()
                if key in self.graph.adj_list[current_node] and value is not None
            }
            current_node = min(neighbours_utility, key=neighbours_utility.get)
            path.append(current_node)

        return path


if __name__ == "__main__":
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 7)
    g.add_edge(2, 5)
    g.add_edge(5, 3)
    g.add_edge(3, 4)

    print("A Star")
    a_star = AStar(g)
    a_star.calculate_utility(0, 4)
    print(a_star._heuristics)
    print(a_star._costs)
    print(a_star.find(0, 4))

    print("Hill Climbing")
    hill_climbing = HillClimbing(g)
    hill_climbing.calculate_utility(0, 4)
    print(hill_climbing.utility)
    print(hill_climbing.find(0, 4))
