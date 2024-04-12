from django.shortcuts import render

def home(request):
    return render(request, "index.html")

def calculate(request):
    if request.method == "POST":
        op = request.POST["operator"]
        n1 = int(request.POST["n1"])
        n2 = int(request.POST["n2"])

        if op == '+':
            res = n1 + n2 
        elif op == '-':
            res = n1 - n2
        elif op == '*':
            res = n1 * n2
        elif op == '/':
            res = n1 / n2 
    return render(request, "result.html", {'result' : res})