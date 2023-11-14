// Enemigo.h
#pragma once
#include <string>

class Enemigo {
public:
    Enemigo(const std::string& nombre);

    std::string obtenerNombre() const;

    // Otros miembros de la clase si es necesario
private:
    std::string nombre;
};
