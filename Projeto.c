//na linguagem "C" usamos as 'bibliotecas'(include).           

#include <stdio.h> // Biblioteca de comunicação com o usuário.
#include <stdlib.h> //Biblioteca de alocação de espaço em memória.
#include <locale.h> //Biblioteca de acentuação de texto por região.
#include <string.h> // biblioteca reponsável por cuidar das strings
    int registro() //colocamos as funções separadas do 'switch case' para performar o sistema (deixar mais leve) e poder chama-las em qualquer parte do código
   { 
     char arquivo[40]; //
	 char cpf [40];  //
	 char nome [40];  // Variáveis do tipo "char" para o menu de registro
	 char sobrenome [40];  //
	 char cargo [40];  //
	   
	   printf("Digite o CPF a ser cadastrado: ");
	   scanf ("%s" , cpf); //"%s" serve para escanear strings (string= conjunto de variáveis)
	   
	   strcpy(arquivo , cpf); // "strcpy" responsável por copiar os valores das strings
	   
	   FILE *file;  // cria o arquivo
	   file = fopen(arquivo , "w"); // "fopen"- abre o arquivo
	   fprintf(file, cpf);
	   fclose(file); // "fclose"- fecha o arquivo
	   
	   file = fopen(arquivo, "a");
	   fprintf(file, "\t|\t");
	   fclose(file);
	   
	   printf("Digite o nome a ser cadastrado: ");
	   scanf("%s" ,nome);
	   
	   file = fopen(arquivo, "a"); // "a"- serve para ATUALIZAR/incluir O ARQUIVO, e não criar outro novo
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
	   fprintf(file,cargo); // "fprintf"- serve para colocar as informações dentro do arquivo
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
 	  
 	  if(file == NULL) // "==" comparação | "NULL"= núlo ou seja "se o arquivo for núlo".
 	  {
 	    printf("CPF não cadastrado.\n");	
	  }
	  
	  while(fgets(conteudo, 200, file)!= NULL) // "while": enquanto
	  {
	  	printf("\n Essas são as informações do usuário: ");
	  	printf("%s", conteudo);
	  	printf("\n\n");
	  }
	   system("pause");
 	
   }
 
    int deletar() //
   {
	  printf("Você escolheu Deletar Nomes\n");
      system("pause");
   }


int main()   //"int main" é a função principal  do código...ou o "body". | sempre a função que vai ser exibida na tela
{
	int opcao=0;//definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	   system("cls");
	 
	   setlocale (LC_ALL, "Portuguese"); //Sempre colocar ";" no final de cada função.
	
	   printf("\tCadastro Rabbit\n\n"); //o "\n" é para acrescentar espaçamento entre as linhas./ descer linha
	   printf("Escolha a opção desejada no menu:\n\n ");
   	   printf("\t1 - Registrar nomes\n"); // "\t" é para acrescentar espaçamento.
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("\tOpção:   ");
	 

	 scanf("%d", &opcao);// "%d" serve para armazenar uma variável do tipo inteiro. / "scanf" é para escanear a escolha do usuário
	 system("cls"); // nova tela / deletar mensagens anteriores
	 
	   switch(opcao)  // 'switch case' é outra versão do "if" para variáveis.
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
		
		default: // usamos 'default' para referirmos à uma opção que não mapeamos
		printf("Esta opção não está disponível no momento.\n");
		system("pause");
	   }
    }
}
