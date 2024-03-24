from django import forms
from .models import Works, Lives

class worksForm(forms.ModelForm):
    class Meta:
        model = Works
        fields = ['personName', 'companyName', 'salary']

class livesForm(forms.ModelForm):
    class Meta:
        model = Lives
        fields = ['personName', 'street', 'city']

