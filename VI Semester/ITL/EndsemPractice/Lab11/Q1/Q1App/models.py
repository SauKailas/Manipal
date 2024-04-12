from django.db import models

class Author(models.Model):
    fname = models.CharField(max_length = 100)
    lname = models.CharField(max_length = 100)
    email = models.EmailField(unique = True)

class Publisher(models.Model):
    pname = models.CharField(max_length = 100)
    street = models.CharField(max_length = 100)
    city = models.CharField(max_length = 100)
    state = models.CharField(max_length = 100)
    country = models.CharField(max_length = 100)
    website = models.URLField()

class Book(models.Model):
    title = models.CharField(max_length = 100)
    publication = models.DateField()
    authors = models.ManyToManyField(Author)
    publisher = models.ForeignKey(Publisher, on_delete = models.CASCADE)