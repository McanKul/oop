//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//mehmetcan kul
//150210076
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;



class pokemon
{
private:
    string name;
    int hpValue;
    int atkValue;

public:
    pokemon() = default;
    pokemon(string poke_name, int poke_hpValue, int poke_atkValue) : name(poke_name), hpValue(poke_hpValue), atkValue(poke_atkValue){};

    pokemon(const pokemon &poke) : name(poke.name), hpValue(poke.hpValue), atkValue(poke.atkValue) {}

    string get_pokemon_name() const { return this->name; }
    int get_hpValue() { return this->hpValue; }
    int get_atkValue() { return this->atkValue; }
    void set_hp(int value);
};

class pokedex
{
private:
    pokemon pokedexArray[100];
    int value;

public:
    int get_value() { return this->value; };
    void set_value(int number);
    pokedex() : value(0){};
    void updatePokedex(const pokemon &poke);
    void printPokedex();
};

class player
{
private:
    string name;
    int pokemonNumber;
    int pokeballNumber;
    int badgeNumber;
    pokemon playerPokemon;

public:
    pokedex playerPokedex;
    player(){};
    player(string name, pokemon poke) : name(name), pokemonNumber(0), pokeballNumber(10), badgeNumber(0), playerPokemon(poke){};
    string get_player_name() { return this->name; }
    int showPokemonNumber() { return this->pokemonNumber; }
    int showPokeballNumber() { return this->pokeballNumber; }
    int showBadgeNumber() { return this->badgeNumber; }
    pokemon getPokemon() { return this->playerPokemon; }
    void battleWon();
    void catchPokemon();

};

class enemy
{
private:
    string name;
    pokemon enemyPokemon;

public:
    enemy(){};
    enemy(string name, pokemon poke) : name(name), enemyPokemon(poke){};
    string getName() { return this->name; }
    pokemon getPokemon() { return this->enemyPokemon; }
};

#endif