#include <iostream>
#include <string>
#include <fstream>
#include "Loja.h"

using namespace std;

int main()
{
    int opcao;

    Loja minhaLoja;

    //Ler os dados salvos no arquivo - Não deu certo kk
    minhaLoja.carregarDadosDoArquivo("loja_de_roupa.txt");

    do
    {
        cout << endl;
        cout << "1.Inserir" << endl;
        cout << "2.Listar todos" << endl;
        cout << "3.Exibir um (pesquisando por nome)" << endl;
        cout << "4.Alterar (por nome)" << endl;
        cout << "5.Remover" << endl;
        cout << "6.Relatorio" << endl;
        cout << "7.Sair" << endl;

        cin >> opcao;

        switch(opcao)
        {
            case 1:{ //Inserir novo produto
                minhaLoja.adicionarItem();
                minhaLoja.salvarDadosEmArquivo("loja_de_roupa.txt");
                break;
            }
            case 2: {//Listar todos
                minhaLoja.listarTodos();
                break;
            }
            case 3:{ //Exibir pesquisando por nome
                std::string nomeASerPesquisado;

                cout << "Qual roupa deseja pesquisar? ";
                cin >> nomeASerPesquisado;

                minhaLoja.pesquisarItem(nomeASerPesquisado);

                break;
            }
            case 4:{ //Alterar um item existente
                std::string nome;

                cout << "Qual item deseja alterar? ";
                cin >> nome;
                minhaLoja.pesquisarEAlterar(nome);
                minhaLoja.salvarDadosEmArquivo("loja_de_roupa.txt");
                break;
            }
            case 5: {//Remover
                std::string itemASerRemovido;

                cout << "Qual o nome do item a ser removido? " << endl;
                cin >> itemASerRemovido;

                minhaLoja.removerItemPorNome(itemASerRemovido);
                minhaLoja.salvarDadosEmArquivo("loja_de_roupa.txt");
                break;
            }
            case 6: //Exibir relatorio
                minhaLoja.gerarRelatorio();
                minhaLoja.listarTodos();
                minhaLoja.salvarDadosEmArquivo("loja_de_roupa.txt");
                break;
            case 7: //sair
                break;
           default:
                cout << "Opcao invalida" << endl << endl;
                break;
        }
    }while(opcao != 7);

    return 0;

}

