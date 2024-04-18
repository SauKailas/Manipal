import pandas as pd 

df = pd.read_excel("Datasets/GermanCredit.xlsx", engine = "openpyxl")

for duration, amount in zip(df["DurationOfCreditInMonths"], df["CreditAmount"]):
	print('%s\t%s' % (duration, amount))