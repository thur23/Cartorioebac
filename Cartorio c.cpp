#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�oo em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar o usu�rio no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a"); // abrir arquivo
	fprintf(file,","); //  "," adcionar uma v�rgula no arquivo
	fclose(file); // fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletar infoma��es do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abrir arquivo
	fprintf(file,nome); // salvar o valor da variavel
	fclose(file); // fecho arquivo 
	
	file = fopen(arquivo, "a"); // abrir arquivo
	fprintf(file,","); // "," adiciona uma v�rgula no arquivo 
	fclose(file); // fecho o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletar informa��o do usu�rio
	scanf("%s",sobrenome); //%s fere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,sobrenome); // salvar o valor da variavel
	fclose(file); // fecho  o arquivo
	
	file = fopen(arquivo, "a"); // abrir o arquivo 
	fprintf(file,","); // "," adiciona uma v�rgula no arquivo
	fclose(file); // fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletar informa��o do usuario
	scanf("%s",cargo); // salvar o valor da variavel
	
	file = fopen(arquivo, "a"); //abrir arquivo 
	fprintf(file,cargo); //salvar o valor da variavel
	fclose(file); //fecho o arquivo
	
	system("pause"); // faz uma pausa

}

int consulta() // fun��o responsavel por consultar
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40]; //inicio cria��o de variaveis/string
    char conteudo[200]; //final cria��o de variaveis/string 
    
    printf("Digite o CPF a ser consultado: "); //coletar informa��o do usuario
    scanf("%s",cpf);//%s refere-se a string
    
    FILE *file; //cria o arquivo
    file = fopen(cpf,"r");// cria o arquivo
    
    if(file == NULL) // anula
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
   	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // responde o usuario
		printf("%s", conteudo); // salva o valor da variavel
		printf("\n\n"); // espa�amento 
	}
	
	system("pause"); // faz uma pausa


}

int deletar() //fun��o responsavel por deletar usuario
{
	char cpf[40]; //inicio cria��o de variaveis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletetar informa��o do usuario
    scanf("%s",cpf); //%s refere-se 
    
    remove(cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); // cria o arquivo
    
    if(file == NULL); // anula
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n"); //responde usuario
    	system("pause"); // faz uma pausa
    		
	}
    
}

int main() //ponto de partida
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cart�rio da EBAC###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1- Registrar nomes\n");
	    printf("\t2- Consultar nomes\n");
	    printf("\t3- Deletar  nomes\n\n"); 
	    printf("\t4- Sair do sistema\n\n");
	    printf("Op��o: ");//Fim do menu
	
        scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    
        system("cls");// responsavel por limpar a tela
        
        switch(opcao)//Inicio de sele��o do menu
        {
        	case 1:
            registro(); //  chamada de fun��es
		    break; // encerra instru��o
		    
		    case 2:
		    consulta(); // chamada de fun��es
			break; // encerra instru��o
			
			case 3:	
			deletar(); // chamada de fun��es
		    break;// encerra instru��o
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		    
		    
		    
		    default:
		    printf("Essa op��o n�o est� disponivel!\n");
	     	system("pause");
	     	break; // encerra instru��o
	    } //Fim da sele��o
        
    }
}
