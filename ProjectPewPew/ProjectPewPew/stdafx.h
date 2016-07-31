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

// External GL   
#include "GL/glew.h"
#include "GLFW/glfw3.h"

// Other
#include "TypeDefs.h"
#include "lodePNG.h"

// OpenGL
#include "GLEnums.h"
#include "Shader.h"
#include "Texture.h"

// Game Logic
#include "BGGrid.h"
#include "FGGrid.h"
#include "Player.h"
#include "Game.h"