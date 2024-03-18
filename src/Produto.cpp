#include "Produto.h"

Produto::Produto(const std::string nome, float preco) : nome(nome), preco(preco){}

std::string Produto::getNome() const{
    return nome;
}

float Produto::getPreco() const{
    return preco;
}

void Produto::setPreco(float novoPreco){
    preco = novoPreco;
}
