#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Esm/ProgramProviderBase.hpp"

namespace WIGSUL
{

using namespace Arp;
using namespace Arp::Plc::Commons::Esm;

//forwards
class WIGSULComponent;

class WIGSULComponentProgramProvider : public ProgramProviderBase
{

public:   // construction/destruction
    WIGSULComponentProgramProvider(WIGSULComponent& wIGSULComponentArg);
    virtual ~WIGSULComponentProgramProvider() = default;

public:   // IProgramProvider operations
    IProgram::Ptr CreateProgramInternal(const String& programName, const String& programType) override;

private:   // deleted methods
    WIGSULComponentProgramProvider(const WIGSULComponentProgramProvider& arg) = delete;
    WIGSULComponentProgramProvider& operator=(const WIGSULComponentProgramProvider& arg) = delete;

private: // fields
    WIGSULComponent& wIGSULComponent;
};

///////////////////////////////////////////////////////////////////////////////
// inline methods of class WIGSULComponentProgramProvider

inline WIGSULComponentProgramProvider::WIGSULComponentProgramProvider(WIGSULComponent& wIGSULComponentArg)
    : wIGSULComponent(wIGSULComponentArg)
{
}

} // end of namespace WIGSUL
