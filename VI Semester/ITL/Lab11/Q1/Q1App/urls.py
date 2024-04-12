from django.urls import path
from . import views 

urlpatterns = [
    path('', views.home, name="home"),
    path('insert_author', views.insert_author, name="insert_author"),
    path('insert_publisher', views.insert_publisher, name="insert_publisher"),
    path('insert_book', views.insert_book, name="insert_book")
]