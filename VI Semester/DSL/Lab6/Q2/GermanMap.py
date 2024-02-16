import sys
import pandas as pd

df = pd.read_excel('Datasets/GermanCredit.xlsx', engine='openpyxl')

for index, row in df.iterrows():
    dur = row['DurationOfCreditInMonths']
    cred = row['CreditAmount']
    print("{0}\t{1}".format(dur, cred))
