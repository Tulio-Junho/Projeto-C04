//Integrantes:
//Nome: Alice Gabriela de Souza  		    Matricula: 2438
//Nome: Kaio Henrique Santos Araujo 		Matricula: 803
//Nome: Lucas Mendon�a de Almeida           Matricula: 791

#define INF 99999

#include <iostream>
#include <string>
#include <list>
#include <string>
#include <cmath>
using namespace std;

struct cidades{
    string nome;
    int codigo;
    bool centropokemon;
};

struct Aresta{
    int origem, destino, peso;
};

struct pokemons{ 
  int numero;
  string nome; 
  string tipo; 
  int localx, localy; 
};

struct node{ 
  pokemons data; 
  struct node * left; 
  struct node * right; 
}; 



void insertTipo(node * & current, pokemons data){ 
  if(current == NULL){ 
    current = new node; 
    current->data = data; 
    current->left = NULL; 
    current->right = NULL; 
  } else if( data.tipo < current->data.tipo ){ 
    insertTipo(current->left, data); 
  } else { 
    insertTipo(current->right, data); 
  } 
}

void insert(node * & current, pokemons data){ 
  if(current == NULL){ 
    current = new node; 
    current->data = data; 
    current->left = NULL; 
    current->right = NULL; 
  } else if( data.nome < current->data.nome ){ 
    insert(current->left, data); 
  } else { 
    insert(current->right, data); 
  } 
}

node * find_less_save_right(node * & current) { 
  if(current->left != NULL) { 
    return find_less_save_right(current->left); 
  } else { 
    node * copy = current; 
    current = current->right; 
    return copy; 
  } 
}

bool remove(node * & current, string data){ 
  if(current == NULL){ 
    return false; 
  } else if(data == current->data.nome){ 
    node * temp = current; 
    if (current->right == NULL) { 
      current = current->left; 
    } else if (current->left == NULL) { 
      current = current->right; 
    } else { 
      temp = find_less_save_right(current->right); 
      current->data = temp->data; 
    } 
    delete(temp); 
    return true; 
  } else { 
    if(data < current->data.nome){ 
      return remove(current->left, data); 
    } else { 
      return remove(current->right, data); 
    } 
  } 
}

bool removeTipo(node * & current, string nome)
{
    if(current == NULL)
        return false;
    if(current->data.nome == nome)
    {
        node * temp = current;
        if(current->right == NULL)
            current = current->left;
        else if(current->left == NULL)
            current = current->right;
        else{
            temp = find_less_save_right(current->right);
            current->data = temp->data;
        }
        delete temp;
        return true;
    }
    if(removeTipo(current->left, nome))
        return true;

    return removeTipo(current->right, nome);
}

void show_in_order(node * current) { 
  if (current != NULL) { 
    if (current->left != NULL) { 
      show_in_order(current->left); 
    } 
    cout << "Nome: "<< current->data.nome << endl;
    cout << "Tipo: "<< current->data.tipo << endl;
    cout << "Numero: "<< current->data.numero << endl;
    cout << "Localizacao: ("<< current->data.localx << "," << current->data.localy << ")" << endl << endl;  
    if (current->right != NULL) { 
      show_in_order(current->right); 
    } 
  } 
} 

void destruct(node * & current) { 
  if (current != NULL) { 
    if (current->left != NULL) { 
      destruct(current->left); 
    } 
    if (current->right != NULL) { 
      destruct(current->right); 
    } 
    delete(current); 
  } 
} 

void CadastrarCidade(cidades cidade[], int &cidadestotal)
{
    cout << "Para cadastrar uma cidade precisamos de algumas informacoes" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Qual o nome da cidade?" << endl;
    getline(cin, cidade[cidadestotal].nome);
    
    cout << "Qual o codigo da cidade?" << endl;
    cin >> cidade[cidadestotal].codigo;
    
    cout << "Tem centro pokemon? Escreva 1 para sim ou 0 para nao" << endl;
    cin >> cidade[cidadestotal].centropokemon;

    cidadestotal++;
}

void CadastrarEstrada(list<Aresta> grafo[], int origem, int destino, int peso)
{
    Aresta a1;

    a1.origem = origem;
    a1.destino = destino;
    a1.peso = peso;

    Aresta a2;

    a2.origem = destino;
    a2.destino = origem;
    a2.peso = peso;

    grafo[origem].push_back(a1);
    grafo[destino].push_back(a2);
}

int CentroProximo(list<Aresta> grafo[], cidades cidade[],int totalcidades, int origem)
{
    bool visitado[100];
    int pai[100];
    int distancia[100];

    list<Aresta>::iterator it;

    for(int i = 0; i < totalcidades; i++){
        visitado[i] = false;
        pai[i] = -1;
        distancia[i] = INF;
    }
    distancia[origem] = 0;

    while(true){

        int atual = -1;
        int menor = INF;

        for(int i = 0; i < totalcidades; i++){
            if(!visitado[i] && distancia[i] < menor){
                menor = distancia[i];
                atual = i;
            }
        }

        if(atual == -1)
            break;

        visitado[atual] = true;

        for(it = grafo[atual].begin(); it != grafo[atual].end(); ++it)
        {
            int destino = it->destino;
            int peso = it->peso;

            if(distancia[atual] + peso < distancia[destino]){
                distancia[destino] = distancia[atual] + peso;
                pai[destino] = atual;
            }
        }
    }

    int melhorcidade = -1;
    int menordistancia = INF;

    for(int i = 0; i < totalcidades; i++){
        if(cidade[i].centropokemon &&
           distancia[i] < menordistancia)
        {
            menordistancia = distancia[i];
            melhorcidade = i;
        }
    }
    if(melhorcidade == -1){
        cout << "Nenhum centro Pokemon encontrado" << endl;
        return -1;
    }
    cout << "Centro Pokemon encontrado na cidade "
         << cidade[melhorcidade].nome << endl;
    cout << "Distancia total: "
         << menordistancia << endl;
    int caminho[100];
    int tam = 0;
    for(int v = melhorcidade; v != -1; v = pai[v]){
        caminho[tam++] = v;
    }
    cout << "Rota: ";
    for(int i = tam - 1; i >= 0; i--){
        cout << cidade[caminho[i]].nome;

        if(i > 0)
            cout << " -> ";
    }
    cout << endl;
    return melhorcidade;
}

void CadastrarPokemon(node * & current, node * & current2)
{
    pokemons pokemon;
    cout << "Para cadastar um pokemon precisamos de algumas informacoes" << endl;
    cout << "Qual o nome do pokemon?"<<endl;
    getline(cin>>ws, pokemon.nome);
    cout << "Qual o tipo do pokemon?"<<endl;
    getline(cin>>ws, pokemon.tipo);
    cout << "Qual o numero do pokemon?" << endl;
    cin >> pokemon.numero;
    cout << "Qual a localizacao do pokemon?" << endl;
    cin >> pokemon.localx >> pokemon.localy;
    insert(current, pokemon);
    insertTipo(current2, pokemon);
} 
void RemoverPokemon(node * & current, node * & current2)
{
    bool remocao;
    pokemons pokemon;
    cout << "Para remover um pokemon precisamos de uma informacao" << endl;
    cout << "Qual o nome do pokemon?"<<endl;
    getline(cin>>ws, pokemon.nome);
    remocao=remove(current, pokemon.nome);
    remocao=removeTipo(current2, pokemon.nome);
    if(remocao==true)
        cout << "Pokemon removido com sucesso!" << endl;
    else 
        cout << "Pokemon nao encontrado!" << endl;
}
void ListarPokemonsNome(node * current)
{
    show_in_order(current);
}
void ListarPokemonsTipo(node * current)
{
    show_in_order(current);
}
void ContarTipos(node * & current, string tipo, int &contador)
{
    if (current != NULL) { 
    if (current->left != NULL) { 
      ContarTipos(current->left, tipo, contador); 
    } 
    if(current->data.tipo==tipo) contador++;  
    if (current->right != NULL) { 
      ContarTipos(current->right, tipo, contador);      
    } 
  } 
}
float distancia(int x1, int y1, int x2, int y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);//raiz da distancia quadratica
}

int contarPokemonsNoRaio(node* current, int x, int y, int raio) {
    if (current == NULL) return 0; //caso tenha chegado no final do galho da arvore
    int total = 0;
    if (distancia(current->data.localx, current->data.localy, x, y) <= raio) { 
        cout << "  - " << current->data.nome << " (" << current->data.localx << "," << current->data.localy << ")" << endl;
        total = 1;
    }
    total += contarPokemonsNoRaio(current->left, x, y, raio);
    total += contarPokemonsNoRaio(current->right, x, y, raio);
    return total;
}
void EncontrarPokemons(node* current)
{
    int x, y;
    cout << "Qual a sua localizacao atual?" << endl;
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;

    cout << "\nPokemons encontrados em um raio de 100 metros:" << endl;
    int total = contarPokemonsNoRaio(current, x, y, 100);
    cout << "Total: " << total << " pokemon(s)" << endl;
}


int main(){
    bool a = true;
    int escolha;
    cidades cidades[100];
    list<Aresta> grafo[100];
    int cidadestotal = 0;
    node * root = NULL;
	node * rootTipo = NULL;
	int contador=0;
	string tipo;
    cout << "Bem vindo(s) a Pokedex!" << endl;
    cout << "A enciclopedia utilizada por treinadores Pokemon" << endl;

    while(a)
    {
		cout << "Faca sua escolha:" << endl;
        cout << "1. Cadastrar cidade" << endl;
        cout << "2. Cadastrar estrada" << endl;
        cout << "3. Buscar centro Pokemon mais proximo" << endl;
        cout << "4. Cadastrar Pokemon" << endl;
        cout << "5. Remover Pokemon" << endl;
        cout << "6. Listar Pokemons (ordem alfabetica de nome)" << endl;
        cout << "7. Listar Pokemons (ordem alfabetica de tipo)" << endl;
        cout << "8. Contar Pokemons de cada tipo" << endl;
        cout << "9. Encontrar Pokemons proximos" << endl;
        cout << "10. Sair" << endl;


        cin >> escolha;

        switch(escolha)
        {

        case 1:

            CadastrarCidade(cidades, cidadestotal);
            break;

        case 2:

            int origem, destino, peso;
            cout << "Qual a cidade de origem?(digite o codigo por favor)" << endl;
            cin >> origem;
            cout << "Qual a cidade de destino?(digite o codigo por favor)" << endl;
            cin >> destino;
            cout << "Qual a distancia da estrada?" << endl;
            cin >> peso;           
            CadastrarEstrada(grafo,origem,destino,peso);
            break;

        case 3:

            int localizacao;
            cout << "Qual cidade vc esta no momento?(Digite o codigo por favor" << endl;
            cin >> localizacao;
            CentroProximo(grafo,cidades,cidadestotal,localizacao);
            break;
		case 4:
            CadastrarPokemon(root, rootTipo);
            cout << endl;
            break;
        case 5:

            RemoverPokemon(root, rootTipo);
            cout << endl;
            break;
        case 6:

            ListarPokemonsNome(root);
            cout << endl;
            break;
        case 7:

            ListarPokemonsTipo(rootTipo);
            cout << endl;
            break;
        case 8:
            cout<<"Qual tipo deseja contar?"<<endl;
            contador=0;
            getline(cin>>ws, tipo);
            ContarTipos(root, tipo, contador);
            cout << contador << " pokemons desse tipo." << endl;
            break;
        case 9:

            EncontrarPokemons(root);
            cout << endl;
            break;
        case 10:
            
            cout << "Voce saiu.";
            a = false;
            break;  

        }
    }
    destruct(root);
    destruct(rootTipo);
    return 0;
}