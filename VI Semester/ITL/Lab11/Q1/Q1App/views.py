from django.shortcuts import render
from .models import Author, Publisher, Book
from .forms import AuthorForm, PublisherForm, BookForm

def home(request):
    authorForm = AuthorForm()
    publisherForm = PublisherForm()
    bookForm = BookForm()
    authors = Author.objects.all()
    publishers = Publisher.objects.all()
    books = Book.objects.all()
    return render(request, "index.html", {'authorForm' : authorForm, 'publisherForm' : publisherForm,
                                          'bookForm' : bookForm, 'authors' : authors, 
                                          'publishers' : publishers, 'books' : books})

def insert_author(request):
    if request.method == "POST":
        form = AuthorForm(request.POST)
        if form.is_valid():
            form.save()
    authorForm = AuthorForm()
    publisherForm = PublisherForm()
    bookForm = BookForm()
    authors = Author.objects.all()
    publishers = Publisher.objects.all()
    books = Book.objects.all()
    return render(request, "index.html", {'authorForm' : authorForm, 'publisherForm' : publisherForm,
                                          'bookForm' : bookForm, 'authors' : authors, 
                                          'publishers' : publishers, 'books' : books})

def insert_publisher(request):
    if request.method == "POST":
        form = PublisherForm(request.POST)
        if form.is_valid():
            form.save()
    authorForm = AuthorForm()
    publisherForm = PublisherForm()
    bookForm = BookForm()
    authors = Author.objects.all()
    publishers = Publisher.objects.all()
    books = Book.objects.all()
    return render(request, "index.html", {'authorForm' : authorForm, 'publisherForm' : publisherForm,
                                          'bookForm' : bookForm, 'authors' : authors, 
                                          'publishers' : publishers, 'books' : books})

def insert_book(request):
    if request.method == "POST":
        form = BookForm(request.POST)
        if form.is_valid():
            form.save()
    authorForm = AuthorForm()
    publisherForm = PublisherForm()
    bookForm = BookForm()
    authors = Author.objects.all()
    publishers = Publisher.objects.all()
    books = Book.objects.all()
    return render(request, "index.html", {'authorForm' : authorForm, 'publisherForm' : publisherForm,
                                          'bookForm' : bookForm, 'authors' : authors, 
                                          'publishers' : publishers, 'books' : books})