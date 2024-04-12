from django import forms 
from .models import Author, Publisher, Book

class AuthorForm(forms.ModelForm):
    class Meta:
        model = Author
        fields = ['fname', 'lname', 'email']

class PublisherForm(forms.ModelForm):
    class Meta:
        model = Publisher
        fields = ['pname', 'street', 'city', 'state', 'country', 'website']

class BookForm(forms.ModelForm):
    class Meta:
        model = Book
        fields = ['title', 'publication', 'authors', 'publisher']