//    open-forest: an orientering game.
//    Copyright (C) 2018  karamellpelle@hotmail.com
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#ifndef BATB_FOREST_AIM_HPP
#define BATB_FOREST_AIM_HPP
#include "include.hpp"


namespace batb
{


namespace forest
{

// z axis is forward; x right, y up
class Aim
{
public:
    Aim() : pos( aim[3] ) { }

    // we need copy/move since 'pos' points to this->aim!
    Aim(const Aim& a) : aim( a.aim ), pos( aim[3] )               { }
    Aim(Aim&& a)      : aim( std::move( a.aim ) ), pos( aim[3] )  { }

    inline void setPos(const glm::vec3& vec)
    {
        pos = glm::vec4( vec, 1.0 );
    }
    inline void setPos(const glm::vec4::value_type& x, const glm::vec4::value_type& y, const glm::vec4::value_type& z)
    {
        pos = glm::vec4( x, y, z, 1.0 );
    }
    glm::mat4  aim;
    glm::vec4& pos;
};



} // namespace forest

} // namespace batb





#endif

