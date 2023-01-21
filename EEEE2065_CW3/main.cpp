#include "CW3.h"

int main()
{
    //create object for adventure game
    adventure_game ag;

    //print welcome message
    ag.welcomeMssg();

    while(ag.getCommand()>0){
        if(ag.processCommand()==0){
            break;
        }
    }
    return 0;
}
