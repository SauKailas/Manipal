# Generated by Django 5.0.4 on 2024-04-14 03:37

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Student',
            fields=[
                ('id', models.PositiveIntegerField(primary_key=True, serialize=False)),
                ('fname', models.CharField(max_length=100)),
                ('lname', models.CharField(max_length=100)),
                ('dob', models.DateField()),
                ('email', models.EmailField(max_length=254)),
                ('branch', models.CharField(max_length=100)),
            ],
        ),
    ]