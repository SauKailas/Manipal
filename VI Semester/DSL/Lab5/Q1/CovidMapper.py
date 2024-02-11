import pandas as pd

df = pd.read_csv('covid_19_data.csv')

for date in df["ObservationDate"]:
    print('%s,,%s' % (date, 1))