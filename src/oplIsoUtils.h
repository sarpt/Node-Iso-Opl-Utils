// thin cpp wrapper exposing iso2opl getGameId
// native C++ addons study
// by sarpt

#ifndef __OPLISOUTILS_H__
#define __OPLISOUTILS_H__

#include <string>
#include <node.h>
#include "iso2opl.h"

extern "C" s64 GetGameID(const char *isofile, int isBigEndian, short closeOnEnd, char *GameID);

#endif
