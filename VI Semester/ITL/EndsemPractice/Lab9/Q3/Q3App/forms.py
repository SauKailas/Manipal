from django import forms  

class Marks(forms.Form):
    name = forms.CharField(label = "Name", max_length = 30)
    marks = forms.IntegerField(label = "Marks", widget = forms.NumberInput(), min_value = 0, max_value = 500)