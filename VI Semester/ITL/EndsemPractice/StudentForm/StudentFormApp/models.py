from django.db import models

class Student(models.Model):
    id = models.PositiveIntegerField(primary_key = True)
    fname = models.CharField(max_length = 100)
    lname = models.CharField(max_length = 100)
    dob = models.DateField()
    email = models.EmailField()
    branch = models.CharField(max_length = 100)