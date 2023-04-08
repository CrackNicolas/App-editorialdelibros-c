#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
using namespace std;

FILE *file;
FILE *file_aux;

struct Fecha{
	int dd,mm,aaaa;
}fech;

struct ISBN{
	int PreInter,DigitoCon;
	char GrupoR[6],Agente[8],Ident[7];
}s;

struct Datos{
	char TituloObra[100],nombre[100],apellido[100],NomEdit[100];
	struct Fecha fech;
	struct ISBN s;
	float Precio;
	int nroEnteros;
}dat;

void Menu_principal();
void Cargar_datos(FILE *file);
void Muestra_datos(FILE *file);
void Eliminar_registro(FILE *file);
void Menu_busqueda();
void Busqueda(FILE *file);

int val=0,vall=0,valll=0,v=0,vv=0,vvv=0,x=0,xx=0,V=0,z=0,zz=0,zzz=0,zzzz=0,y=0,yy=0,yyy=0,sum=0,R=0,g=0,p=0,n=0,mm=0,j,l=0,band=0,a=0,m=0,d=0,LimDia=0;
char opc;

int main(){
	do{
		Menu_principal();
		switch(n){
			case 1:
				Cargar_datos(file); 
			break;
			case 2:
				Muestra_datos(file); 
			break;
			case 3:
				Busqueda(file); 
			break;
			case 4: 
				Eliminar_registro(file); 
			break;
			case 5:
				system("cls");
				cout<<" .....................................................\n";
				cout<<"                      FINALIZADO";
				cout<<"\n .....................................................";
			break;
		}
	}while(n!=5);
}
void Cargar_datos(FILE *file){
	file = fopen("CargaDatos.dat","a+b");
	do{	
		sum=0,R=0;
		system("cls");
		do{ 
			v=0;vv=0;x=1;xx=1,V=0;
			system("cls");
			_flushall();
			cout<<" .....................................................\n";
			cout<<" \t      SIGA LOS SIGUIENTES PASOS 		 |";
			cout<<"\n .....................................................";
			cout<<"\n   |Su nombre y apellido del autor|\n";
			cout<<"   --------------------------------\n";
			cout<<"\n * Debera contener un nombre y un apillido...\n";
			cout<<"\n * Tanto como su apellido y su nombre deberan empesar";
			cout<<"\n   con mayusculas...\n";
			cout<<"\n * Puede haber abreviaturas mayuscula seguida de";
			cout<<"\n   minusculas y termina en punto...\n";
			cout<<"\n * Se separan con espacio en blanco...\n";
			cout<<"\n * No debera superar los 30 caracteres...\n";
			cout<<"\n * No se permiten numeros...\n";
			cout<<" .......................................................";
			cout<<"\n\n << ";
			system("pause");
			system("cls"); 
			_flushall();
			cout<<"\n "<<j+1<<" -Digite nombre: ";
			scanf("%s",&dat.nombre);
			_flushall();
			cout<<"\n "<<j+1<<" -Digite apellido: ";
			scanf("%s",&dat.apellido);	
			for(int i=0;i<strlen(dat.nombre);i++){
				x = (dat.nombre[i]>=48 && dat.nombre[i]<=57)? 0 : 1;
				if(i==0){
					v = (dat.nombre[i]>=65 && dat.nombre[i]<=90)? 1 : 0;
				}
			}
			for(int i=0;i<strlen(dat.apellido);i++){
				xx = (dat.apellido[i]>=48 && dat.apellido[i]<=57)? 0 : 1;
				if(i==0){
					vv = (dat.apellido[i]>=65 && dat.apellido[i]<=90)? 1 : 0;
				}
			}
			if(xx==0 || x==0){
				cout<<"\n Error. No se permiten numeros. Vuelva a ingresar";
			}else{
				if(v==0 && vv==0){
					cout<<"\n Error. Ingreso mal sus datos. Vuelva a intentar";
					vvv=1;
				}else if(vvv==0){
					if(v==0){
						cout<<"\n Error. Ingreso mal su nombre. Vuelva a intentar";
					}else if(vv==0){
						cout<<"\n Error. Ingreso mal su apellido. Vuelva a intentar";
					}
				}
				if(((strlen(dat.nombre))+(strlen(dat.apellido)))>30){
					cout<<"\n Su nombre y apellido no debe superar los 30 caracteres";
					V=0;
				}else{ 
					V=1; 
				}
			}
			if(x==1 && xx==1 && v==1 && vv==1 && V==1){ 
				val=1; 
			}else{ 
				Sleep(3500); 
			}
		}while(val==0);
		do{ 
			z=0;zz=1;zzz=0;zzzz=0;
			system("cls");
			_flushall();
			cout<<" .....................................................\n";
			cout<<" \t        SIGA LOS SIGUIENTES PASOS";
			cout<<"\n .....................................................";
			cout<<"\n   |Titulo de la obra|\n";
			cout<<"   -------------------\n";
			cout<<"\n * Debera contener al menos una letra...\n";
			cout<<"\n * Solo se permiten numeros decimales...\n";
			cout<<"\n * Signos de puntuacion...\n";
			cout<<"\n * Longitud maxima 100 caracteres...\n";
			cout<<" .....................................................";
			cout<<"\n\n << ";
			system("pause");
			system("cls");
			_flushall();
			cout<<"\n "<<j+1<<" -Digite el titulo de la obra: ";
			scanf("%s",&dat.TituloObra);
			for(int i=0;i<strlen(dat.TituloObra);i++){
				if((dat.TituloObra[i]>=65 && dat.TituloObra[i]<=90)||(dat.TituloObra[i]>=97 && dat.TituloObra[i]<=122)){
					z=1;	
				}
				if(dat.TituloObra[i]>=48 && dat.TituloObra[i]<=57){
					zz=1;
				}
				if((dat.TituloObra[i]>=33 && dat.TituloObra[i]<=64)||(dat.TituloObra[i]>=91 && dat.TituloObra[i]<=96)||(dat.TituloObra[i]>=123 && dat.TituloObra[i]<=126)){
					zzz=1;	
				}
				if(strlen(dat.TituloObra)<100){
					zzzz=1;
				}
			}
			if(z==0){
				cout<<"\n Error. El titulo de la obra debe contener por lo menos una letra";
			}
			if(zz==0){
				cout<<"\n Error. El titulo de la obra solo permite numeros decimales";
			}
			if(zzz==0){
				cout<<"\n Error. El titulo de la obra debe contener signos de puntuacion";
			}
			if(zzzz==0){
				cout<<"\n Error. El titulo de la obra no debe ser mayor a 40 caracteres";
			}
			if(z==1 && zz==1 && zzz==1 && zzzz==1){
				vall=1;
			}else{ 
				Sleep(3500); 
			}
		}while(vall==0);
		vall=0;
		do{ 
			z=0;zz=1;zzz=0;zzzz=0;
			system("cls");
			_flushall();
			cout<<" .....................................................\n";
			cout<<" \t       SIGA LOS SIGUIENTES PASOS";
			cout<<"\n .....................................................";
			cout<<"\n   |Nombre de la editorial|\n";
			cout<<"   ------------------------\n";
			cout<<"\n * Debera contener al menos una letra...\n";
			cout<<"\n * Solo se permiten numeros decimales...\n";
			cout<<"\n * Signos de puntuacion...\n";
			cout<<"\n * Longitud maxima 100 caracteres...\n";
			cout<<" .....................................................";
			cout<<"\n\n << ";
			system("pause");
			system("cls");
			_flushall();
			cout<<"\n "<<j+1<<" -Digite nombre de la editorial: ";
			scanf("%s",&dat.NomEdit);
			for(int i=0;i<strlen(dat.NomEdit);i++){
				if((dat.NomEdit[i]>=65 && dat.NomEdit[i]<=90)||(dat.NomEdit[i]>=97 && dat.NomEdit[i]<=122)){
					z=1;
				}
				if(dat.NomEdit[i]>=48 && dat.NomEdit[i]<=57){
					zz=1;
				}
				if((dat.NomEdit[i]>=33 && dat.NomEdit[i]<=64)||(dat.NomEdit[i]>=91 && dat.NomEdit[i]<=96)||(dat.NomEdit[i]>=123 && dat.NomEdit[i]<=126)){
					zzz=1;
				}
				if(strlen(dat.NomEdit)<100){
					zzzz=1;
				}
			}
			if(z==0){
				cout<<"\n Error. El nombre de la editorial debe contener por lo menos una letra";
			}
			if(zz==0){
				cout<<"\n Error. El nombre de la editorial solo permite numeros decimales";
			}
			if(zzz==0){
				cout<<"\n Error. El nombre de la editorial debe contener signos de puntuacion";
			}
			if(zzzz==0){
				cout<<"\n Error. El nombre de la editorial no debe ser mayor a 40 caracteres";
			}
			if(z==1 && zz==1 && zzz==1 && zzzz==1){
				vall=1;
			}else{ 
				Sleep(3500); 
			}
		}while(vall==0);
		system("cls");
		vall=0;
		do{
			system("cls");
			_flushall();
			cout<<"\n "<<j+1<<" -Digite fecha de publicacion \n";
			Sleep(2000);
			do{ 
				system("cls");
				printf("\n Digite el a%co: ",164);
				cin>>a;
				if(a<=0){
					printf("\n El a%co no puede ser menor a cero...Vuelva a intentar",164);
					Sleep(2000);
				}
			}while(a<=0);
			if(a % 4 == 0){ 
				printf(" El a%co es bisiesto",164); 
				Sleep(2000); 
			}
			do{ 
				system("cls");
				printf("\n Digite el mes: ");
				cin>>m;
				if(m<=0 || m>=13){
					cout<<"\n El mes solo puede ser del 1 al 12...Vuelva a intentar";
					Sleep(2000);
				}
			}while(m<=0 || m>=13);
			if(a % 4 == 0){
				LimDia = (m==2)? 29 : (m==1||m==3||m==5||m==7||m==8||m==10||m==12)? 31 : 30;
			}else{
				LimDia = (m==2)? 28 : (m==1||m==3||m==5||m==7||m==8||m==10||m==12)? 31 : 30;
			}
			system("cls");
			do{	
				system("cls");
				printf("\n Digite el dia: ",164);
				cin>>d;
				if(d<=0||d>LimDia){
					cout<<"\n Este mes solo tiene "<<LimDia<<" dias...Vuelva a intentar";
					Sleep(2000);
				}
			}while(d<=0||d>LimDia);
			cout<<"\n Fecha valida: "<<d<<" / "<<m<<" / "<<a<<" ";
			dat.fech.dd=d;
			dat.fech.mm=m;
			dat.fech.aaaa=a;
			vall=1;
			getch();
		}while(vall==0);
		system("cls");
		vall=0;
		cout<<"\n "<<j+1<<" -Digite el precio del libro \n";
		Sleep(2000);
		do{
			system("cls");
			_flushall();
			cout<<"\n "<<j+1<<" -Precio: $";
			scanf("%f",&dat.Precio);
			vall = (dat.Precio>0.01 && dat.Precio<=99999.99)? 1 : 0;
			if(vall==0){
				cout<<"\n Solo se permiten numeros que esten entre 0.01 y 99999.99";
				Sleep(2000);
			}
		}while(vall==0);
		do{
			system("cls");
			_flushall();
			cout<<" .....................................................\n";
			cout<<" \t       SIGA LOS SIGUIENTES PASOS";
			cout<<"\n .....................................................";
			cout<<"\n   |Cantida de ejemplares|\n";
			cout<<"   ---------\n";
			cout<<"\n * Su cantidad debera estar entre 1 _ 9999...\n";
			cout<<" .....................................................";
			cout<<"\n\n << ";
			system("pause");
			system("cls");
			_flushall();
			cout<<"\n "<<j+1<<" -Cantidad: ";
			scanf("%d",&dat.nroEnteros);
			valll = (dat.nroEnteros>=1 && dat.nroEnteros<=9999)? 1 : 0;
			if(valll==0){
				cout<<"\n Error el numero que ingreso no esta dentro del rango permitido .Vuelva a ingresar";
				Sleep(2000);
			}
		}while(valll==0);
		system("cls");
		_flushall();
		cout<<" .....................................................\n";
		cout<<" \t        SIGA LOS SIGUIENTES PASOS";
		cout<<"\n .....................................................";
		cout<<"\n   |ISBN|\n";
		cout<<"   ------\n";
		cout<<"\n * Para el prefijo internacional tenga en cuenta que\n";
		cout<<"   el numero 978 se usa para crear un ISBN de 10\n";
		cout<<"   digitos y el 979 no es compatible con esos ISBN\n";
		cout<<"\n * Para el grupo de registro solo se permiten digitos\n";
		cout<<"   del 1 al 5\n";
		cout<<"\n * Para el agente editor solo se permiten digitos\n";
		cout<<"   del 1 al 7 \n";
		cout<<"\n * Para el identificador de titulo solo se permiten\n";
		cout<<"   digitos del 1 al 6 \n";
		cout<<" .........................................................";
		cout<<"\n\n << ";
		system("pause");
		system("cls");
		do{ 
			system("cls");
			_flushall();
			cout<<"\n Digite prefijo internacional (978/979): ";
			cin>>dat.s.PreInter;
			if(dat.s.PreInter!=978&&dat.s.PreInter!=979){
				p=0;
				cout<<"\n Error solo se permiten los numeros 978 y 979";
			}else{ 
				sum = (9+(7*3)) + (dat.s.PreInter==978)? 8 : 9;
				p=1; 
			} 
			Sleep(1000);
		}while(p==0);
		p=0;
		do{ 
			system("cls");
			_flushall();
			cout<<"\n Digite el grupo de registro: ";
			gets(dat.s.GrupoR);
			p = ((strlen(dat.s.GrupoR))>=6)? 0 : 1;
			if(p==0){
				cout<<"\n Error el numero que puso no es encuentra en el rango permitido. Vuelva a intentar";
				Sleep(2000);
			}
		}while(p==0);
		p=0;
		do{ 
			system("cls");
			_flushall();
			cout<<"\n Digito agente editor: ";
			gets(dat.s.Agente);
			p = ((strlen(dat.s.Agente))>=8)? 0 : 1;
			if(p==0){
				cout<<"\n Error el numero que puso no es encuentra en el rango permitido. Vuelva a intentar";
				Sleep(2000);
			}
		}while(p==0);
		p=0;
		do{ 
			system("cls");
			_flushall();
			cout<<"\n Digite identificador de titulo: ";
			gets(dat.s.Ident);
			p = ((strlen(dat.s.Ident))>=7)? 0 : 1;
			if(p==0){
				cout<<"\n Error el numero que puso no es encuentra en el rango permitido. Vuelva a intentar";
				Sleep(2000);
			}
		}while(p==0);
		for(int i=0;i<strlen(dat.s.GrupoR);i++){
			if(dat.s.GrupoR[i]>=48&&dat.s.GrupoR[i]<=57){
				g=dat.s.GrupoR[i];
				if(g==48){ g=0; }
				if(g==49){ g=1; }
				if(g==50){ g=2; }
				if(g==51){ g=3; }
				if(g==52){ g=4; }
				if(g==53){ g=5; }
				if(g==54){ g=6; }
				if(g==55){ g=7; }
				if(g==56){ g=8; }
				if(g==57){ g=9; }
				if(i==0||i==2||i==4){
					sum=(sum+(g*3));
				}
				if(i==1||i==3){
					sum+=g;
				}
			}
			g=0;
		}
		for(int i=0;i<(strlen(dat.s.Agente));i++){
			if(dat.s.Agente[i]>=48&&dat.s.Agente[i]<=57){
				g=dat.s.Agente[i];
				if(g==48){ g=0; }
				if(g==49){ g=1; }
				if(g==50){ g=2; }
				if(g==51){ g=3; }
				if(g==52){ g=4; }
				if(g==53){ g=5; }
				if(g==54){ g=6; }
				if(g==55){ g=7; }
				if(g==56){ g=8; }
				if(g==57){ g=9; }
				if(((strlen(dat.s.GrupoR))==1)||((strlen(dat.s.GrupoR))==3)||((strlen(dat.s.GrupoR))==5)){
					sum = (i==1||i==3||i==5)? (sum+(g*3)) : (sum+g);
				}
				if(((strlen(dat.s.GrupoR))==0)||((strlen(dat.s.GrupoR))==2)||((strlen(dat.s.GrupoR))==4)){
					sum = (i==0||i==2||i==4||i==6)? (sum+(g*3)) : (sum+g);
				}
			}
			g=0;
		}
		for(int i=0;i<(strlen(dat.s.Ident));i++){
			if(dat.s.Ident[i]>=48&&dat.s.Ident[i]<=57){
				g=dat.s.Ident[i];
				if(g==48){ g=0; }
				if(g==49){ g=1; }
				if(g==50){ g=2; }
				if(g==51){ g=3; }
				if(g==52){ g=4; }
				if(g==53){ g=5; }
				if(g==54){ g=6; }
				if(g==55){ g=7; }
				if(g==56){ g=8; }
				if(g==57){ g=9; }
				if(((strlen(dat.s.Agente))==1)||((strlen(dat.s.Agente))==3)||((strlen(dat.s.Agente))==5)||((strlen(dat.s.Agente))==7)){
					sum = (i==0||i==2||i==4)? (sum+(g*3)) : (sum+g);
				}
				if(((strlen(dat.s.Agente))==0)||((strlen(dat.s.Agente))==2)||((strlen(dat.s.Agente))==4)){
					sum = (i==1||i==3||i==5)? (sum+(g*3)) : (sum+g);
				}
			}
			g=0;
		}		
		R=sum%10;
		if(R!=0){
			dat.s.DigitoCon=10-R;
		}else if(R==0){
			dat.s.DigitoCon=R;
		}
		printf("\n ISBN :%d-%s-%s-%s-%d",dat.s.PreInter,dat.s.GrupoR,dat.s.Agente,dat.s.Ident,dat.s.DigitoCon);
		getch();		
		fwrite(&dat,sizeof(Datos),1,file);
		system("cls");
		_flushall();
		cout<<"\n Decea cargar mas registros (s/n): ";
		scanf("%c",&opc);
		if(opc=='s'||opc=='S'){ 
			j++; 
			band=0; 
		}
		if(opc=='n'||opc=='N'){ 
			band=1; 
		}
	}while(band==0);
	fclose(file);
}
void Muestra_datos(FILE *file){
	system("cls");
	cout<<" .........................................................\n";
	cout<<" \t          MOSTRANDO REGISTROS";
	cout<<"\n .........................................................";	
	rewind(file);
	file = fopen("CargaDatos.dat","r+b");
	fread(&dat,sizeof(Datos),1,file);
	while(!feof(file)){
		cout<<"\n ---------------------------------------------------------";
		cout<<"\n Registro numero "<<l+1<<"\n";
		printf(" - Nombre y apellido: %s %s",dat.nombre,dat.apellido);
		printf("\n - Titulo de la obra: %s",dat.TituloObra);
		printf("\n - Nombre de la editorial: %s",dat.NomEdit);
		cout<<"\n - Fecha de publicacion: "<<dat.fech.dd<<"/"<<dat.fech.mm<<"/"<<dat.fech.aaaa<<"";
		printf("\n - Precio: $%.2f",dat.Precio);
		cout<<"\n - Cantidad: "<<dat.nroEnteros;
		printf("\n - ISBN: %d-%s-%s-%s-%d",dat.s.PreInter,dat.s.GrupoR,dat.s.Agente,dat.s.Ident,dat.s.DigitoCon);
		cout<<"\n ---------------------------------------------------------";
		l++;
		fread(&dat,sizeof(Datos),1,file);
	}
	getch();
	fclose(file);
}
void Eliminar_registro(FILE *file){
	char nomAux[40],apeAux[40];
	int f=0;
	system("cls");
	_flushall();
	cout<<"\n Digite el nombre de la persona que decee eliminar: ";
	scanf("%s",&nomAux);
	cout<<"\n Digite el apellido de la persona que decee eliminar: ";
	scanf("%s",&apeAux);
	rewind(file);
	file = fopen("CargaDatos.dat","r+b");
	file_aux = fopen("EliminaRef.dat","a+b");
	fread(&dat,sizeof(Datos),1,file);
	while(!feof(file)){
		if((strcmp(nomAux,dat.nombre)&&strcmp(apeAux,dat.apellido))==0){
			system("cls");
			system("color 4");
			cout<<"\n -----------------------------------------------------";
			cout<<"\n 	   Registro eliminado con exito";
			cout<<"\n -----------------------------------------------------";
			f=1;
		}else{
			fwrite(&dat,sizeof(Datos),1,file_aux);
		}
		fread(&dat,sizeof(Datos),1,file);
	}
	if(f==0){ 
		system("cls");
		system("color 4");
		cout<<"\n -----------------------------------------------------";
		cout<<"\n 	       Registro no encontrado";
		cout<<"\n -----------------------------------------------------";
		Sleep(2000);
	}
	fclose(file);
	fclose(file_aux);
	remove("CargaDatos.dat");
	rename("EliminaRef.dat","CargaDatos.dat");
	getch();
}
void Busqueda(FILE *file){
	char ApellidoAux[40],NombreAux[40],EditorialAux[40],ObraAux[40];
	int ddd=0,mmm=0,aaa=0,bus=0;
	do{
		Menu_busqueda();
		bus=0;
		system("cls");
		_flushall();
		switch(mm){
			case 1:
				cout<<"\n Digite el nombre que decea buscar: ";
				gets(NombreAux);
				cout<<"\n Digite el apellido que decea buscar: ";
				gets(ApellidoAux);
				rewind(file);
				file = fopen("CargaDatos.dat","r+b");
				fread(&dat,sizeof(Datos),1,file);
				while(!feof(file)){
					if((strcmp(NombreAux,dat.nombre)&&strcmp(ApellidoAux,dat.apellido))==0){
						bus=1;
						system("cls");
						printf("\n\n ISBN :%d-%s-%s-%s-%d",dat.s.PreInter,dat.s.GrupoR,dat.s.Agente,dat.s.Ident,dat.s.DigitoCon);
						cout<<"\n\n Registro \n";
						printf("- Nombre y apellido: %s %s",dat.nombre,dat.apellido);
						printf("\n- Titulo de la obra: %s",dat.TituloObra);
						printf("\n- Nombre de la editorial: %s",dat.NomEdit);
						cout<<"\n- Fecha de publicacion "<<dat.fech.dd<<"/"<<dat.fech.mm<<"/"<<dat.fech.aaaa<<"";
						printf("\n- Precio: $%.2f",dat.Precio);
						cout<<"\n- Cantidad: "<<dat.nroEnteros;
					}
					fread(&dat,sizeof(Datos),1,file);
				}
			break;
			case 2:
				cout<<"\n Digite el nombre de la editorial que decea buscar: ";
				gets(EditorialAux);
				rewind(file);
				file=fopen("CargaDatos.dat","r+b");
				fread(&dat,sizeof(Datos),1,file);
				while(!feof(file)){
					if(strcmp(EditorialAux,dat.NomEdit)==0){
						bus=1;
						system("cls");
						printf("\n\n ISBN :%d-%s-%s-%s-%d",dat.s.PreInter,dat.s.GrupoR,dat.s.Agente,dat.s.Ident,dat.s.DigitoCon);
						cout<<"\n\n Registro \n";
						printf("- Nombre y apellido: %s %s",dat.nombre,dat.apellido);
						printf("\n- Titulo de la obra: %s",dat.TituloObra);
						printf("\n- Nombre de la editorial: %s",dat.NomEdit);
						cout<<"\n- Fecha de publicacion "<<dat.fech.dd<<"/"<<dat.fech.mm<<"/"<<dat.fech.aaaa<<"";
						printf("\n- Precio: $%.2f",dat.Precio);
						cout<<"\n- Cantidad: "<<dat.nroEnteros;
					}
					fread(&dat,sizeof(Datos),1,file);
				}
			break;
			case 3:
				cout<<"\n Digite el titulo de la obra que decea buscar: ";
				gets(ObraAux);
				rewind(file);
				file = fopen("CargaDatos.dat","r+b");
				fread(&dat,sizeof(Datos),1,file);
				while(!feof(file)){
					if(strcmp(ObraAux,dat.TituloObra)==0){
						bus=1;
						system("cls");
						printf("\n\n ISBN :%d-%s-%s-%s-%d",dat.s.PreInter,dat.s.GrupoR,dat.s.Agente,dat.s.Ident,dat.s.DigitoCon);
						cout<<"\n\n Registro \n";
						printf("- Nombre y apellido: %s %s",dat.nombre,dat.apellido);
						printf("\n- Titulo de la obra: %s",dat.TituloObra);
						printf("\n- Nombre de la editorial: %s",dat.NomEdit);
						cout<<"\n- Fecha de publicacion "<<dat.fech.dd<<"/"<<dat.fech.mm<<"/"<<dat.fech.aaaa<<"";
						printf("\n- Precio: $%.2f",dat.Precio);
						cout<<"\n- Cantidad: "<<dat.nroEnteros;
					}
					fread(&dat,sizeof(Datos),1,file);
				}
			break;
			case 4:
				cout<<"\n Digite la fecha de publicacion para buscar registro \n";
				cout<<"- Dia: ";
				cin>>ddd;
				cout<<"- Mes: ";
				cin>>mmm;
				printf("- A%co: ",164);
				scanf("%d",&aaa);
				rewind(file);
				file = fopen("CargaDatos.dat","r+b");
				fread(&dat,sizeof(Datos),1,file);
				cout<<"\n Registros publicados en la fecha "<<ddd<<"/"<<mmm<<"/"<<aaa<<"\n";
				while(!feof(file)){
					if((ddd==dat.fech.dd)&&(mmm==dat.fech.mm)&&(aaa==dat.fech.aaaa)){
						bus=1;
						system("cls");
						printf("\n\n ISBN :%d-%s-%s-%s-%d",dat.s.PreInter,dat.s.GrupoR,dat.s.Agente,dat.s.Ident,dat.s.DigitoCon);
						cout<<"\n\n Registro \n";
						printf("- Nombre y apellido: %s %s",dat.nombre,dat.apellido);
						printf("\n- Titulo de la obra: %s",dat.TituloObra);
						printf("\n- Nombre de la editorial: %s",dat.NomEdit);
						printf("\n- Precio: $%.2f",dat.Precio);
						cout<<"\n- Cantidad: "<<dat.nroEnteros;
					}
					fread(&dat,sizeof(Datos),1,file);
				}
			break;
		}
		if(bus==0){
			system("cls");
			system("color 4");
			cout<<"\n -----------------------------------------------------";
			cout<<"\n 	       Registro no encontrado";
			cout<<"\n -----------------------------------------------------";
		}
		getch();
		fclose(file);
	}while(mm!=5);
	fclose(file);
}
void Menu_principal(){
	system("cls");
	system("color a");
	_flushall();
	cout<<"\n -----------------------------------------------------";
	cout<<"\n |                  MENU PRINCIPAL    		     |";
	cout<<"\n -----------------------------------------------------";
	cout<<"\n\n |    1.-REGISTRO DE DATOS			     |";
	cout<<"\n\n |    2.-MOSTRAR DATOS 				     |";
	cout<<"\n\n |    3.-BUSCAR REGISTRO			     |";
	cout<<"\n\n |    4.-DAR DE BAJA UN REGISTRO 		     |";
	cout<<"\n\n |    5.-SALIR 					     |";
	cout<<"\n\n -----------------------------------------------------";
	cout<<"\n *****************************************************";
	cout<<"\n           SELECIONE EL NUMERO DE SU OPCION ";
	cout<<"\n *****************************************************\n opc ->> ";
	_flushall();
	cin>>n;
}
void Menu_busqueda(){
	system("cls");
	system("color a");
	_flushall();
	cout<<"\n -----------------------------------------------------";
	cout<<"\n |      	   MEDIO DE BUSQUEDA    	     |";
	cout<<"\n -----------------------------------------------------";
	cout<<"\n\n |    1.-NOMBRE Y APELLIDO			     |";
	cout<<"\n\n |    2.-NOMBRE DE LA EDITORIAL		   	     |";
	cout<<"\n\n |    3.-TITULO DE LA OBRA			     |";
	cout<<"\n\n |    4.-FECHA DE PUBLICACION 		     	     |";
	cout<<"\n\n |    5.-SALIR 					     |";
	cout<<"\n\n -----------------------------------------------------";
	cout<<"\n *****************************************************";
	cout<<"\n           SELECIONE EL NUMERO DE SU OPCION ";
	cout<<"\n *****************************************************\n opc ->> ";
	_flushall();
	cin>>mm;
}
