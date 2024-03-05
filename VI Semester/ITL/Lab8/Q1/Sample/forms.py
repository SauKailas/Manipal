from django import forms

class form(forms.Form):
    username = forms.CharField(max_length = 100)
    contact = forms.IntegerField()