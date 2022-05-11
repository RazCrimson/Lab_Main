from abc import ABC, abstractmethod
from typing import List, Optional


class ElectorInterface(ABC):
    @abstractmethod
    def register_voter(self, name: str) -> str:
        pass

    @abstractmethod
    def verify_voter(self, voter_id: str) -> Optional[str]:
        pass

    @abstractmethod
    def get_candidates(self) -> List[str]:
        pass

    @abstractmethod
    def vote(self, voter_id: str, candidate: str) -> bool:
        pass

    @abstractmethod
    def tally_results(self) -> dict:
        pass

    @abstractmethod
    def announce_winner(self) -> str:
        pass
