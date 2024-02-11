import pandas as pd

df = pd.read_csv('Datasets/heart_disease_data.csv')

for age in df["age"]:
    print('%s,,%s' % (age, 1))