#include <iostream>
#include "room.h"
#include <map>
#include <cstring>
#include <vector>

using namespace std;

room::room(char* newDescription) {
  description = newDescription;
}
char* room::getDescription() {
  return description;
}
void room::setExit(char* direction, room* neighbor) {
  exits[direction] = neighbor;
}
void room::getExitString() {
  for (map<char*,room*>::iterator it = exits.begin(); it != exits.end(); it ++) {
    cout << it->first << ' ';
  }
  cout << endl;
}
room* room::getExit(char* direction) {
  for(map<char*,room*>::iterator it = exits.begin(); it != exits.end(); it++) {
    if (strcmp(direction, it->first) == 0) {
      return it->second;
      break;
      }
  }
  return NULL;
}
void room::setItem(item* newItem) {
  items.push_back(newItem);
}
char* room::getRoomItems() {
  for (vector<item*>::iterator it = items.begin(); it != items.end(); it++) {
    cout << (*it)->getDescription() << endl;
  }
}
item* room::removeItems(char* description) {
  for(vector<item*>::iterator it = items.begin(); it != items.end(); it++) {
    if (strcmp(description, (*it)->getDescription()) == 0) {
      items.erase(it);
      return *it;
      break;
    }
  }
}
