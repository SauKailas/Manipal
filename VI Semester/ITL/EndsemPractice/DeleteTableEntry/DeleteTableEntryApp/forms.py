from django import forms 
from .models import Student

class studentForm(forms.ModelForm):
    class Meta:
        model = Student
        fields = ['id', 'name', 'dob', 'branch']
        widgets = {
            'dob' : forms.DateInput(attrs = {'type' : 'date'})
        }