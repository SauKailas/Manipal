from django.db import models

class Products(models.Model):
    title = models.CharField(max_length = 100)
    price = models.FloatField(default = 0.0)
    description = models.TextField()