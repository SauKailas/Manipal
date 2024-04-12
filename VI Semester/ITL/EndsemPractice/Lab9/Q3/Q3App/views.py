from django.shortcuts import render
from .forms import Marks

def firstpage(request):
    form = Marks()
    return render(request, "firstPage.html", {'form' : form})

def secondpage(request):
    if request.method == 'POST':
        form = Marks(request.POST)
        if form.is_valid():
            name = form.cleaned_data.get("name")
            marks = form.cleaned_data.get("marks")
            avg = marks / 50
            return render(request, "secondPage.html", {'name' : name, 'avg' : avg})
    else:
        form = Marks()
        return render(request, "firstPage.html", {'form' : form})