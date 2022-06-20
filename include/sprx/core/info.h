/************************************************************************************
*                                                                                   *
*   spore - https://github.com/fkoppe/spore                                         *
*   ************************************************************************        *
*                                                                                   *
*   Copyright (C) 2022 Felix Koppe <fkoppe@web.de>                                  *
*                                                                                   *
*   This program is free software: you can redistribute it and/or modify            *
*   it under the terms of the GNU Affero General Public License as published        *
*   by the Free Software Foundation, either version 3 of the License, or            *
*   (at your option) any later version.                                             *
*                                                                                   *
*   This program is distributed in the hope that it will be useful,                 *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   *
*   GNU Affero General Public License for more details.                             *
*                                                                                   *
*   You should have received a copy of the GNU Affero General Public License        *
*   along with this program.  If not, see <https://www.gnu.org/licenses/>.          *
*                                                                                   *
************************************************************************************/

#ifndef ___SPRX___INFO_H
#define ___SPRX___INFO_H

#include "sprx/core/essentials.h"

#define SPRX_VERSION uint32_t

#define SPRX_VERSION_MAKE(variant, major, minor, patch) \
((((uint32_t)(variant)) << 29) | (((uint32_t)(major)) << 22) | (((uint32_t)(minor)) << 12) | ((uint32_t)(patch)))

#define SPRX_VERSION_VARIANT(version) \
((uint32_t)(version) >> 29)

#define SPRX_VERSION_MAJOR(version) \
(((uint32_t)(version) >> 22) & 0x7FU)

#define SPRX_VERSION_MINOR(version) \
(((uint32_t)(version) >> 12) & 0x3FFU)

#define SPRX_VERSION_PATCH(version) \
((uint32_t)(version) & 0xFFFU)

static const char* const SPRX_INFO_LIBRARY_NAME = "spore";
static const SPRX_VERSION SPRX_INFO_LIBRARY_VERSION = SPRX_VERSION_MAKE(0, 0, 1, 0);

#endif // ___SPRX___INFO_H
