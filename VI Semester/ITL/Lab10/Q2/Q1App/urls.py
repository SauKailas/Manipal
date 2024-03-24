from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name = "home"),
    path('firstPage', views.firstPage, name = "firstPage"),
    path('secondPage', views.secondPage, name = "secondPage"),
    path('findPeople', views.findPeople, name = "findPeople")
]