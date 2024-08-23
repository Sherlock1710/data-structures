#include<iostream>

struct Producto{
	int id;
	string nombre;
	int precio;
	int unidades;
};

void crearLista(/*Producto* &cab, int id, string n, int p, int u*/){
	cout<<"HOLA MUNDO \n";
}

int main(){
	cab
	int op;
	
	do{
		cout<<"1. Insertar producto(s) \n";
		cout<<"2. Mostrar lista de productos \n";
		cout<<"3. Actualizar unidades \n";
		cout<<"4. Eliminar producto(s) \n";
		cout<<"5. Aplicar descuento \n";
		cout<<"6. Consultar existencias \n";
		cout<<"7. Valor total del inventario \n";
		cout<<"8. Salir \n";
		cin>>op;
		
		switch(op){
			case 1:  crearLista();
			break;
		}
	}
	
	
	return 0;
}
