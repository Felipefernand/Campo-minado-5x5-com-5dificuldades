
#include "iostream"
#include "string"             ///*manipular strings*///
#include "stdlib.h"           ///*para agrupar conjuntos de funções para facilitar a vida :)*///
#include "time.h"             ///*funções e constantes que medem tempo*///
#include "windows.h"          ///*declarações para todas as funções da API do Windows*///

using namespace std;  
int main(){
    
    
    int linha =0;
    int coluna =0;                 //variaveis que vão ser utilizadas
    string nome; 
    int escolha;
    int op;
    int dificul = 0;
    int vidas = 0;
    int tentativas = 0;
    
    bool fin = false;
     voltarmenu:     //Para voltar para o menu quando perder 
    while(1){                  
        cout << "|=========================|" << endl;
        cout << "|1- Jogar                 |" << endl;
        cout << "|2- Sobre min             |" << endl;          
        cout << "|3- Sair                  |" << endl;
        cout << "|=========================|" << endl;
        cout << "Digite um numero: " << endl;
        cin >> op;
        
        
                                //Se o usuario quiser jogar aparecerá
        switch(op){
        
        case 1:
        {
    cout << "---------------------------- Algumas coisas legais para se saber antes de jogar =) ------------------------------------------------" << endl;
    cout << "O jogo campo minado surgiu em 1989 com o lancamento do Windows 3.1 e foi desenvolvido por Robert Donner, depois disso sempre esteve" << endl;
    cout <<"incorporado ao Sistema Operacional Windows, tendo versoes para outros sistemas operacionais e ate para celulares. " <<endl;
    cout << "" << endl;
  cout << "---------------------------------------------Bem vindo!----------------------------------" << endl;
    cout<<"            O Campo Minado eh um jogo aparentemente simples de memória e raciocinio.,"<<endl;
    cout<<"                 O objetivo do Campo Minado eh revelar os quadrados vazios  "<<endl;
    cout<<"                           evitando aqueles que escondem bombas             "<<endl;
    
    cout << "Qual seu nome? " << endl;
    cin >> nome;
    NIVEL: // seleção de niveis
    cout <<"-----------------------------"<<endl;
    cout << "Escolha uma dificuldade "<< nome << endl;
    cout << "1-Praticar (Nao sei jogar) " << endl;
    cout << "2-Facil"                     << endl;
    cout << "3-Medio"                     << endl;
    cout << "4-Dificil"                   << endl;
    cout << "5-Hardcore"                  << endl;
    cout<<"------------------------------"<<endl;
    
    cout<<"Escolha um numero: ";cin>>dificul;cout<<endl;

    switch (dificul) {         //Numero de vidas, dificuldade e tentativas
        case 1:
            dificul = 10;      
            vidas = 50;      //nivel para praticar
            fin = false;
            tentativas=0;
            system("cls");
            break;
        case 2:
            dificul = 8;        //nivel facil
            vidas = 9;
            fin = false;
            tentativas=0;
            system("cls");
            break;
        case 3:
            dificul = 6;       //nivel medio
            vidas = 6;
            fin = false;
            tentativas=0;
            system("cls");
            break;
        case 4:
            dificul = 6;       //nivel dificil
            vidas = 4;
            fin = false;
            tentativas=0;
            system("cls");
            break;
        case 5:
            dificul = 5;       //nivel harcore
            vidas = 1;
            fin = false;
            tentativas=0;
            system("cls");
            break;
        default:
            system("cls");
            cout<<"Escreva um numero entre 1 e 5: "<<endl;
            goto NIVEL;
            break;
    }

    int n[dificul][dificul];
    string m[dificul][dificul];
    srand(time(NULL));

    for (int i = 0;i < dificul; i++) {        //matriz da logica
        for (int j = 0; j < dificul; j++) {  
            n[i][j]=rand()%(2-0) + (i * 100) + (j * 10);
        }
    }
    for (int i = 0;i < dificul; i++) {        //matriz visivel para o usuario do campo minado
        for (int j = 0; j < dificul; j++) {
            m[i][j]="O";   // O são as bombas
        }
    }
               
   cout<<"voce tentou: "<<tentativas<<endl;    //Matriz visivel imprimida
    cout<<"Quantidade de vidas: "<<vidas-1<<endl;
    for (int i = 0;i < dificul; i++) {
        cout<<endl;
        for (int j = 0; j < dificul; j++) {
            cout<<"   "<<m[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    
    while (fin == false) {    //logica para o usuario digitar a linha e a coluna
        LIN:
        cout<<" Digite um numero da linha entre 0 e "<<dificul-1<<" ";cin>>linha;cout<<endl;
        if (linha == 20) {
       
        }
        if (linha < 0 || linha > dificul-1) {
            cout<<"   Digite um numero entre 0 e "<<dificul-1<<" "<<endl;
            goto LIN; //linhas
        }
        COL:
        cout<<" Digite uma coluna entre 0 e "<<dificul-1<<" ";cin>>coluna;cout<<endl;
        if (coluna < 0 || coluna > dificul-1) {
            cout<<"  Digite um numero entre 0 e "<<dificul-1<<" "<<endl;
            goto COL; //colunas  
        }
        tentativas++;
        if (n[linha][coluna]%2== 0) {
            m[linha][coluna] = " ";
        }
        if (n[linha][coluna]%2== 1) {
            m[linha][coluna] = "*";
            vidas--;
            if (vidas==0) {
                fin=true;
            }
        }
        system("cls");
        if (fin==false) {
           cout<<"voce tentou: "<<tentativas<<endl;
            cout<<"Quantidade de vidas: "<<vidas-1<<endl;
            for (int i = 0;i < dificul; i++) {
                cout<<endl;
                for (int j = 0; j < dificul; j++) {
                cout<<"   "<<m[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
        }
        if (fin == true) {
           cout<<"voce tentou: "<<tentativas<<endl;
            cout<<"Quantidade de vidas: "<<vidas-1<<endl;
            cout<<endl;
            
                                    
            cout<<"             Buuuuuuuuuum           "<<endl;
            cout<<"           _.-^^---....,,--         "<<endl;
            cout<<"       _--                  --_     "<<endl;
            cout<<"      <                        >)   "<<endl;
            cout<<"      |                         |   "<<endl;
            cout<<"       \._                   _./    "<<endl;
            cout<<"          ```--. . , ; .--'''       "<<endl;
            cout<<"                  | |   |           "<<endl;  
            cout<<"               .-=||  | |=-.        "<<endl;
            cout<<"               `-=#$%&%$#=-'        "<<endl;
            cout<<"                 | ;  :|            "<<endl;
            cout<<"        _____.,-#%&$@%#&#~,._____   "<<endl;

            cout<<"               Voce perdeu"<<endl;


                  
            cout<<endl;
            goto voltarmenu;    //voltar direto para o menu principal quando perde
          }
        }
            break;
        }
        
        case 2:       //Sobre min
        {
            
            cout << "        Prazer me chamo Felipe  " << endl;
            cout << "             Tenho 18 anos  " << endl;
            cout << "     Fiz 2 cursos de c/c++ na udemy     " << endl;
            cout << "esse codico foi feito para faculdade de SI" << endl;
            cout << " Para mais informacoes meu ig e linkedin" << endl;
            cout << "            se chama @Fhelps11           " << endl;
            break;
        }
        
        case 3:      //Sair do jogo
        {
            cout << "Obrigado por jogar! =D " << endl;
         exit(1);    
        }
        
        default:
            {
              break;
            }
        }
    }
    return 0;
}