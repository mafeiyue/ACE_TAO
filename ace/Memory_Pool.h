/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//     ACE_Memory_Pool.h
//
// = AUTHOR
//    Doug Schmidt and Prashant Jain
//
// ============================================================================

#ifndef ACE_MEMORY_POOL_H
#define ACE_MEMORY_POOL_H

#include "ace/ACE.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Handler.h"
#include "ace/Signal.h"
#include "ace/Mem_Map.h"
#if !defined (ACE_WIN32)
#include "ace/SV_Semaphore_Complex.h"
#endif /* !ACE_WIN32 */

#if !defined (ACE_LACKS_SBRK)
class ACE_Export ACE_Sbrk_Memory_Pool_Options
{
  // = TITLE
  //     Helper class for Sbrk Memory Pool constructor options.
  //
  // = DESCRIPTION
  //     This should be a nested class, but that breaks too many
  //     compilers.
};

class ACE_Export ACE_Sbrk_Memory_Pool
{
  // = TITLE
  //     Make a memory pool that is based on <sbrk(2)>.
public:
  typedef ACE_Sbrk_Memory_Pool_Options OPTIONS;

  ACE_Sbrk_Memory_Pool (LPCTSTR backing_store_name = 0,
                        const OPTIONS *options = 0);
  // Initialize the pool.

  virtual ~ACE_Sbrk_Memory_Pool (void);

  // = Implementor operations.
  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  // Ask system for initial chunk of local memory.

  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  // Acquire at least NBYTES from the memory pool.  ROUNDED_BYTES is
  // the actual number of bytes allocated.

  virtual int release (void);
  // Instruct the memory pool to release all of its resources.

  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  // Sync <len> bytes of the memory region to the backing store
  // starting at <this->base_addr_>.  If <len> == -1 then sync the
  // whole region.

  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  // Sync <len> bytes of the memory region to the backing store
  // starting at <addr_>.

  virtual int protect (ssize_t len = -1, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <this->base_addr_> up to <len> bytes.  If <len> == -1
  // then change protection of all pages in the mapped region.

  virtual int protect (void *addr, size_t len, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <addr> up to <len> bytes.

  virtual void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  virtual size_t round_up (size_t nbytes);
  // Implement the algorithm for rounding up the request to an
  // appropriate chunksize.
};
#endif /* !ACE_LACKS_SBRK */

#if !defined (ACE_LACKS_SYSV_SHMEM)

class ACE_Export ACE_Shared_Memory_Pool_Options
{
  // = TITLE
  //     Helper class for Shared Memory Pool constructor options.
  //
  // = DESCRIPTION
  //     This should be a nested class, but that breaks too many
  //     compilers.
public:
  // = Initialization method.
  ACE_Shared_Memory_Pool_Options (char *base_addr = ACE_DEFAULT_BASE_ADDR,
                                  size_t max_segments = ACE_DEFAULT_MAX_SEGMENTS,
                                  size_t file_perms = ACE_DEFAULT_FILE_PERMS,
                                  off_t minimum_bytes = 0,
                                  size_t segment_size = ACE_DEFAULT_SEGMENT_SIZE);

  char *base_addr_;
  // Base address of the memory-mapped backing store.

  size_t max_segments_;
  // Number of shared memory segments to allocate.

  off_t minimum_bytes_;
  // What the minimum bytes of the initial segment should be.

  size_t file_perms_;
  // File permissions to use when creating/opening a segment.

  size_t segment_size_;
  // Shared memory segment size.
};

class ACE_Export ACE_Shared_Memory_Pool : public ACE_Event_Handler
{
  // = TITLE
  //     Make a memory pool that is based on System V shared memory
  //     (shmget(2) etc.).  This implementation allows memory to be
  //     shared between processes.
public:
  typedef ACE_Shared_Memory_Pool_Options OPTIONS;

  ACE_Shared_Memory_Pool (LPCTSTR backing_store_name = 0,
                          const OPTIONS *options = 0);
  // Initialize the pool.

  virtual ~ACE_Shared_Memory_Pool (void);

  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  // Ask system for initial chunk of local memory.

  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  // Acquire at least NBYTES from the memory pool.  ROUNDED_BYTES is
  // the actual number of bytes allocated.  Also acquires an internal
  // semaphore that ensures proper serialization of Memory_Pool
  // initialization across processes.

  virtual int release (void);
  // Instruct the memory pool to release all of its resources.

  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  // Sync the memory region to the backing store starting at
  // <this->base_addr_>.

  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  // Sync the memory region to the backing store starting at <addr_>.

  virtual int protect (ssize_t len = -1, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <this->base_addr_> up to <len> bytes.  If <len> == -1
  // then change protection of all pages in the mapped region.

  virtual int protect (void *addr, size_t len, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <addr> up to <len> bytes.

  virtual void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  virtual size_t round_up (size_t nbytes);
  // Implement the algorithm for rounding up the request to an
  // appropriate chunksize.

  virtual int commit_backing_store_name (size_t rounded_bytes,
                                    off_t &offset);
  // Commits a new shared memory segment if necessary after an
  // <acquire> or a signal.  <offset> is set to the new offset into
  // the backing store.

  // = Keeps track of all the segments being used.
  struct SHM_TABLE
  {
    key_t key_;
    // Shared memory segment key.

    int shmid_;
    // Shared memory segment internal id.

    int used_;
    // Is the segment currently used.;
  };

  void *base_addr_;
  // Base address of the shared memory segment.  If this has the value
  // of 0 then the OS is free to select any address, otherwise this
  // value is what the OS must try to use to map the shared memory
  // segment.

  size_t file_perms_;
  // File permissions to use when creating/opening a segment.

  size_t max_segments_;
  // Number of shared memory segments in the <SHM_TABLE> table.

  off_t minimum_bytes_;
  // What the minimim bytes of the initial segment should be.

  size_t segment_size_;
  // Shared memory segment size.

  key_t base_shm_key_;
  // Base shared memory key for the segment.

  virtual int find_seg (const void *const searchPtr,
                        off_t &offset,
                        size_t &counter);
  // find the segment that contains the searchPtr

  virtual int in_use (off_t &offset,
                      size_t &counter);
  // Determine how much memory is currently in use.

  ACE_Sig_Handler signal_handler_;
  // Handles SIGSEGV.

  virtual int handle_signal (int signum, siginfo_t *, ucontext_t *);
  // Handle SIGSEGV and SIGBUS signals to remap shared memory
  // properly.
};
#endif /* !ACE_LACKS_SYSV_SHMEM */

class ACE_Export ACE_Local_Memory_Pool_Options
{
  // = TITLE
  //     Helper class for Local Memory Pool constructor options.
  //
  // = DESCRIPTION
  //     This should be a nested class, but that breaks too many
  //     compilers.
};

class ACE_Export ACE_Local_Memory_Pool
{
  // = TITLE
  //   Make a memory pool that is based on C++ new/delete.  This is
  //   useful for integrating existing components that use new/delete
  //   into the ACE Malloc scheme...
public:
  typedef ACE_Local_Memory_Pool_Options OPTIONS;

  ACE_Local_Memory_Pool (LPCTSTR backing_store_name = 0,
                         const OPTIONS *options = 0);
  // Initialize the pool.

  virtual ~ACE_Local_Memory_Pool (void);

  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  // Ask system for initial chunk of local memory.

  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  // Acquire at least NBYTES from the memory pool.  ROUNDED_BYTES is
  // the actual number of bytes allocated.

  virtual int release (void);
  // Instruct the memory pool to release all of its resources.

  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  // Sync <len> bytes of the memory region to the backing store
  // starting at <this->base_addr_>.  If <len> == -1 then sync the
  // whole region.

  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  // Sync <len> bytes of the memory region to the backing store
  // starting at <addr_>.

  virtual int protect (ssize_t len = -1, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <this->base_addr_> up to <len> bytes.  If <len> == -1
  // then change protection of all pages in the mapped region.

  virtual int protect (void *addr, size_t len, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <addr> up to <len> bytes.

  virtual void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  ACE_Unbounded_Set<char *> allocated_chunks_;
  // List of memory that we have allocated.

  virtual size_t round_up (size_t nbytes);

  // Implement the algorithm for rounding up the request to an
  // appropriate chunksize.
};

class ACE_Export ACE_MMAP_Memory_Pool_Options
{
  // = TITLE
  //     Helper class for MMAP Memory Pool constructor options.
  //
  // = DESCRIPTION
  //     This should be a nested class, but that breaks too many
  //     compilers.
public:
  // = Initialization method.
  ACE_MMAP_Memory_Pool_Options (void *base_addr = ACE_DEFAULT_BASE_ADDR,
                                int use_fixed_addr = 1,
                                int write_each_page = 1,
                                off_t minimum_bytes = 0,
                                u_int flags = 0,
                                int guess_on_fault = 1,
                                LPSECURITY_ATTRIBUTES sa = 0);

  void *base_addr_;
  // Base address of the memory-mapped backing store.

  int use_fixed_addr_;
  // Must we use the <base_addr_> or can we let mmap(2) select it?

  int write_each_page_;
  // Should each page be written eagerly to avoid surprises later
  // on?

  off_t minimum_bytes_;
  // What the minimim bytes of the initial segment should be.

  u_int flags_;
  // Any special flags that need to be used for <mmap>.

  int guess_on_fault_;
  // Try to remap without knowing the faulting address.  This
  // parameter is ignored on platforms that know the faulting address
  // (UNIX with SI_ADDR and Win32).

  LPSECURITY_ATTRIBUTES sa_;
  // Pointer to a security attributes object.  Only used on NT.

};

class ACE_Export ACE_MMAP_Memory_Pool : public ACE_Event_Handler
{
  // = TITLE
  //     Make a memory pool that is based on <mmap(2)>.  This
  //     implementation allows memory to be shared between processes.
public:
  typedef ACE_MMAP_Memory_Pool_Options OPTIONS;

  // = Initialization and termination methods.

  ACE_MMAP_Memory_Pool (LPCTSTR backing_store_name = 0,
                        const OPTIONS *options = 0);
  // Initialize the pool.

  virtual ~ACE_MMAP_Memory_Pool (void);

  virtual void *init_acquire (size_t nbytes,
                              size_t &rounded_bytes,
                              int &first_time);
  // Ask system for initial chunk of shared memory.

  virtual void *acquire (size_t nbytes,
                         size_t &rounded_bytes);
  // Acquire at least <nbytes> from the memory pool.  <rounded_bytes>
  // is the actual number of bytes allocated.  Also acquires an
  // internal semaphore that ensures proper serialization of
  // <ACE_MMAP_Memory_Pool> initialization across processes.

  virtual int release (void);
  // Instruct the memory pool to release all of its resources.

  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  // Sync the memory region to the backing store starting at
  // <this->base_addr_>.

  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  // Sync the memory region to the backing store starting at <addr_>.

  virtual int protect (ssize_t len = -1, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <this->base_addr_> up to <len> bytes.  If <len> == -1
  // then change protection of all pages in the mapped region.

  virtual int protect (void *addr, size_t len, int prot = PROT_RDWR);
  // Change the protection of the pages of the mapped region to <prot>
  // starting at <addr> up to <len> bytes.

  virtual int remap (void *addr);
  // Try to extend the virtual address space so that <addr> is now
  // covered by the address mapping.  The method succeeds and returns
  // 0 if the backing store has adequate memory to cover this address.
  // Otherwise, it returns -1.  This method is typically called by a
  // UNIX signal handler for SIGSEGV or a Win32 structured exception
  // when another process has grown the backing store (and its
  // mapping) and our process now incurs a fault because our mapping
  // isn't in range (yet).

  virtual void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  // = Implement the algorithm for rounding up the request to an
  // appropriate chunksize.

  virtual size_t round_up (size_t nbytes);

  virtual int commit_backing_store_name (size_t rounded_bytes,
                                         off_t &map_size);
  // Compute the new <map_size> of the backing store and commit the
  // memory.

  virtual int map_file (off_t map_size);
  // Memory map the file up to <map_size> bytes.

  virtual int handle_signal (int signum, siginfo_t *, ucontext_t *);
  // Handle SIGSEGV and SIGBUS signals to remap shared memory
  // properly.

  ACE_Sig_Handler signal_handler_;
  // Handles SIGSEGV.

  ACE_Mem_Map mmap_;
  // Memory-mapping object.

  void *base_addr_;
  // Base of mapped region.  If this has the value of 0 then the OS is
  // free to select any address to map the file, otherwise this value
  // is what the OS must try to use to mmap the file.

  int flags_;
  // Flags passed into <ACE_OS::mmap>.

  int write_each_page_;
  // Should we write a byte to each page to forceably allocate memory
  // for this backing store?

  off_t minimum_bytes_;
  // What the minimum bytes of the initial segment should be.

  TCHAR backing_store_name_[MAXPATHLEN + 1];
  // Name of the backing store where the shared memory pool is kept.

  int guess_on_fault_;
  // Try to remap without knowing the faulting address.  This
  // parameter is ignored on platforms that know the faulting address
  // (UNIX with SI_ADDR and Win32).

  LPSECURITY_ATTRIBUTES sa_;
  // Security attributes object, only used on NT.

};

class ACE_Export ACE_Lite_MMAP_Memory_Pool : public ACE_MMAP_Memory_Pool
{
  // = TITLE
  //     Make a ``lighter-weight'' memory pool based <ACE_Mem_Map>.
  //
  // = DESCRIPTION
  //     This implementation allows memory to be shared between
  //     processes.  However, unlike the <ACE_MMAP_Memory_Pool>
  //     the <sync> methods are no-ops, which means that we don't pay
  //     for the price of flushing the memory to the backing store on
  //     every update.  Naturally, this trades off increased
  //     performance for less reliability if the machine crashes.
public:
  // = Initialization and termination methods.

  ACE_Lite_MMAP_Memory_Pool (LPCTSTR backing_store_name = 0,
                             const OPTIONS *options = 0);
  // Initialize the pool.

  virtual ~ACE_Lite_MMAP_Memory_Pool (void);

  virtual int sync (ssize_t len = -1, int flags = MS_SYNC);
  // Overwrite the default sync behavior with no-op

  virtual int sync (void *addr, size_t len, int flags = MS_SYNC);
  // Overwrite the default sync behavior with no-op
};

#if defined (__ACE_INLINE__)
#include "ace/Memory_Pool.i"
#endif /* __ACE_INLINE__ */

#endif /* ACE_MEMORY_POOL_H */
