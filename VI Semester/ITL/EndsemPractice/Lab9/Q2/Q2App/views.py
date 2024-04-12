from django.shortcuts import render
from .forms import Vote

def home(request):
    return render(request, "index.html")

def voting(request):
    count_g, count_s, count_b = 1, 1, 1

    if request.method == "POST":
        form = Vote(request.POST)
        if form.is_valid():
            res = request.cleaned_data.get("vote")
            if res == 'good':
                count_g += 1
            elif res == 'bad':
                count_b += 1
            else:
                count_s += 1 
    else:
        form = Vote()
    sum = count_g + count_s + count_b
    context = {
        'per_good' : count_g / sum,
        'per_satis' : count_s / sum,
        'per_bad' : count_b / sum
    }
    return render(request, "index.html", {'form' : form, 'context' : context})