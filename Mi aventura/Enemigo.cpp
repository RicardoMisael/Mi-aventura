// Enemigo.cpp
#include "Enemigo.h"

Enemigo::Enemigo(const std::string& nombre) : nombre(nombre) {
    // L�gica adicional si es necesario
}

std::string Enemigo::obtenerNombre() const {
    return nombre;
}
