#ifndef ROUPA_H
#define ROUPA_H

#include <string>
#include <iostream>
#include "Produto.h"

using namespace std;

class Roupa : public Produto
{
    public:
        Roupa(const std::string& nome, float preco, const std::string cor, int tamanho, const std::string marca) : Produto(nome, preco), cor(cor), tamanho(tamanho), marca(marca){}

        std::string getCor() const;
        int getTamanho() const;
        std::string getMarca() const;


        void setCor(const std::string cor);
        void setTamanho(int tamanho);
        void setMarca(const std::string marca);
        void setPreco(float novoPreco){
            Produto::setPreco(novoPreco);
        }


    protected:

    private:
        std::string cor;
        int tamanho;
        std::string marca;
};

#endif // ROUPA_H
