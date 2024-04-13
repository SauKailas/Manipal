from django.db import models

class Human(models.Model):
    id = models.PositiveIntegerField(primary_key = True)
    fname = models.CharField(max_length = 100)
    lname = models.CharField(max_length = 100)
    phone = models.PositiveIntegerField(default = 0)
    address = models.CharField(max_length = 100)
    city = models.CharField(max_length = 100)
