/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2021 PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "GS/GSLocalMemory.h"

class GSDirtyRect
{
public:
	GSVector4i r;
	u32 psm;
	u32 bw;

	GSDirtyRect();
	GSDirtyRect(GSVector4i& r, u32 psm, u32 bw);
	GSVector4i GetDirtyRect(GIFRegTEX0 TEX0) const;
};

class GSDirtyRectList : public std::vector<GSDirtyRect>
{
public:
	GSDirtyRectList() {}
	GSVector4i GetTotalRect(GIFRegTEX0 TEX0, const GSVector2i& size) const;
	GSVector4i GetDirtyRect(size_t index, GIFRegTEX0 TEX0, const GSVector4i& clamp) const;
};
