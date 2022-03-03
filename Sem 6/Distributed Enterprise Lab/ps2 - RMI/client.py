import sys
import Pyro4
import Pyro4.util

from interface import ElectorInterface

sys.excepthook = Pyro4.util.excepthook

elector: ElectorInterface = Pyro4.Proxy("PYRONAME:elector")

while True:
    print(
        "1. Register to Vote\n"
        "2. Verify Voter\n"
        "3. Get Candidates Names\n"
        "4. Vote\n"
        "5. Tally Results\n"
        "6. Announce Winner\n"
        "Press anything else to Quit\n"
    )
    choice = input("Enter your choice: ")
    match choice:
        case "1":
            name = input("Enter name to register: ")
            voter_id = elector.register_voter(name)
            print(f"Voter ID for {name}: {voter_id}")

        case "2":
            voter_id = input("Enter voter ID to verify: ")
            name = elector.verify_voter(voter_id)
            if name:
                print(f"Voter for {voter_id}: {name}")
            else:
                print("Invalid or unregistered Voter ID!")

        case "3":
            candidates = elector.get_candidates()
            print("\nCandidates: ")
            for candidate in candidates:
                print(candidate)

        case "4":
            voter_id = input("Enter voter ID to vote as: ")
            candidate = input("Enter candidate to vote: ")
            result = elector.vote(voter_id, candidate)
            if result:
                print("Voting succeeded!")
            else:
                print("Voting Failed!")

        case "5":
            candidate_scores = elector.tally_results()
            print("Voting Tally: ")
            for candidate, score in candidate_scores.items():
                print(candidate, " - ", score)

        case "6":
            print(f"Winner is {elector.announce_winner()}")

        case _:
            print("Exiting....")
            exit()
    print()  # For visual comfort
