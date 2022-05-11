from __future__ import annotations


class FuzzySet:
    def __init__(self):
        self.members = {}

    def upsert_member(self, member, probability) -> bool:
        self.members[member] = probability

    def __or__(self, __t: FuzzySet) -> FuzzySet:
        if not isinstance(__t, FuzzySet):
            raise ValueError("Not a Fuzzy Set")

        members = list(set(self.members.keys()) | set(__t.members.keys()))
        result = FuzzySet()

        for member in members:
            membership_probability = max(self.members.get(member, 0), self.members.get(member, 0))
            result.upsert_member(member, membership_probability)

        return result

    def __and__(self, __t: FuzzySet) -> FuzzySet:
        if not isinstance(__t, FuzzySet):
            raise ValueError("Not a Fuzzy Set")

        members = list(set(self.members.keys()) | set(__t.members.keys()))
        result = FuzzySet()

        for member in members:
            membership_probability = min(self.members.get(member, 0), self.members.get(member, 0))
            result.upsert_member(member, membership_probability)

        return result

    def __eq__(self, __t: FuzzySet) -> bool:
        if set(self.members.keys()) != set(__t.members.keys()):
            return False

        for member in self.members.keys():
            if self.members[member] != __t.members[member]:
                return False

        return True

    def __invert__(self) -> FuzzySet:
        result = FuzzySet()
        for member, prob in self.members.items():
            result.upsert_member(member, 1 - prob)

        return result

    def __str__(self) -> str:
        return str(self.members)

    def __hash__(self) -> int:
        return hash(self.members)


if __name__ == "__main__":
    a = FuzzySet()
    b = FuzzySet()
    [a.upsert_member(m, p) for m, p in {2: 1, 3: 0.4, 1: 0.6, 4: 0.2}.items()]
    [b.upsert_member(m, p) for m, p in {2: 0, 3: 0.2, 1: 0.2, 4: 0.8}.items()]

    lhs = ~(a & b)
    rhs = ~a | ~b
    print(lhs, rhs)
    print(lhs == rhs)
