#ifndef ITEM_H
#define ITEM_H
using namespace std;
class item {
 public:
  char* getDescription();
  item(char*);
 private:
  char* description;
};
#endif
