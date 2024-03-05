from django.shortcuts import render
from .forms import Voting

def firstpage(request):
    good = 1
    satisfactory = 1
    bad = 1

    if request.method=="GET":
        return render(request,'voting.html')
    elif request.method=="POST":
        form = Voting(request.POST)
        if form.is_valid():
            res = request.POST['vote']
            if res=='Good':
                good += 1
            elif res=='Satisfactory':
                satisfactory += 1
            else:
                bad += 1
    else:
        form = Voting(None)
    
    total = good + satisfactory + bad 
    pgood = good * 100 / total
    psat = satisfactory * 100 / total
    pbad = bad * 100 / total
            
    return render(request,'voting.html',{'per_good':pgood,'per_satisfactory':psat,'per_bad':pbad})