#pragma once

#include "key.hpp"

// Configuration for the whole firmware, containing the name of the keypad and it's configurations.
struct Configuration
{
    // Version of the configuration, used to check whether the struct layout in the EEPROM is up-to-date.
    uint32_t version;

    // The name of the keypad, used to distinguish it from others.
    char name[128];

    // A list of all key configurations. (rapid trigger, hysteresis, calibration, ...)
    Key keys[KEYS];

    // Returns the version constant of the latest Configuration layout.
    static uint32_t getVersion()
    {
        // Version of the configuration in the format YYMMDDhhmm (e.g. 2301030040 for 12:44am on the 3rd january 2023)
        int64_t version = 2303171835;

        // To reset the configuration if the user switches from a 2-key firmware to a 3-key, mutate the version.
#if KEYS == 3
        version = -version;
#endif

        return version;
    }
};
