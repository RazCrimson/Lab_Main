from abc import ABC, abstractmethod


class Layout(ABC):
    @abstractmethod
    def render(self) -> str:
        # Simple text to represent rendering
        pass


class LinearLayout(Layout, ABC):
    def __init__(self, name: str):
        self.name = name

    def render(self) -> str:
        return "LinearLayout"


class TextureLayout(Layout, ABC):
    def __init__(self, name: str):
        self.name = name

    def render(self) -> str:
        return "TextureLayout"


class FlatLinearLayout(LinearLayout):
    def render(self) -> str:
        return "FlatLinearLayout: " + self.name


class FlatTextureLayout(TextureLayout):
    def render(self) -> str:
        return "FlatTextureLayout: " + self.name


class MaterialLinearLayout(LinearLayout):
    def render(self) -> str:
        return "MaterialLinearLayout: " + self.name


class MaterialTextureLayout(TextureLayout):
    def render(self) -> str:
        return "MaterialTextureLayout: " + self.name


class LayoutFactory(ABC):
    @abstractmethod
    def generate_texture_layout(self, name: str) -> TextureLayout:
        pass

    @abstractmethod
    def generate_linear_layout(self, name: str) -> LinearLayout:
        pass


class FlatLayoutFactory(LayoutFactory):
    def generate_texture_layout(self, name: str) -> TextureLayout:
        return FlatTextureLayout(name)

    def generate_linear_layout(self, name: str) -> LinearLayout:
        return FlatLinearLayout(name)


class MaterialLayoutFactory(LayoutFactory):
    def generate_texture_layout(self, name: str) -> TextureLayout:
        return MaterialTextureLayout(name)

    def generate_linear_layout(self, name: str) -> LinearLayout:
        return MaterialLinearLayout(name)


if __name__ == "__main__":
    factory_1: LayoutFactory = MaterialLayoutFactory()
    factory_2: LayoutFactory = FlatLayoutFactory()
    linear_layout = factory_1.generate_linear_layout("Test 1")
    relative_layout = factory_2.generate_texture_layout("Test 2")
    print(linear_layout.render())
    print(relative_layout.render())
