#include <bits/stdc++.h>

/*Juan Angel López Delgadiillo*/

//Plantilla para imprimir la cola 

template<typename T> void print_queue(T& q){
         while(!q.empty()){
            std::cout<< q.top() << "";
            q.pop();
         }
         std::cout<< '\n';   
        }


/*Vamos a desarrollar la plantilla como se nos pide en la tarea*/

template <class Tpriority, class TKey> 
class UpdatableHeap{
   
public:

/*Primero voy a generar un map de la STL, recordemos que es un contenedor asociativo 
que guarda elementos, en este caso vamos a guardar cada elemento de la cola de prioridad
en esta estructura de datos*/

std::map<Tpriority, TKey> Upheap; /*Creamos un mapa de Prioridades a llaves*/

/*Vamos a forzar una función de comparador de elementos*/

bool cmp(const std::pair<Tpriority, TKey> &l, const std::pair<Tpriority,TKey> &r){
   return l.first < r.first; 
}

/*Aqui lo que vamos a hacer es una funcion que devuelve el elemento de mayor prioridad, y este devuelve 
la prioridad y la clave.*/

pair<Tpriority, TKey> top() const{
   /*Aqui la llave mas chica*/
    TKey minimalKey = Upheap.begin()->first.second;
    /*Aqui la prioridad mas chica*/
    Tpriority minimalPriority = Upheap.begin()->first.first;
    /*Recordemos que este proceso va a hacer iterativo por todo el heap para retornar el elemnto the high priority con su clave*/
    for (auto iter = Upheap.begin(); iter != Upheap.end(); iter++) {
        if (iter->first.first < minimalPriority) {
            minimalPriority = iter->first.first;
            minimalKey = iter->first.second;
        }
    }
    return make_pair(minimalPriority, minimalKey);
}


   void pop(){
      //Si el heap no esta vacio tons borramos el elemento de mayor prioridad. 
      if(!Upheap.empty()){
         Upheap.erase(Upheap.begin());  
      }
   }

   void insertOrUpdate(const TPriority &p, const TKey &k){
      auto aux = Upheap.find(p);
      //Si ya existe el nodo, entonces se actualiza para tener la prioridad especificada.
      if(aux != Upheap.end()){
         update(p, k);
      }
      //En caso contrario pues se inserta el nodo con prioridad p y llave k (osea el Id)
      else{
         insert(p, k);
      }
   } 

   bool isInserted(const TKey &k) const{
      if(!Upheap.empty()){
      TKey temp = Upheap.find(k)
     /* if(temp == std::string::npos){

      }*/
      }
   }

   //Devuelve el numero de elementos que contiene el heap actualmente.
   int getSize() const{
      return Upheap.size();  //devuelve el tamaño del heap :v
   }

   void erase(const TKey &k){
      //Si el heap no esta vacio
      if(!Upheap.empty()){
         Upheap.erase(Upheap.find(k)); //buscamos el nodo con la llave k y lo matamos del heap
      }
   }

};
