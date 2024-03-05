from django.shortcuts import render
from .forms import Registration

def firstpage(request):
    context = {}
    myForm = Registration(request.POST or None)
    context["form"] = myForm 
    return render(request, 'register.html', context)

def secondpage(request):
    context = {}
    myRegistration = Registration(request.POST)
    if myRegistration.is_valid():
        username = myRegistration.cleaned_data["username"]
        email = myRegistration.cleaned_data["email"]
        contact = myRegistration.cleaned_data["contact"]
    else:
        myRegistration = Registration(None)
    context["username"] = username
    context["email"] = email
    context["contact"] = contact
    return render(request, 'success.html', context)