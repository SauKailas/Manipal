import sys
import pandas as pd

df = pd.read_excel('Datasets/GermanCredit.xlsx', engine='openpyxl')

for amount in df["Creditability"]:
    print('%s\t%s' % (amount, 1))