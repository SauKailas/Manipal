from django.shortcuts import render

def home(request):
    return render(request, "input.html")

def add(request):
    if request.method == 'POST':
        name = request.POST["name"]
        message = request.POST["message"]
        bold = "bold" if "bold" in request.POST else ""
        italic = "italic" if "italic" in request.POST else ""
        underline = "underline" if "underline" in request.POST else ""
        color = request.POST.get("color", "")

        context = {
            "name" : name,
            "message" : message,
            "bold" : bold,
            "italic" : italic,
            "underline" : underline,
            "color" : color
        }
        return render(request, "output.html", {'context' : context})