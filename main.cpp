#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

#include "utils/bloom.cpp"
#include "utils/validator.cpp"
#include "utils/auth.cpp"
#include "utils/pages.cpp"

int main() {
    bool* usernameBloomBit = buildUsernameBloomBit();
    bool* weakPassBloomBit = buildWeakPassBloomBit();

    string token = "";
    string page = "Main menu";
    while (true) {
        system("cls");
        if (page == "Main menu") {
            menuPage(page);
        } else if (page == "Registration") {
            registrationPage(page, usernameBloomBit, weakPassBloomBit);
        } else if (page == "Multiple registration") {
            multipleRegistrationPage(page, usernameBloomBit, weakPassBloomBit);
        } else if (page == "Log in") {
            loginPage(page, token, usernameBloomBit);
        } else if (page == "Change password") {
            changePasswordPage(page, token, weakPassBloomBit);
        } else if (page == "Quit") {
            break;
        }
    }
    delete [] usernameBloomBit;
    delete [] weakPassBloomBit;
    return 0;
}