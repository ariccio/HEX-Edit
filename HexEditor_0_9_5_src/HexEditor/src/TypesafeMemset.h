/*
this file is part of HexEdit Plugin for Notepad++
Copyright (C)2006 Jens Lorenz <jens.plugin.npp@gmx.de>
             2015 Alexander Riccio <alexander@riccio.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#pragma once

#ifndef TYPESAFE_MEMSET_H_INCLUDED
#define TYPESAFE_MEMSET_H_INCLUDED


#include <type_traits>
#include <cstring>

namespace templated_helpers {
	template<typename type_struct_to_memset>
	inline void memset_zero_struct( _Pre_satisfies_( the_struct != NULL ) type_struct_to_memset* const the_struct ) {
		static_assert( std::is_pod<type_struct_to_memset>::value, "can't memset a non-pod struct!" );
		static_assert( !std::is_polymorphic<type_struct_to_memset>::value, "can't memset a polymorphic type!" );
		static_assert( std::is_standard_layout<type_struct_to_memset>::value, "can't memset a non-standard layout struct!" );
		memset( the_struct, 0, sizeof( *the_struct ) );
		}

	}
#endif
