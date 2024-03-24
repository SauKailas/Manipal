from django import forms
from .models import Category, Page

class catForm(forms.ModelForm):
    class Meta:
        model = Category
        fields = ['catName', 'numVisits', 'numLikes']

class pageForm(forms.ModelForm):
    class Meta:
        model = Page
        fields = ['catName', 'pageTitle', 'pageURL', 'numViews']