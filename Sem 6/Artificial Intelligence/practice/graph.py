class Graph:
    def __init__(self) -> None:
        self.adjacency_lists: dict[int, list[tuple[int, int]]] = {}

    def add_edge(self, start: int, end: int, cost: int = 1) -> None:
        nodes = self.adjacency_lists.setdefault(start, [])
        entry = (end, cost)
        if entry not in nodes:
            nodes.append(entry)

        self.adjacency_lists.setdefault(end, [])

    def get_neighbours(self, node: int) -> list[tuple[int, int]]:
        return self.adjacency_lists.setdefault(node, [])
