from django.shortcuts import render
from ntpath import join 
from datetime import date, datetime

def home(request):
    return render(request, "index.html")

def employee(request):
    join_date = request.POST['date']
    current_year = date.today().year
    joining_year = datetime.strptime(join_date, '%d/%m/%Y').year 
    print(current_year)
    print(joining_year)
    if(current_year - joining_year > 5):
        result = "YES"
    else:
        result = "NO"
    return render(request, "result.html", {"result" : result})