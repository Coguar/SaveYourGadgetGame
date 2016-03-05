#ifndef __DEFINITIONS_H__
#pragma once

// TODO: use #pragma once
 //TODO: use constants instead of macro
const int DISPLAY_TIME_SPLASH_SCENE = 2;

const float TRANSITION_TIME = 0.5f;
const float SPAWN_FREQUENCY = 0.5f;
const float MAX_SPAWN_FREQUENCY = 0.2f;

const float  RIGHT_SCREEN_SPAWN_THRESHOLD = 0.90f;
const float  LEFT_SCREEN_SPAWN_THRESHOLD = 0.10f;

const float  MAX_RIGHT_SCREEN_SPAWN = 0.99f;
const float  MAX_LEFT_SCREEN_SPAWN = 0.01f;

const float  Y_POS_TO_SPAWN = 0.85f;

const float  MOVEMENT_SPEED = 0.01f;

const int ITEM_COLLISION_BITMASK = 0x000001;
const int WATER_COLLISION_BITMASK = 0x000002;

const float FONT_SIZE = 0.1f;

const float LEVEL_KOEFITSENT = 0.005f;


#endif // __DEFINITIONS_H__