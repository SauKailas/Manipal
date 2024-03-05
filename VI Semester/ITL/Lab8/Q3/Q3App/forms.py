from django import forms

class Student(forms.Form):
    name = forms.CharField(max_length=50, label="Name")
    roll = forms.IntegerField(max_value=100, label="Roll Number")
    choices = (("DS", "DS"), ("PCAP", "PCAP"), ("EEFM", "EEFM"), ("BDA", "BDA"), ("DWDM", "DWDM"))
    subject = forms.ChoiceField(choices=choices, label="Subject")