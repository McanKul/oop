//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//mehmetcan kul
//150210076
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;


int NAME_COUNTER = 0;           // Use this to keep track of the enemy names
int POK_COUNTER = 0;            // Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; // You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  // You don't have to use this variable but its here if you need it


string *readEnemyNames(const char *);
string *readPokemonNames(const char *);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player *, string *, string *);
void catchPokemon(player *, string *);
//------------------------------------------------------------------//


int main(int argc, char *argv[])
{
    system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string *enemyNames = readEnemyNames(argv[1]);
    string *pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n"<< endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;
    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);

    int menuChoice;

    while (true)
    {
        mainMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout << newPlayer.showPokemonNumber() << endl;
            break;
        case 4:
            cout << newPlayer.showPokeballNumber() << endl;
            break;
        case 5:
            cout << newPlayer.showBadgeNumber() << endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" << endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//


string *readEnemyNames(const char *argv)
{
    fstream file(argv);
    string array_size_str;
    int array_size;

    getline(file, array_size_str);
    array_size = stoi(array_size_str);
    string enemy_names_from_file;
    string *enemy_name_list = new string[array_size];
    int i = 0;
    while (getline(file, enemy_names_from_file))
    {
        enemy_name_list[i] = enemy_names_from_file;
        i++;
    }
    return enemy_name_list;
};
//-----------------------------------------------------//


string *readPokemonNames(const char *argv)
{
    fstream file(argv);
    string array_size_str;
    int array_size;

    getline(file, array_size_str);
    array_size = stoi(array_size_str);
    string pokemon_names_from_file;
    string *pokemon_name_list = new string[array_size];
    int i = 0;
    while (getline(file, pokemon_names_from_file))
    {
        pokemon_name_list[i] = pokemon_names_from_file;
        i++;
    }
    return pokemon_name_list;
};
//-----------------------------------------------------//


player characterCreate(string playerName, int pokemonChoice)
{
    string poke_name;
    switch (pokemonChoice)
    {
    case 1:
        poke_name = "Bulbasaur";
        break;
    case 2:
        poke_name = "Charmender";
        break;
    case 3:
        poke_name = "Squirtle";
        break;
    }
    pokemon mypoke(poke_name, 100, PLAYER_POKEMON_ATTACK);
    player my_player(playerName, mypoke);
    return my_player;
};
//--------------------------------------------//


void mainMenu()
{
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//


void fightEnemy(player *newPlayer, string *enemyNames, string *pokemonNames)
{
    pokemon mypokemon = newPlayer->getPokemon();
    pokemon enemy_pokemon(pokemonNames[POK_COUNTER], 100, 10);
    enemy enmy(enemyNames[NAME_COUNTER], enemy_pokemon);
    newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
    int condition;
    cout << "You encounter with " << enemyNames[NAME_COUNTER] << " and his/hers pokemon " << pokemonNames[POK_COUNTER] << endl;
    cout << pokemonNames[POK_COUNTER] << " Health: 100 Attack: 10" << endl;
    cout << "1- Fight." << endl;
    cout << "2- Runaway." << endl;
    cout << "Choice: "<<endl;
    cin >> condition;
    if (condition == 2)
    {
        return;
    }

    while (((mypokemon.get_hpValue() > 0) && (enemy_pokemon.get_hpValue() > 0)) && (condition == 1))
    {
        (mypokemon).set_hp((mypokemon.get_hpValue()) - (enemy_pokemon.get_atkValue()));
        enemy_pokemon.set_hp(enemy_pokemon.get_hpValue() - mypokemon.get_atkValue());

        cout << "Your Pokemons Healt: " << mypokemon.get_hpValue() << endl;
        cout << enemyNames[NAME_COUNTER] << " Pokemons Healt: " << enemy_pokemon.get_hpValue() << endl;
        if ((enemy_pokemon.get_hpValue() > 0) && (condition == 1))
        {
            cout << "1- Fight" << endl;
            cout << "2- Runaway" << endl;
            cout << "Choice: "<<endl;
            cin >> condition;
        }
    }
    if ((mypokemon.get_hpValue() > 0) && (condition == 1))
    {
        cout << "You Won!" << endl;
    }
    newPlayer->battleWon();
    newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
    NAME_COUNTER++;
    POK_COUNTER++;
};
//--------------------------------------------//


void catchPokemon(player *newPlayer, string *pokemonNames)
{
    pokemon enemy_pokemon(pokemonNames[POK_COUNTER], 100, ENEMY_POKEMON_ATTACK);

    newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
    int condition;
    cout << "You encounter with " << pokemonNames[POK_COUNTER] << " Health: 100 Attack: 10." << endl;
    cout << "1- Catch" << endl;
    cout << "2- Runaway" << endl;
    cout << "Choice: ";
    cin >> condition;
    if (condition == 2)
    {
        return;
    }
    cout << "You catch " << pokemonNames[POK_COUNTER] << endl;
    newPlayer->catchPokemon();
    newPlayer->playerPokedex.updatePokedex(enemy_pokemon);
    POK_COUNTER++;
};
//--------------------------------------------//
