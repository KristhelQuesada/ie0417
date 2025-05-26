from django.shortcuts import render

# Create your views here.
from django.shortcuts import render, redirect
from .models import Nota
from .forms import NotaForm

def lista_notas(request):
    notas = Nota.objects.all()
    return render(request, 'notas/lista_notas.html', {'notas': notas})

def crear_nota(request):
    if request.method == 'POST':
        form = NotaForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('lista_notas')
    else:
        form = NotaForm()
    return render(request, 'notas/crear_nota.html', {'form': form})
