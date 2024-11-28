#define MANAGER_H

#include "Account.h"
#include <fstream>
#include <string>

class Manager : public Account {
public:
    Manager(string user, string pass, string n, string phone);
};
