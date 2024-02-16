from django.shortcuts import render

def home(request):
    return render(request, "input.html")

def marks(request):
    maths = request.POST['maths']
    physics = request.POST['physics']
    chemistry = request.POST['chemistry']
    history = request.POST['history']
    geography = request.POST['geography']

    if maths.isdigit() and physics.isdigit() and chemistry.isdigit() and history.isdigit() and geography.isdigit():
        maths = int(maths)
        physics = int(physics)
        chemistry = int(chemistry)
        history = int(history)
        geography = int(geography)

        res = (maths + physics + chemistry + history + geography) / 5
    else:
        res = "Only integers are allowed!"

    return render(request, "result.html", {"result" : res})
    
