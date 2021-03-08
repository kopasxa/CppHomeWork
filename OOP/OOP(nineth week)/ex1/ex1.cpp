#include <iostream>
#include "User.h"
#include "Student.h"

using namespace std;

int main() {
    User us1;
    Student st1;
    st1.createUser();
    /*us1.createUser();
    us1.createUser();*/
    us1.printUsers();
    us1.deleteUser(1);
    /*us1.createUser();*/

}
