#include "JenkinsHash.h"

char to_lower(char c) {
    return  (c | 32);
}

uint32_t hash(std::string key) {
    
    int length = 0;
    int i = 0;
    while (key[i] != 0){
        length++;
        i++;
    }

    uint32_t hash = 0;
    for (int i = 0; i < length; i++){
        hash += to_lower(key[i]);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

std::string uint_to_hex_string(uint32_t number) {
    std::string hex_alphabet = "0123456789abcdef";
    std::string hex_string = "";

    uint32_t dividend = number;

    int remainder = 0;
    int result = -1;
    int index = 7;

    while (result != 0){
        result = dividend / 16;
        remainder = dividend % 16;

        hex_string.insert(hex_string.begin(), hex_alphabet[remainder]);

        dividend = result;
    }


    return hex_string;
    
}

uint32_t jenkins::get_hash_uint32(std::string key){
    return hash(key);
}


std::string jenkins::get_hash_string(std::string key){

    uint32_t hashed = hash(key);
    return uint_to_hex_string(hashed);
};
