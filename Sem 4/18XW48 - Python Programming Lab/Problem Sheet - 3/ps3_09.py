import re

LOG_MATCH_REGEX = r'([A-Za-z]{3,4} \d\d? [0-9:]+) \[([0-9]+)\] (\w+): Device State: (\w+)'
log_match_pattern = re.compile(LOG_MATCH_REGEX)