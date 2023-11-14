#pragma once
#include <string>

class Item {
public:
    Item(const std::string& nombre);

    std::string obtenerNombre() const;

    // Definici�n del operador de igualdad
    bool operator==(const Item& otro) const;

private:
    std::string nombre;
};
