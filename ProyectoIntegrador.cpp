#include<iostream>
#include<cstdlib>
using namespace std;

struct Producto{
    int id;
    string nombre;
    int precio;
    int unidades;
    Producto* sig;
};

void crearLista(Producto* &cab, Producto* &fin, int id, string n, int p, int u){
    Producto* nuevo = new Producto;
    nuevo->id = id;
    nuevo->nombre = n;
    nuevo->precio = p;
    nuevo->unidades = u;
    nuevo->sig = NULL;
    
    cab = nuevo;
    fin = nuevo;
}

void mostrarLista(Producto* cab){
    Producto* aux = cab;
    cout << "===========================INVENTARIO===================== \n";
    while(aux != NULL){
        cout << "Id: " << aux->id << "\n";
        cout << "Nombre: " << aux->nombre << "\n";
        cout << "Precio: " << aux->precio << "\n";
        cout << "Unidades: " << aux->unidades << "\n";
        cout << "----------------------------------------------------------\n";
        aux = aux->sig;
    }
    cout << "\n";
}

void insertarFinal(Producto* &fin, int id, string n, int p, int u){
    Producto* nuevo = new Producto;
    nuevo->id = id;
    nuevo->nombre = n;
    nuevo->precio = p;
    nuevo->unidades = u;
    nuevo->sig = NULL;
    fin->sig = nuevo;
    fin = nuevo;    
}

void insertarInicio(Producto* &cab, int id, string n, int p, int u){
	Producto* nuevo = new Producto;
	nuevo->id = id;
	nuevo->nombre = n;
	nuevo->precio = p;
	nuevo->unidades = u;
	nuevo->sig = cab->sig;
	cab = nuevo;
}

void insertarMedio(Producto* cab, Producto* encontrado, int id, string n, int p, int u){
	Producto* nuevo = new Producto;
	nuevo->id = id;
	nuevo->nombre = n;
	nuevo->precio = p;
	nuevo->unidades = u;
	
	Producto* ant = cab;
	
	while(ant!=encontrado){
		ant = ant->sig;
	}
	
	nuevo->sig = ant->sig;
	ant->sig = nuevo;
	
}

Producto* buscarProducto(Producto* cab, int id){
	Producto* aux = cab;
	
	while(aux->id!=id){
		aux = aux->sig;
	}
	
	return aux;
}

int main(){
    Producto* cab = NULL;
    Producto* fin = NULL;
    int op, id, p, u, c;
    string n;
    bool cond = true;

	while(cond){
		cout << "===========================MENU===========================\n";
        cout << "1. Insertar producto(s) \n";
        cout << "2. Mostrar lista de productos \n";
        cout << "3. Actualizar unidades \n";
        cout << "4. Eliminar producto(s) \n";
        cout << "5. Aplicar descuento \n";
        cout << "6. Consultar existencias \n";
        cout << "7. Valor total del inventario \n";
        cout << "8. Salir \n";
        cout << "Seleccione una opcion: ";
        cin >> op;
        
        // Manejo de error en la entrada
        if(cin.fail()){
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Entrada no valida. Por favor, ingrese un numero.\n\n";
            continue; 
        }
        
        cout << "\n";
        
		switch(op){
            
            case 1:
                cout << "Cuantos productos desea agregar? \n";
                cin >> c;
            
                for(int i = 1; i <= c; i++){
                    cout << "-----------------------Producto " << i << "-----------------------\n";
                    cout << "Ingrese el Id del producto: \n";
                    cin >> id;
                    cin.ignore();
                    
                    cout << "Ingrese el nombre del producto: \n";
                    getline(cin, n);
                    
                    cout << "Ingrese el precio del producto: \n";
                    cin >> p;
                    
                    cout << "Ingrese las unidades del producto: \n";
                    cin >> u;
                    if(cab == NULL){
                        crearLista(cab, fin, id, n, p, u);
                    }else{
                        insertarFinal(fin, id, n, p, u);
                    }
                } 
                
            break;
            
            case 2: 
                mostrarLista(cab);
            break;
            
            case 8: 
            	cond = false;
                cout << "Saliendo del programa...  \n";
            break;
            
            default: 
                cout << "Opcion no valida, por favor seleccione otra opcion.\n";
            break;
        }
	};
        

    return 0;
}

