from abc import ABC, abstractmethod

import networkx as nx
from matplotlib import pyplot as plt


class VisualizeGraph(nx.DiGraph, ABC):
    def visualize_path(self, path: list):
        path_edges = list(zip(path, path[1:]))

        # Get position using spring layout
        pos = nx.spring_layout(self)

        # Draw nodes and edges not included in path
        nx.draw_networkx_nodes(self, pos, nodelist=set(self.nodes) - set(path))
        nx.draw_networkx_edges(
            self,
            pos,
            edgelist=set(self.edges) - set(path_edges),
            connectionstyle="arc3",
        )

        # Draw nodes and edges included in path
        nx.draw_networkx_nodes(self, pos, nodelist=path, node_color="r")
        nx.draw_networkx_edges(
            self,
            pos,
            edgelist=path_edges,
            edge_color="r",
            connectionstyle="arc3, rad = 0.2",
        )

        # Draw labels
        nx.draw_networkx_labels(self, pos)
        plt.show()
