#include "Item.h"

Item::Item(const std::string& nombre) : nombre(nombre) {}

std::string Item::obtenerNombre() const {
    return nombre;
}

// Implementación del operador de igualdad
bool Item::operator==(const Item& otro) const {
    return this->nombre == otro.nombre;
}
