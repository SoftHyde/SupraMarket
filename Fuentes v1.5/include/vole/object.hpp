/* /////////////////////////////////////////////////////////////////////////
 * File:        vole/object.hpp
 *
 * Purpose:     Definition of the vole::object IDispatch wrapper class.
 *
 * Created:     10th August 2006
 * Updated:     21st January 2010
 *
 * Home:        http://vole.sourceforge.net/
 *
 * Copyright (c) 2006-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file vole/object.hpp
 *
 * \brief Definition of the vole::object IDispatch wrapper class.
 */

#ifndef VOLE_INCL_VOLE_HPP_OBJECT
#define VOLE_INCL_VOLE_HPP_OBJECT

#ifndef VOLE_DOCUMENTATION_SKIP_SECTION
# define VOLE_VER_VOLE_HPP_OBJECT_MAJOR     1
# define VOLE_VER_VOLE_HPP_OBJECT_MINOR     6
# define VOLE_VER_VOLE_HPP_OBJECT_REVISION  6
# define VOLE_VER_VOLE_HPP_OBJECT_EDIT      18
#endif /* !VOLE_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* VOLE Header Files */
#include <vole/error/exceptions.hpp>
#include <vole/return_traits/return_traits.hpp>
#include <vole/return_traits/builtins.hpp>
#include <vole/return_traits/ole_types.hpp>
#ifndef VOLE_NO_STD_TYPES
# include <vole/return_traits/std_types.hpp>
#endif /* !VOLE_NO_STD_TYPES */
#ifndef VOLE_NO_TIME_TYPES
# include <vole/return_traits/time_types.hpp>
#endif /* !VOLE_NO_TIME_TYPES */
#include <vole/util/common.hpp>
#include <vole/util/of_type.hpp>

/* STLSoft Header Files */
#include <stlsoft/smartptr/ref_ptr.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

#include <comstl/error/excepinfo_functions.h>
#include <comstl/conversion/interface_cast.hpp>
#include <comstl/util/creation_functions.hpp>
#include <comstl/util/variant.hpp>

#include <winstl/conversion/char_conversions.hpp>
#include <winstl/system/system_traits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef VOLE_NO_NAMESPACE
namespace vole
{
#endif /* !VOLE_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief OLE object facade
 *
 */
class object
{
/// \name Member Types
/// @{
public:
    /// The pointer type
    typedef stlsoft::ref_ptr<IDispatch>     ptr_type;
    /// This type
    typedef object                          class_type;
private:
    typedef comstl::variant                 varx_type;
/// @}

/// \name Construction
/// @{
public:
    /// Default constructs an empty instance.
    ///
    /// \note The given instance has a reduced use spectrum. Only the methods
    ///    is_nothing(), get(), lcid() and swap() are valid. Invocation of any
    ///    other method on an empty instance will result in the throwing of
    ///    vole::object_not_connected_exception.
    explicit object(coercion_level::coercion_level coercionLevel = coercion_level::naturalPromotion)
        : m_lcid(LOCALE_SYSTEM_DEFAULT)
        , m_coercionLevel(coercionLevel)
    {}
    /// Constructs an instance from a raw pointer, and optional coercion level.
    ///
    /// \param p A pointer to an Automation server, via its IDispatch interface. May be NULL
    /// \param bAddRef indicates whether a reference to p should be taken
    /// \param coercionLevel The coercion level to use when converting method/property return types
    object(IDispatch* p, bool bAddRef, coercion_level::coercion_level coercionLevel = coercion_level::naturalPromotion)
        : m_disp(p, bAddRef)
        , m_lcid(LOCALE_SYSTEM_DEFAULT)
        , m_coercionLevel(coercionLevel)
    {}
    /// Constructs an instance from a managed pointer, and optional coercion level.
    ///
    /// \param ptr A smart pointer to an Automation server, via its IDispatch interface
    /// \param coercionLevel The coercion level to use when converting method/property return types
    object(ptr_type ptr, coercion_level::coercion_level coercionLevel = coercion_level::naturalPromotion)
        : m_disp(ptr)
        , m_lcid(LOCALE_SYSTEM_DEFAULT)
        , m_coercionLevel(coercionLevel)
    {}
    /// Constructs an instance from a <code>VARIANT</code>, and optional coercion level.
    ///
    /// \param var A VARIANT containing a pointer to an Automation server, via its IDispatch interface
    /// \param coercionLevel The coercion level to use when converting method/property return types
    explicit object(VARIANT& var, coercion_level::coercion_level coercionLevel = coercion_level::naturalPromotion)
        : m_disp()
        , m_lcid(LOCALE_SYSTEM_DEFAULT)
        , m_coercionLevel(coercionLevel)
    {
        comstl::variant v;
        HRESULT         hr = v.try_conversion_copy(var, VT_DISPATCH);

        if(FAILED(hr))
        {
            throw creation_exception("Source variable does not contain an object", hr);
        }

        COMSTL_ASSERT(VT_DISPATCH == v.vt);

        m_disp.set(v.pdispVal, true);
    }
    /// Releases the underlying object
    ~object()
    {}

    /// Creates an instance of the COM Automation server with the given id,
    /// from the class context CLSCTX_ALL and using a coercion level of
    /// natural promotion
    ///
    /// \param clsid The classid of the server
    static object   create( REFCLSID                            clsid);
    static object   create( REFCLSID                            clsid
                        ,   DWORD                               dwClsContext
                        ,   coercion_level::coercion_level      coercionLevel);

    /// Creates an instance of the COM Automation server with the given id,
    /// from the class context CLSCTX_ALL and using a coercion level of
    /// natural promotion
    ///
    /// \param classId The classid of the server
    static object   create( LPCOLESTR                           classId);
    static object   create( LPCOLESTR                           classId
                        ,   DWORD                               dwClsContext
                        ,   coercion_level::coercion_level      coercionLevel);

#ifndef OLE2ANSI
    static object   create( char const*                         classId);
    static object   create( char const*                         classId
                        ,   DWORD                               dwClsContext
                        ,   coercion_level::coercion_level      coercionLevel);
#endif /* OLE2ANSI */

    HRESULT QueryInterface(REFIID riid, void** ppv)
    {
        return get_checked_disp_()->QueryInterface(riid, ppv);
    }
    template <typename I>
    HRESULT QueryInterface(I** ppi)
    {
        COMSTL_ASSERT(NULL != ppi);

        return this->QueryInterface(comstl::IID_traits<I>::iid(), reinterpret_cast<void**>(ppi));
    }
/// @}

/// \name Attributes
/// @{
public:
    bool is_nothing() const
    {
        return NULL == m_disp.get();
    }

    IDispatch* get() const
    {
        return const_cast<IDispatch*>(m_disp.get());
    }

    LCID lcid() const
    {
        return m_lcid;
    }
/// @}

/// \name Operations
/// @{
public:
    void swap(class_type& rhs) throw()
    {
        m_disp.swap(rhs.m_disp);
    }
/// @}

/// \name Utility functions
/// @{
public:
    /// Tests whether the underlying automation object has a member (method
    /// or property), and optionally returns the dispatch id in a
    /// caller-supplied DISPID variable.
#if 0
    bool    has_member(LPCOLESTR memberName, DISPID* pmemberId = NULL) const;
    DISPID  get_memberId(LPCOLESTR memberName) const;

    bool    has_parameter(DISPID memberId, LPCOLESTR paramName, DISPID* pparamId = NULL) const;
    DISPID  get_paramId(DISPID memberId, LPCOLESTR paramName) const;
#endif /* 0 */
/// @}

/// \name Methods
/// @{
public:
#ifndef VOLE_DOCUMENTATION_SKIP_SECTION
# include "vole/object/generated/methods.hpp"
# include "vole/object/generated/void_methods.hpp"
#else /* !VOLE_DOCUMENTATION_SKIP_SECTION */
# include "./object/generated/methods.hpp"
# include "./object/generated/void_methods.hpp"
#endif /* !VOLE_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Properties (Get)
/// @{
public:
#ifndef VOLE_DOCUMENTATION_SKIP_SECTION
# include "vole/object/generated/get_properties.hpp"
# include "vole/object/generated/put_properties.hpp"
#else /* !VOLE_DOCUMENTATION_SKIP_SECTION */
# include "./object/generated/get_properties.hpp"
# include "./object/generated/put_properties.hpp"
#endif /* !VOLE_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Member Constants
/// @{
private:
    static DWORD get_default_clsctx_()
    {
        return CLSCTX_ALL;
    }
    static coercion_level::coercion_level get_default_coercion_level_()
    {
        return coercion_level::naturalPromotion;
    }
/// @}

/// \name Mid-level Implementation
/// @{
private:
    /// Invokes a method by DISPID
    void invoke_method_impl(VARIANT& result, DISPID dispid, VARIANT const* args, size_t numArgs)
    {
        this->Invoke(dispid, DISPATCH_METHOD, args, numArgs, result);
    }

    /// Invokes a method by name
    void invoke_method_impl(VARIANT& result, LPCOLESTR methodName, VARIANT const* args, size_t numArgs)
    {
        DISPID  dispid  =   GetIDOfName(methodName);

        this->invoke_method_impl(result, dispid, args, numArgs);
    }

    /// Invokes a void-returning method by DISPID
    void invoke_method_impl_v(DISPID dispid, VARIANT const* args, size_t numArgs)
    {
        this->Invoke(dispid, DISPATCH_METHOD, args, numArgs);
    }

    /// Invokes a void-returning method by name
    void invoke_method_impl_v(LPCOLESTR methodName, VARIANT const* args, size_t numArgs)
    {
        DISPID  dispid  =   GetIDOfName(methodName);

        this->invoke_method_impl_v(dispid, args, numArgs);
    }
/// @}

/// \name Low-level Implementation
/// @{
private:
    void check_disp_(char const* message = NULL) const
    {
        if(NULL == m_disp.get())
        {
            if(NULL == message)
            {
                message = "object is not connection to automation server";
            }

            throw object_not_connected_exception(message, DISP_E_BADCALLEE);
        }
    }

    ptr_type get_checked_disp_(char const* message = NULL) const
    {
        check_disp_(message);

        return m_disp;
    }
    ptr_type& get_checked_disp_(char const* message = NULL)
    {
        check_disp_(message);

        return m_disp;
    }

    /// Retrieves the DISPID of the given name, or throws an exception
    ///
    /// \exception 
    DISPID GetIDOfName(LPCOLESTR methodName) const
    {
        LPOLESTR    names[1]    =   { const_cast<LPOLESTR>(methodName) };
        DISPID      dispids[1]  =   { 0 };
        ptr_type    disp        =   get_checked_disp_();
#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("Optimisation later: make overloads of this, so don't need to copy (and therefore skip AddRef()/Release()) cycle"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

        HRESULT     hr          =   disp->GetIDsOfNames(IID_NULL, &names[0], 1, m_lcid, &dispids[0]);

        if(FAILED(hr))
        {
            if(DISP_E_UNKNOWNNAME == hr)
            {
				typedef winstl::system_traits<char>	traits_t;

                static const char           msg[] = "Unknown name: '";
                winstl::w2a                 a(methodName);
                stlsoft::auto_buffer<char>  buff(STLSOFT_NUM_ELEMENTS(msg) + a.size() + 1);

                traits_t::char_copy(&buff[0], msg, STLSOFT_NUM_ELEMENTS(msg) - 1);
                traits_t::char_copy(&buff[0] + (STLSOFT_NUM_ELEMENTS(msg) - 1), a, a.size());
                buff[(STLSOFT_NUM_ELEMENTS(msg) - 1) + a.size()] = '\'';
                buff[(STLSOFT_NUM_ELEMENTS(msg) - 1) + a.size() + 1] = '\0';

                STLSOFT_ASSERT(1 + ::strlen(buff.data()) == buff.size());   // Guard against changing "size()" for winstl::wide2multibyte

                throw invocation_exception(buff.data(), hr);
            }
            else
            {
                throw invocation_exception("GetIDsOfNames failed", hr);
            }
        }

        return dispids[0];
    }

    void Invoke(DISPID      dispid
            ,   WORD        flags
            ,   DISPPARAMS* pDispParams
            ,   VARIANT*    pVarResult
            ,   EXCEPINFO*  pExcepInfo
            ,   UINT*       puArgErr) const
    {
        STLSOFT_ASSERT(NULL != puArgErr);

        EXCEPINFO   xinfo_  =   { 0, 0, NULL, NULL, NULL, 0, NULL, NULL, 0 };
        ptr_type    disp    =   get_checked_disp_();
        HRESULT     hr      =   disp->Invoke(dispid, IID_NULL, m_lcid, flags, pDispParams, pVarResult, (NULL == pExcepInfo) ? (pExcepInfo = &xinfo_,pExcepInfo) : pExcepInfo, puArgErr);

        /* if(DISP_E_TYPEMISMATCH == hr)
        {
            char    msg[101];

            ::sprintf(*puArgErr)

            throw 

            ;
        }
        else */ if(FAILED(hr))
        {
#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("Turn this into an automation_exception / invocation_exception, so can pass in the argErr, and excep info"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

            // We always free the COM exception info in this scope because
            // we always throw a C++ exception out of it
            stlsoft::scoped_handle<EXCEPINFO*>  scopexi(pExcepInfo, comstl::EXCEPINFO_free);

            throw invocation_exception("Method/property invocation failed", hr, pExcepInfo);
        }
    }

    void Invoke(DISPID          dispid
            ,   WORD            flags
            ,   VARIANT const*  args
            ,   UINT            numArgs
            ,   VARIANT&        result) const
    {
        DISPPARAMS  dispparams;
        UINT        argErr;

        dispparams.cArgs                =   numArgs;
        dispparams.rgvarg               =   const_cast<VARIANT*>(&args[0]);
        dispparams.cNamedArgs           =   0;
        dispparams.rgdispidNamedArgs    =   NULL;

        this->Invoke(dispid, flags, &dispparams, &result, NULL, &argErr);
    }

    void Invoke(DISPID          dispid
            ,   WORD            flags
            ,   VARIANT const*  args
            ,   UINT            numArgs) const
    {
        DISPID      dispidNamed =   DISPID_PROPERTYPUT;
        DISPPARAMS  dispparams;
        UINT        argErr;

        dispparams.cArgs                    =   numArgs;
        dispparams.rgvarg                   =   const_cast<VARIANT*>(&args[0]);
        if( flags == DISPATCH_PROPERTYPUT ||
            flags == DISPATCH_PROPERTYPUTREF)
        {
            dispparams.rgdispidNamedArgs    =   &dispidNamed;
            dispparams.cNamedArgs           =   1;
        }
        else
        {
            dispparams.cNamedArgs           =   0;
            dispparams.rgdispidNamedArgs    =   NULL;
        }

        this->Invoke(dispid, flags, &dispparams, NULL, NULL, &argErr);
    }

    void Invoke(DISPID      dispid
            ,   WORD        flags
            ,   VARIANT&    result) const
    {
        this->Invoke(dispid, flags, NULL, 0, result);
    }
/// @}

/// \name Members
/// @{
private:
    ptr_type                                m_disp;
    const LCID                              m_lcid;
    const coercion_level::coercion_level    m_coercionLevel;
/// @}

/// \name Not to be implemented
/// @{
private:
    class_type& operator =(class_type const&);
/// @}
};

// Traits for vole::object

/** Specialisation of vole::com_return_traits for the <code>vole::object</code>
 *   type.
 */
template <>
struct com_return_traits<object>
{
    /** Converts the given <code>VARIANT</code> to an instance of
     *   <code>vole::object</code>, according to the given coercion level.
     *
     * \param var The variant returned by the call to
     *   <code>IDispatch::Invoke()</code>
     * \param coercionLevel Level of coercion supplied to the constructor of
     *   vole::object or vole::collection.
     */
    static object convert(VARIANT const& var, coercion_level::coercion_level coercionLevel)
    {
        STLSOFT_SUPPRESS_UNUSED(coercionLevel);

        LPDISPATCH  pdisp = NULL;

        if(VT_DISPATCH == var.vt)
        {
            return object(var.pdispVal, true, coercionLevel);
        }
        else if(VT_UNKNOWN == var.vt &&
                NULL != var.punkVal &&
                SUCCEEDED(var.punkVal->QueryInterface(IID_IDispatch, reinterpret_cast<void**>(&pdisp))))
        {
            return object(pdisp, false, coercionLevel);
        }
        else
        {
            throw type_conversion_exception("Could not convert VARIANT to object", DISP_E_TYPEMISMATCH);
        }
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef VOLE_DOCUMENTATION_SKIP_SECTION


// Construction - Creation functions

inline /* static */ object object::create(REFCLSID clsid)
{
    LPDISPATCH  pdisp;
    HRESULT     hr  =   comstl::co_create_instance(clsid, &pdisp, get_default_clsctx_());

    if(FAILED(hr))
    {
        throw creation_exception("Could not create coclass", hr);
    }

    return object(pdisp, false, get_default_coercion_level_());
}

inline /* static */ object object::create(REFCLSID clsid, DWORD dwClsContext, coercion_level::coercion_level coercionLevel)
{
    LPDISPATCH  pdisp;
    HRESULT     hr  =   comstl::co_create_instance(clsid, &pdisp, dwClsContext);

    if(FAILED(hr))
    {
        throw creation_exception("Could not create coclass", hr);
    }

    return object(pdisp, false, coercionLevel);
}

inline /* static */ object object::create(LPCOLESTR classId)
{
    LPDISPATCH  pdisp;
    HRESULT     hr  =   comstl::co_create_instance(classId, &pdisp, get_default_clsctx_());

    if(FAILED(hr))
    {
        throw creation_exception("Could not create coclass", hr);
    }

    return object(pdisp, false, get_default_coercion_level_());
}

inline /* static */ object object::create(LPCOLESTR classId, DWORD dwClsContext, coercion_level::coercion_level coercionLevel)
{
    LPDISPATCH  pdisp;
    HRESULT     hr  =   comstl::co_create_instance(classId, &pdisp, dwClsContext);

    if(FAILED(hr))
    {
        throw creation_exception("Could not create coclass", hr);
    }

    return object(pdisp, false, coercionLevel);
}

#ifndef OLE2ANSI
inline /* static */ object object::create(char const* classId)
{
    return create(winstl::a2w(classId).c_str(), get_default_clsctx_(), get_default_coercion_level_());
}

inline /* static */ object object::create(char const* classId, DWORD dwClsContext, coercion_level::coercion_level coercionLevel)
{
    return create(winstl::a2w(classId).c_str(), dwClsContext, coercionLevel);
}
#endif /* OLE2ANSI */



// Utility functions

#if 0
inline bool object::has_member(LPCOLESTR memberName, DISPID* pmemberId = NULL) const
{
    ;
}

inline DISPID object::get_memberId(LPCOLESTR memberName) const
{
    DISPID  memberId;

    if(!has_member(memberName, &memberId))
    {
        throw 
    }

    return memberId;
}

inline bool object::has_parameter(DISPID memberId, LPCOLESTR paramName, DISPID* pparamId = NULL) const
{
}

inline DISPID object::get_paramId(DISPID memberId, LPCOLESTR paramName) const
{
}
#endif /* 0 */

#endif /* !VOLE_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace, and shims
 */

#ifndef VOLE_NO_NAMESPACE
} // namespace vole
#endif /* !VOLE_NO_NAMESPACE */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{

    /// Overload for the stlsoft::is_null shim.
#ifdef VOLE_NO_NAMESPACE
    inline bool is_null(::object const& obj)
#else /* ? VOLE_NO_NAMESPACE */
    inline bool is_null(::vole::object const& obj)
#endif /* VOLE_NO_NAMESPACE */
    {
        return obj.is_nothing();
    }

    /// Overload for the stlsoft::get_ptr shim.
#ifdef VOLE_NO_NAMESPACE
    inline IDispatch* get_ptr(::object const& obj)
#else /* ? VOLE_NO_NAMESPACE */
    inline IDispatch* get_ptr(::vole::object const& obj)
#endif /* VOLE_NO_NAMESPACE */
    {
        return obj.get();
    }

} // namespace stlsoft
#endif /* !_STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !VOLE_INCL_VOLE_HPP_OBJECT */

/* ///////////////////////////// end of file //////////////////////////// */
