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
    cout << "Enter number of users" << endl;
    cout << "Enter your username and password" << endl;
    cout << "- Username must 6-9 characters, not contain space" << endl;
    cout << "- Password must 11-19 characters, not contain space, include uppercase, lowercase, numbers and special characters" << endl;
    cout << endl << "Type /back to go back" << endl;
    
    cout << "--------------------" << endl;
    string n;
    while (true) {
        cout << "Enter number of users (< 100): ";
        cin >> n;
        cin.ignore();
        if (n == "/back") {
            page = "Main menu";
            return;
        }
        if (n.length() < 3 && atoi(n.c_str())) {
            break;
        }
        cout << "Invalid number" << endl;
    }
    User users[stoi(n)];
    for (int idx = 0; idx < stoi(n); idx++) {
        cout << "--------" << endl;
        cout << "User " << idx + 1 << ":" << endl;
        cout << "Enter your username: ";
        getline(cin, users[idx].username);
        if (users[idx].username == "/back") {
            page = "Main menu";
            return;
        }
        cout << "Enter your password: ";
        getline(cin, users[idx].password);
        if (users[idx].password == "/back") {
            page = "Main menu";
            return;
        }
    }
    cout << "--------------------" << endl;
    for (int idx = 0; idx < stoi(n); idx++) {
        cout << "User " << idx + 1 << " ";
        if (signup(users[idx], usernameBloomBit, weakPassBloomBit)) {
            cout << "REGISTER SUCCESSFULLY" << endl;
        }
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