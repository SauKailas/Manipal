from django import forms 

class Feedback(forms.Form):
    name = forms.CharField(label = "Name")
    sex_choices = [("male", "Male"), ("female", "Female")]
    sex = forms.ChoiceField(label = "Sex", choices = sex_choices, widget = forms.RadioSelect)
    course_choices = [("ASP-XML", "ASP-XML"), ("DotNET", "DotNET"), ("JavaPro", "JavaPro"),
                    ("Unix", "Unix"), ("C", "C"), ("C++", "C++")]
    course = forms.ChoiceField(label = "Course", choices = course_choices)
    technical_choices = [("excellent", "Excellet"), ("good", "Good"), ("average", "Average"), ("poor", "Poor")]
    technical = forms.ChoiceField(label = "Technical Choices", choices = technical_choices, widget = forms.RadioSelect)
    suggestions = forms.CharField(label = "Suggestions", widget = forms.Textarea)