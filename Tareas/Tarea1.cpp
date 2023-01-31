#include <bits/stdc++.h>

/*Juan Angel López Delgadiillo*/

/*Vamos a desarrollar la plantilla como se nos pide en la tarea*/

template <class TKey, class Tpriority> 
class UpdatableHeap{

public:

std::unordered_map<TKey,int> key;
std::vector<std::pair<Tpriority,TKey>> nodo;

//Vamos a definir la estructura de los nodos del arbol binario de heap.

int Father(int i){
   return (i-1)/2;
}
int Left(int i){
   return 2*i+1;
}
int Right(int i){
   return 2*i+2;
}
   
//Vamos a programar una funcion que compara los nodos para los intercambios

void comparator(std::pair<Tpriority,TKey> *x, std::pair<Tpriority,TKey> *y){
   std::pair<Tpriority,TKey> aux = *x;
   *x = *y;
   *y = aux;
}

//Aqui vamos a programar nuestro Heapify donde baja de nivel el elemento hasta que no exista conflicto con los hijos.
void maxHeapify(int i){
   int aux, maximal = i;
   int lefty = Left(i);
   int righty = Right(i);

   //En cada uno de los if vamos a comparar nuestros nodos por orden lexicografico... 

   //EN nuestro primer if vamos a comprar por el hijo izquierdo.

   if(lefty < nodo.size() && nodo[lefty].first >= nodo[i].first){
      if(nodo[lefty].first == nodo[i].first && nodo[lefty].second < nodo[i].second){
      }
      else{
         maximal = lefty;
      }
   }

   //En el segundo if vamos a comparar ahora por el hijo derecho 

   if(righty < nodo.size() && nodo[righty] > nodo[i]){
      if(nodo[righty] > nodo[lefty]){
         if(nodo[righty].first == nodo[i].first && nodo[righty].second < nodo[i].second){}
         else{
            maximal = righty;
         }
      }
   }

   if(maximal != i){

    comparator(&nodo[i],&nodo[maximal]);
      aux = key[nodo[i].second];
      key[nodo[i].second] = key[nodo[maximal].second];
      key[nodo[maximal].second] = aux;

      maxHeapify(maximal);
   }

}

int getSize(){
   return nodo.size();
}

//Para regresar el nodo raiz del heap vamos a usar la funcion top, para esto solo regresa el elemento de mayor prioridad dentro 
//del heap, y como el elemento es el nodo raiz entonces simplemente retornamos el primer elemento del vector de nodos, es decir 
//nodo[0]. En caso de que no exista nada en el heap lo que se hace es un pai de prioridades y llaves vacios y retorna ese pair vacio

std::pair<Tpriority,TKey> top(){
   if(nodo.size() != 0){
      return nodo[0];
   }
   else{
      std::pair<Tpriority,TKey> vacio;
      return vacio;
   }
}

bool isInserted(const TKey &k){
   if(nodo.size() == 0){
      return false;
   }
   if(key.find(k) == key.end() && k != top().second){
      return false;
   }else{
      return true;
   }
}

void erase(const TKey &k){
   if(isInserted(k)){
      int element = key[k];
      int aux;

      comparator(&nodo[element],&nodo[getSize()-1]);
      key[nodo[element].second] = element;

      nodo.pop_back();
      key.erase(k);

      if(element == 0){
         maxHeapify(element);
      }

      else if(nodo[Father(element)].first <= nodo[element].first){
         while(element != 0 && nodo[Father(element)].first <= nodo[element].first){
            if(nodo[Father(element)].first == nodo[element].first && nodo[Father(element)].second > nodo[element].second){
               element = 0;
            }
            else{
               comparator(&nodo[element], &nodo[Father(element)]);

               aux = key[nodo[element].second];
               key[nodo[element].second] = key[nodo[Father(element)].second];
               key[nodo[Father(element)].second] = aux;

               element = Father(element);
            }
         }
      }

      else{
         maxHeapify(element);
      }
   }
}

void pop(){
   if(nodo.size() != 0){
      erase(top().second);
   }
}


void InsertorUpdate(const TKey &k, const Tpriority &p){
   int aux;

   //En nuestra primera condicion si el nodo con la llave k no esta insertado entonces se procede a insertar de la sifuiente forma
   if(!isInserted(k)){
      key.insert(std::make_pair(k,getSize()));
      nodo.push_back({p,k});
      int i = getSize()-1;

      //Los if, tienen la funcion de comparar de acuerdo al orden lexicografico

   while(i != 0 && nodo[Father(i)].first <= nodo[i].first){
      if(nodo[Father(i)].first == nodo[i].first && nodo[Father(i)].second > nodo[i].second){
         i = 0;
      }
      else{
         comparator(&nodo[i], &nodo[Father(i)]);

         aux = key[nodo[i].second];
         key[nodo[i].second] = key[nodo[Father(i)].second];
         key[nodo[Father(i)].second] = aux;
         i = Father(i);
      }
   }
}
//En este caso el update simplemente borra el nodo con la llave k y reutilizamos nuestro if anterior con la funcion insertorupdate
else{
   erase(k);
   InsertorUpdate(k,p);
}
}

void PrintHeap(){
   if(nodo.size() == 0){
      std::cout << -1 << std::endl;
   }
   else{
      std::cout << top().second << " " << top().first << std::endl;
   }
}

};


int main(){

   UpdatableHeap<std::string, int> FoodDataBase; 

   int OP, bint, i = 0;
   std::string option, astring;

   std::cin>> OP; //numero de operaciones

   do{
      std::cin>>option;

      if(option == "P"){
         FoodDataBase.PrintHeap();
      }
      if(option == "IU"){
         std::cin>>astring;
         std::cin>>bint;
         FoodDataBase.InsertorUpdate(astring, bint);
      }
      if(option == "DL"){
         FoodDataBase.pop();
      }
      if(option == "D"){
         std::cin>>astring;
         FoodDataBase.erase(astring);
      }

      i++;
   }while (i < OP);
   

   return 0; 
}