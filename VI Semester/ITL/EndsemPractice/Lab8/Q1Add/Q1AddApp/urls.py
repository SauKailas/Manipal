from django.urls import path 
from . import views 

urlpatterns = [
    path('', views.home, name="home"),
    path('print_items', views.print_items, name="print_items")
]