from django.shortcuts import render
from .models import Works, Lives
from .forms import worksForm, livesForm

def home(request):
    works = Works.objects.all()
    lives = Lives.objects.all()
    return render(request, 'index.html', {'Works' : works, 'Lives' : lives, 
                                          'worksForm' : worksForm, 'livesForm' : livesForm})

def firstPage(request):
    form = worksForm(request.POST)
    if form.is_valid():
        form.save()
    works = Works.objects.all()
    lives = Lives.objects.all()
    return render(request, 'index.html', {'Works' : works, 'Lives' : lives, 
                                          'worksForm' : worksForm, 'livesForm' : livesForm})

def secondPage(request):
    form = livesForm(request.POST)
    if form.is_valid():
        form.save()
    works = Works.objects.all()
    lives = Lives.objects.all()
    return render(request, 'index.html', {'Works' : works, 'Lives' : lives, 
                                          'worksForm' : worksForm, 'livesForm' : livesForm})

def findPeople(request):
    companyName = request.POST.get('companyName')
    people = Works.objects.filter(companyName = companyName)
    cities = Lives.objects.filter(personName__in=people.values_list('personName', flat=True)).values_list('city', flat=True).distinct()
    return render(request, 'peopleRetrieve.html', {'people': people, 'cities': cities})