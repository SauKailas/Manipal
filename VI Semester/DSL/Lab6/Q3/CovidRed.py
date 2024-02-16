import sys

country_max_cases = {}
max_cases = 0
old_key = None
total_countries = 0
total_cases = 0

print("Country:\t\tMaximum Cases in Single Day:")
for line in sys.stdin:
    data = line.strip().split("\t")
    if len(data) != 2:
        continue
    current_key, current_value = data
    if old_key and old_key != current_key:
        print(old_key, "\t\t\t", max_cases)
        total_countries += 1
        total_cases += max_cases
        max_cases = 0
    
    if int(current_value) > max_cases:
        max_cases = int(current_value)
    old_key = current_key

if old_key is not None:
    print(old_key, "\t\t\t", max_cases)
    total_cases += max_cases
    total_countries += 1

print("Total Number of Countries: ", total_countries)
print("Total Number of Covid Cases: ", total_cases)
