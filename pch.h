#ifndef PCH_H
#define PCH_H
#ifndef COUT
#define COUT std::cout
#endif
#ifndef WCOUT
#define WCOUT std::wcout
#endif

#include <windows.h>
#include <vector>
#include <ranges>
#include <map>

#include "SDK.hpp"
#include "MinHook/MinHook.h"
#include "Global.hpp"

#include "UnrealContainers.hpp"
#include "PropertyFixup.hpp"
#include "NameCollisions.inl"

#endif //PCH_H