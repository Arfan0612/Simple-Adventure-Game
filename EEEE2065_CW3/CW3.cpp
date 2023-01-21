#include "CW3.h"

void adventure_game::welcomeMssg(){
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "                                 Welcome to Text-Based Adventure Game                     \n";
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "Things to know beforehand:\n";
    cout << "- There are a total of "<< N_rooms <<" places that can be explored.\n";
    cout << "- There are a total of "<< N_monster <<" that can be in any room.\n";
    cout << "- Once an artifact is dropped, it will be gone forever.\n";
    cout << "- To finish the game you must obtain the \'"<< artifacts_name[7] <<"\'\n";
    cout << "- Monsters will fight back if attacked.\n";
    cout << "- If you die fighting a monster, the game is over.\n";
    cout << "---------------------------------------------------------------------------------------------\n";
}

/////////////////////////////////////////////////////////////////
//extra
void adventure_game::convertToLower(){
    //to print strings to lowercase
    for(int i=0; i<(int)current_command.length(); i++){
        current_command[i] = tolower(current_command[i]);
    }
}
void adventure_game::printPlayerStats(){
    //to print the player's current stats
    cout << "**EXP -> ";
    for(int i=0; i<player_exp; i++){
        cout << "+";
    }
    cout << "\n";

    cout << "**Player Health -> ";
    for(int j=0; j<player_health; j++){
        cout << "+";
    }
    cout << "\n";
}
void adventure_game::printDeathMssg(){
    //check which monster the player died to
    for(int i=0; i<N_monster; i++){
        //check which room the player died in
        if(monster_loc[i]==room){
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout  << "YOU DIED!!! while fighting the " << monsters_name[i] << ".\n";
        }
    }
}
void adventure_game::printCongrats(){
    cout  << "---------------------------------------------------------------------------------------------\n";
    cout  << "                                CONGRATULATIONS!!!! YOU WON THE GAME                         \n";
}
void adventure_game::legalmovementMssg(){
    //to inform the player the legal movements they can perform based on the room they are in

    //check the number of room the player can go to based on which room the player is current in
    int number = countPossibleRoom();

    //check which room the player is in and print legal movement accordingly
    if(room==1){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Adventurer\'s Diner (go East)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==2){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Adventurer\'s Hut (go West)\n";
        cout << "- Graveyard (go East)\n";
        cout << "- Forest of Scales (go South)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==3){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Adventurer\'s Diner (go West)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==4){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Forest of Scales (go East)\n";
        cout << "- Dracula\'s Dungeon (go South)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==5){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Adventurer\'s Diner (go North)\n";
        cout << "- Slime\'s Sky (go East)\n";
        cout << "- Recovery Clinic (go West)\n";
        cout << "- Barn (go South)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==6){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Forest of Scales (go West)\n";
        cout << "- Abandoned Castle (go South) ";
        if(movetoArray[5][1]==-1){ cout << "(LOCKED)"; }
        cout << "\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==7){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Recovery Clinic (go North)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==8){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Forest of Scales (go North)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else if(room==9){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "There is only "<<number<<" other room you are allowed to go to:\n";
        cout << "- Slime\'s Sky (go North)\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
}
int adventure_game::countPossibleRoom(){
    //used to count the number of room the player can move to based on the current room the player is in

    //keep track of the number of rooms
    int counter = 0;

    //check for number of rooms the player could travel to
    for(int i=0; i<4; i++){
        //check the moveToArray to check for number of possible rooms the player can move in
        if(!(movetoArray[room-1][i]==-1)){
            //increase the counter if found one
            counter++;
        }
    }

    return counter;
}
void adventure_game::printSummary(){
    //to print the summary of the game if the player exits, dies, or win
    int monster_counter = 0;
    int artifact_counter = 0;

    //check number of monsters player have killed
    for(int i=0; i<N_monster; i++){
        if(monster_HP[i]<=0){
            monster_counter++;
        }
    }

    //check number of artifacts player have picked up throughout the game
    for(int j=0; j<N_artifacts; j++){
        if(artifacts_loc[j]==-1){
            artifact_counter++;
        }
    }

    cout  << "---------------------------------------------------------------------------------------------\n";
    cout  << "Summary:\n";
    cout  << "- You have accumulate a total of "<< player_exp <<" EXP.\n";
    cout  << "- You have killed "<< monster_counter <<" monsters throughout the game.\n";
    cout  << "- You have picked up " << artifact_counter << " number of artifacts throughout the game.\n";
    cout  << "---------------------------------------------------------------------------------------------\n";
}
int adventure_game::count_InventoryItem(){
    //to count the number of items is in the player's inventory

    //to keep track the number of items
    int no_items =0;

    //iterate through the inventory array
    for(int i=0; i<N_inventory; i++){
        //check if the position in the array is occupied or not
        if(!(Inventory[i].empty())){
            //increase the counter if occupied
            no_items++;
        }
    }
    return no_items;
}
void adventure_game::removeActionWord(){
    //used to remove action word such as get, drop

    //to store the location of where the action word starts
    int word_loc;

    if(current_command=="get copper key" || current_command=="get food" || current_command=="get golden chalice"
            || current_command=="get silver spear" || current_command=="get medpack" || current_command=="get sword"
            || current_command=="get elixir" || current_command=="get diamond cross"){
        //find the position at which the first letter of the action letter occur
        word_loc = current_command.find(get);

        //erase the action word from the user input based on where the action word is and the length of the action word
        current_command.erase(word_loc, get.length());
    }
    else if(current_command=="drop copper key" || current_command=="drop food" || current_command=="drop golden chalice"
            || current_command=="drop silver spear" || current_command=="drop medpack" || current_command=="drop sword"
            || current_command=="drop elixir" || current_command=="drop diamond cross"){
        word_loc = current_command.find(drop);
        current_command.erase(word_loc, drop.length());
    }
    else if(current_command=="kill zombie" || current_command=="kill werewolf" || current_command=="kill dragon" ||
            current_command=="kill lizard-man" || current_command=="kill toxic slug" || current_command=="kill dracula"){
        word_loc = current_command.find(kill);
        current_command.erase(word_loc, kill.length());
    }
    else if(current_command=="eat food"){
        word_loc = current_command.find(eat);
        current_command.erase(word_loc, eat.length());
    }
    else if(current_command=="drink elixir"){
        word_loc = current_command.find(drink);
        current_command.erase(word_loc, drink.length());
    }
    else if(current_command=="use medpack"){
        word_loc = current_command.find(use);
        current_command.erase(word_loc, use.length());
    }
}
int adventure_game::checkWinDeath(){
    //check the current game state, whether the player has won or die yet

    //keep track number of items in the player's inventory
    int no_item=0;

    //to store whether the golden chalice is in the player's inventory or not
    int goldenChalice_presence = 0;

    //count the number of items in the player's inventory
    no_item = count_InventoryItem();

    //check if player is dead or alive
    if(player_health>0){
        //check whether there are any items in the player's inventory or not
        if(no_item!=0){
            //iterate through the player's inventory if it is not empty
            for(int i=0; i<N_inventory; i++){
                //check for golden chalice in the player's inventory
                if(Inventory[i] == artifacts_name[7]){
                    //update that the golden chalice is in player's inventory
                    goldenChalice_presence++;
                }
            }

            //check if player has won the game by being in room 1 and having the golden chalice
            if(room==1 && goldenChalice_presence){
                return 2;
            }
        }
        else{
            //continue the game as the player does not have any items
            return 1;
        }
    }
    else{
        //stop the game if the player died
        return 0;
    }

    return 1;
}
int adventure_game::monsterAttackMultiplier(string monster){
    //for determining the monster's damage
    // takes the monster string as input for comparing to determine which monster

    //default monster damage
    int monster_damage = 1;

    //Different monsters might have different attack damage ranges
    //zombie and a toxic slug, their damage is 1
    //lizard-man and werewolf, their damage ranges from 1-3
    if(monster=="lizard-man" || monster=="werewolf"){
        //create randomness in damage
        monster_damage*=((rand()%3)+1);
    }
    //dracula and dragon, their damage ranges from 1-4
    else if(monster=="dracula" || monster=="dragon"){
        //create randomness in damage
        monster_damage*=((rand()%4)+1);
    }

    cout  << "The " << monster << " has dealt "<< monster_damage << " to you.\n";
    cout  << "---------------------------------------------------------------------------------------------\n";

    return monster_damage;
}
int adventure_game::playerAttackMultiplier(string monster){
    //for determining the amount of damage the player would inflict
    //take monster name string as input just for printing later on

    //default player damage
    int player_damage=2;

    //check player's inventory for weapon that is the weakness of the current monster
    for(int i=0; i<N_inventory; i++){
        //increase player's damage if it is fighting against werewolf using the silver spear
        if(room==monster_loc[5] && Inventory[i]==artifacts_name[1]){
            player_damage=4;
            break;
        }
        //increase player's damage if it is fighting against dracula using the diamond cross
        else if(room==monster_loc[3] && Inventory[i]==artifacts_name[6]){
            player_damage=5;
            break;
        }
        //increase player's damage if it is fighting against the dragon using the sword
        else if(room==monster_loc[4] && Inventory[i]==artifacts_name[3]){
            player_damage=5;
            break;
        }
        //increase player's damage if any weapon is in the inventory
        //unless the player is fighting against the dracula with a sword
        else if((Inventory[i]==artifacts_name[1] || Inventory[i]==artifacts_name[6] || Inventory[i]==artifacts_name[3])
                && !(room==monster_loc[3] && Inventory[i]==artifacts_name[3])){
            player_damage=3;
        }
    }

    cout  << "---------------------------------------------------------------------------------------------\n";
    cout  << "You have dealt " << player_damage << " to " << monster << ".\n";

    return player_damage;
}
void adventure_game::getEXP(string monster){
    //for updating player's EXP if player killed a monster
    //takes monster name string as input for printing later on

    //the experience gained from killing a monster is the same as the room number their in
    player_exp+=room;

    cout  << "You have gained "<< room <<" exp from killing the " << monster <<".\n";
    cout  << "---------------------------------------------------------------------------------------------\n";
}
void adventure_game::healthOverflow(int previous_health, string med){
    //check for health overflow and print how much the player healed
    //takes previous health as input to determine how much player has healed
    //takes name of healing artifact used for printing later on

    //to store how much the player healed
    int change=0;

    //check if player health more than max after healing
    if(player_health>12){
        player_health = 12;
        change = player_health-previous_health;

        cout  << "---------------------------------------------------------------------------------------------\n";
        cout  << "You have consumed "<< med <<".\n";
        cout  << "You have gained "<< change <<" health only.\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
    else{
        change = player_health-previous_health;

        cout  << "---------------------------------------------------------------------------------------------\n";
        cout  << "You have consumed "<< med <<".\n";
        cout  << "You have gained "<< change <<" health.\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
}
int adventure_game::checkLockArtifact(int art_loc){
    //check for whether there is a monster guarding an artifact or not and whether the monster is dead or not
    //take location of artifact as input for comparing

    //store whether player is allowed or not to take the artifact
    int allow = 1;

    //check monster locations
    for(int i=0; i<N_monster; i++){
        //see if artifact location matches where a monster would be
        if(monster_loc[i]==art_loc){
            //change value of allow if the monster in that room is still alive
            if(!(monster_HP[i]<=0)){
                //to make sure the player is not allowed to take the artifact
                //as the monster guarding the artifact is still alive
                allow =0;
            }
        }
    }

    if(allow==0){
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout  << "You must first kill the monster in this room to obtain that artifact.\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }

    //allow = 1 -> allow player to take artifact
    //allow = 0 -> do not allow player to take artifact
    return allow;
}
void adventure_game::Battle(int monsterID){
    //to process the battle between monster and player
    //take monsterID as input to know which monster the player is fighting

    //decrease the monster health according to player damage
    monster_HP[monsterID]-=playerAttackMultiplier(monsters_name[monsterID]);

    //if the monster dies after the player attack, the monster would not be able to inflict damage onto player
    if(!(monster_HP[monsterID]<=0)){
        //decrease the player's health according to damage dealt by monster
        player_health-=monsterAttackMultiplier(monsters_name[monsterID]);
    }

    //print killing statement if player killed a monster
    if(monster_HP[monsterID]<=0){
        //to update player's experience
        getEXP(monsters_name[monsterID]);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//process in-game command
void adventure_game::processLook(){
    //to print look command

    //for printing which room the player is in currently
    for(int k=1; k<=N_rooms; k++){
        if(k==room){
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout <<"You are in the " << room_names[k-1] << ".\n";
        }
    }

    //to print if there are any monsters in the current room the player is in
    for(int i=0; i<N_monster; i++){
        //check for if have monster in current room and whether it is alive or dead
        if(monster_loc[i]==room && monster_HP[i]>0){
            cout << "BE AWARE! there is a " << monsters_name[i] << " nearby.\n";
        }
        else if(monster_loc[i]==room && monster_HP[i]<=0){
            cout << "There is a dead " << monsters_name[i] << " nearby.\n";
        }
    }

    //to print if there are any artifacts in the current room the player is in
    for(int j=0; j<N_artifacts; j++){
        //check for location of artifact with the current room the player is in currently
        if(artifacts_loc[j]==room){
            cout << "There is \'" << artifacts_name[j] << "\' in here.\n";
        }
    }

    //inform players of the legal movements that can be made in respective room
    legalmovementMssg();
}

void adventure_game::processKillMonster(){
    //store whether there is a monster or not in the current room
    int check_monster_presence = 0;

    //to store the ID of the monster identified if any
    int monsterID;

    //check if there is a monster in the current room player is in
    for(int i=0; i<N_monster; i++){
        if(monster_loc[i]==room){
            check_monster_presence++;
            monsterID = i;
            break;
        }
    }

    if(current_command=="killMonster" || current_command=="killmonster" || current_command=="km"){
        //check if there is a monster in the current room
        if(check_monster_presence){
            //check if the monster is alive or dead
            if(!(monster_HP[monsterID]<=0)){
                //process battling
                Battle(monsterID);
            }
            else{
                cout  << "---------------------------------------------------------------------------------------------\n";
                cout  << "The " << monsters_name[monsterID] <<" is already dead. There is no monster in here.\n";
                cout  << "---------------------------------------------------------------------------------------------\n";
            }
        }
        else{
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout  << "There is no monster here in " << room_names[room-1] <<".\n";
            cout  << "---------------------------------------------------------------------------------------------\n";
        }
    }
    else if(current_command=="kill zombie" || current_command=="kill werewolf" || current_command=="kill dragon" ||
            current_command=="kill lizard-man" || current_command=="kill toxic slug" || current_command=="kill dracula"){
        removeActionWord();
        //check if the monster the player wants to kill is in the current rooom
        if(check_monster_presence && monsters_name[monsterID]==current_command){
            //check if the monster is alive or dead
            if(!(monster_HP[monsterID]<=0)){
                //process battling
                Battle(monsterID);
            }
            else{
                cout  << "---------------------------------------------------------------------------------------------\n";
                cout  << "The " << monsters_name[monsterID] <<" is already dead. There is no monster in here.\n";
                cout  << "---------------------------------------------------------------------------------------------\n";
            }
        }
        else{
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout  << "There is no " << current_command << " here in " << room_names[room-1] <<".\n";
            cout  << "---------------------------------------------------------------------------------------------\n";
        }
    }
}

void adventure_game::processHelp(){
    cout  << "---------------------------------------------------------------------------------------------\n";
    cout  << "List of Commands\n";
    cout  << "---------------------------------------------------------------------------------------------\n";
    cout  << "Movement commands" << setw(5) << "|  " << "north, n, south, s, east, e, west, w" << endl;
    cout  << "Look command" << setw(10) << "|  " << "look,l" << endl;
    cout  << "Fight command" << setw(9) << "|  " << "killMonster,killmonster,km" << endl;
    cout  << "         " << setw(13) << "|  " << "kill zombie, kill werewolf, kill dragon" << endl;
    cout  << "Get command" << setw(11) << "|  " << "get diamond cross, get sword, get elixir" << endl;
    cout  << "Drop command" << setw(10) << "|  " << "drop copper key, drop food, drop golden chalice." << endl;
    cout  << "Inventory command" << setw(5) << "|  " << "inventory, i" << endl;
    cout  << "Healing command" << setw(7) << "|  " << "eat food, drink elixir, use medpack" << endl;
    cout  << "Unlocking door" << setw(8) << "|  " << "unlock door" << endl;
    cout  << "Exit game" << setw(13) << "|  " << "exit" << endl;
    cout  << "---------------------------------------------------------------------------------------------\n";
}

void adventure_game::processMovement(){
    if(current_command=="north" || current_command=="n"){
        if(movetoArray[room-1][0]!=-1){
            room = movetoArray[room-1][0];
            processLook();
        }
        else{
            legalmovementMssg();
        }
    }
    else if(current_command=="south" || current_command=="s"){
        if(movetoArray[room-1][1]!=-1){
            room = movetoArray[room-1][1];
            processLook();
        }
        else{
            legalmovementMssg();
        }
    }
    else if(current_command=="east" || current_command=="e"){
        if(movetoArray[room-1][2]!=-1){
            room = movetoArray[room-1][2];
            processLook();
        }
        else{
            legalmovementMssg();
        }
    }
    else if(current_command=="west" || current_command=="w"){
        if(movetoArray[room-1][3]!=-1){
            room = movetoArray[room-1][3];
            processLook();
        }
        else{
            legalmovementMssg();
        }
    }

}

void adventure_game::processCheckInventory(){
    //to store the number of items currently in the player's inventory
    int no_items = 0;

    //check for number of items in player's inventory
    no_items = count_InventoryItem();

    cout  << "---------------------------------------------------------------------------------------------\n";
    cout << "You are carrying " << no_items << " items.\n";


    if(no_items!=0){
        //to print out the artifacts name in the player's inventory
        cout << "List of items:\n";
        for(int i=0; i<N_inventory; i++){
            if(!(Inventory[i].empty())){
                cout << "- " << Inventory[i] << "\n";
            }
        }
    }

    cout  << "---------------------------------------------------------------------------------------------\n";
}

void adventure_game::processDropitem(){
    //store number of items in the player's inventory
    int no_item=0;

    //stores whether an artifact was dropped or not
    int changes=0;

    //count number of items in player's inventory
    no_item = count_InventoryItem();

    //to remove the action word "drop" from the user input for easier comparison
    removeActionWord();

    if(no_item!=0){
        //iterate through player's inventory
        for(int i=0; i<N_inventory; i++){
            //check for the artifact the player wanted to drop
            if(Inventory[i]==current_command){
                cout  << "---------------------------------------------------------------------------------------------\n";
                cout << "You have dropped " << Inventory[i] << " from inventory.\n";
                cout  << "---------------------------------------------------------------------------------------------\n";

                //to remove the artifact from player's inventory
                Inventory[i].erase();

                //keep track that there was an item erased from the inventory array
                changes++;
            }
        }

        //check if there are any artifacts dropped or not
        if(changes==0){
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout << "You do not have the item to drop it. No item was dropped.\n";
            cout  << "---------------------------------------------------------------------------------------------\n";
        }
    }
    else{
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "You have "<< no_item <<" item to drop.\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
}

void adventure_game::processHeal(){
    //store number of items in player's inventory
    int no_item = 0;

    //store whether the item player want to use is in the inventory or not
    int item_presence = 0;

    //store the items location
    int item_loc;

    //store previous health before healing
    int previous_health = 0;

    //to remove action word "eat", "drink", "use" from user input
    removeActionWord();

    //count number of items in player's inventory
    no_item = count_InventoryItem();

    //check if player have any items in their inventory
    if(no_item!=0){
        //check for presence of healing artifact in inventory
        for(int i=0; i<N_inventory; i++){
            if(Inventory[i]==current_command){
                item_loc = i;
                item_presence++;
            }
        }

        //to use healing artifact if player has it
        if(item_presence){
            //check if player is full health
            if(player_health!=12){
                //store player's current health before healing
                previous_health = player_health;

                //check to use correct healing artifact
                if(current_command==artifacts_name[0]){
                    player_health+=5;
                    Inventory[item_loc].erase();
                }
                else if(current_command==artifacts_name[2]){
                    player_health+=10;
                    Inventory[item_loc].erase();
                }
                else if(current_command==artifacts_name[4]){
                    player_health+=10;
                    Inventory[item_loc].erase();
                }

                //check for if player's health is more than allowed and printing statement
                healthOverflow(previous_health, current_command);
            }
            else{
                cout  << "---------------------------------------------------------------------------------------------\n";
                cout << "You cannot heal as you are full health.\n";
                cout  << "---------------------------------------------------------------------------------------------\n";
            }
        }
        else{
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout << "You do not have " <<current_command<< " to use.\n";
            cout  << "---------------------------------------------------------------------------------------------\n";
        }
    }
    else{
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "You do not have any items in inventory to use.\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
}

void adventure_game::processGet(){
    //store number of items currently in player's inventory
    int no_items = 0;

    //store the location of first found free space in player's inventory
    int free_loc;

    //count number of items in player's inventory
    no_items = count_InventoryItem();

    //to remove action word "get" from user input
    removeActionWord();

    //check if player's inventory is full or not
    if(no_items<3){
        //check for unoccupied location in player's inventory
        for(int i=0; i<N_inventory; i++){
            if(Inventory[i].empty()){
                //store location of free space in player's inventory
                free_loc = i;
                break; //break loop once free space in inventory is located
            }
        }

        //to check and store artifact if can
        for(int i=0; i<N_artifacts; i++){
            //check for which item the player wants to get
            if(artifacts_name[i]==current_command){
                //check if the artifact is in the current room
                if(artifacts_loc[i]==room){
                    if(checkLockArtifact(artifacts_loc[i])){
                        cout  << "---------------------------------------------------------------------------------------------\n";
                        cout <<  "You have picked up " << artifacts_name[i] << "!\n";
                        cout  << "---------------------------------------------------------------------------------------------\n";

                        //store artifact into player's inventory
                        Inventory[free_loc] = artifacts_name[i];

                        //update location of artifact to that it has been picked up by the player
                        artifacts_loc[i] = -1;
                    }

                }
                else{
                    cout  << "---------------------------------------------------------------------------------------------\n";
                    cout <<  "There is no " << artifacts_name[i] << " in here.\n";
                    cout  << "---------------------------------------------------------------------------------------------\n";
                }
            }
        }
    }
    else{
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout <<  "Your inventory if full! drop an artifact first before considering picking up a new artifact.\n";
        cout <<  "WARNING! dropping an artifact will cause it to disappear forever.\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
}

void adventure_game::processUnlockDoor(){
    //store whether the copper key is present in player's inventory or not
    int key_presence = 0;

    //store the location of the copper key from player's inventory
    int key_pos = 0;

    //check inventory for copper key
    for(int i=0; i<N_inventory; i++){
        if(Inventory[i]==artifacts_name[5]){
            key_presence++;//update that the key is found
            key_pos = i;//update the copper key position from the player's inventory
            break;
        }
    }

    if(key_presence){
        //make sure that the player can only unlock the door if there are in room 6 only
        if(room==6){
            //update that room 9 can be access from room 6 now
            movetoArray[5][1] = 9;

            //remove the key from plyaer's inventory
            Inventory[key_pos].erase();
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout  << "You have successfully unlocked the door to the " << room_names[8] << ".\n";
            cout  << "You are allowed to explore the " << room_names[8] << " now.\n";
            cout  << "---------------------------------------------------------------------------------------------\n";
        }
        else{
            cout  << "---------------------------------------------------------------------------------------------\n";
            cout  << "You must travel to " << room_names[5] << " before you are allowed to unlock door             \n";
            cout  << "---------------------------------------------------------------------------------------------\n";
        }
    }
    else{
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout  << "You do not possess the " << artifacts_name[5] << ". You must first obtain this artifact.     \n";
        cout  << "---------------------------------------------------------------------------------------------\n";
    }
}

/////////////////////////////////////////////////////////////////
//processing
int adventure_game::getCommand(){
    //check the current game state whether player has died or won
    int gamestate = checkWinDeath();

    //if the player has died
    if(gamestate==0){
        printDeathMssg();
        printSummary();
        return 0;
    }
    //if the plater has won the game
    else if(gamestate==2){
        printCongrats();
        printSummary();
        return 0;
    }

    //print player's current stats
    printPlayerStats();

    //ask for user input
    cout << "**Enter command: ";
    getline(cin,current_command);

    //if user enter nothing, it will use the previously entered command
    if(current_command.empty() && !previous_command.empty()){
        current_command = previous_command;
    }

    //store currrent user input
    previous_command = current_command;
    return 1;
}

int adventure_game::processCommand(){
    //convert user input to all lowercase
    convertToLower();

    if(current_command=="exit"){
        printSummary();
        return 0;
    }

    else if(current_command=="help"){
        processHelp();
        return 1;
    }

    else if(current_command=="north" || current_command=="south" || current_command=="east" || current_command=="west" || current_command=="north" ||
            current_command=="n" || current_command=="s" || current_command=="e" || current_command=="w"){
        processMovement();
        return 1;
    }

    else if(current_command=="look" || current_command=="l"){
        processLook();
        return 1;
    }

    else if(current_command=="killMonster" || current_command=="killmonster" || current_command=="km" ||
            current_command=="kill zombie" || current_command=="kill werewolf" || current_command=="kill dragon" ||
            current_command=="kill lizard-man" || current_command=="kill toxic slug" || current_command=="kill dracula"){
        processKillMonster();
        return 1;
    }

    else if(current_command=="get copper key" || current_command=="get food" || current_command=="get golden chalice"
            || current_command=="get silver spear" || current_command=="get medpack" || current_command=="get sword"
            || current_command=="get elixir" || current_command=="get diamond cross"){
        processGet();
        return 1;
    }

    else if(current_command=="drop copper key" || current_command=="drop food" || current_command=="drop golden chalice"
            || current_command=="drop silver spear" || current_command=="drop medpack" || current_command=="drop sword"
            || current_command=="drop elixir" || current_command=="drop diamond cross"){
        processDropitem();
        return 1;
    }

    else if(current_command=="inventory" || current_command=="i"){
        processCheckInventory();
        return 1;
    }

    else if(current_command=="eat food" || current_command=="drink elixir" || current_command=="use medpack"){
        processHeal();
        return 1;
    }

    else if(current_command=="unlock door"){
        processUnlockDoor();
        return 1;
    }

    else{
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "Unknown command, please enter valid command!\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
        return 1;
    }

    return 0;
}

int adventure_game::processCommand(string input){
    int gamestate = checkWinDeath();

    //stop processing the input from user if the player already won the game or died
    if(finish==0){
        return 0;
    }

    //if player has died
    if(gamestate==0){
        printDeathMssg();
        printSummary();
        finish=0;//update that the game should not process anymore inputs from user
        return 0;
    }
    //if player has won the game
    else if(gamestate==2){
        printCongrats();
        printSummary();
        finish=0;//update that the game should not process anymore inputs from user
        return 0;
    }

    //print player's current stats
    printPlayerStats();

    //convert user input to all lowercase
    convertToLower();

    //update the user input that is in the class
    current_command = input;

    cout << "**Enter Command: " << current_command << endl;

    if(current_command=="exit"){
        printSummary();
        return 0;
    }

    else if(current_command=="help"){
        processHelp();
        return 1;
    }

    else if(current_command=="north" || current_command=="south" || current_command=="east" || current_command=="west" || current_command=="north" ||
            current_command=="n" || current_command=="s" || current_command=="e" || current_command=="w"){
        processMovement();
        return 1;
    }

    else if(current_command=="look" || current_command=="l"){
        processLook();
        return 1;
    }

    else if(current_command=="killMonster" || current_command=="killmonster" || current_command=="km" ||
            current_command=="kill zombie" || current_command=="kill werewolf" || current_command=="kill dragon" ||
            current_command=="kill lizard-man" || current_command=="kill toxic slug" || current_command=="kill dracula"){
        processKillMonster();
        return 1;
    }

    else if(current_command=="get copper key" || current_command=="get food" || current_command=="get golden chalice"
            || current_command=="get silver spear" || current_command=="get medpack" || current_command=="get sword"
            || current_command=="get elixir" || current_command=="get diamond cross"){
        processGet();
        return 1;
    }

    else if(current_command=="drop copper key" || current_command=="drop food" || current_command=="drop golden chalice"
            || current_command=="drop silver spear" || current_command=="drop medpack" || current_command=="drop sword"
            || current_command=="drop elixir" || current_command=="drop diamond cross"){
        processDropitem();
        return 1;
    }

    else if(current_command=="inventory" || current_command=="i"){
        processCheckInventory();
        return 1;
    }

    else if(current_command=="eat food" || current_command=="drink elixir" || current_command=="use medpack"){
        processHeal();
        return 1;
    }

    else if(current_command=="unlock door"){
        processUnlockDoor();
        return 1;
    }

    else{
        cout  << "---------------------------------------------------------------------------------------------\n";
        cout << "Unknown command, please enter valid command!\n";
        cout  << "---------------------------------------------------------------------------------------------\n";
        return 1;
    }

    return 0;
}


