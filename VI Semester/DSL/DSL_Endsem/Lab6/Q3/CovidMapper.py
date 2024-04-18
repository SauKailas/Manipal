import pandas as pd 

df = pd.read_csv("Datasets/covid_19_data.csv")

for country, confirmed in zip(df["Country/Region"], df["Confirmed"]):
    print('%s\t%s' % (country, confirmed))