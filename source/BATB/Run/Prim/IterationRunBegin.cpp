#include "BATB/Run/Prim/IterationRunBegin.hpp"


namespace BATB
{


IterationRunBegin0* IterationRunBegin0::create(Config::Block* cfg)
{
    static IterationRunBegin0 ret;

    ret.next_ = IterationRunBegin1::create( cfg );
    return &ret;
}


void IterationRunBegin0::destroy(IterationRunBegin0* iter)
{
    IterationRunBegin1::destroy( iter->next_ );
}

IterationRunBegin1* IterationRunBegin1::create(Config::Block* cfg)
{
    static IterationRunBegin1 ret;
   
    // FIXME: begin iteration from cfg...
    
    return &ret;
}

void IterationRunBegin1::destroy(IterationRunBegin1* iter)
{
    // FIXME: end iteration
}








// to be run once, then calling IterationRunBegin1
void IterationRunBegin0::iterate(IterationStackRunWorld& stack, RunWorld& run)
{
    log << "IterationRunBegin0::iterate" << std::endl;

    // now next iteration
    //stack.next( next_ );
    stack.push( next_ );
}

void IterationRunBegin1::iterate(IterationStackRunWorld& stack, RunWorld& run)
{
    // FIXME: define iteration...
    log << "IterationRunBegin1::iterate" << std::endl;

}


}
