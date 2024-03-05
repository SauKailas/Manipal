from django import forms

class Car(forms.Form):
    options = (("Ferrari", "Ferrari"), ("Lamborghini", "Lamborghini"), ("Mclaren", "Mclaren"), ("Aston Martin", "Aston Martin"))
    manufacturer = forms.ChoiceField(choices = options, label = "Manufacturer")
    model = forms.CharField(label = "Model")