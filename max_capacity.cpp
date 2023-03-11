#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 200000

// Funcao principal
int main() {
 
    // Leitura da primeira linha do arquivo de entrada
    int num_cidades, num_estradas, num_consultas;
    std::cin >> num_cidades >> num_estradas >> num_consultas;

    /* Esta eh a representacao do grafo
       - O numero do seu indice representa o numero da cidade
       - Cada cidade origem possui um vetor de pares
       - Cada par representa a cidade destino (first) e o fluxo dessa estrada (second)
    */
    std::vector<std::vector<std::pair<int,int>>> grafo;
    grafo.reserve(1000);

    // Preenche o grafo com todas as estradas e as cargas limites respectivas
    grafo.assign(num_cidades, std::vector<std::pair<int,int>>());
    for (int i = 0; i < num_estradas; i++){
        int cidade_origem, cidade_destino, carga_limite;
        std::cin >> cidade_origem >> cidade_destino >> carga_limite;
        grafo[cidade_origem].push_back(std::make_pair(cidade_destino, carga_limite));
    }

    // Leitura e armazenamento das consultas
    std::vector<std::pair<int,int>> consultas;
    for (int i = 0; i < num_consultas; i++){
        int ori, dest;
        std::cin >> ori >> dest;
        consultas.push_back(std::make_pair(ori, dest));
    }

    // Algoritmo Dijkstra modificado que acha o fluxo máximo pra cada cidade
    for(int i = 0; i < consultas.size(); i++){

        int origem = consultas[i].first;
        int destino = consultas[i].second;
        // Vetor com o fluxo maximo de cada cidade (cidades representadas pelo indice)
        std::vector<int> fluxos_maximos(num_cidades + 1, -1);
        // Fila de prioridade de acordo com o maior fluxo
        std::priority_queue<std::pair<int,int>> fila_prioridade;
        // Atualiza o fluxo maximo da origem no vetor de fluxos maximos
        fluxos_maximos[origem] = MAX;
        // Coloca a origem na fila de prioridade
        fila_prioridade.push(std::make_pair(MAX, origem));

        // Visita todas as cidades alcancadas pela cidade principal
        while(!fila_prioridade.empty()){
            // Pega o primeiro par da fila de prioridade (nova cidade principal), que tem maior fluxo
            std::pair<int,int> par_aux = fila_prioridade.top();
            int cidade_atual = par_aux.second;

            // Tira da fila porque vai visitar todas as que ela alcanca
            fila_prioridade.pop();

            // Visita todos as cidades alcancadas pela cidade atual
            for(int i = 0; i < grafo[cidade_atual].size(); i++){
                int fluxo_minimo_atualizado = std::min(par_aux.first, grafo[cidade_atual][i].second);
                // Se achar um caminho que passa uma carga maior, atualiza o fluxo dessa cidade
                if(fluxos_maximos[grafo[cidade_atual][i].first] < fluxo_minimo_atualizado){
                    fluxos_maximos[grafo[cidade_atual][i].first] = fluxo_minimo_atualizado;
                    // Adiciona na fila de prioridade a cidade com seu fluxo atualizado
                    fila_prioridade.push(std::make_pair(fluxo_minimo_atualizado, grafo[cidade_atual][i].first));
                }
            }
        }
        // Com o fluxo maximo de todas as cidades atualizado, o resultado esta no indice da cidade destino
        std::cout << fluxos_maximos[destino] << std::endl;
    }

    return 0;
}