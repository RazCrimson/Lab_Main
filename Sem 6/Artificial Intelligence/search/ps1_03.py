import copy
from pprint import pprint


class PuzzleProblem:
    def __init__(self, final_state: list[list[int]]) -> None:
        self.final_state = final_state
        self.final_state_mapping = self.generate_mapping(final_state)

    def generate_mapping(self, state: list[list[int]]):
        state_mapping = dict()
        for i in range(len(state)):
            for j in range(len(state[i])):
                state_mapping[state[i][j]] = (i, j)

        return state_mapping

    def calculate_heuristic(self, current_state: list[list[int]]) -> int:
        heuristic = 0
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                if current_state[i][j] != 0:
                    heuristic += abs(i - self.final_state_mapping[current_state[i][j]][0]) + abs(
                        j - self.final_state_mapping[current_state[i][j]][1]
                    )

        return heuristic

    def find(self, init_state: list[list[int]]):
        prev_heuristic = 10000
        current_heuristic = self.calculate_heuristic(init_state)
        current_state = init_state
        while current_heuristic < prev_heuristic:
            current_state_mapping = self.generate_mapping(current_state)
            i, j = current_state_mapping[0]
            states = []
            heuristics = []
            if i > 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = temp_state[i - 1][j]
                temp_state[i - 1][j] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            if i < len(init_state) - 1:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = temp_state[i + 1][j]
                temp_state[i + 1][j] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            if j > 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = current_state[i][j - 1]
                temp_state[i][j - 1] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            if j < len(init_state[i]) - 1:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = current_state[i][j + 1]
                temp_state[i][j + 1] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            pprint(current_state)
            print("\n")
            pprint(states)
            print("\n")

            min_index = heuristics.index(min(heuristics))
            prev_heuristic = current_heuristic
            current_heuristic = min(heuristics)

            if current_heuristic < prev_heuristic:
                current_state = copy.deepcopy(states[min_index])
                pprint(current_state)
                print("\n")

        return current_state


if __name__ == "__main__":
    init_state = [[7, 2, 4], [5, 0, 6], [8, 3, 1]]

    final_state = [[0, 1, 2], [3, 4, 5], [6, 7, 8]]

    problem = PuzzleProblem(final_state)
    print(problem.find(init_state))
