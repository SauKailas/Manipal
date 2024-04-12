from django.shortcuts import render
from .forms import User

def register(request):
    form = User()
    return render(request, "register.html", {'form' : form})

def success(request):
    form = User(request.POST)
    if form.is_valid():
        context = {
            "username" : form.cleaned_data.get("username"),
            "email" : form.cleaned_data.get("email"),
            "contact" : form.cleaned_data.get("contact")
        }
        return render(request, "success.html", {'context' : context})
    else:
        form = User()
        return render(request, "register.html", {'form' : form})