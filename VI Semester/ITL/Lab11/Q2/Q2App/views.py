from django.shortcuts import render
from .models import Products
from .forms import productForm

def home(request):
    form = productForm()
    products = Products.objects.all()
    return render(request, "index.html", {'form' : form, 'products' : products})

def insert(request):
    if request.method == 'POST':
        form = productForm(request.POST)
        if form.is_valid():
            form.save()
    form = productForm()
    products = Products.objects.all()
    return render(request, "index.html", {'form' : form, 'products' : products})