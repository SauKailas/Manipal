from django.shortcuts import render
from .models import Works, Lives 
from .forms import worksForm, livesForm

def home(request):
    works_Form = worksForm()
    lives_Form = livesForm()
    return render(request, "index.html", {'worksForm' : works_Form, 'livesForm' : lives_Form})

def insert_works(request):
    if request.method == 'POST':
        form = worksForm(request.POST)
        if form.is_valid():
            form.save()
    works_Form = worksForm()
    lives_Form = livesForm()
    return render(request, "index.html", {'worksForm' : works_Form, 'livesForm' : lives_Form})

def insert_lives(request):
    if request.method == 'POST':
        form = livesForm(request.POST)
        if form.is_valid():
            form.save()
    works_Form = worksForm()
    lives_Form = livesForm()
    return render(request, "index.html", {'worksForm' : works_Form, 'livesForm' : lives_Form})