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

#include "sprx/core/sprintf.h"

#define STB_SPRINTF_IMPLEMENTATION
#include "stb/stb_sprintf.h"

#include <assert.h>

int spore_sprintf(char* const buf_, const char* const format_, ...)
{
    assert(NULL != buf_);
    assert(NULL != format_);

    va_list args;
    va_start(args, format_);
    const int result = stbsp_vsprintf(buf_, format_, args);
    va_end(args);

    return result;
}

int spore_snprintf(char* const buf_, const int count_, const char* const format_, ...)
{
    assert(NULL != buf_);
    assert(NULL != format_);

    va_list args;
    va_start(args, format_);
    const int result = stbsp_vsnprintf(buf_, count_, format_, args);
    va_end(args);

    return result;
}

int spore_vsprintf(char* const buf_, const char* const format_, const va_list args_)
{
    assert(NULL != buf_);
    assert(NULL != format_);

    return stbsp_vsprintf(buf_, format_, args_);
}

int spore_vsnprintf(char* const buf_, const int count_, const char* const format_, const va_list args_)
{
    assert(NULL != buf_);
    assert(NULL != format_);

    return stbsp_vsnprintf(buf_, count_, format_, args_);
}

int spore_vsprintfcb(char* (*func_)(const char* buf, void* const arg, const int len), void* const arg_, char* const buf_, const char* const format_, const va_list args_)
{
    assert(NULL != func_);
    assert(NULL != arg_);
    assert(NULL != buf_);
    assert(NULL != format_);

    return stbsp_vsprintfcb(func_, arg_, buf_, format_, args_);
}
