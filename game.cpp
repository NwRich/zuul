/*Nicholas Rich

 */
#include <iostream>
#include<cstring>
#include "room.h"
#include "item.h"
#include <vector>
using namespace std;
void goRoom(room* &currentRoom);
void getHelp();
void getInventory(vector<item*> &inventory);
void pickupItem(vector<item*> &inventory, room* &currentRoom);
void dropItem(vector<item*> &inventory, room* &currentRoom);
int main() {
  room* bedroom = new room("bedroom");
  room* bonusroom = new room("Your bonus room where all of the rooms are connected");
  room* bonusroom1 = new room("you have a really big bonus room");
  room* bathroom = new room("Your bathroom is pearly white and clean");
  room* brothersroom = new room("Your brother is already awake and yells at you to get out of his room");
  room* parentsroom = new room("Your parents woke up 30 minutes ago and there room is already empty");
  room* sistersroom = new room("Your sister is still asleep");
  room* downstairs = new room("You walk downstairs");
  room* desk = new room("this is where you did last nights homework");
  room* livingroom = new room("your parents are watching tv in the living room");
  room* laundryroom = new room("All of your clean clothes are in the laundry room");
  room* kitchen = new room("Your lunch that you made last knight is on the kitchen table");
  room* frontdoor = new room("You are standing infront of your door");
  room* busStop = new room("you are waiting at the bus stop. Did you forget anything?");
  room* school = new room("you arrive at school");

  room* currentRoom = bedroom;

  //item code example
  item* backpack = new item("backpack");
  item* toothbrush = new item("toothbrush");
  item* lunch = new item("lunch");
  item* homework = new item("homework");
  item* clothes = new item("clothes");
  
  bedroom->setExit("north", bonusroom);

  bonusroom->setExit("south",bedroom);
  bonusroom->setExit("west",bonusroom1);
  bonusroom->setItem(backpack);

  bathroom->setExit("west", bonusroom);
  bathroom->setItem(toothbrush);

  brothersroom->setExit("south", bonusroom);

  bonusroom1->setExit("east", bonusroom);
  bonusroom1->setExit("south", sistersroom);
  bonusroom1->setExit("west", downstairs);
  bonusroom1->setExit("north",parentsroom);

  parentsroom->setExit("south",bonusroom1);

  sistersroom->setExit("north",bonusroom1);

  downstairs->setExit("east", bonusroom1);
  downstairs->setExit("south", desk);
  downstairs->setExit("west", livingroom);

  desk->setExit("north", downstairs);
  desk->setItem(homework);

  livingroom->setExit("east", downstairs);
  livingroom->setExit("south", laundryroom);
  livingroom->setExit("north", kitchen);
  livingroom->setExit("west", frontdoor);

  kitchen->setExit("south", livingroom);
  kitchen->setItem(lunch);

  laundryroom->setExit("north", livingroom);
  laundryroom->setItem(clothes);

  frontdoor->setExit("east", livingroom);
  frontdoor->setExit("west", busStop);

  busStop->setExit("east", frontdoor);
  busStop->setExit("west", school);

  vector<item*> inventory;
  bool playing = true;
  char* fInput = new char[80];
  cout << "Welcome to this marvelous adventure" << endl;
  cout << "the oal is to wakeup and get to school on time" << endl;
  cout << "your commands are 'go', 'help', 'inventory', 'pickup', 'drop', and 'quit'" << endl;
  cout << "You just woke up in your bedroom" << endl;
  currentRoom->getExitString();
  while (playing == true) {
    cin >> fInput;
    cin.ignore();
    if (strcmp(fInput, "go") == 0) {
      goRoom(currentRoom);
      if (currentRoom == school) {
	cout << "You got to school on time!" << endl;
	return 0;
      }
    }
    if (strcmp(fInput, "quit") == 0) {
      cout << "leaving already you big baby?" << endl;
      return 0;
    }
    if (strcmp(fInput, "help") == 0) {
      getHelp();
    }
    if (strcmp(fInput, "inventory") == 0) {
      getInventory(inventory);
    }
    if(strcmp(fInput, "pickup") == 0) {
      pickupItem(inventory,currentRoom);
    }
    if (strcmp(fInput, "drop") == 0) {
      dropItem(inventory, currentRoom);
    }
  }
  return 0;
}
void goRoom(room* &currentRoom) {
  char* direction = new char[64];
  cin >> direction;
  cin.ignore();
  room* nextRoom = currentRoom->getExit(direction);
  if (nextRoom == NULL) {
    cout << "There is no exit that way dummy!" << endl;
  }
  else {
    currentRoom = nextRoom;
    cout << currentRoom->getDescription() << endl;
    currentRoom->getExitString();
    currentRoom->getRoomItems();
  }
}
void getHelp() {
  cout << "You need help, you bum! Figure it out on your own!" << endl;
}
void getInventory(vector<item*> &inventory) {
  for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    cout << (*it)->getDescription() << endl;
  }
}
void pickupItem(vector<item*> &inventory, room* &currentRoom) {
  char* input = new char[80];
  cin >> input;
  cin.ignore();
  inventory.push_back(currentRoom->removeItems(input));
}

void dropItem(vector<item*> &inventory, room* &currentRoom) {
  char* input = new char[80];
  cin >> input;
  cin.ignore();
  for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
    if (strcmp(input, (*it)->getDescription()) == 0) {
      cout << (*it)->getDescription() << endl;
      inventory.erase(it);
      currentRoom->setItem(*it);
      break;
    }   
  }
}
# zuul
# zuul
