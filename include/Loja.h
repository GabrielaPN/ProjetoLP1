#ifndef LOJA_H
#define LOJA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Roupa.h"
#include "Estoque.h"

using namespace std;


class Loja : public Roupa, public Estoque
{
    public:
        Loja() : Roupa("", 0.0, "", 0, ""), Estoque(){};

        void adicionarItem();
        void listarTodos();
        void pesquisarItem(std::string& nomeRoupa);
        void pesquisarEAlterar(std::string& nomeRoupa);
        void removerItemPorNome(std::string& nome);
        void gerarRelatorio()const;
        void salvarDadosEmArquivo( const std::string lojaDeRoupa) const;
        void carregarDadosDoArquivo(const std::string& lojaDeRoupa);

    protected:

    private:
        std::vector <Roupa> roupas;
};

#endif // LOJA_H
