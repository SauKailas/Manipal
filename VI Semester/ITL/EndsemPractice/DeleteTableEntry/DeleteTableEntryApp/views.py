from django.shortcuts import render, redirect
from .models import Student
from .forms import studentForm

def home(request):
    students = Student.objects.all()
    form = studentForm()
    return render(request, "input.html", {'students' : students, 'form' : form})

def add_student(request):
    if request.method == 'POST':
        form = studentForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('home')
    else:
        students = Student.objects.all()
        form = studentForm()
        return render(request, "input.html", {'students' : students, 'form' : form})

def delete_student(request, student_id):
    if request.method == 'POST':
        student = Student.objects.filter(id = student_id)
        if student:
            student.delete()
            return redirect('home')
    else:
        students = Student.objects.all()
        form = studentForm()
        return render(request, "input.html", {'students' : students, 'form' : form})
