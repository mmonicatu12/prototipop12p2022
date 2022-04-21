

#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>

/*Librerias para la Fecha y La Hora*/
#include <iomanip>
#include <ctime>

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <windows.h>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
typedef struct {
   int  cuenta;
   char nompaciente[40];
   int primpar;
   int segpar;
   int nombrem;
   int apellidoss;
   int asunto;
}

pacientes;
void  NomCrear(void);
void  NomImprimir(void);
void  NomAnexar (void);
void  NomModificar(void);
void  NomBorrar(void);

void  Crear(void);
void  Imprimir(void);
void  Anexar (void);
void  Modificar(void);
void  Borrar(void);
void  Mantenimiento(void);
void  Bitacora(void);
void  Pend(void);
void  MenuPri(void);

int op,cent;
#include <iostream>
#include <fstream>

using namespace std;
int main(){

//MENU PRINCIPAL//


vector<string> usuarios;
    vector<string> claves;


    usuarios.push_back("MONICA");


    claves.push_back("PARCIAL2");


    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {

        system("cls");
        printf("\n------------------------------------------------------------------------------------------\n");
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::cout << std::put_time(&tm, "\n\t\t\t\t%d-%m-%Y %H-%M-%S") << std::endl;
        printf("\n------------------------------------------------------------------------------------------\n");
        printf("\n");
        Sleep(300);
        cout << "\t\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t\t----------------" << endl;
        cout << "\n\t\t\tUsuario: ";
        Sleep(200);
        getline(cin, usuario);

        char caracter;

        cout << "\t\t\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\t\t\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t----------\2--------------" << endl;
        MenuPri();
        /*
        Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
        */
    }

    cin.get();

    return 0;

}
void MenuPri(void){
      while(cent<=6){
            printf("\n------------------------------------------------------------------------------------------\n");
            printf("\t\t\t/MONICA FRANCISCA TUCH AZ.   94919-21-19514\n");
            printf("\n------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\tBIENVENDIO AL MENU DEL LABORATORIO CLINICO\n");
            printf("\n\t\t\t\t1.- Mantenimiento\n");
            printf("\n\t\t\t\t3.- Bitacora\n");
            printf("\n\t\t\t\t4.- Pendiente\n");
            printf("\n\t\t\t\t5.- Salir del menu\n");
            printf("\n\t\t\t\tOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Mantenimiento();
               break;
               case 2:
                  Bitacora();
               break;
               case 3:
                  Pend();
               break;
               case 4:
                  cent=7;
               break;
               default:
                  system("cls");
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();

}


//FUNCION PARA CREAR ARCHIVO Y REGISTROS DE  clientes/ pacientes//

void NomCrear(void){
FILE *fp;
   pacientes alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("nomina.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
     system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR CLIENTE/PACIENTE");
      printf("\n\nIntroduce el Nombre del cliente/paciente: ");
      gets(alm.nompaciente);
      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el pago:  ");
      scanf("%d",&alm.nombrem);
      printf("\nIngrese sus nombres:  ");
      scanf("%d",&alm.apellidoss);
      printf("\nIngrese sus apellidos:  ");
      scanf("%d",&alm.asunto);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
   }

}



void NomImprimir(void){
FILE *fp;
  pacientes  alm;
   int n;
   if(!(fp=fopen("nomina.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR LISTADO DE CLIENTES/ PACIENTES");
      printf("\n\n\t\t LISTADO   DE   CLIENTES/PACIENTES\n");
      printf("\n------------------------------------------------------------------------------\n");
      printf("CLIENTE/PACIENTE \tDPI \t\t NOMBRES \tAPELLIDOS\tASUNTOS");
      printf("\n------------------------------------------------------------------------------\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nompaciente);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t\t",alm.apellidoss);
         printf("%d\t",alm.asunto);
      }
      printf("\n------------------------------------------------------------------------------\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }

}


void NomAnexar(void){
FILE *fp;
   pacientes	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR CLIENTES/PACIENTES");
   printf("\n\n!!Se anexaran nuevos registro de clientes/ pacientes NOMINA.DAT!!\n");
   if(!(fp=fopen("nomina.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
     system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN CLIENTE/PACIENTE");
      printf("\n\nIntroduce el Nombre del cliente/paciente: ");
      gets(alm.nompaciente);
      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIngresa los nombres:  ");
      scanf("%d",&alm.nombrem);
      printf("\nIngresar los apellidos:  ");
      scanf("%d",&alm.apellidoss);
      printf("\nIntroduce el asuste:  ");
      scanf("%d",&alm.asunto);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXADO CORRECTAMENTE A LA LISTA!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
   }

}


void NomModificar(void){
FILE *fp;
   pacientes alm;
   int n,c,opc;

   if(!(fp=fopen("nomina.dat","r+b")))
   	printf("\n Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 4: MODIFICAR EL REGISTRO DE CLIENTE/PACIENTE");
      printf("\n\nIntroduzca el No. de DPI de un CLIENTE/PACIENTE: ");
      scanf("%d",&alm.cuenta);
      c=alm.cuenta;
      while ((n=fread(&alm, sizeof(alm), 1, fp))!=0 && alm.cuenta!=c);
      if (alm.cuenta!=c)
         printf("No existe la Cuenta: %d ",c);
      else{
         system("cls");
         printf("\n!!Se encontro AL cliente/ paciente!!");
         printf("\n¿Que desea cambiar?, Seleccione una opcion");
         printf("\n\n1.-Nombre");
         printf("\n\n2.-No. de DPI");
         printf("\n\n3.-apellido");
         printf("\n\n4.-telefono");
         printf("\n\n5.-asunto");
         printf("\n\nIntroduzca opicion: ");
         scanf("%d",&opc);
         switch(opc){
                     case 1:
                        fflush(stdin);
                        printf("\nIntroduzca el nuevo paciente: ");
                        gets(alm.nompaciente);
                     break;
                     case 2:
                        printf("\nIntroduza el nuevo DPI: ");
                        scanf("%d",&alm.cuenta);
                     break;
                     case 3:
                        printf("\nIngrese nuevo nombre: ");
                        scanf("%d",&alm.nombrem);
                     break;
                     case 4:
                        printf("\nIngrese nuevo apellido:  ");
                        scanf("%d",&alm.apellidoss);
                     break;
                     case 5:
                        printf("\nIntroduzca nuevo asunto:  ");
                        scanf("%d",&alm.asunto);
                     break;
                     default:
                        printf("\Error, opcion inexistente");
                     break;
         }
         printf("\nGrabando registro\n");
         fseek(fp,-sizeof(alm),SEEK_CUR);
         fwrite(&alm, sizeof(alm), 1, fp);
         printf("\nRegistro grabado con exito");
         printf("\nPresiona una tecla para continuar...");
         getch();
      }
      fclose(fp);
   }
}

void NomBorrar(void){

}

//FUNCION CONTROL DE BITACORA//

void Bitacora (void){
FILE *arch;
    arch=fopen("archivo1.dat","wb");
    if (arch==NULL)
        exit(1);

    char letra='A';
    fwrite(&letra, sizeof(char), 1, arch);
    int valor1=12;
    fwrite(&valor1, sizeof(int), 1, arch);
    float valor2=5.25;
    fwrite(&valor2, sizeof(float), 1, arch);

    fclose(arch);

    printf("Se creo un archivo binario que almacena un char, un int y un float.");

    getch();


}


void Pend(void){

}

//MENU DE MANTENIMIENTO//
void Mantenimiento(void){
    system("cls");
     cent=6;
      while(cent<=6){
            printf("Bienvenido al menu de MANTENIMIENTO");
            printf("\n\n1.- Crear archivo y crear un nuevo cliente/paciente");
            printf("\n\n2.- Visualizar la lista existente");
            printf("\n\n3.- Añadir Clinica con el nuevo cliente/paciente al archivo existente");
            printf("\n\n4.- Modificar el registro de un cliente/paciente");
            printf("\n\n5.- Borrar el registro de un clientes/paciente");
            printf("\n\n6.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Crear();
               break;
               case 2:
                  Imprimir();
               break;
               case 3:
                  Anexar();
               break;
               case 4:
                  Modificar();
               break;
               case 5:
                  Borrar();
               break;
               case 6:
                  system("cls");
                  MenuPri();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}



void Crear(void){
   FILE *fp;
   pacientes alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("registro.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
     system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN CLIENTE/PACIENTE");
      printf("\n\nIntroduce el nombre del cliente/paciente: ");
      gets(alm.nompaciente);

      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la Edad:  ");
      scanf("%d",&alm.primpar);
      printf("\nIntroduce el numero de Telefono:  ");
      scanf("%d",&alm.segpar);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
   }
}


void Imprimir(void){
   FILE *fp;
   pacientes  alm;
   int n;
   if(!(fp=fopen("registro.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE CLIENTE/PACIENTE");
      printf("\n\n\t\t R E G I S T R O  D E  CLIENTE/PACIENTE\n");
      printf("\n------------------------------------------------------------------------------\n");
      printf("CLIETE/PACIENTE \tDPI \t\t EDAD \t\tTELEFONO");
      printf("\n------------------------------------------------------------------------------\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nompaciente);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t\t",alm.primpar);
         printf("%d \t\t\n",alm.segpar);
      }
      printf("\n------------------------------------------------------------------------------\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}


void Anexar(void){
   FILE *fp;
   pacientes	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR CLINICA AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos CLINICA al registro de clientes/pacientes.txt!!\n");
   if(!(fp=fopen("registro.alum","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre de la clinica: ");
      gets(alm.nompaciente);
      fflush(stdin);
      printf("\nIntroduce el No. de direccion: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la Edad del cliente/paciente:  ");
      scanf("%d",&alm.primpar);
      printf("\nIntroduce el Numero de Telefono:  ");
      scanf("%d",&alm.segpar);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA MODIFICAR UN REGISTRO CON BUSQUEDA
void Modificar(void){
   FILE *fp;
   pacientes alm;
   int n,c,opc;

   if(!(fp=fopen("registro.alum","r+b")))
   	printf("\n Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 4: MODIFICAR EL REGISTRO DE UN CLIENTE/PACIENTE");
      printf("\n\nIntroduzca el No. de DPI de un CLIENTE/PACIENTE: ");
      scanf("%d",&alm.cuenta);
      c=alm.cuenta;
      while ((n=fread(&alm, sizeof(alm), 1, fp))!=0 && alm.cuenta!=c);
      if (alm.cuenta!=c)
         printf("No existe la Cuenta: %d ",c);
      else{
         system("cls");
         printf("\n!!Se encontro al cliente/paciente!!");
         printf("\n¿Que desea cambiar?, Seleccione una opcion");
         printf("\n\n1.-Nombre");
         printf("\n\n2.-No. de DPI");
         printf("\n\n3.-Edad");
         printf("\n\n4.-Telefono");
         printf("\n\nIntroduzca opicion: ");
         scanf("%d",&opc);
         switch(opc){
                     case 1:
                        fflush(stdin);
                        printf("\nIntroduzca el nuevo nombre: ");
                        gets(alm.nompaciente);
                     break;
                     case 2:
                        printf("\nIntroduza el nuevo DPI: ");
                        scanf("%d",&alm.cuenta);
                     break;
                     case 3:
                        printf("\nIntroduzca la Edad: ");
                        scanf("%d",&alm.primpar);
                     break;
                     case 4:
                        printf("\nIntroduzca el numero de Telefono:  ");
                        scanf("%d",&alm.segpar);
                     break;
                     default:
                        printf("\Error, opcion inexistente");
                     break;
         }
         printf("\nGrabando registro\n");
         fseek(fp,-sizeof(alm),SEEK_CUR);
         fwrite(&alm, sizeof(alm), 1, fp);
         printf("\nRegistro grabado con exito");
         printf("\nPresiona una tecla para continuar...");
         getch();
      }
      fclose(fp);
   }
}



void Borrar(void){
   FILE *fp,*fd;
   pacientes alm;
   int n,c,encontrado=0;
 system("cls");
   printf("\tELIGIO LA OPCION 5: BORRAR EL REGISTRO DE UN CLIENTE/PACIENTE");
   printf("\n\nIngrese el No. de DPI del cliente/paciente que desea Eliminar: ");
   scanf("%d",&alm.cuenta);
   c=alm.cuenta;
   if(!(fp=fopen("registro.alum","rb")))
   	printf("\n Error de apuertura del registro");
   else{
      if(!(fd=fopen("auxregis.txt","wb")))
         printf("\n Error,imposible borrar registro, el archivo no existe");
      else{
         while ((n=fread(&alm, sizeof(alm), 1, fp))!=0){
            if(alm.cuenta!=c)
              fwrite(&alm, sizeof(alm), 1, fd);
            else
              encontrado=1;
         }
         fclose(fd);
      }
      fclose(fp);
      if(encontrado){
         system("del registro.alum");
         system("ren auxregis.txt registro.alum");
         printf("\n!!!Registro borrado satisfactoriamente!!!\n");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
      else{
         system("del auxregis.txt");
         printf("\n!!!No se entontro ningun paciente con ese numero de cuenta!!!");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
   }
}

