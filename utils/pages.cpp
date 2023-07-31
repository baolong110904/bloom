void menuPage(string &page) {
    cout << "MENU" << endl;
    cout << "--------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Multiple Registration" << endl;
    cout << "3. Log in" << endl;
    cout << "4. Quit" << endl;

    cout << "--------------------" << endl;
    string choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == "1") {
            page = "Registration";
            break;
        } else if (choice == "2") {
            page = "Multiple registration";
            break;
        } else if (choice == "3") {
            page = "Log in";
            break;
        } else if (choice == "4") {
            page = "Quit";
            break;
        } else {
            cout << "Invalid option" << endl;
        }
    }
}

void registrationPage(string &page, bool* usernameBloomBit, bool* weakPassBloomBit) {
    cout << "REGISTRATION" << endl;
    cout << "--------------------" << endl;
    cout << "Enter your username and password" << endl;
    cout << "- Username must 6-9 characters, not contain space" << endl;
    cout << "- Password must 11-19 characters, not contain space, include uppercase, lowercase, numbers and special characters" << endl;
    cout << endl << "Type /back to go back" << endl;

    cout << "--------------------" << endl;

    User user;
    cout << "Enter your username: ";
    getline(cin, user.username);
    if (user.username == "/back") {
        page = "Main menu";
        return;
    }
    cout << "Enter your password: ";
    getline(cin, user.password);
    if (user.password == "/back") {
        page = "Main menu";
        return;
    }

    if (signup(user, usernameBloomBit, weakPassBloomBit)) {
        cout << "--------------------" << endl;
        cout << "REGISTER SUCCESSFULLY";
        page = "Main menu";
    };
    char pause = getch();
}

void multipleRegistrationPage(string &page, bool* usernameBloomBit, bool* weakPassBloomBit) {
    cout << "MULTIPLE REGISTRATION" << endl;
    cout << "--------------------" << endl;

    cout << endl << "Reading SignUp.txt ..." << endl;

    ifstream ifs("data/SignUp.txt");
    if (ifs.is_open()) {
        // Read file
        vector <User> users;
        while (!ifs.eof()) {
            User newUser;
            ifs >> newUser.username >> newUser.password;
            users.push_back(newUser);
        }

        // Sign up and show result
        cout << "--------------------" << endl;
        if (users.size() != 0) {
            for (int idx = 0; idx < users.size(); idx++) {
                cout << "User " << idx + 1 << " ";
                if (multiSignup(users.at(idx), usernameBloomBit, weakPassBloomBit)) {
                    cout << "REGISTER SUCCESSFULLY" << endl;
                }
            }
        } else {
            cout << "No user found at data/SignUp.txt";
        }
    } else {
        cout << "Cannot open file, please check data/SignUp.txt";
    }
    char pause = getch();
    page = "Main menu";
}

void loginPage(string &page, string &token, bool* usernameBloomBit) {
    cout << "LOG IN" << endl;
    cout << "--------------------" << endl;
    cout << "Enter your username and password" << endl;
    cout << endl << "Type /back to go back" << endl;
    
    cout << "--------------------" << endl;
    User user;
    cout << "Enter your username: ";
    getline(cin, user.username);
    if (user.username == "/back") {
        page = "Main menu";
        return;
    }
    cout << "Enter your password: ";
    getline(cin, user.password);
    if (user.password == "/back") {
        page = "Main menu";
        return;
    }

    if (login(user, usernameBloomBit)) {
        cout << "LOG IN SUCCESSFULLY";
        token = user.username;
        page = "Change password";
    }
    char pause = getch();
}

void changePasswordPage(string &page, string token, bool* weakPassBloomBit) {
    cout << "CHANGE PASSWORD" << endl;
    cout << "--------------------" << endl;
    cout << "Enter your new password" << endl;
    cout << "- Username must 6-9 characters, not contain space" << endl;
    cout << "- Password must 11-19 characters, not contain space, include uppercase, lowercase, numbers and special characters" << endl;
    cout << endl << "Type /back to go back" << endl;
    
    cout << "--------------------" << endl;
    string newPassword;
    cout << "Enter new password: ";
    getline(cin, newPassword);
    if (newPassword == "/back") {
        page = "Main menu";
        return;
    }

    if (changePass(token, newPassword, weakPassBloomBit)) {
        cout << "CHANGE PASSWORD SUCCESSFULLY";
        page = "Main menu";
    }
    char pause = getch();
}