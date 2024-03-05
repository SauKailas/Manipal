from django.shortcuts import render
from .forms import Student

def home(request):
    context = {}
    myForm = Student(request.POST or None)
    context["form"] = myForm
    return render(request, "firstPage.html", context)

def firstpage(request):
    context = {}
    a = request.session
    myForm = Student(request.POST)
    if myForm.is_valid():
        a["name"] = myForm.cleaned_data["name"]
        a["roll"] = myForm.cleaned_data["roll"]
        a["subject"] = myForm.cleaned_data["subject"]
        return render(request, "secondPage.html", {"name" : a["name"], "roll" : a["roll"], "subject" : a["subject"]})
    else:
        return render(request, "secondPage.html", {"name" : "", "roll" : "", "subject" : ""})

def secondpage(request):
    if request.session.has_key("name"):
        del request.session["name"]
    if request.session.has_key("roll"):
        del request.session["roll"]
    if request.session.has_key("subject"):
        del request.session["subject"]
    context = {}
    myForm = Student(request.POST or None)
    context["form"] = myForm
    return render(request, "firstPage.html", context)