import scipy.integrate as integrate


def get_membership_value(val: float, dimensions: list, cutoff: float = 1):
    # Assumption: Every fuzzy set has atleast one point where membership is guaranteed 
    x1, x2, x3, x4 = sorted(dimensions)

    if not (x1 < val < x4):
        return 0
    elif x2 <= val <= x3:
        return 1

    left_value = (val - x1) / (x2 - x1) if x1 != x2 else None
    right_value = (x4 - val) / (x4 - x3) if x3 != x4 else None

    return min(v for v in [left_value, right_value, cutoff] if v is not None)


def fuzzify(val: float, membership: dict):
    return {fuzzy_set: get_membership_value(val, dimensions) for fuzzy_set, dimensions in membership.items()}


def rule_evaluation(result_membership: dict, rules: list, *fuzzes: list[dict]):
    inferences = {fuzzy_set: 0 for fuzzy_set in result_membership.keys()}

    for rule in rules:
        fuzz_sets, result_set = rule[:-1], rule[-1]
        current_inference = min(fuzz[fuzz_set] for fuzz, fuzz_set in zip(fuzzes, fuzz_sets))
        inferences[result_set] = max(inferences[result_set], current_inference)

    return inferences


def get_aggregated_membership_value(val: float, fuzz: dict, membership: dict):
    return max(get_membership_value(val, dimensions, fuzz[fuzz_set]) for fuzz_set, dimensions in membership.items())


def center_of_gravity(fuzz: dict, membership: dict):
    # Find the integral range that needs to be computed
    result_sets = [result_set for result_set, val in fuzz.items() if val > 0]
    result_low = min(val for result_set, vals in membership.items() for val in vals if result_set in result_sets)
    result_high = max(val for result_set, vals in membership.items() for val in vals if result_set in result_sets)

    numerator = lambda val: val * get_aggregated_membership_value(val, fuzz, membership)
    denominator = lambda val: get_aggregated_membership_value(val, fuzz, membership)

    num_integrated = integrate.quad(numerator, result_low, result_high)
    denom_integrated = integrate.quad(denominator, result_low, result_high)

    return num_integrated[0] / denom_integrated[0]


def compute(result_membership: dict, rules: dict, vals: list, memberships: list[dict]):
    if len(vals) != len(memberships):
        raise ValueError("Values & Memberships mismatch!")

    fuzzes = [fuzzify(val, membership) for val, membership in zip(vals, memberships)]
    fuzzy_inferences = rule_evaluation(result_membership, rules, *fuzzes)

    return center_of_gravity(fuzzy_inferences, result_membership)


if __name__ == "__main__":
    RULES = [
        ["L", "G", "VL"],
        ["M", "G", "L"],
        ["S", "G", "L"],
        ["L", "M", "L"],
        ["M", "M", "M"],
        ["S", "M", "M"],
        ["L", "NG", "M"],
        ["M", "NG", "S"],
        ["S", "NG", "VS"],
    ]

    DIRTINESS_MEMBERSHIP = {
        "S": [0, 0, 0, 50],
        "M": [0, 50, 50, 100],
        "L": [50, 100, 100, 100],
    }

    DIRT_TYPE_MEMBERSHIP = {
        "NG": [0, 0, 0, 50],
        "M": [0, 50, 50, 100],
        "G": [50, 100, 100, 100],
    }

    WASH_DURATION_MEMBERSHIP = {
        "VS": [0, 8, 8, 12],
        "S": [8, 12, 12, 20],
        "M": [12, 20, 20, 40],
        "L": [20, 40, 40, 60],
        "VL": [40, 60, 60, 60],
    }

    result = compute(
        WASH_DURATION_MEMBERSHIP,
        RULES,
        [25, 75],
        [DIRTINESS_MEMBERSHIP, DIRT_TYPE_MEMBERSHIP],
    )
    print("Result: ", result)


    membership_values = {
        "NL": [0, 0, 31, 61],
        "NM": [31, 61, 61, 95],
        "NS": [61, 95, 95, 127],
        "ZE": [95, 127, 127, 159],
        "PS": [127, 159, 159, 191],
        "PM": [159, 191, 191, 223],
        "PL": [191, 223, 255, 255],
    }

    rules = [
        ["NL", "ZE", "PL"],
        ["ZE", "NL", "PL"],
        ["NM", "ZE", "PM"],
        ["NS", "PS", "PS"],
        ["PS", "NS", "NS"],
        ["PL", "ZE", "NL"],
        ["ZE", "NS", "PS"],
        ["ZE", "NM", "PM"],
    ]

    result = compute(
        membership_values,
        rules,
        [100, 70],
        [membership_values, membership_values],
    )

    print("Result: ", result)
