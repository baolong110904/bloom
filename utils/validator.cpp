bool usernameValidate(string username, bool* usernameBloomBit) {
    if (username.length() <= 5 || username.length() >= 10) {
        cout << "Username must be 6-9 characters in length" << endl;
        return false;
    }
    if (username.find(' ') != string::npos) {
        cout << "Username must not contain space" << endl;
        return false;
    }
    if (lookupBloom(usernameBloomBit, username)) {
        cout << "Username is already taken" << endl;
        return false;
    }
    return true;
}

bool passwordValidate(string password, bool* weakPassBloomBit) {
    if (password.length() <= 10 || password.length() >= 20) {
        cout << "Password must be 11-19 characters in length" << endl;
        return false;
    }
    if (password.find(' ') != string::npos) {
        cout << "Password must not contain space" << endl;
        return false;
    }
    bool up = 0, low = 0, num = 0, spec = 0;
    for (int i=0; i<password.length(); i++) {
        if ('A' <= password[i] && password[i] <= 'Z') {
            up = true;
        } else if ('a' <= password[i] && password[i] <= 'z') {
            low = true;
        } else if ('0' <= password[i] && password[i] <= '9') {
            num = true;
        } else {
            spec = true;
        }
    }
    if (!(up && low && num && spec)) {
        cout << "Password must include uppercase, lowercase, numbers and special characters" << endl;
        return false;
    }
    if (lookupBloom(weakPassBloomBit, password)) {
        cout << "Weak password" << endl;
        return false;
    }
    return true;
}