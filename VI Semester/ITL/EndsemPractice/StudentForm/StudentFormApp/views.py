from django.shortcuts import render, redirect
from .models import Student
from .forms import studentForm

def home(request):
    students = Student.objects.all()
    form = studentForm()
    return render(request, "index.html", {'students' : students, 'form' : form})

def update_student(request):
    if request.method == 'POST':
        form = studentForm(request.POST)
        if form.is_valid():
            form.save()
            redirect('home')
    else: 
        form = studentForm()
    students = Student.objects.all()
    return render(request, "index.html", {'students' : students, 'form' : form})

