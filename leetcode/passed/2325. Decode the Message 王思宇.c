char* decodeMessage(char* key, char* message) {
    char table[27]; // Store key and 26 letters' corresponding information
    bool duplicate = false;
    int k = 0;

    for (int i = 0; key[i]; i++) {
        if (key[i] == ' ') continue;
        duplicate = false;
        for (int j = 0; j <= i - 1; j++) {
            if (key[j] == key[i]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            table[k] = key[i];
            k++;
        }
    }
    table[26] = '\0';

    char* decoded_message = (char*)malloc((strlen(message) + 1)*sizeof(char)); // Allocate memory

    for (int i = 0; message[i]; i++) {
        if (message[i] == ' ') {
            decoded_message[i] = ' ';
            continue;
        }
        for (int j = 0; table[j]; j++) {
            if (message[i] == table[j]) {
                decoded_message[i] = 'a'+ j;
                break;
            }
        }
    }
    decoded_message[strlen(message)] = '\0';

    return decoded_message;
}
