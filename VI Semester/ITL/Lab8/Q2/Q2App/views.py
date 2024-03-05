from django.shortcuts import render
from .forms import Car

def home(request):
    context = {}
    myForm = Car(request.POST or None)
    context['form'] = myForm
    return render(request, "input.html", context)

def result(request):
    context = {}
    manufacturer = "NONE"
    model = "NONE"
    myForm = Car(request.POST)
    if myForm.is_valid():
        manufacturer = myForm.cleaned_data["manufacturer"]
        model = myForm.cleaned_data["model"]
    else:
        myForm = Car(None)
    context["manufacturer"] = manufacturer
    context["model"] = model
    return render(request, "result.html", context)