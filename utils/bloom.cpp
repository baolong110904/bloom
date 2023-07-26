int hash1(string str) {
    long long int hash = 0;
    for (int i = 0; i < str.size(); i++) {
        hash += (int) str[i];
        hash = hash % MAX_SIZE;
    }
    return hash;
}

int hash2(string str) {
    long long int hash = 1;
    for (int i = 0; i < str.size(); i++) {
        hash += pow(19, i) * str[i];
        hash = hash % MAX_SIZE;
    }
    return hash % MAX_SIZE;
}

int hash3(string str) {
    long long int hash = 7;
    for (int i = 0; i < str.size(); i++) {
        hash = (hash * 31 + str[i]) % MAX_SIZE;
    }
    return hash % MAX_SIZE;
}

int hash4(string str) {
    long long int hash = 3;
    int p = 7;
    for (int i = 0; i < str.size(); i++) {
        hash += hash * 7 + str[0] * pow(p, i);
        hash = hash % MAX_SIZE;
    }
    return hash;
}

bool lookupBloom(bool* bitArray, string str) {
    int pos1 = hash1(str), pos2 = hash2(str), pos3 = hash3(str), pos4 = hash4(str);
    return (bitArray[pos1] && bitArray[pos2] && bitArray[pos3] && bitArray[pos4]);
}

void insertBloom(bool* bitArray, string str) {
    int pos1 = hash1(str), pos2 = hash2(str), pos3 = hash3(str), pos4 = hash4(str);
    bitArray[pos1] = bitArray[pos2] = bitArray[pos3] = bitArray[pos4] = true;
}