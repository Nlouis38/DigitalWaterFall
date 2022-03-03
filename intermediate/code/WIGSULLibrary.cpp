#include "WIGSULLibrary.hpp"
#include "Arp/System/Core/CommonTypeName.hxx"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeSystem.h"
#include "WIGSULComponent.hpp"

namespace WIGSUL
{

WIGSULLibrary::WIGSULLibrary(AppDomain& appDomain)
    : MetaLibraryBase(appDomain, ARP_VERSION_CURRENT, typeDomain)
    , typeDomain(CommonTypeName<WIGSULLibrary>().GetNamespace())
{
    this->componentFactory.AddFactoryMethod(CommonTypeName<::WIGSUL::WIGSULComponent>(), &::WIGSUL::WIGSULComponent::Create);
    this->InitializeTypeDomain();
}

void WIGSULLibrary::Main(AppDomain& appDomain)
{
    SingletonBase::CreateInstance(appDomain);
}

extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain)
{
    WIGSULLibrary::Main(appDomain);
    return  WIGSULLibrary::GetInstance();
}

} // end of namespace WIGSUL
