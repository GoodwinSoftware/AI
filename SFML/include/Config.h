#ifndef CONFIG_H
#define CONFIG_H

// Global
#define WINDOW_NAME "Ant Simulator"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500
#define UPDATE_INTERVAL 0.01f
#define ANTIALIASING_LEVEL 8

#define PATHFINDER_GRID_SIZE 30

// Image Locations
#define ANT_IMAGE_NAME "images/Ant.png"
#define ANTEATER_IMAGE_NAME "images/Anteater.png"

enum GameObjectType 
{
	UnassignedGO = 0,
	AntGO,
	CharacterGO,
	ObsticleGO,
	FoodGO,
	AntEaterGO,
};

#endif