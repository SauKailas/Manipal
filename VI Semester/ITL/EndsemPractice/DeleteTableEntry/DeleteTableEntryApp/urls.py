from django.urls import path 
from . import views 

urlpatterns = [
    path('', views.home, name="home"),
    path('add_student', views.add_student, name="add_student"),
    path('delete_student/<int:student_id>/', views.delete_student, name="delete_student")
]