from django.urls import path 
from . import views 

urlpatterns = [
    path('', views.home, name="home"),
    path('display_details', views.display_details, name="display_details")
]