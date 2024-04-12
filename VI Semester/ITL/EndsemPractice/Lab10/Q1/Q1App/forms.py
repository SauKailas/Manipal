from django import forms
from .models import Category, Page

class catForm(forms.ModelForm):
    class Meta:
        model = Category
        fields = ['name', 'visits', 'likes']

class pageForm(forms.ModelForm):
    class Meta:
        model = Page
        fields = ['name', 'title', 'url', 'views']