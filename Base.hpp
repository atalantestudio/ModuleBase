#pragma once

#include <cfloat>
#include <cstdint>

#include "Context.hpp"
#include "Macros.hpp"
#include "Types.hpp"
#include "Limits.hpp"
#include "Cast.hpp"
#include "Bit.hpp"

#if OPERATING_SYSTEM == OPERATING_SYSTEM_WINDOWS
	#include <Windows.h>
#endif