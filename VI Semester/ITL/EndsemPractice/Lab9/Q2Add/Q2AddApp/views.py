from django.shortcuts import render
from .forms import Feedback

def home(request):
    prefix = ""
    name = ""
    form = Feedback()
    return render(request, "suggestions.html", {'form' : form, 'prefix' : prefix, 'name' : name})

def display(request):
    if request.method == 'POST':
        form = Feedback(request.POST)
        if form.is_valid():
            name = form.cleaned_data.get("name")
            sex = form.cleaned_data.get("sex")
            if sex == 'male':
                prefix = "Mr."
            else:
                prefix = "Miss"
            form = Feedback()
            return render(request, "suggestions.html", {'form' : form, 'prefix' : prefix, 'name' : name})
        else:
            output = ""
            prefix = ""
            name = ""
            form = Feedback()
            return render(request, "suggestions.html", {'form' : form, 'prefix' : prefix, 'name' : name})    