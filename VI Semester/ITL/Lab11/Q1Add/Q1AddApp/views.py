from django.shortcuts import render
from .models import Student
from .forms import studentForm

def home(request):
    form = studentForm()
    students = Student.objects.all()
    return render(request, "index.html", {'form' : form, 'students' : students})

def register(request):
    if request.method == 'POST':
        form = studentForm(request.POST)
        if form.is_valid():
            form.save()
    form = studentForm()
    students = Student.objects.all()
    return render(request, "index.html", {'form' : form, 'students' : students})