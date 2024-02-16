from django.shortcuts import render

def home(request):
    return render(request, "input.html")

def calculator(request):
    n1 = request.POST['n1']
    n2 = request.POST['n2']
    op = request.POST['op']

    if n1.isdigit() and n2.isdigit():
        n1 = int(n1)
        n2 = int(n2)

        if op == '+':
            res = n1 + n2
        elif op == '-':
            res = n1 - n2
        elif op == '*':
            res = n1 * n2 
        elif op == '/':
            res = n1 / n2 
        else:
            res = "Invalid Operator!"
    else:
        res = "Only integer numbers are allowed!"
    return render(request, "result.html", {"result" : res})
