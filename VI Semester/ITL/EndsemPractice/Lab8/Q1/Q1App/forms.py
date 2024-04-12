from django import forms 

class Car(forms.Form):
    manufacturer = forms.ChoiceField(choices = [("Audi", "Audi"), ("BMW", "BMW"), ("Ferrari", "Ferrari"), ("Lamborghini", "Lamborghini"),
                                                ("Bugatti", "Bugatti")], label = "manufacturer")
    model = forms.CharField(label = "model")