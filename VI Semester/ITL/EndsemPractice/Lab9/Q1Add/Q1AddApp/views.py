from django.shortcuts import render
from .forms import Items

def firstpage(request):
    form = Items()
    return render(request, "firstPage.html", {'form' : form})

def secondpage(request):
    if request.method == 'POST':
        form = Items(request.POST)
        if form.is_valid():
            brand = form.cleaned_data.get("brand")
            items = form.cleaned_data.get("item")
            quantity = form.cleaned_data.get("quantity")
            items_str = ", ".join(items) if items else "None"
            cost = quantity * 100
            context = {
                "brand" : brand,
                "items" : items_str,
                "quantity" : quantity,
                "cost" : cost
            }
            return render(request, "secondPage.html", {'context' : context})
        else:
            return render(request, "firstPage.html", {'form' : form})
    else:
        form = Items()
        return render(request, "firstPage.html", {'form' : form})