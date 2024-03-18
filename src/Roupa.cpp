#include "Roupa.h"

std::string Roupa::getCor() const {
    return cor;
}

int Roupa::getTamanho() const {
    return tamanho;
}

std::string Roupa::getMarca() const {
    return marca;
}

void Roupa::setCor(const std::string cor){
    this->cor = cor;
}

void Roupa::setTamanho(int tamanho){
    this->tamanho = tamanho;
}

void Roupa::setMarca(const std::string marca){
    this->marca = marca;
}

