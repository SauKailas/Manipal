from django import forms

class Student(forms.Form):
    name = forms.CharField(label = "name")
    roll = forms.IntegerField(label = "roll", min_value=210905000, max_value=210905999,
                            widget = forms.NumberInput())   
    subject = forms.ChoiceField(label = "subject", choices = [("Mathematics", "Mathematics"),
                            ("Physics", "Physics"), ("Chemistry", "Chemistry")])
