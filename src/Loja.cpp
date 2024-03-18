#include "Loja.h"

void Loja::adicionarItem() {
    std::string nome, cor, marca;
    int tamanho;
    float preco;

    cin.ignore();

    cout << "Cadastrando um novo produto:" << endl;
    cout << "Digite o nome do produto: ";
    getline(cin, nome);
    cout << "Digite o preco do produto: R$";
    cin >> preco;
    cin.ignore();
    cout << "Digite a cor do produto: ";
    getline(cin, cor);
    cout << "Digite o tamanho do produto: ";
    cin >> tamanho;
    cin.ignore();
    cout << "Digite a marca do produto: ";
    getline(cin, marca);

    Roupa novaRoupa(nome, preco, cor, tamanho, marca);
    roupas.push_back(novaRoupa);

    Estoque::adicionarItem(preco);

    cout << "Item adicionado!" << endl;

}

void Loja::listarTodos() {
    cout << "Roupas disponiveis:" << endl;
    for(const Roupa& r : roupas){
        cout << "-> Nome: " << r.getNome() << " - Preco: R$ " << r.getPreco() << " - Cor: " << r.getCor() << " - Tamanho: " << r.getTamanho() << " - Marca: " << r.getMarca() << endl;
    }
}

void Loja::pesquisarItem(std::string& nomeRoupa) {
    bool encontrado = false;

    cout << "Pesquisando por: " << nomeRoupa << endl;

    for(const Roupa& r : roupas){
        if(r.getNome() == nomeRoupa){
            encontrado = true;

            cout << "Item encontrado:" << endl;
            cout << "Nome: " << r.getNome() << " - Preco: R$ " << r.getPreco() << " - Cor: " << r.getCor() << " - Tamanho: " << r.getTamanho() << " - Marca: " << r.getMarca() << std::endl;
        }
    }

    if(!encontrado){
        cout << "Item nao encontrado." << endl;
    }
}

void Loja::pesquisarEAlterar(std::string& nomeRoupa) {
   for (Roupa& r : roupas) {
        bool encontrado = false;

        if (r.getNome() == nomeRoupa) {
            encontrado = true;

            cout << "Item encontrado:" << endl;
            cout << "Nome: " << r.getNome() << " - Pre�o: R$" << r.getPreco() << " - Cor: " << r.getCor() << " - Tamanho: " << r.getTamanho() << " - Marca: " << r.getMarca() << std::endl;

            Estoque::removerItem(r.getPreco());

            // Altera��o dos atributos da roupa encontrada
            float novoPreco, precoAntigo;
            std::string novaCor;
            int novoTamanho;
            std::string novaMarca;

            cout << "Digite a novo pre�o: ";
            cin >> novoPreco;
            r.setPreco(novoPreco);
            Estoque::adicionarItem(novoPreco);

            cout << "Digite a nova cor: ";
            cin >> novaCor;
            r.setCor(novaCor);

            cout << "Digite o novo tamanho: ";
            cin >> novoTamanho;
            r.setTamanho(novoTamanho);

            cout << "Digite a nova marca: ";
            cin >> novaMarca;
            r.setMarca(novaMarca);

            cout << "Item atualizado com sucesso!" << endl;
        }
        if (!encontrado) {
            cout << "Item nao encontrado." << endl;
        }
    }
}

void Loja::removerItemPorNome(std::string& nome) {
    float precoItem = 0.0;

    // Encontrar o item pelo nome e obter seu pre�o
    for (const Roupa& r : roupas) {
        if (r.getNome() == nome) {
            precoItem = r.getPreco();
            break;
        }
    }

    auto it = std::remove_if(roupas.begin(), roupas.end(), [&](const Roupa& r) {
        return r.getNome() == nome;
    });

    if (it != roupas.end()) {
        roupas.erase(it, roupas.end());
        cout << "Item removido com sucesso." << endl;

        // Atualizar o estoque
        Estoque::removerItem(precoItem);
    } else {
            cout << "Nenhum item encontrado com o esse nome." << endl;
    }
}

void Loja::gerarRelatorio() const {
    cout << "Quantidade total de itens no estoque da loja: " << getQuantidadeTotal() << endl;
    cout << "Valor total na loja: " << getPrecoTotal() << endl;
}

void Loja::salvarDadosEmArquivo(const std::string lojaDeRoupa) const {
     std::ofstream arquivo(lojaDeRoupa);
    if(arquivo.is_open()){
        arquivo << "Quantidade total de itens: " << getQuantidadeTotal() << endl;
        arquivo << "Valor total de loja: R$" << getPrecoTotal() << endl;
        arquivo << "Itens disponiveis:" << endl;
        for(const Roupa& r : roupas){
            arquivo << "Nome: " << r.getNome() << " - Pre�o: R$" << r.getPreco() << " - Cor: " << r.getCor() << " - Tamanho: " << r.getTamanho() << " - Marca: " << r.getMarca() << endl;
        }

        arquivo.close();
        cout << "Dados salvos no arquivo " << lojaDeRoupa << endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para salvar." << endl;
    }
}
//Tentativa de ler os dados do arquivo quando abrir o programa
void Loja::carregarDadosDoArquivo(const std::string& lojaDeRoupa) {
    std::ifstream arquivo(lojaDeRoupa);
    if (arquivo.is_open()) {
        // Limpar o vetor de roupas para evitar duplica��o
        roupas.clear();

        // Vari�veis tempor�rias para armazenar os dados lidos do arquivo
        std::string nome, cor, marca;
        int tamanho;
        float preco;

        // Ler os dados do arquivo e adicionar roupas ao vetor
        while (arquivo >> nome >> preco >> cor >> tamanho >> marca) {
            Roupa novaRoupa(nome, preco, cor, tamanho, marca);
            roupas.push_back(novaRoupa);
        }

        arquivo.close();
        cout << "Dados carregados do arquivo " << lojaDeRoupa << endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para carregar dados." << endl;
    }
}