from django import forms

class User(forms.Form):
    username = forms.CharField(label = "Username", required = True)
    password = forms.CharField(label = "Password", widget = forms.PasswordInput(), required = False)
    email = forms.CharField(label = "Email", widget = forms.EmailInput(), required = False)
    contact = forms.IntegerField(label = "Contact", widget = forms.NumberInput(), min_value = 
                                 0000000000, max_value = 9999999999, required = False) 
    