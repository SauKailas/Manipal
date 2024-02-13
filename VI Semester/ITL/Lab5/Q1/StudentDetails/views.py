from django.shortcuts import render

def home(request):
    return render(request, "input.html")

def student(request):
    details = {
        'Name' : request.POST['name'],
        'DOB' : request.POST['dob'],
        'Address' : request.POST['address'],
        'Contact' : request.POST['contact'],
        'Email' : request.POST['email'],
    }

    num1 = request.POST['english']
    num2 = request.POST['physics']
    num3 = request.POST['chemistry']

    if num1.isdigit() and num2.isdigit() and num3.isdigit():
        a = int(num1)
        b = int(num2)
        c = int(num3)
        avg = str((a + b + c) / 3)
        if len(avg) > 5:
            avg = (avg)[:4]
        res = float(avg)
        return render(request, "result.html", {"result" : res, "details" : details})
    else:
        res =  "Only digits are allowed!"
        return render(request, "result.html", {"result" : res, "details" : details})
    

