//=====================================================
//                Projeto de Pokedex
//=====================================================
// Integrantes:
// Kauã Aparecido Silva Morais       - GES - 756
// Ana Clara Oliveira e Silva        - GES - 867
// Túlio César Alves Junho           - GES - 741
// João Vitor Lima da Silveira       - GES - 500
// Vitoria Cássia Bernardo Rodrigues - GEC - 2094

#include <iostream> 
#include <locale>
#include <cstdlib>
using namespace std;

  

int menu(){                 //Exibe o menu da pokedex
    int decisao = -1;

    cout << "  ====================================================================================================================" << endl;
    cout << "                                                     POKEDEX                " << endl;
    cout << "  ====================================================================================================================" << endl;
    cout << "\n# Olá, Jovem Treinador! Essa é a Pokédex, sua maior aliada em sua jornada de se tornar o melhor treinador dos Pokémons!" << endl;
    cout << endl;
    cout << "Faça sua escolha: " << endl;
    cout << endl;
    cout << "[1] Cadastrar Cidade. " << endl;
    cout << "[2] Cadastrar Estrada. " << endl;
    cout << "[3] Buscar Centro Pokémon mais próximo. " << endl;
    cout << "[4] Cadastrar Pokémon. " << endl;
    cout << "[5] Remover Pokémon. " << endl;
    cout << "[6] Listar Pokémons (ordem alfabética por nome). " << endl;
    cout << "[7] Listar Pokemons (ordem alfabética por tipo). " << endl;
    cout << "[8] Contar Pokémons de cada Tipo. " << endl;
    cout << "[9] Encontrar Pokémons próximos. " << endl;
    cout << "[0] Sair do Programa. " << endl;
    cout << endl;

    cin >> decisao;

    return decisao;
}

void onConstruct(){
    cout << "Funcionalidade em Construcao... \n" << endl;
}

int main(){

	setlocale(LC_ALL, "Portuguese_Brazil");  
	
    //Imagem pikachu
    
    #ifdef _WIN32
    // Ativa cores ANSI no Windows Terminal
    system("chcp 65001 > nul");
    #endif

    // Pikachu #025 - arte colorida do projeto Pokemon Terminal Art
    const char* comando =
        "curl -s "
        "https://raw.githubusercontent.com/shinya/pokemon-terminal-art/main/"
        "fullcolor/diamond/025.txt";

    system(comando);
    cout << "\033[0m" << endl;

    //Começo do código
    
    int decisao = -1;

    while(decisao != 0){

        decisao = menu();

            switch (decisao)        //Switch que controla a entrada desejada do usuário.
        {
        case 0:                 //Encerrando o programa
            cout << "\nPokédex desligando... Pika Pika :(\n" << endl;
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
            cout << "Opção inválida, Jovem Treinador! " << endl;
            break;
        }

    }

    return 0;
}
