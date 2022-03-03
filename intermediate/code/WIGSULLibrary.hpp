#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/System/Core/AppDomain.hpp"
#include "Arp/System/Core/Singleton.hxx"
#include "Arp/System/Core/Library.h"
#include "Arp/Plc/Commons/Meta/MetaLibraryBase.hpp"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeDomain.hpp"

namespace WIGSUL
{

using namespace Arp::System::Acf;
using namespace Arp::Plc::Commons::Meta;
using namespace Arp::Plc::Commons::Meta::TypeSystem;

class WIGSULLibrary : public MetaLibraryBase, public Singleton<WIGSULLibrary>
{
public: // typedefs
    typedef Singleton<WIGSULLibrary> SingletonBase;

public: // construction/destruction
    WIGSULLibrary(AppDomain& appDomain);
    virtual ~WIGSULLibrary() = default;

public: // static operations (called through reflection)
    static void Main(AppDomain& appDomain);

private: // methods
    void InitializeTypeDomain();

private: // deleted methods
    WIGSULLibrary(const WIGSULLibrary& arg) = delete;
    WIGSULLibrary& operator= (const WIGSULLibrary& arg) = delete;

private:  // fields
    TypeDomain typeDomain;
};

extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain);

///////////////////////////////////////////////////////////////////////////////
// inline methods of class WIGSULLibrary

} // end of namespace WIGSUL
