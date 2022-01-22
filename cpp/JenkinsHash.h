#pragma once
#include <iostream>
#include <string>

namespace jenkins {
    /**
     * @brief Return the hash as a string in hex.
     * 
     * @param key Key to hash
     * @return std::string the hashed key as a string in hex
     */
    std::string get_hash_string(std::string key);


    /**
     * @brief Get the hash as a uint32_t
     * 
     * @param key Key to hash
     * @return uint32_t hash
     */
    uint32_t get_hash_uint32(std::string key);
}