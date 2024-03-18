#include "Estoque.h"

Estoque::Estoque() : quantidadeTotal(0), precoTotal(0.0) {}

void Estoque::adicionarItem(float preco) {
    quantidadeTotal++;
    precoTotal += preco;
}

void Estoque::removerItem(float preco) {
    quantidadeTotal--;
    precoTotal -= preco;
}

void Estoque::alterarItem(float preco, float novoPreco) {
    precoTotal = precoTotal - preco + novoPreco;
}

int Estoque::getQuantidadeTotal() const {
    return quantidadeTotal;
}

float Estoque::getPrecoTotal() const {
    return precoTotal;
}
