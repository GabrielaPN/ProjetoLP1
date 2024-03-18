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
    bool encontrado = false;

    for (Roupa& r : roupas) {
        if (r.getNome() == nomeRoupa) {
            encontrado = true;

            cout << "Item encontrado:" << endl;
            cout << "Nome: " << r.getNome() << " - Preço: R$" << r.getPreco() << " - Cor: " << r.getCor() << " - Tamanho: " << r.getTamanho() << " - Marca: " << r.getMarca() << std::endl;

            Estoque::removerItem(r.getPreco());

            // Alteração dos atributos da roupa encontrada
            float novoPreco, precoAntigo;
            std::string novaCor;
            int novoTamanho;
            std::string novaMarca;

            cout << "Digite a novo preço: ";
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
    }
    if (!encontrado) {
            cout << "Item nao encontrado." << endl;
        }
}

void Loja::removerItemPorNome(std::string& nome) {
    float precoItem = 0.0;

    // Encontrar o item pelo nome e obter seu preço
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
        arquivo << getPrecoTotal() << endl;
        for(const Roupa& r : roupas){
            arquivo << r.getNome() << endl << r.getPreco() << endl << r.getCor() << endl << r.getTamanho() << endl << r.getMarca() << endl;
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
        // Limpar o vetor de roupas para evitar duplicação
        roupas.clear();

        std::string line;

        while(getline(arquivo, line)) { //ler todas as linhas que conseguir e dentro do while já é lido as próximas linhas
            Roupa n = Roupa(line, 0.0, "", 0, ""); //criação de um no objeto que recebe o nome lido
            getline(arquivo, line); //cada getline é a leitura de cada atributo de roupa
            float preco = stof(line); //coverter string para float ou int
            n.setPreco(preco);
            getline(arquivo, line);
            n.setCor(line);
            getline(arquivo, line);
            n.setTamanho(stoi(line));
            getline(arquivo, line);
            n.setMarca(line);

            roupas.push_back(n); //adiciona o objeto de roupa no vector
            Estoque::adicionarItem(preco); //soma os precos lidos
        }

        arquivo.close();
        cout << "Dados carregados do arquivo " << lojaDeRoupa << endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo para carregar dados." << endl;
    }
}
