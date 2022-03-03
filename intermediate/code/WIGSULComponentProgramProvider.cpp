#include "WIGSULComponentProgramProvider.hpp"
#include "WIGSULProgram.hpp"

namespace WIGSUL
{

IProgram::Ptr WIGSULComponentProgramProvider::CreateProgramInternal(const String& programName, const String& programType)
{
    if (programType == "WIGSULProgram")
    { 
        return std::make_shared<::WIGSUL::WIGSULProgram>(this->wIGSULComponent, programName);
    }

    // else unknown program
    return nullptr;
}

} // end of namespace WIGSUL
