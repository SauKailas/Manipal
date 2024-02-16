from django.shortcuts import render

def home(request):
    return render(request, "input.html")

def employee(request):
    id = int(request.POST['id'])
    join_year = int(request.POST['year'])
    curr_year = 2024

    if curr_year - join_year > 5:
        res = "YES"
    else:
        res = "NO"
    
    return render(request, "result.html", {"result" : res, "id" : id})