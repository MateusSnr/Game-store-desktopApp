//Nome: Mateus Salles Novaes Rocha
//Ra: 200581

#include<stdio.h>
#include<string.h>

struct infos{
	int codigo;
	char produto[15];
	int quantidade;
	float valor;
	float total;
	
	infos(int qtd,float value){
		quantidade = qtd;
		valor = value;
	}
	
	void Totaliza(){
		float calc;
		
		total = quantidade*valor;
		
		if(quantidade>=5){
			calc = (total/100)*5;
			total-=calc;
		}
	}
};
	
	int EfetuarPedido(){
		int codigoV;
		
		char prod[15];
		
		float valorA;
		
		int codigoA;
		
		infos itens(itens.quantidade,itens.codigo);
		
		printf("\nDigite o codigo do produto: ");
		scanf("%d",&codigoV);
		
		FILE *fp;
		
		fp = fopen("F:\\SEMESTRE1\\P2-1Semestre - C++\\produtos.txt","r");
		
		while(!feof(fp)){
			fscanf(fp,"%d %s %f", &codigoA, &prod, &valorA);
			if(codigoA == codigoV){
				itens.codigo = codigoA;
				strcpy(itens.produto,prod);
				itens.valor = valorA;
				
				printf("\nQuantidade de itens comprados: ");
				scanf("%d",&itens.quantidade);
		
				itens.Totaliza();
		
				FILE *mk;
		
				mk = fopen("F:\\SEMESTRE1\\P2-1Semestre - C++\\vendas.txt","a+");
		
				if(mk == 0){
					printf("\nErro ao abrir arquivo!!");
					return (1);
				}
				else{
					fflush(stdin);
					fprintf(mk,"%d\t%s\t%.2f\t\t%d\t%.2f\n",itens.codigo,itens.produto,itens.valor,itens.quantidade,itens.total);
				break;
				}
			}
			if(feof(fp)){
				printf("\nProduto nao encontrado!!");
				printf("\nDigite o codigo do produto: ");
				scanf("%d",&codigoV);
			}
		}
	}
	int ListarPedidos(){
		char textao[1000];
		
		int CodigoL,QuantidadeL;
		float TotalL;float ValorL;
		char ProdutoL[15];
		
		int cont = 0;
		
		FILE *tp;
		
		tp = fopen("F:\\SEMESTRE1\\P2-1Semestre - C++\\vendas.txt","r+");
		
		if(tp == 0){
			printf("\nErro ao abrir arquivo!!");
			return (9);
		}
		else{
			while(!feof(tp)){
				if(cont <= 4){
					fscanf(tp,"%s",&textao);
					printf("\t%s\t",textao);
					cont++;
				}
				else{
					printf("\n");
					fscanf(tp,"%d %s %f %d %f",&CodigoL ,&ProdutoL ,&ValorL ,&QuantidadeL ,&TotalL);
					printf("\n\t%d\t\t%s\t%.2f\t\t%d\t\t%.2f",CodigoL,ProdutoL,ValorL,QuantidadeL,TotalL);
			}
		}
	}
}

	int ListarProdutos(){
		
		int Codigo2,Cont2 = 0;
		float Preco2;
		char Produto2[15];
		
		FILE *cs;
		
		cs = fopen("F:\\SEMESTRE1\\P2-1Semestre - C++\\produtos.txt","r+");
		
		if(cs == 0){
			printf("\nErro ao abrir arquivo Produtos.txt!!");
			return(10);
		}
		else{
			while(!feof(cs)){
				printf("\n");
				fscanf(cs,"%d %s %f",&Codigo2,&Produto2,&Preco2);
				printf("\n\t%d\t\t%s\t\t\t%.2f",Codigo2,Produto2,Preco2);
				}
			}
		}
	

int main(){
	int escolha;
	
	do{
		printf("\n---MENU---\n");
		printf("\n1 - Efetuar Pedido;");
		printf("\n2 - Listar Pedidos;");
		printf("\n3 - Listar Produtos;");
		printf("\n4 - Sair;");
		printf("\nEscolha: ");
		scanf("%d",&escolha);
		
		switch(escolha){
			case 1:
				EfetuarPedido();
				break;
			case 2:
				ListarPedidos();
				break;
			case 3:
				ListarProdutos();
				break;
		}
		
	}while(escolha != 4);
}
