import copy


class JarFiller:
    def __init__(self, final_state: list[int]) -> None:
        self.final_state = final_state

    def calculate_utility(self, state: list[int]) -> int:
        utility = 0
        if self.final_state[0] != -1:
            utility += abs(self.final_state[0] - state[0])

        if self.final_state[1] != -1:
            utility += abs(self.final_state[1] - state[1])

        return utility

    def compare_states(self, current_state: list[int]) -> bool:
        if (self.final_state[0] != -1 and current_state[0] != self.final_state[0]) or (
            self.final_state[1] != -1 and current_state[1] != self.final_state[1]
        ):
            return False
        return True

    def find(self, init_state: list[int]) -> list[int]:
        prev_utility = 1000
        current_state = init_state
        while init_state != self.final_state:
            states = []
            utilities = []

            current_utility = self.calculate_utility(current_state)

            if current_state[0] != 4:
                temp_state = copy.deepcopy(current_state)
                temp_state[0] = 4
                states.append(temp_state)
                utilities.append(self.calculate_utility(temp_state))

            if current_state[1] != 3:
                temp_state = copy.deepcopy(current_state)
                temp_state[1] = 3
                states.append(temp_state)
                utilities.append(self.calculate_utility(temp_state))

            if current_state[0] != 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[0] = 0
                states.append(temp_state)
                utilities.append(self.calculate_utility(temp_state))

                if current_state[1] != 3:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[1] = max(3, temp_state[1] + temp_state[0])
                    temp_state[0] = 0
                    states.append(temp_state)
                    utilities.append(self.calculate_utility(temp_state))

            if current_state[1] != 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[1] = 0
                states.append(temp_state)
                utilities.append(self.calculate_utility(temp_state))

                if current_state[0] != 4:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0] = max(4, temp_state[0] + temp_state[1])
                    temp_state[1] = 0
                    states.append(temp_state)
                    utilities.append(self.calculate_utility(temp_state))

            print(current_state, "\n")
            print(states, "\n")

            min_index = utilities.index(min(utilities))
            prev_utility = current_utility
            current_utility = min(utilities)

            if current_utility < prev_utility:
                current_state = copy.deepcopy(states[min_index])
                print(current_state, "\n")

            else:
                break

        return current_state


if __name__ == "__main__":
    init_state = [0, 0]
    final_state = [4, -1]

    problem = JarFiller(final_state)
    print(problem.find(init_state))
