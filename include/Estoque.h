#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <vector>

class Estoque
{
    public:
        Estoque();

        void adicionarItem (float preco);
        void removerItem(float preco);
        void alterarItem(float preco, float novoPreco);
        int getQuantidadeTotal() const;
        float getPrecoTotal() const ;

    protected:
        int quantidadeTotal;
        float precoTotal;

    private:
};

#endif // ESTOQUE_H
