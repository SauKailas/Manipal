from django.urls import path 
from . import views

urlpatterns = [
    path('', views.firstpage, name="firstpage"),
    path('firstpage', views.firstpage, name="firstpage")
]