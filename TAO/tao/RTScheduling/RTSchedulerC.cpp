// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:291


#include "RTScheduler.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "tao/Var_Size_Argument_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "RTSchedulerC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:492

#if !defined (_CORBA_POLICYLIST__ARG_TRAITS_CS_)
#define _CORBA_POLICYLIST__ARG_TRAITS_CS_
  
  template<>
  class TAO_RTScheduler_Export Arg_Traits<CORBA::PolicyList>
    : public
        Var_Size_Arg_Traits_T<
            CORBA::PolicyList,
            CORBA::PolicyList_var,
            CORBA::PolicyList_out
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::ThreadAction.

RTScheduling::ThreadAction_ptr
TAO::Objref_Traits<RTScheduling::ThreadAction>::duplicate (
    RTScheduling::ThreadAction_ptr p
  )
{
  return RTScheduling::ThreadAction::_duplicate (p);
}

void
TAO::Objref_Traits<RTScheduling::ThreadAction>::release (
    RTScheduling::ThreadAction_ptr p
  )
{
  CORBA::release (p);
}

RTScheduling::ThreadAction_ptr
TAO::Objref_Traits<RTScheduling::ThreadAction>::nil (void)
{
  return RTScheduling::ThreadAction::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<RTScheduling::ThreadAction>::marshal (
    RTScheduling::ThreadAction_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

RTScheduling::ThreadAction::ThreadAction (void)
{}

RTScheduling::ThreadAction::~ThreadAction (void)
{}

RTScheduling::ThreadAction_ptr
RTScheduling::ThreadAction::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ThreadAction::_nil ();
    }
  
  ThreadAction_ptr proxy =
    dynamic_cast<ThreadAction_ptr> (_tao_objref);
  
  return ThreadAction::_duplicate (proxy);
}

RTScheduling::ThreadAction_ptr
RTScheduling::ThreadAction::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ThreadAction::_nil ();
    }
  
  ThreadAction_ptr proxy =
    dynamic_cast<ThreadAction_ptr> (_tao_objref);
  
  return ThreadAction::_duplicate (proxy);
}

RTScheduling::ThreadAction_ptr
RTScheduling::ThreadAction::_duplicate (ThreadAction_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RTScheduling::ThreadAction::_tao_release (ThreadAction_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
RTScheduling::ThreadAction::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:RTScheduling/ThreadAction:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* RTScheduling::ThreadAction::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/ThreadAction:1.0";
}

CORBA::Boolean
RTScheduling::ThreadAction::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::DistributableThread.

RTScheduling::DistributableThread_ptr
TAO::Objref_Traits<RTScheduling::DistributableThread>::duplicate (
    RTScheduling::DistributableThread_ptr p
  )
{
  return RTScheduling::DistributableThread::_duplicate (p);
}

void
TAO::Objref_Traits<RTScheduling::DistributableThread>::release (
    RTScheduling::DistributableThread_ptr p
  )
{
  CORBA::release (p);
}

RTScheduling::DistributableThread_ptr
TAO::Objref_Traits<RTScheduling::DistributableThread>::nil (void)
{
  return RTScheduling::DistributableThread::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<RTScheduling::DistributableThread>::marshal (
    RTScheduling::DistributableThread_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

RTScheduling::DistributableThread::DistributableThread (void)
{}

RTScheduling::DistributableThread::~DistributableThread (void)
{}

RTScheduling::DistributableThread_ptr
RTScheduling::DistributableThread::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DistributableThread::_nil ();
    }
  
  DistributableThread_ptr proxy =
    dynamic_cast<DistributableThread_ptr> (_tao_objref);
  
  return DistributableThread::_duplicate (proxy);
}

RTScheduling::DistributableThread_ptr
RTScheduling::DistributableThread::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DistributableThread::_nil ();
    }
  
  DistributableThread_ptr proxy =
    dynamic_cast<DistributableThread_ptr> (_tao_objref);
  
  return DistributableThread::_duplicate (proxy);
}

RTScheduling::DistributableThread_ptr
RTScheduling::DistributableThread::_duplicate (DistributableThread_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RTScheduling::DistributableThread::_tao_release (DistributableThread_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
RTScheduling::DistributableThread::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:RTScheduling/DistributableThread:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* RTScheduling::DistributableThread::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/DistributableThread:1.0";
}

CORBA::Boolean
RTScheduling::DistributableThread::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::Current.

RTScheduling::Current_ptr
TAO::Objref_Traits<RTScheduling::Current>::duplicate (
    RTScheduling::Current_ptr p
  )
{
  return RTScheduling::Current::_duplicate (p);
}

void
TAO::Objref_Traits<RTScheduling::Current>::release (
    RTScheduling::Current_ptr p
  )
{
  CORBA::release (p);
}

RTScheduling::Current_ptr
TAO::Objref_Traits<RTScheduling::Current>::nil (void)
{
  return RTScheduling::Current::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<RTScheduling::Current>::marshal (
    RTScheduling::Current_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/exception_cs.cpp:63

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::UNSUPPORTED_SCHEDULING_DISCIPLINE (void)
  : CORBA::UserException (
        "IDL:RTScheduling/Current/UNSUPPORTED_SCHEDULING_DISCIPLINE:1.0",
        "UNSUPPORTED_SCHEDULING_DISCIPLINE"
      )
{
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::~UNSUPPORTED_SCHEDULING_DISCIPLINE (void)
{
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::UNSUPPORTED_SCHEDULING_DISCIPLINE (const ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE&
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::operator= (const ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE *
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<UNSUPPORTED_SCHEDULING_DISCIPLINE *> (_tao_excp);
}

const RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE *
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const UNSUPPORTED_SCHEDULING_DISCIPLINE *> (_tao_excp);
}

CORBA::Exception *RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE, 0);
  return retval;
}

CORBA::Exception *
RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE (*this),
      0
    );
  return result;
}

void RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_raise (void) const
{
  TAO_RAISE (*this);
}

void RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE::_tao_type (void) const
{
  return ::RTScheduling::Current::_tc_UNSUPPORTED_SCHEDULING_DISCIPLINE;
}

// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_RTSCHEDULING_CURRENT_IDTYPE_CS_)
#define _RTSCHEDULING_CURRENT_IDTYPE_CS_

RTScheduling::Current::IdType::IdType (void)
{}

RTScheduling::Current::IdType::IdType (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max)
{}

RTScheduling::Current::IdType::IdType (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Octet * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max, length, buffer, release)
{}

RTScheduling::Current::IdType::IdType (
    const IdType &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (seq)
{}

RTScheduling::Current::IdType::~IdType (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_RTSCHEDULING_CURRENT_NAMELIST_CS_)
#define _RTSCHEDULING_CURRENT_NAMELIST_CS_

RTScheduling::Current::NameList::NameList (void)
{}

RTScheduling::Current::NameList::NameList (
    CORBA::ULong max
  )
  : TAO_Unbounded_String_Sequence
    (max)
{}

RTScheduling::Current::NameList::NameList (
    CORBA::ULong max,
    CORBA::ULong length,
    char * * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_String_Sequence
    (max, length, buffer, release)
{}

RTScheduling::Current::NameList::NameList (
    const NameList &seq
  )
  : TAO_Unbounded_String_Sequence
    (seq)
{}

RTScheduling::Current::NameList::~NameList (void)
{}

#endif /* end #if !defined */

RTScheduling::Current::Current (void)
{}

RTScheduling::Current::~Current (void)
{}

RTScheduling::Current_ptr
RTScheduling::Current::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }
  
  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);
  
  return Current::_duplicate (proxy);
}

RTScheduling::Current_ptr
RTScheduling::Current::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Current::_nil ();
    }
  
  Current_ptr proxy =
    dynamic_cast<Current_ptr> (_tao_objref);
  
  return Current::_duplicate (proxy);
}

RTScheduling::Current_ptr
RTScheduling::Current::_duplicate (Current_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RTScheduling::Current::_tao_release (Current_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
RTScheduling::Current::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/RTCORBA/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:RTScheduling/Current:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* RTScheduling::Current::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/Current:1.0";
}

CORBA::Boolean
RTScheduling::Current::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::ResourceManager.

RTScheduling::ResourceManager_ptr
TAO::Objref_Traits<RTScheduling::ResourceManager>::duplicate (
    RTScheduling::ResourceManager_ptr p
  )
{
  return RTScheduling::ResourceManager::_duplicate (p);
}

void
TAO::Objref_Traits<RTScheduling::ResourceManager>::release (
    RTScheduling::ResourceManager_ptr p
  )
{
  CORBA::release (p);
}

RTScheduling::ResourceManager_ptr
TAO::Objref_Traits<RTScheduling::ResourceManager>::nil (void)
{
  return RTScheduling::ResourceManager::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<RTScheduling::ResourceManager>::marshal (
    RTScheduling::ResourceManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

RTScheduling::ResourceManager::ResourceManager (void)
{}

RTScheduling::ResourceManager::~ResourceManager (void)
{}

RTScheduling::ResourceManager_ptr
RTScheduling::ResourceManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ResourceManager::_nil ();
    }
  
  ResourceManager_ptr proxy =
    dynamic_cast<ResourceManager_ptr> (_tao_objref);
  
  return ResourceManager::_duplicate (proxy);
}

RTScheduling::ResourceManager_ptr
RTScheduling::ResourceManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return ResourceManager::_nil ();
    }
  
  ResourceManager_ptr proxy =
    dynamic_cast<ResourceManager_ptr> (_tao_objref);
  
  return ResourceManager::_duplicate (proxy);
}

RTScheduling::ResourceManager_ptr
RTScheduling::ResourceManager::_duplicate (ResourceManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RTScheduling::ResourceManager::_tao_release (ResourceManager_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
RTScheduling::ResourceManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/RTCORBA/Mutex:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:RTScheduling/ResourceManager:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* RTScheduling::ResourceManager::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/ResourceManager:1.0";
}

CORBA::Boolean
RTScheduling::ResourceManager::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for RTScheduling::Scheduler.

RTScheduling::Scheduler_ptr
TAO::Objref_Traits<RTScheduling::Scheduler>::duplicate (
    RTScheduling::Scheduler_ptr p
  )
{
  return RTScheduling::Scheduler::_duplicate (p);
}

void
TAO::Objref_Traits<RTScheduling::Scheduler>::release (
    RTScheduling::Scheduler_ptr p
  )
{
  CORBA::release (p);
}

RTScheduling::Scheduler_ptr
TAO::Objref_Traits<RTScheduling::Scheduler>::nil (void)
{
  return RTScheduling::Scheduler::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<RTScheduling::Scheduler>::marshal (
    RTScheduling::Scheduler_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from 
// be/be_visitor_exception/exception_cs.cpp:63

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::INCOMPATIBLE_SCHEDULING_DISCIPLINES (void)
  : CORBA::UserException (
        "IDL:RTScheduling/Scheduler/INCOMPATIBLE_SCHEDULING_DISCIPLINES:1.0",
        "INCOMPATIBLE_SCHEDULING_DISCIPLINES"
      )
{
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::~INCOMPATIBLE_SCHEDULING_DISCIPLINES (void)
{
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::INCOMPATIBLE_SCHEDULING_DISCIPLINES (const ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES&
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::operator= (const ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES *
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<INCOMPATIBLE_SCHEDULING_DISCIPLINES *> (_tao_excp);
}

const RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES *
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const INCOMPATIBLE_SCHEDULING_DISCIPLINES *> (_tao_excp);
}

CORBA::Exception *RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES, 0);
  return retval;
}

CORBA::Exception *
RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES (*this),
      0
    );
  return result;
}

void RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_raise (void) const
{
  TAO_RAISE (*this);
}

void RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
CORBA::TypeCode_ptr RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES::_tao_type (void) const
{
  return ::RTScheduling::Scheduler::_tc_INCOMPATIBLE_SCHEDULING_DISCIPLINES;
}

RTScheduling::Scheduler::Scheduler (void)
{}

RTScheduling::Scheduler::~Scheduler (void)
{}

RTScheduling::Scheduler_ptr
RTScheduling::Scheduler::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Scheduler::_nil ();
    }
  
  Scheduler_ptr proxy =
    dynamic_cast<Scheduler_ptr> (_tao_objref);
  
  return Scheduler::_duplicate (proxy);
}

RTScheduling::Scheduler_ptr
RTScheduling::Scheduler::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Scheduler::_nil ();
    }
  
  Scheduler_ptr proxy =
    dynamic_cast<Scheduler_ptr> (_tao_objref);
  
  return Scheduler::_duplicate (proxy);
}

RTScheduling::Scheduler_ptr
RTScheduling::Scheduler::_duplicate (Scheduler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RTScheduling::Scheduler::_tao_release (Scheduler_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
RTScheduling::Scheduler::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:RTScheduling/Scheduler:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* RTScheduling::Scheduler::_interface_repository_id (void) const
{
  return "IDL:RTScheduling/Scheduler:1.0";
}

CORBA::Boolean
RTScheduling::Scheduler::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::PolicyList>;

  template class
    TAO::Var_Size_Arg_Traits_T<
        CORBA::PolicyList,
        CORBA::PolicyList_var,
        CORBA::PolicyList_out
      >;

#endif /* end #if !defined */

  template class
    TAO::Objref_Traits<
        RTScheduling::ThreadAction
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::ThreadAction
      >;
  
  template class
    TAO_Objref_Out_T<
        RTScheduling::ThreadAction
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::DistributableThread
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::DistributableThread
      >;
  
  template class
    TAO_Objref_Out_T<
        RTScheduling::DistributableThread
      >;

  template class
    TAO_FixedSeq_Var_T<
        RTScheduling::Current::IdType,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Var_Base_T<
        RTScheduling::Current::IdType,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Out_T<
        RTScheduling::Current::IdType,
        RTScheduling::Current::IdType_var,
        CORBA::Octet
      >;

  template class
    TAO_MngSeq_Var_T<
        RTScheduling::Current::NameList,
        TAO_SeqElem_String_Manager
      >;

  template class
    TAO_Seq_Var_Base_T<
        RTScheduling::Current::NameList,
        TAO_SeqElem_String_Manager
      >;

  template class
    TAO_MngSeq_Out_T<
        RTScheduling::Current::NameList,
        RTScheduling::Current::NameList_var,
        TAO_SeqElem_String_Manager
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::Current
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::Current
      >;
  
  template class
    TAO_Objref_Out_T<
        RTScheduling::Current
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::ResourceManager
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::ResourceManager
      >;
  
  template class
    TAO_Objref_Out_T<
        RTScheduling::ResourceManager
      >;

  template class
    TAO::Objref_Traits<
        RTScheduling::Scheduler
      >;

  template class
    TAO_Objref_Var_T<
        RTScheduling::Scheduler
      >;
  
  template class
    TAO_Objref_Out_T<
        RTScheduling::Scheduler
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_SEQUENCE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::PolicyList>

# pragma instantiate \
    TAO::Var_Size_Arg_Traits_T< \
        CORBA::PolicyList, \
        CORBA::PolicyList_var, \
        CORBA::PolicyList_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::ThreadAction \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::ThreadAction
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::ThreadAction
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::DistributableThread \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::DistributableThread
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::DistributableThread
      >

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        RTScheduling::Current::IdType, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        RTScheduling::Current::IdType, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        RTScheduling::Current::IdType, \
        RTScheduling::Current::IdType_var, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_MngSeq_Var_T< \
        RTScheduling::Current::NameList, \
        TAO_SeqElem_String_Manager \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        RTScheduling::Current::NameList, \
        TAO_SeqElem_String_Manager \
      >

# pragma instantiate \
    TAO_MngSeq_Out_T< \
        RTScheduling::Current::NameList, \
        RTScheduling::Current::NameList_var, \
        TAO_SeqElem_String_Manager \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::Current \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::Current
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::Current
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::ResourceManager \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::ResourceManager
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::ResourceManager
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        RTScheduling::Scheduler \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        RTScheduling::Scheduler
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        RTScheduling::Scheduler
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
