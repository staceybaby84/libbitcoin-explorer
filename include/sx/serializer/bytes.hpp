/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BYTES_HPP
#define BYTES_HPP

#include <array>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <bitcoin/bitcoin.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace sx {
namespace serializer {

/**
 * Serialization helper to convert between hex string and data_chunk.
 */
class bytes
{
public:

    /**
     * Constructor.
     */
    bytes() 
        : value_() {}

    /**
     * Initialization constructor.
     * 
     * @param[in]  hex  The value to initialize with.
     */
    bytes(const std::string& hex)
    {
        std::stringstream(hex) >> *this;
    }

    /**
     * Initialization constructor.
     * 
     * @param[in]  value  The value to initialize with.
     */
    bytes(const bc::data_chunk& value)
        : value_(value.begin(), value.end()) {}

    /**
     * Initialization constructor.
     * 
     * @param[in]  value  The value to initialize with.
     */
    template<size_t Size>
    bytes(const bc::byte_array<Size>& value)
        : value_(value.begin(), value.end()) {}

    /**
     * Copy constructor.
     *
     * @param[in]  other  The object to copy into self on construct.
     */
    bytes(const bytes& other)
        : bytes(other.value_) {}

    /**
     * Return a reference to the data member.
     *
     * @return  A reference to the object's internal data.
     */
    bc::data_chunk& data()
    {
        return value_;
    }

    /**
     * Overload cast to internal type.
     *
     * @return  This object's value cast to internal type.
     */
    operator const bc::data_chunk() const
    {
        return value_; 
    }

    /**
     * Overload stream in. If input is invalid sets no bytes in argument.
     *
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input, bytes& argument)
    {
        std::string hex;
        input >> hex;
        bc::data_chunk chunk = bc::decode_hex(hex);
        argument.value_.assign(chunk.begin(), chunk.end());
        return input;
    }

    /**
     * Overload stream out.
     *
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output, 
        const bytes& argument)
    {
        output << bc::encode_hex(argument.value_);
        return output;
    }

private:

    /**
     * The state of this object.
     */
    bc::data_chunk value_;
};

} // sx
} // serializer

#endif