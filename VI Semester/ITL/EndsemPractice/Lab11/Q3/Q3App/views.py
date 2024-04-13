from django.shortcuts import render, redirect
from .models import Human 
from .forms import humanForm 

def home(request):
    humans = Human.objects.all()
    form = humanForm()
    return render(request, "index.html", {'form' : form, 'humans' : humans})

def update(request):
    humans = Human.objects.all()
    if request.method == 'POST':
        form = humanForm(request.POST)
        if form.is_valid():
            form.save()
            redirect('home')
    else:
        form = humanForm()
    return render(request, "index.html", {'form' : form, 'humans' : humans})

def delete(request, id):
    human = Human.objects.get(id = id)
    human.delete()
    humans = Human.objects.all()
    form = humanForm()
    return render(request, "index.html", {'form' : form, 'humans' : humans})