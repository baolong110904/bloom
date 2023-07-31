bool* buildUsernameBloomBit() {
    bool* bitArray = new bool [MAX_SIZE];
    for (int i=0; i<MAX_SIZE; i++) {
        bitArray[i] = false;
    }
    ifstream ifs("data/Account.txt");
    while (!ifs.eof()) {
        string username;
        ifs >> username;
        insertBloom(bitArray, username);
        ifs >> username; // Skip password
    }
    ifs.close();
    return bitArray;
}

bool* buildWeakPassBloomBit() {
    bool* bitArray = new bool [MAX_SIZE];
    for (int i=0; i<MAX_SIZE; i++) {
        bitArray[i] = false;
    }
    ifstream ifs("data/WeakPass.txt");
    while (!ifs.eof()) {
        string weakPass;
        ifs >> weakPass;
        insertBloom(bitArray, weakPass);
    }
    ifs.close();
    return bitArray;
}

struct User {
    string username = "";
    string password = "";
};

bool signup(User user, bool* usernameBloomBit, bool* weakPassBloomBit) {
    if (usernameValidate(user.username, usernameBloomBit) && passwordValidate(user.password, user.username, weakPassBloomBit)) {
        ofstream ofs("data/Account.txt", ios::app);
        if (!ofs.is_open()) {
            cout << "Something went wrong";
            return false;
        }

        insertBloom(usernameBloomBit, user.username);
        ofs << user.username << " " << user.password << endl;
        ofs.close();
        return true;
    } else {
        return false;
    }
}

bool multiSignup(User user, bool* usernameBloomBit, bool* weakPassBloomBit) {
    if (usernameValidate(user.username, usernameBloomBit) && passwordValidate(user.password, user.username, weakPassBloomBit)) {
        ofstream ofs("data/Account.txt", ios::app);
        if (!ofs.is_open()) {
            cout << "Something went wrong";
            return false;
        }

        // Save to Account.txt
        insertBloom(usernameBloomBit, user.username);
        ofs << user.username << " " << user.password << endl;
        ofs.close();
        return true;
    } else {
        // Save to Fail.txt
        ofstream ofs("data/Fail.txt", ios::app);
        if (!ofs.is_open()) {
            cout << "Something went wrong";
        }
        ofs << user.username << " " << user.password << endl;
        ofs.close();
        return false;
    }
}

bool login(User user, bool* usernameBloomBit) {
    if (!lookupBloom(usernameBloomBit, user.username)) {
        cout << "Account does not exist";
        return false;
    }
    
    ifstream ifs("data/Account.txt");
    if (!ifs.is_open()) {
        cout << "Something went wrong";
        return false;
    }
    while (!ifs.eof()) {
        string username, password;
        ifs >> username >> password;
        if (user.username == username) {
            if (user.password == password) {
                return true;
            } else {
                cout << "Wrong password";
                return false;
            }
        }
    }
    ifs.close();
}

bool changePass(string token, string newPassword, bool* weakPassBloomBit) {
    if (!passwordValidate(newPassword, token, weakPassBloomBit)) {
        return false;
    }

    // Get & change data
    ifstream ifs("data/Account.txt");
    if (!ifs.is_open()) {
        cout << "Something went wrong";
        return false;
    }
    vector <User> users;
    while (true) {
        User user;
        ifs >> user.username >> user.password;
        if (ifs.eof()) {
            break;
        }
        users.push_back(user);
        if (users.back().username == token) {
            users.back().password = newPassword;
        }
    }
    ifs.close();

    // Save back
    ofstream ofs("data/Account.txt");
    for (int i=0; i<users.size(); i++) {
        ofs << users.at(i).username << " " << users.at(i).password << endl;
    }
    ofs.close();

    return true;
}