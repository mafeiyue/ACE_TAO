/* -*- C++ -*- */
// $Id$

#if defined (ACE_WIN32) || defined (ACE_HAS_POSIX_SEM) || defined (ACE_PSOS)
ACE_INLINE const ACE_mutex_t &
ACE_Process_Mutex::lock (void) const
{
// ACE_TRACE ("ACE_Process_Mutex::lock");
  return this->lock_.lock ();
}
#endif /* ACE_WIN32 || ACE_HAS_POSIX_SEM || ACE_PSOS */

// Explicitly destroy the mutex.
ACE_INLINE int
ACE_Process_Mutex::remove (void)
{
  return this->lock_.remove ();
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire (void)
{
  return this->lock_.acquire ();
}

// Conditionally acquire lock (i.e., don't wait on queue).
ACE_INLINE int
ACE_Process_Mutex::tryacquire (void)
{
  return this->lock_.tryacquire ();
}

// Release lock and unblock a thread at head of priority queue.
ACE_INLINE int
ACE_Process_Mutex::release (void)
{
  return this->lock_.release ();
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire_read (void)
{
  return this->lock_.acquire_read ();
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire_write (void)
{
  return this->lock_.acquire_write ();
}

// Conditionally acquire a lock (i.e., won't block).
ACE_INLINE int
ACE_Process_Mutex::tryacquire_read (void)
{
  return this->lock_.tryacquire_read ();
}

// Conditionally acquire a lock (i.e., won't block).
ACE_INLINE int
ACE_Process_Mutex::tryacquire_write (void)
{
  return this->lock_.tryacquire_write ();
}

ACE_INLINE int
ACE_Process_Mutex::tryacquire_write_upgrade (void)
{
  return 0;
}
