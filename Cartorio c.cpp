#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaçoo em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar o usuário no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); // abrir arquivo
	fprintf(file,","); //  "," adcionar uma vírgula no arquivo
	fclose(file); // fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletar infomações do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abrir arquivo
	fprintf(file,nome); // salvar o valor da variavel
	fclose(file); // fecho arquivo 
	
	file = fopen(arquivo, "a"); // abrir arquivo
	fprintf(file,","); // "," adiciona uma vírgula no arquivo 
	fclose(file); // fecho o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletar informação do usuário
	scanf("%s",sobrenome); //%s fere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,sobrenome); // salvar o valor da variavel
	fclose(file); // fecho  o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo 
	fprintf(file,","); // "," adiciona uma vírgula no arquivo
	fclose(file); // fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletar informação do usuario
	scanf("%s",cargo); // salvar o valor da variavel
	
	file = fopen(arquivo, "a"); //abrir arquivo 
	fprintf(file,cargo); //salvar o valor da variavel
	fclose(file); //fecho o arquivo
	
	system("pause"); // faz uma pausa

}

int consulta() // função responsavel por consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40]; //inicio criação de variaveis/string
    char conteudo[200]; //final criação de variaveis/string 
    
    printf("Digite o CPF a ser consultado: "); //coletar informação do usuario
    scanf("%s",cpf);//%s refere-se a string
    
    FILE *file; //cria o arquivo
    file = fopen(cpf,"r");// cria o arquivo
    
    if(file == NULL) // anula
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
   	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); // responde o usuario
		printf("%s", conteudo); // salva o valor da variavel
		printf("\n\n"); // espaçamento 
	}
	
	system("pause"); // faz uma pausa


}

int deletar() //função responsavel por deletar usuario
{
	char cpf[40]; //inicio criação de variaveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletetar informação do usuario
    scanf("%s",cpf); //%s refere-se 
    
    remove(cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); // cria o arquivo
    
    if(file == NULL); // anula
    {
    	printf("O usuário não se encontra no sistema!.\n"); //responde usuario
    	system("pause"); // faz uma pausa
    		
	}
    
}

int main() //ponto de partida
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cartório da EBAC###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1- Registrar nomes\n");
	    printf("\t2- Consultar nomes\n");
	    printf("\t3- Deletar  nomes\n\n"); 
	    printf("\t4- Sair do sistema\n\n");
	    printf("Opção: ");//Fim do menu
	
        scanf("%d", &opcao); //Armazenando a escolha do usuário
    
        system("cls");// responsavel por limpar a tela
        
        switch(opcao)//Inicio de seleção do menu
        {
        	case 1:
            registro(); //  chamada de funções
		    break; // encerra instrução
		    
		    case 2:
		    consulta(); // chamada de funções
			break; // encerra instrução
			
			case 3:	
			deletar(); // chamada de funções
		    break;// encerra instrução
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		    
		    
		    
		    default:
		    printf("Essa opção não está disponivel!\n");
	     	system("pause");
	     	break; // encerra instrução
	    } //Fim da seleção
        
    }
}
