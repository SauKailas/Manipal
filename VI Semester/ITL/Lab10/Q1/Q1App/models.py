from django.db import models

class Category(models.Model):
    catName = models.CharField(max_length = 100)
    numVisits = models.PositiveIntegerField(default = 0)
    numLikes = models.PositiveIntegerField(default = 0)

class Page(models.Model):
    catName = models.ForeignKey(Category, on_delete = models.CASCADE)
    pageTitle = models.CharField(max_length = 100)
    pageURL = models.URLField()
    numViews = models.PositiveIntegerField(default = 0)