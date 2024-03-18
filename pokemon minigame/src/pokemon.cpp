//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---mehmetcan kul
//---150210076
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

// pokemon class

void pokemon::set_hp(int value){
   hpValue=value;
};
// pokemon class end

// pokedex class

void pokedex::set_value(int number)
{
   value = number;
};

void pokedex::updatePokedex(const pokemon &poke)
{
   if (value == 0)
   {
      pokedexArray[value] = poke;
      value++;
      return;
   }

   for (int i = 0; i < value; i++)
   {
      if (pokedexArray[i].get_pokemon_name() == poke.get_pokemon_name())
      {
         return;
      }
   }

   pokedexArray[value] = poke;
   value++;
   return;
};

void pokedex::printPokedex()
{
   for (int i = 0; i < value; i++)
   {
      cout << pokedexArray[i].get_pokemon_name() << endl;
   }
};
// pokedex class end

//player class
void player::battleWon(){
   badgeNumber++;
   pokeballNumber +=3;
}

void player::catchPokemon(){
   pokemonNumber++;
   pokeballNumber--;
}
//player class end