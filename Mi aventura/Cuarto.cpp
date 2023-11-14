#include "Cuarto.h"

Cuarto::Cuarto(const std::string& nombre, const std::string& descripcion)
    : nombre(nombre), descripcion(descripcion) {}

void Cuarto::agregarItem(const Item& item) {
    items.push_back(item);
}

void Cuarto::eliminarItem(const Item& item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
}

void Cuarto::agregarEnemigo(const Enemigo& enemigo) {
    enemigos.push_back(enemigo);
}

void Cuarto::mostrarInfo() const {
    std::cout << "Nombre del cuarto: " << nombre << std::endl;
    std::cout << "Descripción: " << descripcion << std::endl;

    if (!items.empty()) {
        std::cout << "Items en el cuarto: ";
        for (const auto& item : items) {
            std::cout << item.obtenerNombre() << " ";
        }
        std::cout << std::endl;
    }

    if (!enemigos.empty()) {
        std::cout << "Enemigos en el cuarto: ";
        for (const auto& enemigo : enemigos) {
            std::cout << enemigo.obtenerNombre() << " ";
        }
        std::cout << std::endl;
    }
}

const std::vector<Item>& Cuarto::obtenerItems() const {
    return items;
}

const std::vector<Enemigo>& Cuarto::obtenerEnemigos() const {
    return enemigos;
}
