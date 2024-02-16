import sys
import pandas as pd

df = pd.read_csv('Datasets/covid_19_data.csv')

for index, row in df.iterrows():
    location = row['Country/Region']
    confirmed = row['Confirmed']
    print("{0}\t{1}".format(location, confirmed))
