import pandas as pd 

df = pd.read_csv("Datasets/covid_19_data.csv")
separator = '\t'

for date in df["ObservationDate"]:
	print('%s%s%s' % (date, separator, 1))