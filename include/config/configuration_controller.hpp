#pragma once

#include "config/configuration.hpp"

// Default configuration file loaded into the EEPROM if no configuration was saved yet. Also used to reset the keypad and calibration
// structs that might get modified on a firmware update and have to be reset back to their default values then later on.
inline Configuration defaultConfig =
{
    .version = Configuration::getVersion(),
    .name = {'m', 'i', 'n', 'i', 'p', 'a', 'd' },
    .keys =
    {
        {
            .version = Key::getVersion(),
            .index = 0,
            .rapidTrigger = false,
            .continuousRapidTrigger = false,
            .rapidTriggerUpSensitivity = 50,
            .rapidTriggerDownSensitivity = 50,
            .lowerHysteresis = 250,
            .upperHysteresis = 300,
            .keyChar = 'z',
            .hidEnabled = false,
            .restPosition = 1800,
            .downPosition = 1100
        },
        {
            .version = Key::getVersion(),
            .index = 1,
            .rapidTrigger = false,
            .continuousRapidTrigger = false,
            .rapidTriggerUpSensitivity = 50,
            .rapidTriggerDownSensitivity = 50,
            .lowerHysteresis = 250,
            .upperHysteresis = 300,
            .keyChar = 'x',
            .hidEnabled = false,
            .restPosition = 1800,
            .downPosition = 1100
        },
#if KEYS == 3
        {
            .version = Key::getVersion(),
            .index = 2,
            .rapidTrigger = false,
            .continuousRapidTrigger = false,
            .rapidTriggerUpSensitivity = 50,
            .rapidTriggerDownSensitivity = 50,
            .lowerHysteresis = 250,
            .upperHysteresis = 300,
            .keyChar = 'c',
            .hidEnabled = false,
            .restPosition = 1800,
            .downPosition = 1100
        }
#endif
    }
};

inline class ConfigurationController
{
public:
    ConfigurationController(Configuration *defaultConfig) : config(*defaultConfig) {};

    void loadConfig();
    void saveConfig();

    Configuration config;
} ConfigController(&defaultConfig);
