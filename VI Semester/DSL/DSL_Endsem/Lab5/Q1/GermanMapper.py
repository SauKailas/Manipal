import pandas as pd 

df = pd.read_excel("Datasets/GermanCredit.xlsx", engine="openpyxl")

for amount in df["Creditability"]:
	print("%s,,%s" % (amount, 1))