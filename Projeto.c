//na linguagem "C" usamos as 'bibliotecas'(include).           

#include <stdio.h> // Biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //Biblioteca de acentua��o de texto por regi�o.
#include <string.h> // biblioteca repons�vel por cuidar das strings
    int registro() //colocamos as fun��es separadas do 'switch case' para performar o sistema (deixar mais leve) e poder chama-las em qualquer parte do c�digo
   { 
     char arquivo[40]; //
	 char cpf [40];  //
	 char nome [40];  // Vari�veis do tipo "char" para o menu de registro
	 char sobrenome [40];  //
	 char cargo [40];  //
	   
	   printf("Digite o CPF a ser cadastrado: ");
	   scanf ("%s" , cpf); //"%s" serve para escanear strings (string= conjunto de vari�veis)
	   
	   strcpy(arquivo , cpf); // "strcpy" respons�vel por copiar os valores das strings
	   
	   FILE *file;  // cria o arquivo
	   file = fopen(arquivo , "w"); // "fopen"- abre o arquivo
	   fprintf(file, cpf);
	   fclose(file); // "fclose"- fecha o arquivo
	   
	   file = fopen(arquivo, "a");
	   fprintf(file, "\t|\t");
	   fclose(file);
	   
	   printf("Digite o nome a ser cadastrado: ");
	   scanf("%s" ,nome);
	   
	   file = fopen(arquivo, "a"); // "a"- serve para ATUALIZAR/incluir O ARQUIVO, e n�o criar outro novo
	   fprintf(file, nome);
	   fclose(file);
	   
	   file = fopen(arquivo, "a");
	   fprintf(file, "\t|\t");
	   fclose(file);
	   
	   printf("Digite o sobrenome a ser cadastrado: ");
	   scanf("%s" , sobrenome);
	   
	   file = fopen(arquivo, "a");
	   fprintf(file,sobrenome);
	   fclose(file);
	
	   file = fopen (arquivo, "a");
	   fprintf(file, "\t|\t");
	   fclose(file);
	
	   printf("Digite o cargo a ser castrado: ");
	   scanf("%s" ,cargo);
	   
	   file = fopen (arquivo, "a");
	   fprintf(file,cargo); // "fprintf"- serve para colocar as informa��es dentro do arquivo
	   fclose(file);
	}
    int consulta() //
   {
 	   setlocale (LC_ALL, "Portuguese"); 
 	   
	   char cpf[40];
 	   char conteudo[200];
 	  
 	  printf("Digite o CPF a ser consultado: ");
 	  scanf("%s" , cpf);
 	  
 	  FILE *file;
 	  file = fopen(cpf, "r"); // "r"vem de "read"= ler | Ler CPF
 	  
 	  if(file == NULL) // "==" compara��o | "NULL"= n�lo ou seja "se o arquivo for n�lo".
 	  {
 	    printf("CPF n�o cadastrado.\n");	
	  }
	  
	  while(fgets(conteudo, 200, file)!= NULL) // "while": enquanto
	  {
	  	printf("\n Essas s�o as informa��es do usu�rio: ");
	  	printf("%s", conteudo);
	  	printf("\n\n");
	  }
	   system("pause");
 	
   }
 
    int deletar() //
   {
	  printf("Voc� escolheu Deletar Nomes\n");
      system("pause");
   }


int main()   //"int main" � a fun��o principal  do c�digo...ou o "body". | sempre a fun��o que vai ser exibida na tela
{
	int opcao=0;//definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	   system("cls");
	 
	   setlocale (LC_ALL, "Portuguese"); //Sempre colocar ";" no final de cada fun��o.
	
	   printf("\tCadastro Rabbit\n\n"); //o "\n" � para acrescentar espa�amento entre as linhas./ descer linha
	   printf("Escolha a op��o desejada no menu:\n\n ");
   	   printf("\t1 - Registrar nomes\n"); // "\t" � para acrescentar espa�amento.
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("\tOp��o:   ");
	 

	 scanf("%d", &opcao);// "%d" serve para armazenar uma vari�vel do tipo inteiro. / "scanf" � para escanear a escolha do usu�rio
	 system("cls"); // nova tela / deletar mensagens anteriores
	 
	   switch(opcao)  // 'switch case' � outra vers�o do "if" para vari�veis.
	   {
	 	case 1:
		 registro();
	    break;
	    
	    case 2:
	     consulta();
    	break;
    	
    	case 3:
    	 deletar();
		break;
		
		case 4:
		 printf("Obrigado por utilizar o sistema!");
		 return 0;
		 break;
		
		default: // usamos 'default' para referirmos � uma op��o que n�o mapeamos
		printf("Esta op��o n�o est� dispon�vel no momento.\n");
		system("pause");
	   }
    }
}
