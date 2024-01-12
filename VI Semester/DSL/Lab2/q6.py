import pandas as pd 

student_marks = {"Name" : ["Annie", "Diya", "Charles", "James", "Emily", "Saurabh"], 
                 "Quiz_1/10" : [8.0, 9.0, 7.5, 8.5, 6.5, 7.9],
                 "In_Sem_1/15" : [11.0, 14.0, 14.5, 13.0, 12.5, 13.0],
                 "Quiz_2/10" : [9.5, 6.5, 8.5, 9.0, 9.0, 8.5],
                 "In_Sem_2/15" : [12.5, 13.5, 14.5, 15.0, 13.0, 13.7]}
df = pd.DataFrame(student_marks)

df["Total"] = df[["Quiz_1/10", "In_Sem_1/15", "Quiz_2/10", "In_Sem_2/15"]].sum(axis=1)
mean_row = df[["Quiz_1/10", "In_Sem_1/15", "Quiz_2/10", "In_Sem_2/15", "Total"]].mean(axis=0)
df.loc["Mean"] = mean_row

print("Dataframe: ")
print(df)