#include "item.h"
using namespace std;
item::item(char* newDescription) {
  description = newDescription;
}
char* item::getDescription() {
  return description;
}
