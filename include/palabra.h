/**
  * @file palabra.h
  * @brief fichero cabecera de la clase palabra
  *
  */

  #ifndef _PALABRA_H_
  #define _PALABRA_H_

 /**
   * @brief Palabra
   *
   * Una instancia @e c del tipo de datos abstracto @c Palabra es un objeto
   * que contiene una palabra origen y sus diversas traducciones en el
   * idioma del diccionario cargado.
   */
   #include <fstream>
   #include <iostream>
   #include <string>
   #include <vector>
   #include <set>
   #include <map>

   using namespace std;

   class Palabra{
   	  private:
   	  	/**
   	  	  * @page repPalabra Rep del TDA palabra
   	  	  *
   	  	  * @section invPalabra Invariante de la representación.
   	  	  *
   	  	  * Un objeto válido @e de la Palabra debe cumplir 
   	  	  *  - @c p.traduc.size() > 0
   	  	  *
   	  	  * @section fapPalabra Función  de abstracción.
   	  	  *
   	  	  * Un objeto válido @e rep de Palabra representa al par 
   	  	  * de datos @c string y @c un conjunto de strings.
   	  	  * {string, {string1, string2,...}}
   	  	  *
   	  	  */

   	 	pair<string, set<string> > palabra;
      
   	 public:
   	 	/***Constructores***/
   	 	/**
   	 	  * @brief Constructor por defecto
   	 	  * @note 
   	 	  *  Este constructor también corresponde al de por defecto.
   	 	  */
   	 	Palabra();
   	 	
   	 	/**
   	 	  * @brief Constructor con parámetros
   	 	  * @param orig es la clave, y palabras son las traducciones
   	 	  */
   	 	Palabra(pair<string, set<string> > p);
   	 	
   	 	/***Modificadores***/
   	 	/**
   	 	  * @brief GetClave
   	 	  * @return la variable clave.
   	 	  */
   	 	string GetClave();

   	 	/**
   	 	  * @brief SetClave
   	 	  *	@param un string que modifica la clave.
   	 	  */
   	 	void SetClave(string c);
   	 	
   	 	/**
   	 	  * @brief GetTraducciones
   	 	  * @return Devuelve el vector de traducciones.
   	 	  */
   	 	vector<string> GetTraduccion();

      /**
        * @brief Obtener el set de traducciones
        * @return Devuelve el set de traducciones
        */
   	 	set<string> GetTraducciones();

      /**
        * @brief Imprime una palabra con el formato
        * "Clave | Traducciones"
        */
      void print();

      /**
        * @brief Limpia el contenido de palabra.
        */
      void clear();

      /**
        * @brief Añade un caracter a la palabra origen
        * @param c caracter de entrada
        */
      void InsertLet(char c);

   	 	/**
   	 	  * @brief Inserta una traduccion a la lista de traducciones
   	 	  * @param t traducccion de la palabra origen.
   	 	  */   
   	 	void InsertTraduc(string t);  

      /**
        * @brief Tamaño de set de traducciones
        * @return el numero de traducciones de la palabra origen.
        */
      int SizeTr();

      class const_iterator;

        /**
          * @brief Clase para iterar sobre las traducciones
          */
        class iterator{
           private:
            set<string>::iterator it;

           public:
            iterator(){ }

            iterator& operator++(){
              ++it;
              return *this;
            }

            iterator& operator--(){
              --it;
              return *this;
            }

            const string& operator*(){
              return *it;
            }

            bool operator==(const iterator &i){
              return (i.it==it);
            }

            bool operator!=(const iterator &i){
              return (i.it!=it);
            }

            friend class Palabra;
            friend class const_iterator;
        };

        /** 
          * @brief Clase const para iterar sobre traducciones.
          */
        class const_iterator{
           private:
            set<string>::const_iterator it;
         
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

            const string& operator*(){
              return *it;
            }

            bool operator==(const iterator& i){
              return (i.it==it);
            }

            bool operator!=(const iterator& i){
              return (i.it!=it);
            }

            friend class Palabra;
        };

        /**
          * @brief Inicializa un iterator al comienzo de las traducciones.
          */
        iterator begin(){
          iterator i;
          i.it= palabra.second.begin();
          return i;
        }

        /** 
          * @brief Inicializa un iterator al final de las traducciones.
          */ 
        iterator end(){
          iterator i;
          i.it= palabra.second.end();
          return i;
        }

        /**
          * @brief Inicializa un const_iterator al comienzo de las traducciones.
          */
        const_iterator begin() const{
          const_iterator i;
          i.it= palabra.second.begin();
          return i;
        }

        /** 
          * @brief Inicializa un const_iterator al final de las traducciones.
          */ 
        const_iterator end() const{
          const_iterator i;
          i.it= palabra.second.end();
          return i;
        }
       
};

#endif 