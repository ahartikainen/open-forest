//    open-forest: an orientering game.
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
#include "OgreCamera.h"
#include "batb.hpp"
#include "batb/run/iteration/IterationRunDemo.hpp"
#include "batb/demo/iteration/IterationDemoForest.hpp"

namespace batb
{

namespace run
{


IterationRunDemo::IterationRunDemo(BATB& b) : IterationRun( b )
{

}



void IterationRunDemo::iterate_begin(World& run)
{
    BATB_LOG_FUNC( batb );

    //// create stack for demo::World
    //stack_ = { new IterationDemo( batb ) };

    // load Forest
    // NOTE: this fails anyway; 'this' is destroyed upon 
    //       iteration is finished
    static bool init = false;
    if (!init)
    {
        demo = new demo::World( run );
        forest::WorldLoader loader( batb );
        loader.load( demo->forest, YAML::Node() );

        init = true;
    }
    // setup substack
    stack = { new demo::IterationDemoForest( batb ) };

    demo->tick = run.tick;
}


IterationStack IterationRunDemo::iterate_run(World& run)
{
    // iterate demo::World
    game::iterate( stack, *demo );
    if ( stack.empty() )
    {
        return _;
    }
    else
    {
        return { this };
    }


}
////////////////////////////////////////////////////////////////////////////////
//

} // namespace run

} // namespace batb

