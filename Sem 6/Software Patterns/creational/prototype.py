# Example 1 - Using a separate method
import copy
from abc import ABC, abstractmethod


class Prototype(ABC):
    @abstractmethod
    def clone():
        ...


class Component(Prototype):
    def __init__(self, x: int, y: int) -> None:
        self.x = x
        self.y = y

    def get_x_coordinate(self) -> int:
        return self.x

    def get_y_coordinate(self) -> int:
        return self.y

    def clone(self):
        return self.__class__(self.x, self.y)

    def __str__(self):
        return f"<{self.__class__}: " + ", ".join(f"{key}='{getattr(key)}'" for key in dir(self))


class Button(Component):
    def __init__(self, x: int, y: int, length: int, breadth: int, text):
        super().__init__(x, y)
        self.length = length
        self.breadth = breadth
        self.button_text = text

    def clone(self):
        button_text = copy.deepcopy(self.button_text)
        return self.__class__(self.x, self.y, self.length, self.breadth, button_text)


component = Component(10, 11)
print(component)
print(component.clone())
button = Button(12, 13, 5, 5, "Text")
print(button)
print(button.clone())


# Example 2 - Using python dunder methods


class ChildComponent(Component, ABC):
    def __init__(self, x: int, y: int, parent: Component) -> None:
        super().__init__(x, y)
        self.parent = parent

    def get_parent(self):
        return self.parent

    def __copy__(self):
        return copy.copy(self)

    def __deepcopy__(self):
        parent = copy.copy(self.parent)
        return self.__class__(self.x, self.y, parent)


class ChildButton(ChildComponent):
    def __init__(self, x, y, parent, length, breadth, text):
        super().__init__(x, y, parent)
        self.length = length
        self.breadth = breadth
        self.button_text = text

    def clone(self):
        parent = copy.copy(self.parent)
        button_text = copy.deepcopy(self.button_text)
        return self.__class__(self.x, self.y, parent, self.length, self.breadth, button_text)
