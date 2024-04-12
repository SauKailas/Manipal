from django.shortcuts import render
from .forms import Student 

def firstpage(request):
    form = Student()
    return render(request, "firstPage.html", {"form" : form})

def secondpage(request):
    form = Student(request.POST)
    if form.is_valid():
        request.session['name'] = form.cleaned_data['name']
        request.session['roll'] = form.cleaned_data['roll']
        request.session['subject'] = form.cleaned_data['subject']
        print("Session Data:", request.session.items())
        context = {
            "name": request.session["name"],
            "roll": request.session["roll"],
            "subject": request.session["subject"]
        }
        print("Context:", context)
        return render(request, "secondPage.html", {"context" : context})
    else:
        return render(request, "secondPage.html", {"name" : "", "roll" : "", "subject" : ""})