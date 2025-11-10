#pragma once

#include <cfloat>
#include <cstdint>
#include <cstdlib>

#include "Context.hpp"
#include "Macros.hpp"
#include "Types.hpp"
#include "Limits.hpp"
#include "Cast.hpp"
#include "Bit.hpp"

#include "buffer.hpp"
#include "str8.hpp"

#if OPERATING_SYSTEM == OPERATING_SYSTEM_WINDOWS
	#include <Windows.h>
#endif