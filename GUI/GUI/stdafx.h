// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#pragma once
#ifndef SCREENS_HPP_INCLUDED
#define SCREENS_HPP_INCLUDED

//Basic Screen Class
#include "cScreen.h"
#include "screenManager.h"

//Including each screen of application
#include "MainMenu.h"
#include "WaveDescription.h"
#include "WaveComplete.h"
#include "LevelComplete.h"
#include "WinnerPage.h"
#include "GameOverPage.h"
#include "BuySellPage.h"
#include "WaveRunningPage.h"


#include "path.h"
#include "GUI.h"
#include "BuySell.h"
#include "pathOverlays.h"
#include "Cursor.h"

#include <iostream>
#include <SFML/Config.hpp>
#endif // SCREENS_HPP_INCLUDED