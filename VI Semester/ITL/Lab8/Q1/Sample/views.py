from django.shortcuts import render
from .forms import form

def home(request):
    context = {}
    myForm = form(request.POST or None)
    context['form'] = myForm
    return render(request, "input.html", context)

def login(request):
    username = "NONE"
    contact = "00000"
    myForm = form(request.POST)
    if myForm.is_valid():
        username = myForm.cleaned_data["username"]
        contact = myForm.cleaned_data["contact"]
        request.session["username"] = username
    else:
        myForm = form()
    context = {"username" : username, "contact" : contact}
    return render(request, "login.html", context)

def logout(request):
    del request.session["username"]
    return render(request, "logout.html")
