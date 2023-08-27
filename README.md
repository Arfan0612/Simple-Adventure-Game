# Introduction

In this adventure game there are a total of 9 rooms that the player can explore to. There are as many as 6 monsters scattered in any of the 9 rooms. In addition, there are artifacts that can be collected by the player to gain an advantage in certain scenarios throughout the adventure game.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/ff48d1bb-63e5-4868-a604-e6ab43ae3928)

Player will be asked for user input for their next course of action. The player’s health and experience (EXP) will be shown to the player each time the game ask for user input. The class made for this game is in **CW3.cpp**.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/f81c2ff9-5370-48b2-9146-9c5a864e40af)

# Fighting algorithm

The way the fighting algorithm works is that the monster will only attack the player if the player initiated the attack by entering any kill monster related commands. The amount of damage inflicted to the player by the monster is dependent on which monster the player is fighting. The list below demonstrates the damage range of monsters:

-	Zombie and toxic slug attack damage is 1 point
-	Lizard-man and were attack damage ranges from 1 to 3 points
-	Dracula and Dragon attack damage ranges from 1 to 4 points

For the monsters who deal more than 1 point of damage, the amount of damage is randomized. Srand() and rand() were used to generate the randomness within the allowed range. Figure below shows the formula used to determine the monster’s damage.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/954a9886-df6b-4bf3-921f-8825995b1186)

While the algorithm used to determine the player’s, damage is different in a way that it is dependent on the weapon that the player carries. These weapons, known as one of the artifacts in the game, will give the player an advantage in certain scenarios. There are 3 known weapon artifacts in the game that the player can collect to gain an advantage in a battle against the monsters. The list below shows the weapon and its advantage:

-	Silver spear inflicts more damage onto the werewolf with 4 points
-	The diamond cross inflicts more damage onto Dracula with 5 points
-	The sword inflicts more damage onto Dragon with 5 points
  
An algorithm is used to check whether any of the weapon is carried by the player when fighting a monster. If the player has a weapon that is not specialized in killing that monster, the player will only inflict 3 points onto that monster. For example, player will only inflict 3 damage to a werewolf if the player only has a sword in its inventory. In the case the player does not have any weapon artifact when killing a monster, the player will only inflict 2 points of damage to that monster. This algorithm is shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/a7111970-3574-41fc-bf0f-d627328223b4)

Even if the player leaves the room after attacking the monster, the monster’s health will not reduce, and the player would still be able to come back to the room kill that monster. The amount of damage deducted from player and monster’s health in dependent on the amount of damage either of them inflict on each other. An example of the fighting message is shown in Figure below. Although it is possible that the player kills the monster first before the monster is able to reciprocate the attack. 

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/b101b6ea-378f-4d4a-87f3-f0989aa8514d)

For the artifacts that require killing the monster to get, an algorithm is used to prevent the player from picking up those artifacts if the monster guarding it is alive. When getting that artifact, a function is called to check for whether there is a monster guarding the artifact or not and to check whether that monster is alive or not. Figure below illustrates the function used for that task.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/da3a5aaf-be88-4ceb-b2eb-6acba27618f3)

# Health and Experience system

At the beginning of the game the player will have 12 health points. These 12 points can be deducted from the player if attacked by a monster. The amount of health points deducted from the player entirely relies on how many damages points the monster inflict which has been explained in the previous section. If the player kills a monster, they will be able to take the artifact that the monster is hiding and gain experience that is dependent on the room the player killed in the monster in. For example, if the player kills the zombie which is located in room 3, the player will gain 3 experience points and be able to get the silver spear artifact as shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/5146e12b-71d2-4664-b2e8-89934683f727)

If the player manages to get their hands on healing artifacts such as food, med-pack, and elixir, the player can consume one of them to increase back their health points. A player will not be allowed to consume a healing artifact if their health points are at max which is at 12 points. An algorithm will be used to check for the healing artifacts in the player’s inventory and use them according to the player’s command. A snippet of this algorithm’s code is shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/1b69d1a2-e242-40e4-a97b-62280e7d4072)

The player will also be informed of how much health has been restored as shown in the Figure below. A function is also used to correct the health points if it is more than the allowed 12 health points. Once the healing artifact is consumed, it will be removed from the current game session.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/d033d45e-0d51-4b6c-9b9f-75ffdcc2b421)

Although once the player’s health reaches less or equals to 0 health points, the game is over. Before the program asks for user input, the program will always first check the player’s health by calling a function that check whether the player has won the game or died. If the game returns 0 to the calling environment which is in the getCommand function, it indicates that the player has died. But if the function returns integer 2, it indicates that the player has obtained the golden chalice artifact and returned to the starting room which is the Adventurer’s Hut. A snippet of this function is shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/517e40a5-950b-4f4f-8d25-2416a62cab4d)

# Help command

When the player is unsure of what valid command to enter to the program, they can enter “help” when they program asks for user input. This command will show player examples of valid command they could enter into the program to execute an action in the game. Figure below illustrates what the help command does.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/edf4bd65-92e3-494f-b41c-f72b281c447d)

# Look command

When the player is unsure of what room they are in and what legal movements they could make, they can use the look command. The look command will let the player know what room they are in, if there is monster or not in the current room, and even if there is an artifact that the player could get in the room. The player will also be shown a list of legal movement the player could make in the current room they are in. As the rooms, monsters, and artifact info is stored in an array, three for loops were used to determine if there are any monster or artifact based on the room the player is in. This algorithm is demonstrated in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/29349bf3-45f9-4e29-bff3-8869891ba853)

Figure below illustrates an example of what the printing statements of the look command looks like.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/41e4c07c-3f35-4da4-b09d-b049f391ded0)

# Movement command

When the players want to move from one room to another, they will need to use the valid movement command such as north, south, west, and east. If the player makes an illegal movement in a room, they will be shown the list of valid movements they can make. A 2D array is used to store the valid movements the player is allowed to make in each room. Each 1D array in the 2D array is in the form of N, S, E W. The value of -1 is used to represent that the player is not allowed to make that movement. While the values that are not -1, represents the next room the player would be in if they make that movement. As shown in the Figure below, if the player is in room 1 and moves east, the player would be in room 2 next. 

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/26527a2a-75f1-4368-8cd5-1a76156567ef)

Figure below illustrates what the look movement look like when used and what happens if the player makes an invalid movement in a room.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/f5e16bf5-f84a-46b3-9448-f0556efc9833)

# Check inventory command

If the player wants to know what artifacts they are currently carrying, they can use the inventory command. A player is only allowed to carry a total of 3 items. An array that store data type C++ strings is used to store the items the player is carrying as depicted in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/13972971-be22-4bb6-9cea-e56221647e0b)

The way the algorithm works is that it will iterate through each position in the array to check if it is empty. If a string, which represents an artifact, occupies the position in the array, it will increase the counter’s value that is used to keep track the number of items in the array. This command will also print out what artifact is in the player’s inventory as shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/90579e9a-aca3-461e-9004-4fa2c0e485c6)

# Get command

If there is an artifact that the player wants to carry throughout the game that could benefit the player later on, the player will have to use the get command to store the artifact in the player’s inventory. The algorithm will first determine the number of artifacts that are in the player’s current inventory. If it is not full, it will then check for an empty position in the inventory array mentioned previously. Next it will check for if the artifact the player wants is in the current room or not. If it is, the artifact’s name string will be stored in the empty position in the player’s inventory. It will only store it if the artifact is not guarded by a monster or the monster guarding it is dead. After the artifact has been picked up, an array storing the location of the artifacts will be updated to integer -1 to let the program know that the artifact has been picked up. This algorithm is demonstrated in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/6ae2b767-ff1d-4d32-a25b-0d37ce1010d4)

The player will be alerted of what artifact they have picked up. However, if the player’s inventory is full, the player would need to drop an artifact from their inventory in order to be able to pick up another artifact. This is shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/93f4017c-968f-459d-a6d2-619334d1d936)

# Drop command

If a player wants to drop artifact, the player will need to use the drop command to free space from their inventory. The way the algorithm works is that it will first check if there are any artifacts in the player’s inventory to be dropped. Then it will iterate through the player’s inventory to check for the artifact that the player wants to drop. If the player does not have the item, they will be alerted. When the artifact is found in the player’s inventory, the artifact will be erased from the inventory array, making the position the artifact was in, unoccupied. This algorithm is shown in the Figure below. 

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/1450b0f2-7860-4ae8-b3be-0b3f02ade408)

Although it is important to note that once an artifact is dropped it will be gone from the current game session. This means the player must reassure themselves if the artifact will be useful or not later in the game before dropping it. Figure below demonstrates dropping of an artifact and checking the inventory to make sure the artifact is dropped. 

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/1f993b81-3bcf-4d63-9b63-542723fcc009)

# Unlock door command

There is one room the player has to access to have a chance at winning the game. That is room 9 which is named the Castle. This room is locked since the start of the game session. To unlock room 9, the player must obtain the copper key artifact by killing Dracula first. In addition, it is a must that the player be in room 6 to unlock room 9. The algorithm will first iterate through the inventory array to check for the presence of the copper key. If the copper key is present, it will then check for if the player is in room 6. Once these conditions are met, the array storing legal movements of each room will be updated accordingly. This algorithm is illustrated in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/cd0d803a-e817-46eb-a7cd-cf44e5b4e365)

After the copper key is used, it will disappear from the current game session. This is illustrated in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/24475c95-510c-415c-8abf-6b2afffac858)

# Printing summary

If the player exits mid game, dies, or even win the game, a summary will be printed of what the player has achieved in the game such as numbers of artifacts picked up and number of monsters killed. An example of the summary is shown in the Figure below, where a player has won the game.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/d1ee61d4-37f3-475b-b06d-5af74ad50cdc)

For printing the summary, the current player experience will be printed out by accessing the variable that keeps track of the player’s experience throughout the game. Then a for loop is used to check the monster HP array to check for which monster is already dead. After that, another for loop is used to check the artifact location array for -1 that shows that this particular has been picked up before by the player throughout the game. This algorithm is as shown in the Figure below.

![image](https://github.com/Arfan0612/Simple-Adventure-Game/assets/94776851/35c580b6-0955-4f8f-9faf-114b11998e2f)



































