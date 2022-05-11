from abc import ABC, abstractmethod


class ResourceContract(ABC):
    @abstractmethod
    def access_resource(self, resource_name: str):
        pass
