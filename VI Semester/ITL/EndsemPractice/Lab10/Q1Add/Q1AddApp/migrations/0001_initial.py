# Generated by Django 5.0.4 on 2024-04-12 13:29

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Institutes',
            fields=[
                ('id', models.PositiveIntegerField(default=0, primary_key=True, serialize=False)),
                ('name', models.CharField(max_length=100)),
                ('no_courses', models.PositiveIntegerField(default=0)),
            ],
        ),
    ]
