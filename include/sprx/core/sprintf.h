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

#ifndef ___SPRX___SPRINTF_H
#define ___SPRX___SPRINTF_H

#include "sprx/core/essentials.h"

#include <stdarg.h>

#define SPRX_SPRINTF_BUFFER_SIZE_MIN 512

int spore_sprintf(char* const buf, const char* const format, ...);
int spore_snprintf(char* const buf, const int count, const char* const format, ...);
int spore_vsprintf(char* const buf, const char* const format, const va_list args);
int spore_vsnprintf(char* const buf, const int count, const char* const format, const va_list args);
int spore_vsprintfcb(char* (*func)(const char* buf, void* const arg, const int len), void* const arg, char* const buf, const char* const format, const va_list args);

#endif // ___SPRX___SPRINTF_H
