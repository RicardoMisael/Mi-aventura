#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Enemigo.h"

class Cuarto {
public:
    Cuarto(const std::string& nombre, const std::string& descripcion);

    void agregarItem(const Item& item);
    void eliminarItem(const Item& item);
    void agregarEnemigo(const Enemigo& enemigo);

    void mostrarInfo() const;

    const std::vector<Item>& obtenerItems() const;
    const std::vector<Enemigo>& obtenerEnemigos() const;

private:
    std::string nombre;
    std::string descripcion;
    std::vector<Item> items;
    std::vector<Enemigo> enemigos;
};

