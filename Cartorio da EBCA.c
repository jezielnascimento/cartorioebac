#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o (Portuguese)
#include <string.h> // biblioteca responsavel por criar uma string


int registro() //Registro de informa��es de alunos e professores
{
	
	char arquivo[99]; //Vai armazenar as outras variaveis abaixo que se chama strings pois s�o varias
	char cpf[40]; //Daqui em diante seram Strings que seram armazenadas no (Arquivo) acima
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\n\nDigite o CPF a ser cadastrado:\n"); //Derecionamento de comando ao usuario
	scanf("%s", cpf);//Leitura e armazenamento das informa��es fornecidas pelo usuario
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo 
	file = fopen(arquivo,"w"); //Abre o arquivo criado e escreve no arquivo quando colocado = (w)
	fprintf(file,cpf); //Salvo o valor do cpf digitado pelo usuario no arquivo que acabamos de criar
	fclose(file); //Fecho o arquivo
	
	file = fopen(arquivo, "a");//Fa�o novamente a abertura do arquivo e fa�o a inser��o de pular linha (\n)
	fprintf(file, "\n"); //Abro arquivo
	fclose(file); //Fecho arquivo
	
	//Desta mesma forma descrita acima, ocorrera com as abaixo
	printf("\n\nDigite o NOME a ser cadastrado:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("\n\nDigite o SOBRENOME a ser cadastrado:\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("\n\nDigite o CARGO a ser cadastrado:\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	system("pause"); //Quando pauso o sistema em uma tela at� o usuario clicar em qualquer tecla
	
	
}

int consulta()  //Funcao para ser usado dentro da intm main, conforme a decisao do usuario
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem (sempre bom colocar ao inicio dos int) 
	
char cpf[40]; //Strings que seram consultadas
char conteudo[200]; //Faz a leitura de todo o arquivo salvo com a quantidade maxima de caracter inserida (200)
	
printf("\n\nDigite o CPF a ser consultado:\n");//Direcionamento ao usuario do que fazer a seguir
scanf("%s",cpf);//Armazendo da sua responta
  	
FILE *file;//Faco a abertura de arquivo
file = fopen(cpf,"r");//Escolho qual arquivo quero abrir (r) apartir de qual informa��o inserida (strings) pelo meu usario 
  	
if(file == NULL) //If - comando de repeti��o (== para se caso houver erro de digita��o se tornar NULL..
{
	printf("\n\nN�o foi possivel abrir o arquivo, n�o localizado!.\n");//...E essa sera a mensagem que aparecera ao usuario
}
	
while(fgets(conteudo, 100, file) != NULL)//Estrutura de repeti��o
//Fgets � a fun��o que vai ler o arquivo file e vai armazenar seu conteudo em conteudo e vai mostrar a baixo ao usuario
//Caso as informa��es n�o possam ser lidas ser
{
	printf("Essas s�o as informa��es do usu�rio:");
	printf("%s", conteudo,"\n"); //Exibi��o na tela do usuario as irforma��es contidas na string digitada pelo usuario

}
system ("pause");
}

int deletar()  //Funcao para ser usado dentro da int main, conforme a decisao do usuario
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf, "r"); //O r � de ler o arquivo
	
	if(file == NULL)
	{
		
		printf("O usu�rio n�o se encontra no sistema \n");
		system("pause");
	}
}




int main () //Funcao
{
	int opcao=0; // Definindo as variaveis
	int x=1; //Laco de repeti��o
	char senhadigitada[10]="a";//Criando string para a senha, e dando a ela valor
	int comparacao;
	

	
		system("cls");	
	
		setlocale(LC_ALL, "Portuguese"); // Definindo as  linguagem
	
		printf("\n\n   CART�RIO DA EBAC \n\n"); //Msg e menu de entrada
		printf("Login de administrador! \nDigite sua senha: ");
		scanf("%s", senhadigitada);
		
		comparacao = strcmp(senhadigitada,"admin");
		
		if(comparacao == 0)
		{
		system ("cls");
				
		for(x=1;x=1;)
		{
		printf("Escolha a op��o deseja do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n"); 
		printf("\t2 - Consultar nomes\n"); 
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: ");                      
	
		scanf("%d", &opcao); // Recebendo comando do usuario e armazendano a escolha
	
		system ("cls");//Apaga as informa��es na tela apos decis�o
	
		switch(opcao) //Estrutua de repeti��o com os valores ja inseridos a cima em forma de int
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
			printf("Obrigado por ultilizar nosso sistema!\n");
			return 0;
			break;

			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			//fim da sele��o

		}
	}
}
			else
   		printf("Senha incorreta");

   		
}
