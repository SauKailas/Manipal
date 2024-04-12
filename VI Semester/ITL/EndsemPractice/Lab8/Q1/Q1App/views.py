from django.shortcuts import render
from .forms import Car

def home(request):
    form = Car()
    return render(request, "index.html", {"form" : form})

def display_details(request):
    manufacturer = request.POST["manufacturer"]
    model = request.POST["model"]
    return render(request, "result.html", {"manufacturer" : manufacturer, "model" : model})