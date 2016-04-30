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
#ifndef BATB_RUN_CCNSOLE_TBCONSOLE_HPP
#define BATB_RUN_CCNSOLE_TBCONSOLE_HPP
#include "batb/batb_include.hpp"
#include "batb/gui.hpp"
#include "batb/tb.hpp"


namespace tb { class TBEditField; }
namespace tb { class TBEditFieldEnter; }


namespace batb
{
class BATB;

namespace run
{
class Console;



class TBConsole : public tb::TBWindow           // or TBWidget?
{
friend class ConsoleStreambuf;

public:
    TBOBJECT_SUBCLASS( TBConsole, tb::TBWindow );

    TBConsole(BATB& );

    virtual void OnFocusChanged(bool focus) override;
    virtual bool OnEvent(const tb::TBWidgetEvent &ev) override;       // TBWidget
  
    // output
    void output(const std::string& );
    void clear();

    BATB& batb;

private:
    tb::TBEditFieldEnter* tb_input_ = nullptr;
    tb::TBEditField* tb_output_ = nullptr;

};


} // namespace run

} // namespace batb


#endif

