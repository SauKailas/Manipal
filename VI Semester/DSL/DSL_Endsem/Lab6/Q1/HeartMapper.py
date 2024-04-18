import pandas as pd 

df = pd.read_csv('Datasets/heart_disease_data.csv')
separator = '\t'

for age in df["age"]:
	print('%s%s%s' % (age, separator, 1))