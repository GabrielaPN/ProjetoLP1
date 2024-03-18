#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>


class Produto
{
    public:
        Produto(const std::string nome, float preco);
        std::string getNome() const;
        float getPreco() const ;
        void setPreco(float novoPreco);

    protected:

    private:
        std::string nome;
        float preco;
};

#endif // PRODUTO_H
