from django.shortcuts import render
from .models import Category, Page
from .forms import catForm, pageForm

def home(request):
    categories = Category.objects.all()
    pages = Page.objects.all()
    return render(request, 'index.html', {'Categories' : categories, 'Pages' : pages,
                                          'catForm' : catForm(), 'pageForm' : pageForm()})

def firstPage(request):
    form = catForm(request.POST)
    if form.is_valid():
        form.save()
    categories = Category.objects.all()
    pages = Page.objects.all()
    return render(request, 'index.html', {'Categories' : categories, 'Pages' : pages,
                                          'catForm' : catForm(), 'pageForm' : pageForm()})

def secondPage(request):
    form = pageForm(request.POST)
    if form.is_valid():
        form.save()
    categories = Category.objects.all()
    pages = Page.objects.all()
    return render(request, 'index.html', {'Categories' : categories, 'Pages' : pages,
                                          'catForm' : catForm(), 'pageForm' : pageForm()})