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

#ifndef ___SPRX___VECTOR_H
#define ___SPRX___VECTOR_H

#include "sprx/core/essentials.h"

#define SPRX_VECTOR_AT(vector, index, type) \
((type*)spore_vector_at(vector, index))

#define SPRX_VECTOR_FRONT(vector, type) \
((type*)spore_vector_front(vector))

#define SPRX_VECTOR_BACK(vector, type) \
((type*)spore_vector_back(vector))

#define SPRX_VECTOR_DATA(vector, type) \
((type*)spore_vector_data(vector))

void* spore_vector_new(const size_t elements_size);
void* spore_vector_new_c(const size_t elements_size, const size_t capacity);
void* spore_vector_new_s(const size_t elements_size, const size_t capacity, const size_t size);
void spore_vector_delete(void* const vector);

void* spore_vector_at(void* const vector, const size_t index);
void* spore_vector_front(void* const vector);
void* spore_vector_back(void* const vector);
void* spore_vector_data(void* const vector);

void spore_vector_push_front(void* const vector, void* const element);
void spore_vector_push_back(void* const vector, void* const element);
void spore_vector_pop_front(void* const vector);
void spore_vector_pop_back(void* const vector);

void spore_vector_insert(void* const vector, const size_t index, void* const element);
void spore_vector_erase(void* const vector, const size_t index);

void spore_vector_emplace_front(void* const vector, void(* const func)(void* const dest, void* const arg), void* const arg);
void spore_vector_emplace_back(void* const vector, void(* const func)(void* const dest, void* const arg), void* const arg);
void spore_vector_emplace(void* const vector, const size_t index, void(* const func)(void* const dest, void* const arg), void* const arg);

size_t spore_vector_capacity(void* const vector);
void spore_vector_reserve(void* const vector, const size_t capacity);
void spore_vector_shrink_to_fit(void* const vector);

size_t spore_vector_size(void* const vector);
void spore_vector_resize(void* const vector, const size_t size);
void spore_vector_clear(void* const vector);

#endif // ___SPRX___VECTOR_H
