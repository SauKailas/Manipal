from django import forms 
from .models import Student

class studentForm(forms.ModelForm):
    class Meta:
        model = Student 
        fields = ['id', 'fname', 'lname', 'dob', 'email', 'branch']
        widgets = {
            'dob' : forms.DateInput(attrs={'type':'date'})
        }