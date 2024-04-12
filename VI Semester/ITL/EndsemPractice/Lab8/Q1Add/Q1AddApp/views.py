from django.shortcuts import render
from .forms import GroceryItems

def home(request):
    form = GroceryItems()
    selected_items = []
    return render(request, "index.html", {'form' : form, 'selected_items' : selected_items})

def print_items(request):
    selected_items = []

    if request.method == "POST":
        form = GroceryItems(request.POST)
        if form.is_valid():
            selected_items_names = form.cleaned_data.get("selected_items")
            if selected_items_names:
                for item in selected_items_names:
                    selected_items.append((item, "20.0"))
    else:
        form = GroceryItems()
    return render(request, "index.html", {'form' : form, 'selected_items' : selected_items})