#include <iostream>
#include <cstdlib>
using namespace std;

struct Producto {
    int id;
    string nombre;
    int precio;
    int unidades;
    Producto* sig;
};

void crearLista(Producto*& cab, Producto*& fin, int id, string n, int p, int u) {
    Producto* nuevo = new Producto;
    nuevo->id = id;
    nuevo->nombre = n;
    nuevo->precio = p;
    nuevo->unidades = u;
    nuevo->sig = NULL;
    
    cab = nuevo;
    fin = nuevo;
}

void mostrarLista(Producto* cab) {
    Producto* aux = cab;
    cout << "===========================INVENTARIO===================== \n";
    while (aux != NULL) {
        cout << "Id: " << aux->id << "\n";
        cout << "Nombre: " << aux->nombre << "\n";
        cout << "Precio: " << aux->precio << "\n";
        cout << "Unidades: " << aux->unidades << "\n";
        cout << "----------------------------------------------------------\n";
        aux = aux->sig;
    }
    cout << "\n";
}

Producto* buscarProducto(Producto* cab, int id) {
    Producto* aux = cab;
    while (aux != NULL && aux->id != id) {
        aux = aux->sig;
    }
    return aux; 
}

Producto* buscarProductoPorNombre(Producto* cab, const string& nombre) {
    Producto* aux = cab;
    while (aux != NULL) {
        if (aux->nombre == nombre) return aux;
        aux = aux->sig;
    }
    return NULL;
}

void insertarInicio(Producto*& cab, int id, string n, int p, int u) {
    Producto* nuevo = new Producto;
    nuevo->id = id;
    nuevo->nombre = n;
    nuevo->precio = p;
    nuevo->unidades = u;
    nuevo->sig = cab;
    cab = nuevo;
}

void insertarMedio(Producto* cab, Producto* encontrado, int id, string n, int p, int u) {
    if (encontrado == NULL) {
        cout << "El producto no fue encontrado para la insercion en el medio.\n";
        return;
    }
    Producto* nuevo = new Producto;
    nuevo->id = id;
    nuevo->nombre = n;
    nuevo->precio = p;
    nuevo->unidades = u;
    nuevo->sig = encontrado->sig;
    encontrado->sig = nuevo;
}

void insertarFinal(Producto*& fin, int id, string n, int p, int u) {
    Producto* nuevo = new Producto;
    nuevo->id = id;
    nuevo->nombre = n;
    nuevo->precio = p;
    nuevo->unidades = u;
    nuevo->sig = NULL;
    if (fin != NULL) {
        fin->sig = nuevo;
    }
    fin = nuevo;    
}

void actualizarUnidades(Producto* encontrado, int u){
	encontrado->unidades = u;	
}

void eliminarProducto(Producto* &cab, Producto* eliminar){
	Producto* ant = cab;
	
	if(cab==eliminar){
		cab = eliminar->sig;
		delete eliminar;
	}else{
		while(ant->sig!=eliminar){
			ant=ant->sig;
		}
		ant->sig = eliminar->sig;
		delete eliminar;
	}
	
}

void aplicarDescuento(Producto* encontrado, int porcentaje){
		int precio = encontrado->precio; 
		int descuento = precio*porcentaje/100;
		encontrado->precio = precio-descuento;
}

void consultarExistencias(Producto* cab, int u){
	Producto* aux = cab;
	cout<<"==========================================================\n";
	cout<<"PRODUCTOS CON MENOS DE "<<u<<" UNIDADES: \n";
	while(aux != NULL){
		if(aux->unidades<=u){
			cout << "Id: " << aux->id << "\n";
	        cout << "Nombre: " << aux->nombre << "\n";
	        cout << "Precio: " << aux->precio << "\n";
	        cout << "Unidades: " << aux->unidades << "\n";
	        cout << "----------------------------------------------------------\n";
		}
		aux = aux->sig;
	}
	
}

int valorTotalInventario(Producto* cab){
	Producto* aux = cab;
	int sum = 0;
	
	while(aux != NULL){
		sum+= aux->precio*aux->unidades;
		aux = aux->sig;
	}
	return sum;
}

int main() {
    Producto* cab = NULL;
    Producto* fin = NULL;
    Producto* encontrado;
    Producto* eliminar;
    int op, op2, id, id_enc, p, u, c;
    string n;
    bool cond = true;

    while (cond) {
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
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Entrada no valida. Por favor, ingrese un numero.\n\n";
            continue; 
        }
        
        cout << "\n";
        
        switch (op) {
            case 1:
                cout << "Cuantos productos desea agregar? \n";
                cin >> c;
            
                for (int i = 1; i <= c; i++) {
                	id+=1;
                    cout << "-----------------------Producto " << id<< "-----------------------\n";
                    
                    cin.ignore();
                    cout << "Ingrese el nombre del producto: \n";
                    getline(cin, n);
                    
                    if (buscarProductoPorNombre(cab, n) != NULL) {
                        cout << "El producto con el nombre " << n << " ya existe.\n";
                        id-=1;
                        continue;
                    }
                    
                    cout << "Ingrese el precio del producto: \n";
                    cin >> p;
                    
                    cout << "Ingrese las unidades del producto: \n";
                    cin >> u;

                    if (cab == NULL) {
                        crearLista(cab, fin, id, n, p, u);
                    } else {
                        cout << "Como desea insertar el producto? \n";
                        cout << "1. Insertar Inicio \n";
                        cout << "2. Insertar Medio \n";
                        cout << "3. Insertar Final \n";
                        cout << "Seleccione una opcion: ";
                        cin >> op2;
                        
                        if (cin.fail()) {
                            cin.clear(); 
                            cin.ignore(1000, '\n'); 
                            cout << "Entrada no valida. Por favor, ingrese un numero.\n\n";
                            continue; 
                        }
                                    
                        switch (op2) {
                            case 1:
                                insertarInicio(cab, id, n, p, u);
                                break;
                                
                            case 2:
                            	cout<<"Ingrese el id del producto para agregar el nuevo antes \n";
                            	cin>>id_enc;
                                encontrado = buscarProducto(cab, id_enc);    
                                insertarMedio(cab, encontrado, id, n, p, u);
                                break;
                                
                            case 3:
                                insertarFinal(fin, id, n, p, u); 
                                break;
                                
                            default:
                                cout << "Opcion no valida, por favor seleccione otra opcion.\n";
                                break;
                        }
                    }
                }
                break;
            
            case 2: 
                mostrarLista(cab);
                break;
                
            case 3:
            	cout<<"Ingrese el Id del producto para actulizar sus unidades: \n";
				cin>>id;
				encontrado = buscarProducto(cab, id);
				
				if(encontrado!=NULL){
					cout<<"Ingrese el nuevo valor para las unidades: \n";
					cin>>u;
					actualizarUnidades(encontrado, u);
				}else{
					cout<<"El producto con Id "<<id<<", no existe. \n";
				}
				
            break;
            
            case 4:
            	cout<<"Ingrese el id del producto a eliminar: \n";
				cin>>id;
				eliminar = buscarProducto(cab, id);
				if (eliminar != NULL){
					eliminarProducto(cab, eliminar);
				}else{
					cout<<"El producto con Id "<<id<<", no existe. \n";
				}
				
            break;
            
            case 5:
            	cout<<"Ingrese el id del producto para aplicar el descuento: \n";
            	cin>>id;
            	encontrado = buscarProducto(cab, id);
            	if(encontrado!=NULL){
            		cout<<"Ingrese el descuento que desea realizar: \n";
	            	cin>>p;
	            	aplicarDescuento(encontrado, p);
					cout<<"Se aplico un "<<p<<"% de descuento al producto con Id"<<" 1\n";
				}else{
					cout<<"El producto con Id "<<id<<", no existe. \n";
				}
            	
            break;
            
            case 6:	
            	cout<<"Ingrese el numero minimo de unidades para filtrar el producto: \n";
            	cin>>u;
            	consultarExistencias(cab, u);
            break;
            
            case 7:
            	cout<<"El valor total del inventario es de "<<valorTotalInventario(cab)<<"$ \n";
            break;
            
            case 8: 
                cond = false;
                cout << "Saliendo del programa...  \n";
                break;
            
            default: 
                cout << "Opcion no valida, por favor seleccione otra opcion.\n";
                break;
        }
    }

    return 0;
}
