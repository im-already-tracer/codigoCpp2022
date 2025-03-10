#include "juego.h"
#include <time.h>

Juego::Juego()
{

}

bool Juego::isOk(int nro)
{
    if (this->secuencia->getVec()[2] == nro) {
        this->puntos++;
        return true;
    }
    this->puntos--;
    return false;
}

int Juego::getPuntos()
{
    return this->puntos;
}

void Juego::generar()
{
    srand(time(NULL));
    if (this->secuencia != nullptr) {
        delete this->secuencia;
    }

    int semi = rand() % 3;
    switch (semi) {
        case 0:
            this->secuencia = new SecuenciaPar();
        break;
    default:
            this->secuencia = new SecuenciaImpar();
        break;
    }
    this->secuencia->generar();
}

std::ostream& operator<<(std::ostream &os, const Juego &juego)
{
    os << juego.secuencia->getVec()[0] << " ";
    os << juego.secuencia->getVec()[1] << " ";
    os << " ??? ";
    os << juego.secuencia->getVec()[3] << " ";
    return os;
}
