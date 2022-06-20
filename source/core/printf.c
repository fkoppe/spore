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

#include "sprx/core/printf.h"
#include "sprx/core/sprintf.h"

#include <assert.h>
#include <stdio.h>

int spore_print(const char* const data_)
{
    assert(NULL != data_);

    return fputs(data_, stdout);
}

int spore_print_error(const char* const data_)
{
    assert(NULL != data_);

    return fputs(data_, stderr);
}

int spore_printf(const char* const format_, ...)
{
    assert(NULL != format_);

    char buffer[SPRX_SPRINTF_BUFFER_SIZE_MIN];

    va_list list;
    va_start(list, format_);
    const size_t len = spore_vsprintf(buffer, format_, list);
    va_end(list);

    char* const data = malloc(sizeof(char) * (len + 1));
    assert(NULL != data);

    va_start(list, format_);
    const int result = spore_vsprintf(data, format_, list);
    va_end(list);
    assert(result == len);

    data[len] = '\0';
    fputs(data, stdout);

    free(data);

    return result;
}

int spore_printf_error(const char* const format_, ...)
{
    assert(NULL != format_);

    char buffer[SPRX_SPRINTF_BUFFER_SIZE_MIN];

    va_list list;
    va_start(list, format_);
    const size_t len = spore_vsprintf(buffer, format_, list);
    va_end(list);

    char* const data = malloc(sizeof(char) * (len + 1));
    assert(NULL != data);

    va_start(list, format_);
    const int result = spore_vsprintf(data, format_, list);
    va_end(list);
    assert(result == len);

    data[len] = '\0';
    fputs(data, stderr);

    free(data);

    return result;
}

int spore_vprintf(const char* const format_, const va_list args_)
{
    assert(NULL != format_);

    char buffer[SPRX_SPRINTF_BUFFER_SIZE_MIN];

    const size_t len = spore_vsprintf(buffer, format_, args_);

    char* const data = malloc(sizeof(char) * (len + 1));
    assert(NULL != data);

    const int result = spore_vsprintf(data, format_, args_);
    assert(result == len);

    data[len] = '\0';
    fputs(data, stdout);

    free(data);

    return result;
}

int spore_vprintf_error(const char* const format_, const va_list args_)
{
    assert(NULL != format_);

    char buffer[SPRX_SPRINTF_BUFFER_SIZE_MIN];

    const size_t len = spore_vsprintf(buffer, format_, args_);

    char* const data = malloc(sizeof(char) * (len + 1));
    assert(NULL != data);

    const int result = spore_vsprintf(data, format_, args_);
    assert(result == len);

    data[len] = '\0';
    fputs(data, stderr);

    free(data);

    return result;
}
