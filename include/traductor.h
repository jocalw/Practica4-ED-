/**
  * @file traductor.h
  * @brief Fichero cabecera del TDA Traductor.
  *
  */
#ifndef _TRADUCTOR_H_
#define _TRADUCTOR_H_

#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <map>
#include "palabra.h"

using namespace std;

/**
  * @brief T.D.A. Traductor
  *
  * Una instancia @e c del tipo de datos abstracto @c Traductor es un
  * un contenedor de objetos del T.D.A. @c Palabra con el cual buscamos
  * y devolvemos todas las traducciones de una palabra dada.
  */
class Traductor{
  private:
  	/** 
  	  * @page repTraducciones Rep del TDA Traductor.
	  * 
	  * @section faTraducciones Función de abstracción.
	  *
	  * Un objeto válido @e rep del TDA Traductor representa al valor
	  * (T.diccionario)
	  */
	map<string, Palabra> diccionario;
	
  public:

  	/**
  	  * @brief Constructor por defecto de la clase, crea el diccionario.
  	  */
  	Traductor();  

  	/**
  	  * @brief Constructor de copia.
  	  * @param t map de palabras a introducir en el diccionario.
  	  */
  	Traductor(map<string, Palabra> t);

  	/**
  	  * @brief Entrada de un flujo a un fichero desde istream.
  	  * @param is stream de entrada.
  	  * @param t Traductor que recibe el contenido del flujo.
  	  * @retval El diccionario de palabras.
  	  * @return Devuelve el control al flujo para concatenar lecturas.
	  */
	friend istream& operator>> (istream& is, Traductor& t);

	/** 
	  * @brief GetPalabra
	  * @param i indice de la palabra en el diccionario.
	  * @return Devuelve un objeto palabra.
	  */
	Palabra GetPalabra(string i);

	/**
	  * @brief Imprime el contenido del diccionario llamando a
	  * Palabra.print() reiteradamente.
	  */
	void print();

	/**
	  * @brief Busca las traducciones de una palabra.
	  * @param a palabra clave que buscamos.
	  * @return Devuelve un vector con las traducciones.
	  */
	vector<string> GetTraducciones(string a);

	/** 
	  * @brief Busca una palabra en el traductor.
	  * @param a palabra clave que buscamos.
      * @return Devuelve un bool si la encuentra.
      */
    bool buscarPalabra(string a);
    
    /**
      * @brief Comprueba si el tradcutor está vacío.
      * @return Devuelve un bool dependiendo del resultado.
      */
    bool empty();

    /**
      * @brief Introduce una nueva traduccion para la palabra deseada.
      * @param c palabra clave a la cual queremos añadir una nueva traducción.
      * @param t traducción que se añadira al conjunto de traducciones de la 
      * palabra clave seleccionada.
      */
    void InsertaTraduccion(string c, string t);

    /**
      * @brief Introduce una nueva entrada "clave | traducciones"
      * al diccionario.
      * @param c palabra clave que añadimos al diccionario.
      * @param t traduccines de la palabra clave.
      */
    void InsertaPalabra(string o, string t);

    class const_iterator;

    /**
      * @brief Clase para iterar sobre las traducciones.
      */
    class iterator{
       private:
       	map<string, Palabra>::iterator it;
       
       public:
       	iterator();

       	iterator& operator++(){
       		++it;
       		return *this;	
       	} 		

       	iterator& operator--(){
       		--it;
       		return *this;
       	}

       	pair<const string, Palabra>& operator*(){
       		return *it;
       	}

       	bool operator ==(const iterator &i){
       		return (i.it==it);
       	}

       	bool operator !=(const iterator &i){
       		return (i.it!=it);
       	}

       	friend class Traductor;
       	friend class const_iterator;
    };

    /**
      * @brief clase const para iterar sobre las traducciones.
      */
    class const_iterator{
   	   private:
   	   	map<string, Palabra>::const_iterator it;

   	   public:
   	   	const_iterator(){}

   	   	const_iterator(const iterator &i){ it=i.it;}

   	   	const_iterator& operator++(){
   	   		++it;
   	   		return *this;
   	   	}

   	   	const_iterator& operator--(){
   	   		--it;
   	   		return *this;
   	   	}

   	   	const_iterator& operator=(const iterator &i){
   	   		it=i.it;
   	   		return *this;
   	   	}

   	   	const pair<const string, Palabra>& operator*(){
   	   		return *it;
   	   	}

   	   	bool operator==(const const_iterator &i){
   	   		return (i.it==it);
   	   	}

   	   	bool operator!=(const const_iterator &i){
   	   		return (i.it!=it);
   	   	}

   	   	friend class Traductor;
    };  

    /**
      * @brief Inicializa un iterator al comienzo de la guia.
      */
    iterator begin(){
    	iterator i;
    	i.it=diccionario.begin();
    	return i; 
    }   

    /**
      * @brief Inicializa un iterator al final de la guia.
      */
    iterator end(){
    	iterator i;
    	i.it=diccionario.end();
    	return i; 
    }

    /**
      * @brief Inicializa un const iterator al comienzo de la guia.
      */
    const_iterator begin() const{
    	const_iterator i;
    	i.it=diccionario.begin();
    	return i; 
    }   

    /**
      * @brief Inicializa un const iterator al final de la guia.
      */
    const_iterator end() const{
    	const_iterator i;
    	i.it=diccionario.end();
    	return i; 
    }

};
#endif