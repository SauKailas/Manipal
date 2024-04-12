from django.shortcuts import render

def home(request):
    return render(request, "index.html")

def student(request):
    details = {
        'name' : request.POST["name"],
        'dob' : request.POST["dob"],
        'address' : request.POST["address"],
        'contact' : request.POST["contact"],
        'email' : request.POST["email"]
    }
    num1 = request.POST['eng']
    num2 = request.POST['phy']
    num3 = request.POST['chem']

    if num1.isdigit() and num2.isdigit() and num3.isdigit():
        a = int(num1)
        b = int(num2)
        c = int(num3)
        avg = str((a + b + c) / 3)
        avg = avg[:4]
        return render(request, "result.html", {'details' : details, 'result' : avg})
    else:
        res = "Only Digits Allowed!"
        return render(request, "result.html", {'result' : res})