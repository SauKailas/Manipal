from django.shortcuts import render
from .models import Institutes
from .forms import instituteForm

def home(request):
    if request.method == 'POST':
        form = instituteForm(request.POST)
        if form.is_valid():
            form.save()
    form = instituteForm()
    institutes = Institutes.objects.all()
    return render(request, "index.html", {'form' : form, 'institutes' : institutes})