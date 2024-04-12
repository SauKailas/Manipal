from django.urls import path 
from . import views 

urlpatterns = [
    path('', views.home, name="home"),
    path('insert_works', views.insert_works, name="insert_works"),
    path('insert_lives', views.insert_lives, name="insert_lives")
]