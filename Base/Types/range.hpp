// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	template<typename OffsetType, typename CountType>
	struct range {
		OffsetType offset;
		CountType count;
	};
}