/**
 *  @file   StubContainerInterceptorRegistration_Impl.h
 *
 *  $Id$
 *
 *  @author Marcel Smit <msmit@remedy.nl>
 */
#if !defined STUBCONTAINERINTERCEPTORREGISTRATION_IMPL_H
#define STUBCONTAINERINTERCEPTORREGISTRATION_IMPL_H

#include /**/ "ace/pre.h"

#include "ciao/Containers/Generic/Generic_Container_export.h"

#include "ccm/Generic/CCM_StubContainerInterceptorC.h"
#include "ccm/Generic/CCM_StubContainerInterceptorRegistrationC.h"
#include "ciao/Containers/Generic/Interceptor_Registration_T.h"

namespace CIAO
{
  /**
   * @class StubContainerInterceptorRegistration_Impl
   *
   * @brief Implementation of the CCM_ServerContainerInterceptorRegistration interface
   *
   * Implementation of the registration process of Server Container
   * Interceptors
   *
   * Part of COPI (Container Portable Interceptor)
   */
  class GENERIC_CONTAINER_Export StubContainerInterceptorRegistration_Impl
    : public Interceptor_Registration_T<
        ::Components::ContainerPortableInterceptor::StubContainerInterceptorRegistration,
        ::Components::ContainerPortableInterceptor::StubContainerInterceptor>
  {
  public:
    StubContainerInterceptorRegistration_Impl (void);
    virtual ~StubContainerInterceptorRegistration_Impl (void);

    /// Registers a StubContainerInterceptor.
    /// Returns a cookie for this registration.
    virtual ::Components::Cookie *
    register_stub_interceptor (
      ::Components::ContainerPortableInterceptor::StubContainerInterceptor_ptr ci);

    /// Unregisters a StubContainerInterceptor.
    /// Throws an InvalidRegistration exception when the
    /// StubContainerInterceptor cannot be found.
    /// Returns the StubContainerInterceptor
    virtual ::Components::ContainerPortableInterceptor::StubContainerInterceptor_ptr
    unregister_stub_interceptor (::Components::Cookie * cookie);
  };
}

#include /**/ "ace/post.h"

#endif /* STUBCONTAINERINTERCEPTORREGISTRATION_IMPL_H */