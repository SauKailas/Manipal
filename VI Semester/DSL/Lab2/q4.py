import pandas as pd

student_data = {"Name" : ["Saurabh", "Messi", "Ronaldo"], 
				 "Height" : [181, 173, 183],
				 "Qualification" : ["Bachelor's Degree", "Master's Degree", "Ph.D"]}

address_list = ["Manipal Block 14, India", "Rosario 147, Argentina", "Lisboa 130, Portugal"]

df = pd.DataFrame(student_data)
df.insert(1, "Address", address_list)

print("Dataframe: ")
print(df)