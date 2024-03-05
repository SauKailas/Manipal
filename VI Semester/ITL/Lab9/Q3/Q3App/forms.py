from django import forms

class Voting(forms.Form):
    choices = (
        ('Good', "Good"),
        ('Satisfactory', 'Satisfactory'),
        ('Bad', 'Bad')
    )
    vote = forms.ChoiceField(widget=forms.RadioSelect(choices=choices))