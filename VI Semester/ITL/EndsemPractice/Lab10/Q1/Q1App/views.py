from django.shortcuts import render, redirect
from .models import Category, Page 
from .forms import pageForm, catForm

def home(request):
    cat_form = catForm()
    page_form = pageForm() 
    categories = Category.objects.all()
    pages = Page.objects.all()
    return render(request, "index.html", {'cat_Form': cat_form, 'page_Form': page_form, 'categories': categories, 'pages': pages})

def category(request):
    form = catForm(request.POST)
    if form.is_valid():
        form.save()
        cat_form = catForm()
        page_form = pageForm() 
        categories = Category.objects.all()
        pages = Page.objects.all()
        return render(request, "index.html", {'cat_Form': cat_form, 'page_Form': page_form, 'categories': categories, 'pages': pages})

def page(request):
    form = pageForm(request.POST)
    if form.is_valid():
        form.save()
        cat_form = catForm()
        page_form = pageForm() 
        categories = Category.objects.all()
        pages = Page.objects.all()
        return render(request, "index.html", {'cat_Form': cat_form, 'page_Form': page_form, 'categories': categories, 'pages': pages})