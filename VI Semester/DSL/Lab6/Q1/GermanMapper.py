import sys
import pandas as pd

df = pd.read_excel('Datasets/GermanCredit.xlsx', engine='openpyxl')
separator = '\t'

for amount in df["Creditability"]:
    print('%s%s%d' % (amount, separator, 1))

