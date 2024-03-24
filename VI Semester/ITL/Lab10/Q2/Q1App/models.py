from django.db import models

class Works(models.Model):
    personName = models.CharField(max_length = 100)
    companyName = models.CharField(max_length = 100)
    salary = models.FloatField(default = 0)

class Lives(models.Model):
    personName = models.ForeignKey(Works, on_delete = models.CASCADE)
    street = models.CharField(max_length = 30)
    city = models.CharField(max_length = 30)