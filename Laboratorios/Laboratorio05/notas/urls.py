# Este archivo no fue generado por Django

from django.urls import path
from . import views

urlpatterns = [
    path('', views.lista_notas, name='lista_notas'),
    path('nueva/', views.crear_nota, name='crear_nota'),
]
