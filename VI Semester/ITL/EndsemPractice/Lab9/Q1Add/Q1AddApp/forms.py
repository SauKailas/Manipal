from django import forms 

class Items(forms.Form):
    brand_choices = [("apple", "Apple"), ("samsung", "Samsung"), ("motorola", "Motorola"), 
               ("hp", "HP"), ("nokia", "Nokia")]
    brand = forms.ChoiceField(label = "Brand", choices = brand_choices, widget = forms.RadioSelect)
    item_choices = [("laptop", "Laptop"), ("mobile", "Mobile")]
    item = forms.MultipleChoiceField(label = "Item", choices = item_choices, widget = forms.CheckboxSelectMultiple)
    quantity = forms.IntegerField(label = "Quantity", widget = forms.NumberInput)
