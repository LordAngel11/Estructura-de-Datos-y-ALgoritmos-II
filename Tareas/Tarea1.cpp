#include <bits/stdc++.h>

/*Juan Angel López Delgadiillo*/

/*Vamos a desarrollar la plantilla como se nos pide en la tarea*/

template <class Tpriority, class TKey> 
class UpdatableHeap{
   
public:

/*Primero voy a generar un map de la STL, recordemos que es un contenedor asociativo 
que guarda elementos, en este caso vamos a guardar cada elemento de la cola de prioridad
en esta estructura de datos*/

std::map<Tpriority, TKey> Upheap; /*Creamos un mapa de Prioridades a llaves*/

/*Vamos a forzar una función de comparador de los nodos*/

bool cmp(const std::pair<Tpriority, TKey> &l, const std::pair<Tpriority,TKey> &r){
   return l.first < r.first; 
}

/*Aqui lo que vamos a hacer es una funcion que devuelve el elemento de mayor prioridad, y este devuelve 
la prioridad y la clave.*/

std::pair<Tpriority, TKey> top() const {
    return Upheap.begin()->second; 
  }


   void pop(){
      //Si el heap no esta vacio tons borramos el elemento de mayor prioridad. 
      if(!Upheap.empty()){
         Upheap.erase(Upheap.begin());  
      }
   }

   void insertOrUpdate(const TPriority &p, const TKey &k){
      auto auxiterator = Upheap.find(p);
      //Si ya existe el nodo, entonces se actualiza para tener la prioridad especificada.
      if(auxiterator != Upheap.end()){
         update(p, k);
         /*
         auxiterator->first = p; 
         */
        //auxiterator->second.first = p;
      }
      //En caso contrario pues se inserta el nodo con prioridad p y llave k (osea el Id)
      else{
         //insert(p, k);
         Upheap.emplace(p,k);
        //heap.insert(std::make_pair(k, std::make_pair(p,k)));
      }
   } 

   bool isInserted(const TKey &k) const{
      if(!Upheap.empty()){
      return Upheap.find(k) != Upheap.end(); 
      }
   }

   bool isempty(){        
      if(Upheap.empty()){     //Si el heap esta vacio pues regresa que esta vacio
      return Upheap.empty();   
      }
   }

   //Devuelve el numero de elementos que contiene el heap actualmente.
   int getSize() const{
      return Upheap.size();  //devuelve el tamaño del heap :v, no hay mucha ciencia 
   }

   void erase(const TKey &k){
      //Si el heap no esta vacio
      if(!Upheap.empty()){
         Upheap.erase(Upheap.find(k)); //buscamos el nodo con la llave k y lo matamos del heap
      }
   }

};


int main(){

   UpdatableHeap<std::string, int> FoodDataBase; 

   int OP; //Numero de operaciones
   int i = 0; 

   std::cin>>OP; 

   do{

      std::string option;
      int valor;

      std::cin>>option;

      if(option == "P"){
         if(!FoodDataBase.isempty()){
         std::cout<< FoodDataBase.top().first <<" "<< FoodDataBase.top().second <<std::endl;
         }
         else{
            std::cout << "-1" << std::endl;
         }
      }

      if(option == "IU"){
         
      }


      i++;
   }while (i <= OP);
   



   return 0; 
}