#pragma once

// TODO: use #pragma once
 //TODO: use constants instead of macro

//timers
const int DISPLAY_TIME_SPLASH_SCENE = 2;
const float TRANSITION_TIME = 0.5f;
const float SPAWN_FREQUENCY = 0.5f;

//spawn positions
const float  RIGHT_SCREEN_SPAWN_THRESHOLD = 0.90f;
const float  LEFT_SCREEN_SPAWN_THRESHOLD = 0.10f;
const float  MAX_RIGHT_SCREEN_SPAWN = 0.99f;
const float  MAX_LEFT_SCREEN_SPAWN = 0.01f;
const float  Y_POS_TO_SPAWN = 0.85f;

//item speed
const float  MOVEMENT_SPEED = 0.01f;

//bitmasks
const int ITEM_COLLISION_BITMASK = 0x000001;
const int WATER_COLLISION_BITMASK = 0x000002;

//fonts size
const float FONT_SIZE = 0.1f;

//level raising
const int FREQUENCY_RAISING = 10;
const float LEVEL_KOEFITSENT = 0.001f;
const int LAPTOP_SPAWN_SCORE = 100;
const float MAX_SPAWN_FREQUENCY = 0.2f;