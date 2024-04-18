import sys

total_countries = 0
total_confirmed = 0
current_country = None
current_confirmed = 0

print('Country\tMaximum Cases In A Single Day')
for line in sys.stdin:
    country, confirmed = line.strip().split('\t')

    try:
        confirmed = int(confirmed)
    except ValueError:
        continue

    if current_country == country:
        if confirmed > current_confirmed:
            current_confirmed = confirmed
    else:
        if current_country:
            print('%s\t%s' % (current_country, current_confirmed))
        total_countries += 1
        total_confirmed += current_confirmed
        current_country = country 
        current_confirmed = confirmed

if current_country == country:
    print('%s\t%s' % (current_country, current_confirmed))
    total_countries += 1
    total_confirmed += current_confirmed

print('\n\nTotal Number of Countries : %s' % (total_countries))
print('Total Number of Cases in a Single Day : %s' % (total_confirmed))
