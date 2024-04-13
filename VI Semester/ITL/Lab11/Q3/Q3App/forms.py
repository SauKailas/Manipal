from django import forms 
from .models import Human 

class humanForm(forms.ModelForm):
    class Meta:
        model = Human 
        fields = ['id', 'fname', 'lname', 'phone', 'address', 'city']