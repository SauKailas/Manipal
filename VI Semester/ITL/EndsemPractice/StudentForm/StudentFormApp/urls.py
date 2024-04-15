from django.urls import path 
from . import views 

urlpatterns = [
    path('', views.home, name="home"),
    path('update_student', views.update_student, name="update_student")
]