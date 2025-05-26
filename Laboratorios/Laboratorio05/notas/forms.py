# Este archivo no fue creado por Django
from django import forms
from .models import Nota

class NotaForm(forms.ModelForm):
    class Meta:
        model = Nota
        fields = ['titulo', 'contenido']
