from __future__ import annotations

import copy
from typing import Dict, List, Tuple


class State:
    def __init__(self, current_state: List[List[int]], utility: int, goal_state: List[List[int]]) -> None:
        self.current_state = current_state
        self.utility = utility
        self.goal_state = goal_state
        self.heuristic = self.calculate_heuristic(goal_state)
        self.is_goal = self.compare_states()

    def generate_mapping(self, current_state: List[List[int]]) -> Dict[int, Tuple[int, int]]:
        state_mapping = dict()
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                state_mapping[current_state[i][j]] = (i, j)

        return state_mapping

    def calculate_heuristic(self, goal_state: List[List[int]]) -> int:
        heuristic = 0
        goal_state_mapping = self.generate_mapping(goal_state)
        for i in range(len(self.current_state)):
            for j in range(len(self.current_state[i])):
                if self.current_state[i][j] != 0:
                    heuristic += abs(i - goal_state_mapping[self.current_state[i][j]][0]) + abs(
                        j - goal_state_mapping[self.current_state[i][j]][1]
                    )

        return heuristic

    def get_subsequent_states(self) -> List[State]:
        current_state_mapping = self.generate_mapping(self.current_state)
        subsequent_states = list()
        i, j = current_state_mapping[0]
        if i > 0:
            temp_state = copy.deepcopy(self.current_state)
            temp_state[i][j] = temp_state[i - 1][j]
            temp_state[i - 1][j] = 0
            subsequent_states.append(State(temp_state, self.utility + 1, self.goal_state))

        if i < len(self.current_state) - 1:
            temp_state = copy.deepcopy(self.current_state)
            temp_state[i][j] = temp_state[i + 1][j]
            temp_state[i + 1][j] = 0
            subsequent_states.append(State(temp_state, self.utility + 1, self.goal_state))

        if j > 0:
            temp_state = copy.deepcopy(self.current_state)
            temp_state[i][j] = self.current_state[i][j - 1]
            temp_state[i][j - 1] = 0
            subsequent_states.append(State(temp_state, self.utility + 1, self.goal_state))

        if j < len(self.current_state[i]) - 1:
            temp_state = copy.deepcopy(self.current_state)
            temp_state[i][j] = self.current_state[i][j + 1]
            temp_state[i][j + 1] = 0
            subsequent_states.append(State(temp_state, self.utility + 1, self.goal_state))

        return subsequent_states

    def compare_states(self) -> bool:
        for row1, row2 in zip(self.current_state, self.goal_state):
            for current_state_element, goal_state_element in zip(row1, row2):
                if current_state_element != goal_state_element:
                    return False
        return True

    def __eq__(self, __o: object) -> bool:
        if not isinstance(__o, State):
            return False

        other_state = __o
        for row1, row2 in zip(self.current_state, other_state.current_state):
            for current_state_element, other_state_element in zip(row1, row2):
                if current_state_element != other_state_element:
                    return False
        return True

    def __hash__(self) -> int:
        return hash(str(self.current_state))


class PriorityQueue:
    def __init__(self) -> None:
        self.queue = list()

    def enqueue(self, current_state: State) -> None:
        self.queue.append(copy.deepcopy(current_state))

    def dequeue(self) -> State:
        min_index = 0
        min_value = 10000000
        for index, state_element in enumerate(self.queue):
            current_value = state_element.utility + state_element.heuristic
            if current_value < min_value:
                min_value = current_value
                min_index = index

        return self.queue.pop(min_index)


class PuzzleProblem:
    def __init__(self, goal_state: List[List[int]]):
        self.goal_state = goal_state

    def a_star(self, init_state: List[List[int]]) -> list:
        parent = dict()
        closed_list = list()
        open_list = PriorityQueue()
        initial_state = State(init_state, 0, self.goal_state)
        open_list.enqueue(initial_state)
        final_state = None

        i = 0
        while len(open_list.queue) != 0:
            print("index:", i)
            current_state = open_list.dequeue()
            print(current_state.current_state)
            if current_state.is_goal:
                final_state = current_state
                break

            closed_list.append(copy.deepcopy(current_state))

            subsequent_states = current_state.get_subsequent_states()

            for subsequent_state in subsequent_states:

                if subsequent_state in open_list.queue:
                    index = open_list.queue.index(subsequent_state)
                    state_in_list = open_list.queue[index]
                    if subsequent_state.utility < state_in_list.utility:
                        open_list.queue.pop(index)

                if subsequent_state in closed_list:
                    index = closed_list.index(subsequent_state)
                    state_in_list = closed_list[index]
                    if subsequent_state.utility < state_in_list.utility:
                        closed_list.pop(index)

                if subsequent_state not in open_list.queue and subsequent_state not in closed_list:
                    open_list.enqueue(subsequent_state)
                    parent[subsequent_state] = current_state

            i += 1
            print("\n")

        path = []

        if final_state:
            current_state = final_state
            while current_state != initial_state:
                path.append(current_state.current_state)
                current_state = parent[current_state]

            return path

        # return State(self.goal_state, self.goal_state)


if __name__ == "__main__":
    init_state = [[7, 2, 4], [5, 0, 6], [8, 3, 1]]

    goal_state = [[0, 1, 2], [3, 4, 5], [6, 7, 8]]

    problem = PuzzleProblem(goal_state)
    result = problem.a_star(init_state)
    print(result)
