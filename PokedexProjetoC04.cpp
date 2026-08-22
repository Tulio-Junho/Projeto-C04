//=====================================================
//                Projeto de Pokedex
//=====================================================
// Integrantes:
// Kauã Aparecido Silva Morais       - GES - 756
// Ana Clara Oliveira e Silva        - GES - 867
// Túlio César Alves Junho           - GES - 741
// Vitoria Cássia Bernardo Rodrigues - GEC - 2094
// 


#include <iostream> 
using namespace std;

int menu(){                 //Exibe o menu da pokedex
    int decisao = -1;

    cout << "======================================" << endl;
    cout << "               POKEDEX                " << endl;
    cout << "======================================" << endl;
    cout << "# Ola Jovem Treinador! Essa eh a Pokedex, sua maior aliada na sua jornada de se tornar o melhor treinador dos Pokemons!" << endl;
    cout << endl;
    cout << "Faca sua escolha: " << endl;
    cout << endl;
    cout << "[1] Cadastrar Cidade. " << endl;
    cout << "[2] Cadastrar Estrada. " << endl;
    cout << "[3] Buscar centro Pokemon mais proximo. " << endl;
    cout << "[4] Cadastrar Pokemon. " << endl;
    cout << "[5] Remover Pokemon. " << endl;
    cout << "[6] Listar Pokemons (ordem alfabetica por nome). " << endl;
    cout << "[7] Listar Pokemons (ordem alfabetica por tipo). " << endl;
    cout << "[8] Contar Pokemons de cada Tipo. " << endl;
    cout << "[9] Encontrar Pokemons proximos. " << endl;
    cout << "[0] Sair do Programa. " << endl;
    cout << endl;

    cin >> decisao;

    return decisao;
}

void onConstruct(){
    cout << "Funcionalidade em Construcao... " << endl;
}

int main(){

    
    int decisao = -1;

    while(decisao != 0){

        decisao = menu();

            switch (decisao)        //Switch que controla a entrada desejada do usuário.
        {
        case 0:                 //Encerrando o programa
            cout << "Pokedex desligando... Pika Pika :(" << endl;
            return 0;
        case 1:                 //Cadastrar cidade
            onConstruct();      
            break;
        case 2:                 //Cadastrar estradas
            onConstruct();      
            break;
        case 3:                 //Buscar centro Pokemon mais proximo
            onConstruct();
            break;
        case 4:                 //Cadastrar pokemon
            onConstruct();
            break;
        case 5:                 //Remover pokemon
            onConstruct();
            break;
        case 6:                 //Listar pokes por ordem alfabetica do nome
            onConstruct();
            break;
        case 7:                 //Listar pokes por ordem alfabetica por tipo
            onConstruct();
            break;
        case 8:                 //Contar pokes de cada tipo
            onConstruct();
            break;
        case 9:                 //Encontrar pokes próximos
            onConstruct();
            break;
    
        default:     
            cout << "Opcao invalida, Jovem Treinador! " << endl;
            break;
        }

    }

    return 0;
}