#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>  
#include <string.h> 
using namespace std;
const char *nombre_archivo = "prueba.dat";

struct estudiante{
	int cod;
	char nom[50];
	char ape[50];
	char dire[50];
	int telefono;
};
void ingresar_estudiante();
void abrir_estudiante();
void modificar_estudiante();
void eliminar();


class Archivo
{
	public:
		ofstream archivo;
	
			
		
void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
	}
	estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(estudiante), 1, archivo );
	cout<<"____________________________________________________________________________________________"<<endl;
	cout << "id" <<" | "<< "CODIGO" <<" | "<< "NOMBRE"<<" | "<<"APELLIDO"<<" | "<<"DIRECCION"<<" | "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"___________________________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.cod <<" | "<< estudiante.nom<<" | "<<estudiante.ape<<" | "<<estudiante.dire<<" | "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
		void agregar()
		{
				char continuar;
				FILE* archivo = fopen(nombre_archivo, "ab");
			
			estudiante estudiante;
		 string nom,ape,dire;
		do{
			
			fflush(stdin);
				system ("cls"); 
			cout<<"DATOS ESTUDIANTE"<<endl;
			cout<<"Ingresar Codigo: ";
			cin>>estudiante.cod;
      	    cin.ignore();
			
			cout<<"Ingresar Nombre: ";
			getline(cin,nom);
    	    strcpy(estudiante.nom, nom.c_str()); 
			
			cout<<"Ingresar Apellido: ";
			getline(cin,ape);
			strcpy(estudiante.ape, ape.c_str());
			cout<<"Ingresar Direccion: ";
			getline(cin,dire);
			strcpy(estudiante.dire, dire.c_str()); 
			cout<<"Ingresar Telefono: ";
			cin>>estudiante.telefono;
			cin.ignore();		
			
			
			fwrite( &estudiante, sizeof(estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();

		}
		
	
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
	
		int id;
		string nom,ape,dire;	
    	estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(estudiante), SEEK_SET );  
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.cod;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nom);
    	strcpy(estudiante.nom, nom.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,ape);
		strcpy(estudiante.ape, ape.c_str()); 
	
		cout<<"Ingrese el Direccion:";
		getline(cin,dire);
		strcpy(estudiante.dire, dire.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
		system("PAUSE");
}	

void eliminar(){
 	
	FILE *archivo, *archivo_tem; 	
	estudiante estudiante; 
	archivo_tem=fopen(nombre_archivo,"w+b");
	archivo=fopen(nombre_archivo,"rb"); 

	abrir_estudiante();

	int id=1,i=1;
	cout<<"ingrese el id a eliminar:"; 
	cin>>id; 	                      				                
	                                                                                
	while(fread(&estudiante,sizeof(estudiante),1,archivo)){ 	
	if (i != id){
	fwrite(&estudiante,sizeof(estudiante),1,archivo_tem);
	} 
	i++;
	}
	fclose(archivo_tem); 
	fclose(archivo);                 
	archivo_tem=fopen(nombre_archivo,"rb"); 
	archivo=fopen(nombre_archivo,"wb");
	while(fread(&estudiante,sizeof(estudiante),1, archivo_tem)){ 
	fwrite(&estudiante,sizeof(estudiante),1, archivo); 
	}
	                
	fclose(archivo_tem);
	fclose(archivo); 
	abrir_estudiante();	
}	

	

};
int main()
{
Archivo uno;
uno.agregar();
uno.modificar_estudiante();
uno.eliminar();

return 0;
system("pause");	

}
