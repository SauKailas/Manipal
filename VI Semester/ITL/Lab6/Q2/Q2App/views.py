from django.shortcuts import render

def home(request):
    return render(request, "input.html")

def add(request):
    context = {
        "text" : request.POST["text"],
        "title" : request.POST["title"],
        "background_color" : request.POST["background_color"],
        "font_size" : request.POST["font_size"],
        "title_size" : request.POST["title_size"],
        "title_font" : request.POST["title_font"]
    }
    return render(request, "output.html", {'context' : context})