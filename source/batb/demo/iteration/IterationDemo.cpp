//    open-demo: an orientering game.
//    Copyright (C) 2014  carljsv@student.matnat.uio.no
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
#include "batb.hpp"
#include "batb/demo/iteration/IterationDemo.hpp"
#include "batb/demo/World.hpp"

namespace batb
{


namespace demo
{

IterationDemo::IterationDemo(BATB& b) : batb( b )
{

}

IterationStack IterationDemo::iterate(World& world)
{

    world.tick = run.tick;

    ////////////////////////////////////////
    // actual iteration, implemented by subclass
    ////////////////////////////////////////
    auto ret = iterate_demo( world );
 

    // TODO: finish up, free mem (events, ...)
    step( events );

    return ret;
}


} // namespace demo

} // namespace batb
