#pragma once

#include <string>

// Declaraci�n de la clase Item
class Item {
public:
    Item(const std::string& nombre);

    const std::string& obtenerNombre() const;

private:
    std::string nombre;
};

// Declaraci�n de la clase Enemigo
class Enemigo {
public:
    Enemigo(const std::string& nombre, int vida);

    const std::string& obtenerNombre() const;
    int obtenerVida() const;

private:
    std::string nombre;
    int vida;
};

// Otras declaraciones comunes seg�n las necesidades de tu programa

