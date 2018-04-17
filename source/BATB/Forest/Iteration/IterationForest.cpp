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
#include "BATB/Forest/Iteration/IterationForest.hpp"
#include "BATB/Forest/World.hpp"

namespace batb
{


namespace forest
{

IterationForest::IterationForest(BATB* b) : batb( b )
{

}

IterationStack IterationForest::iterate(World& world)
{
    ////////////////////////////////////////
    // actual iteration, implemented by subclass
    ////////////////////////////////////////
    auto ret = iterate_forest( world );
 

    // TODO: finish up, free mem (events, ...)
    //
    events_step( world.events );

    // count number of IterationForest-iterations
    ++world.frames;

    return ret;
}


} // namespace forest

} // namespace batb
