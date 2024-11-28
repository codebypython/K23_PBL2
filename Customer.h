#define CUSTOMER_H

#include "Account.h"
#include <fstream>
#include <string>
using namespace std;

class Customer : public Account {
public:
    Customer(string user, string pass, string n, string phone);
};
