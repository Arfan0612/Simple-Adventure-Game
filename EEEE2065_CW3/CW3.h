#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;

class adventure_game{
private:
    string current_command;
    string previous_command;

    //player info
    int room=1;
    int player_exp =0;
    int player_health = 12;
    int finish = 1;

    //form of {N, S, E, W} for each room
    int movetoArray[9][4] ={
    {-1,-1,2,-1},
    {-1,5,3,1},
    {-1,-1,-1,2},
    {-1,7,5,-1},
    {2,8,6,4},
    {-1,-1,-1,5},
    {4,-1,-1,-1},
    {5,-1,-1,-1},
    {6,-1,-1,-1}
    };

    //action keywords
    const string get = "get ";
    const string drop = "drop ";
    const string eat = "eat ";
    const string drink = "drink ";
    const string use = "use ";
    const string kill = "kill ";
    const string equip = "equip ";

    //Rooms
    const int N_rooms = 9;
    const string room_names[9] = {"Adventurer\'s Hut", "Adventurer\'s Diner", "Graveyard", "Recovery Clinic",
    "Forest of Scales", "Slime\'s Sky", "Dungeon", "Barn", "Castle"};

    //Monsters
    //monsters starts attacking the moment the player initiates the fight
    const int N_monster = 6;
    string monsters_name [6] = {"zombie","lizard-man","toxic slug", "dracula", "dragon", "werewolf"};
    int monster_HP [6] = {6,5,4,12,12,12};
    int monster_loc[6] = {3,5,6,7,9,8};

    //Inventory
    const int N_inventory = 3;
    string Inventory [3];

    //Artifacts
    const int N_artifacts = 8;
    const string artifacts_name[8] = {"food","silver spear","medpack","sword",
    "elixir","copper key","diamond cross","golden chalice"};
    int artifacts_loc[8] = {2,3,4,5,6,7,8,9};

    /////////////////////////////////////////////////////////////////
    //extra
    void convertToLower();
    void printPlayerStats();
    void printDeathMssg();
    void printCongrats();
    void legalmovementMssg();
    int countPossibleRoom();
    void printSummary();
    int count_InventoryItem();
    void removeActionWord();
    int checkWinDeath();
    int monsterAttackMultiplier(string monster);
    int playerAttackMultiplier(string monster);
    void getEXP(string monster);
    void healthOverflow(int previous_health, string med);
    int checkLockArtifact(int art_loc);
    void Battle(int monsterID);

    /////////////////////////////////////////////////////////////////
    //in-game commands
    void processLook();
    void processKillMonster();
    void processHelp();
    void processMovement();
    void processCheckInventory();
    void processDropitem();
    void processHeal();
    void processGet();
    void processUnlockDoor();

public:
    void welcomeMssg();

    /////////////////////////////////////////////////////////////////
    //constructor & destructor
    adventure_game(){srand(time(0));}
    ~adventure_game(){}

    /////////////////////////////////////////////////////////////////
    //processing
    int getCommand();
    int processCommand();
    int processCommand(string input);
};
