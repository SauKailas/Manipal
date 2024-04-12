from django.db import models

class Institutes(models.Model):
    id = models.PositiveIntegerField(primary_key=True, default = 0)
    name = models.CharField(max_length = 100)
    no_courses = models.PositiveIntegerField(default = 0)