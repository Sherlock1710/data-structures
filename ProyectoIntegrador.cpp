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

void eliminarProducto(){
	
}

int main() {
    Producto* cab = NULL;
    Producto* fin = NULL;
    Producto* encontrado;
    int op, op2, id, id_enc, p, u, c, n_prod;
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
                	n_prod+=1;
                    cout << "-----------------------Producto " << n_prod << "-----------------------\n";
                    cout << "Ingrese el Id del producto: \n";
                    cin >> id;
                    cin.ignore();
                    
                    if (buscarProducto(cab, id) != NULL) {
                        cout << "El producto con el Id " << id << " ya existe.\n";
                        n_prod-=1;
                        continue;
                    }
                    
                    cout << "Ingrese el nombre del producto: \n";
                    getline(cin, n);
                    
                    if (buscarProductoPorNombre(cab, n) != NULL) {
                        cout << "El producto con el nombre " << n << " ya existe.\n";
                        n_prod-=1;
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
                                encontrado = buscarProducto(cab, id);    
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
            	cout<<"Ingrese el Id del producto para actulizar sus unidades \n";
				cin>>id;
				encontrado = buscarProducto(cab, id);
				
				cout<<"Ingrese el nuevo valor para las unidades: \n";
				cin>>u;
				actualizarUnidades(encontrado, u);
            break;
            
            case 4:
            break;
            
            case 5:
            break;
            
            case 6:	
            break;
            
            case 7:
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
