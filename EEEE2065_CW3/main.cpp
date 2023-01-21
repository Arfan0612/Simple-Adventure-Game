#include "CW3.h"

int main()
{
    int i;
    //create object for adventure game
    adventure_game ag;

    //print welcome message
    ag.welcomeMssg();

//    while(ag.getCommand()>0){
//        if(ag.processCommand()==0){
//            break;
//        }
//    }

    i = ag.processCommand("east");
    i = ag.processCommand("get food");
    i = ag.processCommand("east");
    i = ag.processCommand("kill zombie");
    i = ag.processCommand("killMonster");
    i = ag.processCommand("km");
    i = ag.processCommand("km");
    i = ag.processCommand("km");
    i = ag.processCommand("get silver spear");
    i = ag.processCommand("west");
    i = ag.processCommand("south");
    i = ag.processCommand("south");
    i = ag.processCommand("kill werewolf");
    i = ag.processCommand("km");


    return 0;
}
