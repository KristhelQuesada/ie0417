// MIT License
// 
// Copyright (c) 2024 Kristhel Quesada
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <sstream>
#include "Funciones.hpp"
using namespace std;

// https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
// Funcion que verifica la opcion ingresada en el menu
int verifyMenuOption(string input, int out_range) {
    int size_input = size(input); // determina el tamanio del string
    int verified_input;

    // Las opciones que queremos verificar solo tienen un caracter,
    // por tanto se pregunta si esto sucede
    if (size_input == 1) {

        // Luego se crea el objeto de la clase istringstream
        istringstream objetoEntrada(input);

        // Verifica si el caracter es un numero
        /* Para ello intenta extraer un entero de la cadena con
            objetoEntrada >> verified_input
           que devuelve true si la extraccion fue exitosa
        */
        if (objetoEntrada >> verified_input) {
            return verified_input;
        } else {
            return out_range;
        }

    } else {
        return out_range;
    }
}