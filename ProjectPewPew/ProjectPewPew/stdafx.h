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

// External GL   
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Other
#include "TypeDefs.h"
#include "KeyManager.h"

// OpenGL
#include "GLEnums.h"
#include "Shader.h"
#include "VAO.h"

// Game Logic

#include "Tile.h"

#include "BGGrid.h"
#include "FGGrid.h"
#include "Player.h"
#include "Game.h"