import pandas as pd

student_names = {"Name" : ["Ram", "Diya", "Chandan", "James", "Alice"]}
df1 = pd.DataFrame(student_names)

student_marks = {"Maths" : [80.0, 90.0, 77.5, 87.5, 86.5], 
                 "Physics" : [81.0, 94.0, 74.5, 83.0, 82.5],
                 "Chemistry" : [91.5, 86.5, 85.5, 90.0, 91.0],
                 "Biology" : [82.5, 83.5, 84.5, 85.0, 93.0]}
df2 = pd.DataFrame(student_marks)

df3 = pd.concat([df1, df2], axis = 1)
df3["Total"] = df3[["Maths", "Physics", "Chemistry", "Biology"]].sum(axis = 1)

print("Dataframe:")
print(df3)