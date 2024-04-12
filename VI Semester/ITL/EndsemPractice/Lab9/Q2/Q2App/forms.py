from django import forms 

class Vote(forms.Form):
    choices = [("good", "Good"), ("satisfactory", "Satisfactory"), ("bad", "Bad")]
    vote = forms.ChoiceField(label="Vote", widget = forms.RadioSelect(choices = choices))