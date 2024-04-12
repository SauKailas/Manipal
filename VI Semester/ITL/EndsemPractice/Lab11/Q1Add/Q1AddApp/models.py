from django.db import models

class Student(models.Model):
    id = models.PositiveIntegerField(primary_key = True)
    name = models.CharField(max_length = 100)
    course = models.CharField(max_length = 100)
    dob = models.DateField()