import sys
import pandas as pd

df = pd.read_csv('Datasets/heart_disease_data.csv')

for index, row in df.iterrows():
    age = row['age']
    chol = row['chol']
    print("{0}\t{1}".format(age, chol))
