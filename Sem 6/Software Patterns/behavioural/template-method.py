from abc import ABC, abstractmethod


class ServiceTemplate(ABC):
    def __init__(self, name) -> None:
        self.name = name

    def initialize(self) -> None:
        print(f"{self.name}: Initialized")

    def terminate(self) -> None:
        print(f"{self.name}: Terminated")

    @abstractmethod
    def execute(self) -> None:
        pass

    def run(self) -> None:
        self.initialize()
        self.execute()
        self.terminate()


class CleanupService(ServiceTemplate):
    def __init__(self):
        super().__init__("Cleanup")

    def execute(self):
        print(f"{self.name}: Cleaning resources")


if __name__ == "__main__":
    cs = CleanupService()
    cs.run()
