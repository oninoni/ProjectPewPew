#pragma once

#include "targetver.h"

using namespace std;

// External STD libs
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <sstream>  
#include <string.h>
#include <vector>
#include <Windows.h>
#include <filesystem>
#include <unordered_map>
#define _USE_MATH_DEFINES
#include <math.h>

// Memory Leak Detector
#ifdef _DEBUG
#include <vld.h>
#endif

// External GL
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Other
#include "TypeDefs.h"
#include "lodePNG.h"

// Math
#include "vec2.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Location.h"

// OpenGL
class VAO;
#include "GLEnums.h"
#include "Shader.h"
#include "VAO.h"
#include "Texture.h"
#include "TextureData.h"
#include "TextureMapItem.h"
#include "TextureMap.h"
#include "View.h"

// Game Logic    
class Game;
class Player;
class Gun;
#include "Tile.h"
#include "BGGrid.h"
#include "FGGrid.h"
#include "RayCaster.h"
#include "InputManager.h"
#include "Cursor.h"
#include "Player.h"
#include "Gun.h"
#include "Entity.h"
#include "Game.h"
#include "HUD.h"