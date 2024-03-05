from django import forms

class CGPA(forms.Form):
    name = forms.CharField(max_length=30, required=True)
    marks = forms.CharField(max_length=5, required=True)