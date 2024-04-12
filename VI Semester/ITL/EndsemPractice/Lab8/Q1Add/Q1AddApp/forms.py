from django import forms

class GroceryItems(forms.Form):
    items = [
        ("apples", "Apples"),
        ("mangoes", "Mangoes"),
        ("oranges", "Oranges"),
        ("milk", "Milk"),
        ("butter", "Butter")
    ]
    selected_items = forms.MultipleChoiceField(choices = items, widget = forms.CheckboxSelectMultiple)