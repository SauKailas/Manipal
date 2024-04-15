from django.db import models

class Student(models.Model):
    id = models.PositiveIntegerField(primary_key = True)
    name = models.CharField(max_length = 100)
    dob = models.DateField()
    branch = models.CharField(max_length = 100)