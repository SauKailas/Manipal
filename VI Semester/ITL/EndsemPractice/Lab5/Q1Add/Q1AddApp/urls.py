from django.urls import path
from . import views 

urlpatterns = [
    path('', views.generate_captcha, name="generate_captcha"),
    path('generate_captcha', views.generate_captcha, name="generate_captcha")
]