from operator import add, sub
from pprint import pprint

INITIAL_STATE = [3, 3, 1]
GOAL_STATE = [0, 0, 0]


class State:
    def __init__(self, state, utility):
        self.state = state
        self.utility = utility

    @staticmethod
    def get_all_actions():
        return [
            [0, 1, 1],
            [0, 2, 1],
            [1, 0, 1],
            [2, 0, 1],
            [1, 1, 1],
        ]

    def is_goal(self) -> bool:
        return self.state == GOAL_STATE

    def heuristic(self) -> int:
        return sum(abs(m - n) for m, n in zip(self.state, GOAL_STATE))

    def is_valid(self) -> bool:
        if any(m > n for m, n in zip(self.state, INITIAL_STATE)):
            return False
        elif any(n < 0 for n in self.state):
            return False
        elif (
            (self.state[0] == 1 and self.state[1] == 3)
            or (self.state[0] == 2 and self.state[1] == 3)
            or (self.state[0] == 1 and self.state[1] == 2)
        ):
            return False
        elif (self.state[0] == 2 and self.state[1] == 1) or (self.state[0] == 1 and self.state[1] == 0):
            return False
        return True

    def apply_action(self, action):
        if self.state[2] == 1:
            return State(list(map(sub, self.state, action)), self.utility + 1)
        return State(list(map(add, self.state, action)), self.utility + 1)

    def get_valid_neighbours(self):
        possible_states = [self.apply_action(action) for action in self.get_all_actions()]
        return [state for state in possible_states if state.is_valid()]

    def __repr__(self):
        return f"<State: {self.state}, utility={self.utility}>"

    def __eq__(self, __o: object) -> bool:
        if not isinstance(__o, State):
            return False

        return self.state == __o.state

    def __hash__(self) -> int:
        return hash(str(self.state))


class MissionariesAndCannibals:
    def __init__(self, initial_state: State) -> None:
        self.initial_state = initial_state

    def a_star(self):
        visited = []
        nodes = [self.initial_state]

        parents = {}

        while len(nodes) != 0:
            node = min(nodes, key=lambda node: node.utility + node.heuristic())
            if node.is_goal():
                return node, parents

            nodes.remove(node)
            visited.append(node)

            for successor in node.get_valid_neighbours():

                if successor in nodes:
                    state_in_list = nodes[nodes.index(successor)]
                    if successor.utility < state_in_list.utility:
                        nodes.remove(state_in_list)

                if successor in visited:
                    state_in_list = visited[visited.index(successor)]
                    if successor.utility < state_in_list.utility:
                        visited.remove(state_in_list)

                if successor not in nodes and successor not in visited:
                    nodes.append(successor)
                    parents[successor] = node

        return None


if __name__ == "__main__":
    initial_state = State(INITIAL_STATE, 0)
    mc = MissionariesAndCannibals(initial_state)
    node, parents = mc.a_star()
    path = [node]
    while node != initial_state:
        node = parents[node]
        path.append(node)

    path.reverse()
    pprint(path)
