from django.shortcuts import render
from .forms import CGPA

def firstPage(request):
    context = {}
    myForm = CGPA(request.POST or None)
    context["form"] = myForm
    return render(request, "firstpage.html", context)

def secondPage(request):
    context = {}
    myForm = CGPA(request.POST)
    if myForm.is_valid():
        name = myForm.cleaned_data["name"]
        marks = myForm.cleaned_data["marks"]
        marks = int(marks)
        cgpa = str(float(marks/50))
        context["name"] = name
        context["cgpa"] = cgpa
    else:
        myForm = CGPA(None)
    return render(request, "secondpage.html", context)
