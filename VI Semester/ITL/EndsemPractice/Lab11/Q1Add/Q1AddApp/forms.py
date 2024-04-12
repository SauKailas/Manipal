from django import forms 
from .models import Student

class studentForm(forms.ModelForm):
    class Meta:
        model = Student
        fields = ['id', 'name', 'course', 'dob']
        widgets = {
            'dob' : forms.DateInput(attrs={'type': 'date'})
        }