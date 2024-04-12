from django.db import models

class Works(models.Model):
    person = models.CharField(max_length = 100)
    company = models.CharField(max_length = 100)
    salary = models.FloatField(default = 0)

class Lives(models.Model):
    person = models.ForeignKey(Works, on_delete = models.CASCADE)
    street = models.CharField(max_length = 100)
    city = models.CharField(max_length = 100)