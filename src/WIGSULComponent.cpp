#include "WIGSULComponent.hpp"
#include "Arp/Plc/Commons/Esm/ProgramComponentBase.hpp"
#include "WIGSULLibrary.hpp"

namespace WIGSUL
{

WIGSULComponent::WIGSULComponent(IApplication& application, const String& name)
: ComponentBase(application, ::WIGSUL::WIGSULLibrary::GetInstance(), name, ComponentCategory::Custom)
, programProvider(*this)
, ProgramComponentBase(::WIGSUL::WIGSULLibrary::GetInstance().GetNamespace(), programProvider)
{
}

void WIGSULComponent::Initialize()
{
    // never remove next line
    ProgramComponentBase::Initialize();

    // subscribe events from the event system (Nm) here
}

void WIGSULComponent::LoadConfig()
{
    // load project config here
}

void WIGSULComponent::SetupConfig()
{
    // never remove next line
    ProgramComponentBase::SetupConfig();

    // setup project config here
}

void WIGSULComponent::ResetConfig()
{
    // never remove next line
    ProgramComponentBase::ResetConfig();

    // implement this inverse to SetupConfig() and LoadConfig()
}

} // end of namespace WIGSUL
