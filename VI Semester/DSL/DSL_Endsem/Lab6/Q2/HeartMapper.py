import pandas as pd 

df = pd.read_csv("Datasets/heart_disease_data.csv")

for age, chol in zip(df["age"], df["chol"]):
	print('%s\t%s' % (age, chol))