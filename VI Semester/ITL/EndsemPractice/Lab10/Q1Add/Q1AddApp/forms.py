from django import forms 
from .models import Institutes

class instituteForm(forms.ModelForm):
    class Meta:
        model = Institutes
        fields = ['id', 'name', 'no_courses']
