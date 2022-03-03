from typing import Optional, List
import Pyro4
import os

from interface import ElectorInterface


@Pyro4.expose
class Elector(ElectorInterface):
    def __init__(self, candidates: List[str]) -> None:
        self.__voters = {}
        self.__candidates = {candidate: 0 for candidate in candidates}

    def register_voter(self, name: str) -> str:
        # Note: Not considering the security problems due to the simple naming scheme
        voter_id = str(len(self.__voters)).zfill(3)
        voter_id = "V" + voter_id
        self.__voters[voter_id] = (name, False)
        return voter_id

    def verify_voter(self, voter_id: str) -> Optional[str]:
        if voter_id in self.__voters:
            return self.__voters[voter_id][0]
        return None

    def get_candidates(self) -> List[str]:
        # Additional method to let client know the candidates
        return list(self.__candidates.keys())

    def vote(self, voter_id: str, candidate: str) -> bool:
        if voter_id not in self.__voters or candidate not in self.__candidates:
            return False

        voter_name, vote_status = self.__voters[voter_id]
        if vote_status == True:
            return False
        self.__voters[voter_id] = (voter_name, True)
        self.__candidates[candidate] += 1
        return True

    def tally_results(self) -> dict:
        return self.__candidates.copy()

    def announce_winner(self) -> str:
        return max(self.__candidates, key=self.__candidates.get)


if __name__ == "__main__":
    candidates_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "candidates")
    f = open(candidates_file)
    candidates = f.read().split("\n")
    f.close()

    elector = Elector(candidates)
    Pyro4.Daemon.serveSimple({elector: "elector"}, ns=True)
