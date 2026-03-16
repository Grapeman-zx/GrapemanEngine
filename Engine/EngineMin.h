#pragma once
#ifdef ENGINE_EXPORTS
#define GM_ENGINE __declspec(dllexport)
#else
#define GM_ENGINE __declspec(dllimport)
#endif
